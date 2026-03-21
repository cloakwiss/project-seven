package inject

/*
#cgo LDFLAGS: -L../../builds/debug/ -linjectdll 

#include<stdlib.h>
#include<stdint.h>
int InjectHookDll(char *Dll, char *Executable, uint8_t Remove);
*/
import "C"

import (
	"errors"
	"unsafe"
)

func InjecHookDll(dll_path string, exec_path string, remove bool) error {
	dll := C.CBytes(append([]byte(dll_path), 0))
	defer C.free(unsafe.Pointer(dll))

	exec := C.CBytes(append([]byte(exec_path), 0))
	defer C.free(unsafe.Pointer(exec))

	rm := 1
	if (remove) {
		rm = 0
	}
	
	ret := C.InjectHookDll((*C.char)(dll), (*C.char)(exec), C.uint8_t(rm))
	if ret == 0 {
		return nil	
	} else {
		return errors.New("Error Injecting dll")
	}
}
