package main

import (
	"bufio"
	"context"
	"fmt"
	"log"
	"net/http"
	"os/exec"
	"path/filepath"
	// "syscall"
	// "runtime"
	"time"
	// "strings"

	"ui_server/doman"

	"github.com/Microsoft/go-winio"
	"github.com/sqweek/dialog"
	"github.com/webview/webview_go"
)

// Inject/Remove HookDLL ------------------------------------------------------------------------ //
func injectDLL(TargetPath string, HookdllPath string) {
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

func removeDLL(TargetPath string) {
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

// ---------------------------------------------------------------------------------------------- //

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

func handleClient(conn any, w *webview.WebView, cancel context.CancelFunc) {

	defer func() {
		if c, ok := conn.(interface{ Close() error }); ok {
			c.Close()
			cancel()
		}
	}()

	reader, ok := conn.(interface{ Read([]byte) (int, error) })
	if !ok {
		log.Println("Invalid connection type")
		return
	}

	scanner := bufio.NewScanner(reader)
	i := 0
	for scanner.Scan() {
		text := scanner.Text()
		html := fmt.Sprintf("\"%d\": %s\n", i, text)
		doman.AppendTextById("hook-status", html, w) // I am getting blocked, it doesn't work for some reason
		i++
	}

	if err := scanner.Err(); err != nil {
		log.Printf("Read error: %v", err)
	}
}

// ---------------------------------------------------------------------------------------------- //

// Spawning the core system --------------------------------------------------------------------- //
func spawnP7(TargetPath string, HookdllPath string, w *webview.WebView) {
	injectDLL(TargetPath, HookdllPath)
	defer removeDLL(TargetPath)

	pipeName := `\\.\pipe\DataPipe`

	ctx, cancel := context.WithCancel(context.Background())

	pipeCfg := &winio.PipeConfig{
		SecurityDescriptor: "",
		MessageMode:        true,
		InputBufferSize:    256,
		OutputBufferSize:   256,
	}

	listener, err := winio.ListenPipe(pipeName, pipeCfg)
	if err != nil {
		log.Fatalf("Failed to create pipe: %v", err)
	}
	defer listener.Close()

	fmt.Println("Waiting for Hook DLL...")

	go func() {
		spawn := exec.Command("./launcher.exe", TargetPath)
		// output, err := spawn.CombinedOutput()
		// txt := fmt.Sprintf("Target Output:\n%s\n", output)
		// tst := "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
		// doman.AppendTextById("console-output", txt+tst, w)
		// if err != nil {
		// 	log.Fatalf("Target Spawn Failed for some reason %v", err)
		// }

		spawn.Stdout = nil
		spawn.Stderr = nil
		spawn.Stdin = nil

		err := spawn.Start()
		if err != nil {
			panic(err)
		}
		// cancel context when target app exits.
	}()

	go func() {
		for {
			conn, err := listener.Accept()
			if err != nil {
				log.Printf("Listener stopped: %v", err)
				return
			}
			fmt.Println("Hannji Hello")

			handleClient(conn, w, cancel)
		}
	}()

	// Let server run until killed
	<-ctx.Done()
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

	// Binds for handling interactions fromt the client side -------------------------------------- //
	w.Bind("PickTarget", func() (string, error) {
		path, err := pickFile()
		if err != nil {
			fmt.Println("TargetPicking is not going well for some reason.")
			fmt.Println(err)
		}

		fmt.Printf("The Target Path is: %s\n", path)
		TargetPath = path
		return path, err
	})

	w.Bind("PickHookdll", func() (string, error) {
		path, err := pickFile()
		if err != nil {
			fmt.Println("HookdllPicking is not going well for some reason.")
			fmt.Println(err)
		}

		fmt.Printf("The Hookdll Path is: %s\n", path)
		HookdllPath = path
		return path, err
	})

	w.Bind("SpawnP7", func() {
		spawnP7(TargetPath, HookdllPath, &w)
	})
	// -------------------------------------------------------------------------------------------- //

	// Launching the UI --------------------------------------------------------------------------- //

	go func() {
		for {
			time.Sleep(500 * time.Millisecond)
			tst := fmt.Sprintf("Server time: %v\n", time.Now())
			doman.AppendTextById("console-output", tst, &w)
		}
	}()
	// 	tble := `
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
	// 	`
	// 	id := "system-log"
	// 	doman.InsertHtmlById(id, tble, &w)

	w.Run()
	// -------------------------------------------------------------------------------------------- //
}
