package ntdb

import (
	"database/sql"
	"errors"
	"log"

	deserialize "github.com/cloakwiss/project-seven/deserialize"
)

type FunctionData struct {
	Name, Return, Description, Requirement string
	Arity                                  uint
	FunctionParameters
}

type FunctionParameters []FunctionParameter

type FunctionParameter struct {
	Name, Datatype, Usage, Documentation string
}

func (s *Ntdb) GetFunctionData(function_name string) FunctionData {
	if data, found := s.cache[function_name]; found {
		return data
	}
	data := query(s.dbconnection, function_name)
	s.cache[function_name] = data
	return data
}

// This function interacts with the database for query and should not be called directly
func query(dbConnection *sql.DB, function_name string) FunctionData {
	functionSymbols, er := dbConnection.Prepare(
		`SELECT FunctionSymbols.name, FunctionSymbols.arity, FunctionSymbols.return, 
		FunctionSymbols.description, FunctionSymbols.requirements FROM FunctionSymbols 
		WHERE FunctionSymbols.name = ?;`)

	if er != nil {
		log.Panicf("Failed to prepare the FunctionSymbols query, due to: %v", er)
	}
	defer functionSymbols.Close()

	functionParameters, er := dbConnection.Prepare(
		`SELECT FunctionParameters.srno, FunctionParameters.name, FunctionParameters.datatype, 
		FunctionParameters.usage, FunctionParameters.documentation FROM FunctionParameters WHERE 
		FunctionParameters.function_name = ? AND FunctionParameters.srno <= ? ORDER BY 
		FunctionParameters.srno;`)

	if er != nil {
		log.Panic("Failed to prepare the FunctionParameter query, due to: %+w", er)
	}
	defer functionParameters.Close()

	var functionData FunctionData
	{
		resultingSymbol, er := functionSymbols.Query(function_name)
		if er != nil {
			log.Panicf("Query of Function Symbols table failed due to: %v", er)
		}
		defer resultingSymbol.Close()

		if resultingSymbol.Next() {
			if er := resultingSymbol.Scan(
				&functionData.Name,
				&functionData.Arity,
				&functionData.Return,
				&functionData.Description,
				&functionData.Requirement,
			); er != nil {
				log.Panicf("Some error %v while scanning %s's result \n", er, "FunctionSymbol")
			}
		}
		if resultingSymbol.Next() {
			log.Panic("Only 1 Row is expected from the Function Symbols table")
		}
		if functionData.Name != function_name {
			log.Panicf("Search failed!!!!: %v | %v\n", functionData.Name, function_name)
		}
	}
	{
		resultingParameters, er := functionParameters.Query(functionData.Name, functionData.Arity)
		if er != nil {
			log.Panic("Query of Function Parameter table failed due to: %+w", er)
		}
		defer resultingParameters.Close()

		functionData.FunctionParameters = make(FunctionParameters, 0, int(functionData.Arity))
		for i := 0; i < int(functionData.Arity) && resultingParameters.Next(); i += 1 {
			var functionPara FunctionParameter
			var num int

			if er := resultingParameters.Scan(
				&num,
				&functionPara.Name,
				&functionPara.Datatype,
				&functionPara.Usage,
				&functionPara.Documentation,
			); er != nil {
				log.Panicf("Some error %v while scanning %s's result \n", er, "FunctionParameter")
			}

			// This should not be possible
			if num != i+1 {
				log.Panicln("Out of order")
			}
			functionData.FunctionParameters = append(functionData.FunctionParameters, functionPara)
		}

		// This should not be possible
		if resultingParameters.Next() {
			log.Panicf("Expected only %d rows in result, found more.\n", functionData.Arity)
		}
	}
	return functionData
}

// --------------------------------------------------------------------------------------------- //
// Template Getters (to be implemented generally for all funcs) -------------------------------- //
// --------------------------------------------------------------------------------------------- //

// Get Call Arguments fromt the function data
func (funcData *FunctionData) GetCallArgs() ([]deserialize.Values, error) {
	if funcData.Name == "MessageBoxA" {
		args := make([]deserialize.Values, 4)

		args[0].Name = "hWnd"
		args[0].Val = uint64(0)

		args[1].Name = "lpText"
		args[1].Val = string("")

		args[2].Name = "lpCaption"
		args[2].Val = string("")

		args[3].Name = "uType"
		args[3].Val = uint32(0)

		return args, nil
	} else {
		return nil, errors.New("Unimplemented function id")
	}
}

// Get Return Values from the function data
func (funcData *FunctionData) GetReturnValues() ([]deserialize.Values, error) {
	if funcData.Name == "MessageBoxA" {
		args := make([]deserialize.Values, 1)

		args[0].Name = "result"
		args[0].Val = int32(0)

		return args, nil
	} else {
		return nil, errors.New("Unimplemented function id")
	}
}
