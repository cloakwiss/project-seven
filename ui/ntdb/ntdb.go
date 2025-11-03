package ntdb

import (
	"database/sql"
)

type Ntdb struct {
	dbconnection *sql.DB
	cache        map[string]FunctionData
	size         uint
}

// TODO: This connection needs to be closed properly
// TODO: Cache size restriction is not implemented for now
func NewNtdb(connection *sql.DB, cacheSize uint) Ntdb {
	return Ntdb{
		connection,
		make(map[string]FunctionData),
		cacheSize,
	}
}
