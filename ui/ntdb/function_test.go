package ntdb_test

import (
	"database/sql"
	"errors"
	"fmt"
	"log"
	"testing"

	"github.com/cloakwiss/project-seven/ui/ntdb"

	"github.com/cloakwiss/project-seven/deserialize"
	_ "github.com/mattn/go-sqlite3"
)

func getReturnValues(id string) ([]deserialize.Values, error) {
	switch id {
	case "MessageBoxA":
		{
			args := make([]deserialize.Values, 1)

			args[0].Name = "result"
			args[0].Val = int32(0)

			return args, nil
		}

	default:
		{
			return nil, errors.New("Unimplemented function id")
		}
	}
}

func getCallArgs(id string) ([]deserialize.Values, error) {
	switch id {
	case "MessageBoxA":
		{
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
		}

	case "Sleep":
		{
			args := make([]deserialize.Values, 1)

			args[0].Name = "dwMilliseconds"
			args[0].Val = uint32(0)

			return args, nil
		}

	default:
		{
			return nil, errors.New("Unimplemented function id")
		}
	}
}

func Test(t *testing.T) {
	db, err := sql.Open("sqlite3", "./ntdocs.db")
	if err != nil {
		log.Panicf("Cannot open ntdocs.db : %s\n", err)
	}
	defer db.Close()

	s := ntdb.NewNtdb(db, 1000)

	ids := []string{"Sleep"}

	for _, id := range ids {
		fmt.Printf("Testing %s\n", id)
		fData := s.GetFunctionData(id)
		trueArgs, err := fData.GetCallArgs()
		if err != nil {
			fmt.Printf("error getting call args from db for id %s: err: %v\n", id, err)
		}

		callArgs, err := getCallArgs(id)
		if err != nil {
			fmt.Printf("error getting call args from tester for id %s: err: %v\n", id, err)
		}

		if deserialize.DeepEqualValues(trueArgs, callArgs) {
			fmt.Println("Passed")
		} else {
			fmt.Println("Failed")
		}
	}
}
