package main

import (
	"log"
	"fmt"
	"net/http"
	"path/filepath"
	// "syscall"
	// "runtime"
	// "time"
	// "strings"

	// "ui_server/doman"
	"ui_server/weblog"
	"ui_server/p7"

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
// ---------------------------------------------------------------------------------------------- //

func main() {
	// Hosting the ui ----------------------------------------------------------------------------- //
	fs := http.FileServer(http.Dir("./res"))
	addr := ":42069"

	go func() {
		fmt.Printf("Serving static files on http://localhost%s\n", addr)
		if err := http.ListenAndServe(addr, fs); err != nil {
			log.Fatal(err)
		}
	}()
	// -------------------------------------------------------------------------------------------- //

	// Webview setup ------------------------------------------------------------------------------ //
	w := webview.New(true)
	defer w.Destroy()

	w.SetTitle("P7")

	w.Navigate("http://localhost:42069/index.html")

	var TargetPath, HookdllPath string
	// -------------------------------------------------------------------------------------------- //

	// Log to the ui console not the stdout/stderr
	wlog := weblog.NewLogger(&w)
	wlog.Debug("Logger Initialized")

	// Binds for handling interactions fromt the client side -------------------------------------- //
	w.Bind("PickTarget", func() (string, error) {
		path, err := pickFile()
		if err != nil {
			wlog.Error("TargetPicking is not going well for some reason. %v", err)
		}

		wlog.Info("The Target Path is: %s", path)
		TargetPath = path
		return path, err
	})

	w.Bind("PickHookdll", func() (string, error) {
		path, err := pickFile()
		if err != nil {
			wlog.Error("HookdllPicking is not going well for some reason: %v", err)
		}

		wlog.Info("The Hookdll Path is: %s", path)
		HookdllPath = path
		return path, err
	})

	w.Bind("SpawnP7", func() {
		go p7.Spawn(wlog, TargetPath, HookdllPath, &w)
	})
	// -------------------------------------------------------------------------------------------- //

	// Launching the UI --------------------------------------------------------------------------- //

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

	w.Run()
	// -------------------------------------------------------------------------------------------- //
}
