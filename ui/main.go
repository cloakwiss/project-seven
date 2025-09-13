package main

import (
	"fmt"
	"log"
	"net/http"
	"os/exec"
	"path/filepath"
	// "strings"

	"github.com/sqweek/dialog"
	"github.com/webview/webview_go"
)

func InjectDLL(TargetPath string, HookdllPath string) {
	HookdllPath = fmt.Sprintf("-d%s", HookdllPath)
	TargetPath = fmt.Sprintf("-e%s", TargetPath)
	spawn := exec.Command(
		"../builds/debug/main.exe",
		HookdllPath,
		TargetPath,
	)

	output, err := spawn.CombinedOutput()
	fmt.Printf("InjectDLL Output: \n%s\n", output)
	if err != nil {
		log.Fatalf("InjectDLL Spawn Failed for some reason %v", err)
	}
}

func RemoveDLL(TargetPath string) {
	TargetPath = fmt.Sprintf("-e%s", TargetPath)
	spawn := exec.Command(
		"../builds/debug/main.exe",
		TargetPath,
		"-r",
	)

	output, err := spawn.CombinedOutput()
	fmt.Printf("RemoveDLL Output: \n%s\n", output)
	if err != nil {
		log.Fatalf("RemoveDLL Spawn Failed for some reason %v", err)
	}
}

func PickFile() (string, error) {
	selected, err := dialog.File().Title("Choose a file").Load()
	if err != nil {
		return "Error in Picking File", nil
	}

	abs, err := filepath.Abs(selected)
	if err != nil {
		return selected, nil
	}

	return abs, nil
}

func SpawnP7(TargetPath string, HookdllPath string) {
	InjectDLL(TargetPath, HookdllPath)
	defer RemoveDLL(TargetPath)

	spawn := exec.Command(TargetPath)

	output, err := spawn.CombinedOutput()
	fmt.Printf("Target Output: \n%s\n", output)
	if err != nil {
		log.Fatalf("Target Spawn Failed for some reason %v", err)
	}

}

func main() {
	fs := http.FileServer(http.Dir("./res"))
	addr := ":42069"

	go func() {
		fmt.Printf("Serving static files on http://localhost%s\n", addr)
		if err := http.ListenAndServe(addr, fs); err != nil {
			log.Fatal(err)
		}
	}()

	// Start the webview
	w := webview.New(true)
	defer w.Destroy()

	w.SetTitle("P7")

	// Navigate to the local html
	w.Navigate("http://localhost:42069/index.html")

	var TargetPath, HookdllPath string

	// Bind Go function to JS
	w.Bind("PickTarget", func() (string, error) {
		path, err := PickFile()
		if err != nil {
			fmt.Println("TargetPicking is not going well for some reason.")
			fmt.Println(err)
		}

		fmt.Printf("The Target Path is: %s\n", path)
		TargetPath = path
		return path, err
	})

	w.Bind("PickHookdll", func() (string, error) {
		path, err := PickFile()
		if err != nil {
			fmt.Println("HookdllPicking is not going well for some reason.")
			fmt.Println(err)
		}

		fmt.Printf("The Hookdll Path is: %s\n", path)
		HookdllPath = path
		return path, err
	})

	w.Bind("SpawnP7", func() {
		SpawnP7(TargetPath, HookdllPath)
	})

	w.Run()
}
