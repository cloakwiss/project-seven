package p7

import (
	"fmt"
	"os/exec"
)

const InjecterEXE string = "../builds/debug/main.exe"

// Inject the Hookdll from HookDllPath into
// the Target app in the TargetPath
func (p7 *ApplicationState) InjectDLL() {
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

// Remove the Hookdll from HookDllPath from
// the Target app in the TargetPath
func (p7 *ApplicationState) RemoveDLL() {
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
