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

	// "ui/doman"
	"ui/app"
	"ui/core"
	"ui/weblog"

	"github.com/sqweek/dialog"
	"github.com/webview/webview_go"
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

func SendControl(p7 *app.ApplicationState, controlSignal app.Control) {

	if p7.OutPipe != nil {
		b := []byte{byte(controlSignal)}
		go func() {
			_, err := p7.OutPipe.Write(b)

			if err != nil {
				p7.Log.Error("Write error: %v\n", err)
			}
			// } else {
			// 	p7.Log.Debug("Wrote Signal %d", controlSignal)
			// }
		}()

	} else {
		if !p7.IsCoreRunning && (p7.OutPipe == nil) {
			p7.Log.Error("P7 is not running")
		} else if p7.OutPipe == nil {
			p7.Log.Error("OutPipe is not connected")
		}
	}
}

// ---------------------------------------------------------------------------------------------- //

func main() {

	p7 := app.ApplicationState{
		Title:         "P7",
		IsCoreRunning: false,
		Port:          "42069",
		Page:          app.IndexPage,
		InPipeName:    `\\.\pipe\P7_HOOKS`,
		OutPipeName:   `\\.\pipe\P7_CONTROLS`,
		StepState:     true,
	}

	// Hosting the ui ----------------------------------------------------------------------------- //

	const Url = "http://localhost:"
	fs := http.FileServer(http.Dir("./res"))
	go func() {
		fmt.Printf("Serving static files on %s%s\n", Url, p7.Port)
		if err := http.ListenAndServe(":"+p7.Port, fs); err != nil {
			log.Fatal(err)
		}
	}()

	// Navigating to the MainPage ----------------------------------------------------------------- //

	page := fmt.Sprintf("%s%s/%s", Url, p7.Port, p7.Page)
	ready := make(chan struct{})

	var wg sync.WaitGroup
	wg.Go(func() {
		runtime.LockOSThread()

		p7.Ui = webview.New(true)
		defer p7.Ui.Destroy()

		p7.Ui.SetTitle(p7.Title)
		p7.Ui.Navigate(page)
		p7.Log = weblog.NewLogger(&p7.Ui)

		// Binds for handling interactions fromt the client side -------------------------------------- //
		p7.Ui.Bind("PickTarget", func() (string, error) {
			path, err := pickFile()
			if err != nil {
				p7.Log.Error("TargetPicking is not going well for some reason. %v", err)
			}

			p7.Log.Info("The Target Path is: %s", path)
			p7.TargetPath = path
			return path, err
		})

		p7.Ui.Bind("PickHookdll", func() (string, error) {
			path, err := pickFile()
			if err != nil {
				p7.Log.Error("HookdllPicking is not going well for some reason: %v", err)
			}

			p7.Log.Info("The Hookdll Path is: %s", path)
			p7.HookDllPath = path
			return path, err
		})

		p7.Ui.Bind("SpawnP7", func() {
			if p7.TargetPath != "" && p7.HookDllPath != "" {
				if !p7.IsCoreRunning {
					go core.Launch(&p7)
				} else {
					p7.Log.Error("Already Running a P7 instance.")
				}
			} else {
				p7.Log.Fatal("Target Path and HookDll path is empty.")
			}
		})

		p7.Ui.Bind("Stop", func() {
			p7.Log.Info("Stop clicked")
			SendControl(&p7, app.Stop)
		})

		p7.Ui.Bind("Resume", func() {
			p7.Log.Info("Resume clicked")
			SendControl(&p7, app.Resume)
		})

		p7.Ui.Bind("Abort", func() {
			p7.Log.Info("Abort clicked")
			SendControl(&p7, app.Abort)
		})

		p7.Ui.Bind("Step", func() {
			p7.Log.Info("Step clicked")

			if p7.StepState {
				SendControl(&p7, app.STEC)
			} else {
				SendControl(&p7, app.STSC)
			}

			// To alter step to start at end of calls
			p7.StepState = !p7.StepState
		})

		p7.Ui.Bind("STEC", func() {
			p7.Log.Info("STEC clicked")
			SendControl(&p7, app.STEC)

			// To properly fall into the next call start
			p7.StepState = false
		})

		p7.Ui.Bind("STSC", func() {
			p7.Log.Info("STSC clicked")
			SendControl(&p7, app.STSC)

			// To properly fall into the next call end
			p7.StepState = true
		})
		// -------------------------------------------------------------------------------------------- //

		close(ready)
		p7.Ui.Run()
	})
	<-ready

	// -------------------------------------------------------------------------------------------- //

	// Log to the ui console not the stdout/stderr
	p7.Log.Debug("Ui Started")

	// Testing Utilities -------------------------------------------------------------------------- //
	// go func() {
	// 	for {
	// 		time.Sleep(500 * time.Millisecond)
	// 		tst := fmt.Sprintf("Server time: %v\n", time.Now())
	// 		doman.AppendTextById("console-output", tst, &w)
	// 	}
	// }()
	// tble := `
	// <div class="table-container" id="divForTable">
	//   <table class="table-styled">
	//     <thead>
	//       <tr>
	//         <th>ID</th><th>Name</th><th>Department</th><th>Role</th><th>Location</th><th>Email</th><th>Phone</th>
	//       </tr>
	//     </thead>
	//     <tbody>
	//       <tr data-row-id="1">
	//         <td>1</td><td>Alice Johnson</td><td>Engineering</td><td>Software Engineer</td><td>New York</td><td>alice.johnson@example.com</td><td>+1-202-555-0123</td>
	//       </tr>
	//       <tr data-row-id="2">
	//         <td>2</td><td>Bob Smith</td><td>Marketing</td><td>Content Strategist</td><td>San Francisco</td><td>bob.smith@example.com</td><td>+1-415-555-0456</td>
	//       </tr>
	//       <tr data-row-id="3">
	//         <td>3</td><td>Charlie Lee</td><td>Sales</td><td>Account Manager</td><td>Chicago</td><td>charlie.lee@example.com</td><td>+1-312-555-0789</td>
	//       </tr>
	//       <tr data-row-id="4">
	//         <td>4</td><td>Diana Prince</td><td>Product</td><td>Product Manager</td><td>London</td><td>diana.prince@example.co.uk</td><td>+44-20-7946-0958</td>
	//       </tr>
	//       <tr data-row-id="5">
	//         <td>5</td><td>Eddie Hernandez</td><td>Support</td><td>Support Lead</td><td>Sydney</td><td>eddie.hernandez@example.com.au</td><td>+61-2-9374-1234</td>
	//       </tr>
	//     </tbody>
	//   </table>
	// </div>
	// `
	// id := "system-log"
	// doman.InsertHtmlById(id, tble, &w)
	// -------------------------------------------------------------------------------------------- //

	wg.Wait()
}
