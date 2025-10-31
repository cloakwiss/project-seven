package main

import (
	"fmt"
	"log"
	"net/http"
	"path/filepath"
	"runtime"
	"sync"

	// "syscall"
	// "time"
	// "strings"

	"github.com/cloakwiss/project-seven/ui/p7"

	"github.com/sqweek/dialog"
	webview "github.com/webview/webview_go"
)

// Random Utilities ----------------------------------------------------------------------------- //
func pickFile() (string, error) {
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

// ---------------------------------------------------------------------------------------------- //

func main() {

	app := p7.ApplicationState{
		Title:           "P7",
		IsCoreRunning:   false,
		Port:            "42069",
		Page:            p7.IndexPage,
		HookPipeName:    `\\.\pipe\P7_HOOKS`,
		ControlPipeName: `\\.\pipe\P7_CONTROLS`,
		LogPipeName:     `\\.\pipe\P7_LOGS`,
		StepState:       true,
	}

	// Hosting the ui ----------------------------------------------------------------------------- //

	const Url = "http://localhost:"
	fs := http.FileServer(http.Dir("./res"))
	go func() {
		fmt.Printf("Serving static files on %s%s\n", Url, app.Port)
		if err := http.ListenAndServe(":"+app.Port, fs); err != nil {
			log.Fatal(err)
		}
	}()

	// Navigating to the MainPage ----------------------------------------------------------------- //

	page := fmt.Sprintf("%s%s/%s", Url, app.Port, app.Page)
	ready := make(chan struct{})

	var wg sync.WaitGroup
	wg.Go(func() {
		runtime.LockOSThread()

		app.Ui = webview.New(true)
		defer func() {
			app.SendControl(p7.Abort)
			app.Ui.Destroy()
		}()

		app.Ui.SetTitle(app.Title)
		app.Ui.Navigate(page)
		app.Log = p7.NewLogger(&app.Ui)

		// Binds for handling interactions fromt the client side -------------------------------------- //
		app.Ui.Bind("PickTarget", func() (string, error) {
			path, err := pickFile()
			if err != nil {
				app.Log.Error("TargetPicking is not going well for some reason. %v", err)
			}

			app.Log.Info("The Target Path is: %s", path)
			app.TargetPath = path
			return path, err
		})

		app.Ui.Bind("PickHookdll", func() (string, error) {
			path, err := pickFile()
			if err != nil {
				app.Log.Error("HookdllPicking is not going well for some reason: %v", err)
			}

			app.Log.Info("The Hookdll Path is: %s", path)
			app.HookDllPath = path
			return path, err
		})

		app.Ui.Bind("SpawnP7", func() {
			if app.TargetPath != "" && app.HookDllPath != "" {
				if !app.IsCoreRunning {
					go app.Launch()
				} else {
					app.Log.Error("Already Running a P7 instance.")
				}
			} else {
				app.Log.Fatal("Target Path and HookDll path is empty.")
			}
		})

		app.Ui.Bind("Stop", func() {
			app.SendControl(p7.Stop)
		})

		app.Ui.Bind("Resume", func() {
			app.SendControl(p7.Resume)
		})

		app.Ui.Bind("Abort", func() {
			app.SendControl(p7.Abort)
		})

		app.Ui.Bind("Step", func() {
			if app.StepState {
				app.SendControl(p7.STEC)
			} else {
				app.SendControl(p7.STSC)
			}

			// To alter step to start at end of calls
			app.StepState = !app.StepState
		})

		app.Ui.Bind("STEC", func() {
			app.SendControl(p7.STEC)

			// To properly fall into the next call start
			app.StepState = false
		})

		app.Ui.Bind("STSC", func() {
			app.SendControl(p7.STSC)

			// To properly fall into the next call end
			app.StepState = true
		})
		// -------------------------------------------------------------------------------------------- //

		close(ready)
		app.Ui.Run()
	})
	<-ready

	// -------------------------------------------------------------------------------------------- //

	app.Log.Debug("P7 Started")

	wg.Wait()
}
