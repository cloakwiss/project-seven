package p7

import (
	"bufio"
	"context"
	"fmt"
	"os/exec"

	"ui_server/doman"
	"ui_server/inject"
	"ui_server/weblog"

	"github.com/Microsoft/go-winio"
	"github.com/webview/webview_go"
)

func handleClient(wlog weblog.Logger, conn any, w *webview.WebView) {

	defer func() {
		if c, ok := conn.(interface{ Close() error }); ok {
			c.Close()
		}
	}()

	reader, ok := conn.(interface{ Read([]byte) (int, error) })
	if !ok {
		wlog.Error("Invalid connection type")
		return
	}

	scanner := bufio.NewScanner(reader)
	i := 0
	for scanner.Scan() {
		text := scanner.Text()

		html := fmt.Sprintf("\"%d\": %s\n", i, text)
		doman.AppendTextById("hook-status", html, w)

		i += 1
	}

	if err := scanner.Err(); err != nil {
		wlog.Error("Read error: %v", err)
	}
}

// ---------------------------------------------------------------------------------------------- //

// Spawning the core system --------------------------------------------------------------------- //
func Spawn(wlog weblog.Logger, TargetPath string, HookdllPath string, w *webview.WebView) {
	inject.InjectDLL(wlog, TargetPath, HookdllPath)
	defer inject.RemoveDLL(wlog, TargetPath)

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
		wlog.Fatal("Failed to create pipe: %v", err)
	}
	defer listener.Close()

	wlog.Info("Waiting for Hook DLL...")

	go func() {
		spawn := exec.Command(TargetPath)
		output, err := spawn.CombinedOutput()

		wlog.Info("Target Output:\n%s\n", output)
		if err != nil {
			wlog.Fatal("Target Spawn Failed for some reason %v", err)
		}

		cancel()
	}()

	go func() {
		for {
			conn, err := listener.Accept()
			if err != nil {
				wlog.Info("Listener stopped: %v", err)
				return
			}

			handleClient(wlog, conn, w)
		}
	}()

	// Let server run until killed
	<-ctx.Done()
}
