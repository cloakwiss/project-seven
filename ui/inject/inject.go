package inject

import (
	"fmt"
	"os/exec"

	"ui/app"
)

const InjecterEXE string = "../builds/debug/main.exe"

func InjectDLL(p7 *app.ApplicationState) {
	HookdllPath := fmt.Sprintf("-d%s", p7.HookDllPath)
	TargetPath := fmt.Sprintf("-e%s", p7.TargetPath)

	spawn := exec.Command(
		InjecterEXE,
		HookdllPath,
		TargetPath,
	)

	output, err := spawn.CombinedOutput()
	p7.Log.Info("InjectDLL Output: \n%s", output)
	if err != nil {
		p7.Log.Fatal("InjectDLL Spawn Failed for some reason %v", err)
	}
}

func RemoveDLL(p7 *app.ApplicationState) {
	TargetPath := fmt.Sprintf("-e%s", p7.TargetPath)
	spawn := exec.Command(
		InjecterEXE,
		TargetPath,
		"-r",
	)

	output, err := spawn.CombinedOutput()
	p7.Log.Info("RemoveDLL Output: \n%s", output)
	if err != nil {
		p7.Log.Fatal("RemoveDLL Spawn Failed for some reason %v", err)
	}
}
