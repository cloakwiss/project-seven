package inject

import (
	"fmt"
	"os/exec"

	"ui_server/weblog"
)

const InjecterEXE string = "../builds/debug/main.exe"

func InjectDLL(wlog weblog.Logger, TargetPath string, HookdllPath string) {
	HookdllPath = fmt.Sprintf("-d%s", HookdllPath)
	TargetPath = fmt.Sprintf("-e%s", TargetPath)

	spawn := exec.Command(
		InjecterEXE,
		HookdllPath,
		TargetPath,
	)

	output, err := spawn.CombinedOutput()
	wlog.Info("InjectDLL Output: \n%s", output)
	if err != nil {
		wlog.Fatal("InjectDLL Spawn Failed for some reason %v", err)
	}
}

func RemoveDLL(wlog weblog.Logger, TargetPath string) {
	TargetPath = fmt.Sprintf("-e%s", TargetPath)
	spawn := exec.Command(
		InjecterEXE,
		TargetPath,
		"-r",
	)

	output, err := spawn.CombinedOutput()
	wlog.Info("RemoveDLL Output: \n%s", output)
	if err != nil {
		wlog.Fatal("RemoveDLL Spawn Failed for some reason %v", err)
	}
}
