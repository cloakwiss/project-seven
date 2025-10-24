package core

import (
	"encoding/hex"
	"fmt"

	"ui/app"
	"ui/doman"
)

const (
	HOOK_CALL_ID byte = 0x82
	HOOK_RET_ID  byte = 0x28
)

func addHookCallRet(p7 *app.ApplicationState, buffer []byte) {
	switch buffer[0] {
	case HOOK_CALL_ID:
		{
			html := fmt.Sprintf("Hook Call Bytes: \n%v", hex.Dump(buffer[1:]))
			doman.AppendTextById("hook-status", html, &p7.Ui)
			p7.Hooks.CallList.Add(p7, buffer[1:])
			break
		}

	case HOOK_RET_ID:
		{
			html := fmt.Sprintf("Hook Return Bytes: \n%v", hex.Dump(buffer[1:]))
			doman.AppendTextById("hook-status", html, &p7.Ui)
			p7.Hooks.ReturnList.Add(p7, buffer[1:])
			break
		}

	default:
		{
			p7.Log.Fatal("Neither call nor return id found in the first byte in buffer")
			break
		}
	}
}
