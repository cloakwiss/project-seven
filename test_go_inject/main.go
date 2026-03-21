package  main

import "test/inject"

func main() {
	inject.InjecHookDll("../builds/debug/hook.dll", "../builds/debug/samples/MessageBox.exe", true);
}
