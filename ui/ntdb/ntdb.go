package ntdb

import (
	"database/sql"
	"errors"
	"fmt"
)

type Ntdb struct {
	dbconnection *sql.DB
	typeMap      map[string]string
	cache        map[string]FunctionData
	size         uint
}

func buildTypeMapFromDB(db *sql.DB) (map[string]string, error) {
	rows, err := db.Query("SELECT name, distilled_type FROM win_type")
	if err != nil {
		return nil, err
	}
	defer rows.Close()

	m := make(map[string]string)
	for rows.Next() {
		var key, value string
		if err := rows.Scan(&key, &value); err != nil {
			return nil, err
		}
		m[key] = value
	}
	if err := rows.Err(); err != nil {
		return nil, err
	}
	return m, nil
}

// TODO: This connection needs to be closed properly
// TODO: Cache size restriction is not implemented for now
func NewNtdb(connection *sql.DB, cacheSize uint) (Ntdb, error) {
	typeMap, error := buildTypeMapFromDB(connection)
	if error != nil {
		return Ntdb{}, error
	}
	fmt.Printf("Type Map: %v\n", typeMap)

	return Ntdb{
		connection,
		typeMap,
		make(map[string]FunctionData),
		cacheSize,
	}, nil
}

func QueryTypeOf(dbconnection *sql.DB, name string) (int, error) {
	var e error

	statement, er := dbconnection.Prepare(`with 
		p as (select count(name) as pri from win_type where name = ?), 
	    s as (select count(*) as stru from (select name from StructureSymbols where name = ? union select pointer_name from StructurePointer where pointer_name = ?))
	select (case 
		when p.pri == 1 and s.stru == 0 then 1
		when p.pri == 0 and s.stru == 1 then 2 
		else -1
	end) as result from p, s;`)
	if er != nil {
		e = errors.New("Cannot prepare the query statement.")
	}
	defer statement.Close()

	// name is needed 3 times
	result := statement.QueryRow(name, name, name)
	var n int
	if er := result.Scan(n); er != nil {
		e = errors.New("Cannot scan data of row maybe the query failed")
	}
	return n, e
}
