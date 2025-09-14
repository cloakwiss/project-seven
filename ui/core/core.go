package core

import (
	"bufio"
	"context"
	"fmt"
	"os/exec"
	"runtime"

	"ui/app"
	"ui/doman"
	"ui/inject"

	"github.com/Microsoft/go-winio"
)

func handleClient(p7 *app.ApplicationState, conn any) {

	defer func() {
		if c, ok := conn.(interface{ Close() error }); ok {
			c.Close()
		}
	}()

	reader, ok := conn.(interface{ Read([]byte) (int, error) })
	if !ok {
		p7.Log.Error("Invalid connection type")
		return
	}

	scanner := bufio.NewScanner(reader)
	i := 0
	for scanner.Scan() {
		text := scanner.Text()

		html := fmt.Sprintf("\"%d\": %s\n", i, text)
		doman.AppendTextById("hook-status", html, &p7.Ui)

		i += 1
	}

	if err := scanner.Err(); err != nil {
		p7.Log.Error("Read error: %v", err)
	}
}

// ---------------------------------------------------------------------------------------------- //

// Spawning the core system --------------------------------------------------------------------- //
func Launch(p7 *app.ApplicationState) {
	inject.InjectDLL(p7)
	defer inject.RemoveDLL(p7)

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
		p7.Log.Fatal("Failed to create pipe: %v", err)
	}
	defer listener.Close()

	p7.Log.Info("Waiting for Hook DLL...")

	go func() {
		runtime.LockOSThread()
		spawn := exec.Command(p7.TargetPath)
		output, err := spawn.CombinedOutput()

		p7.Log.Info("Target Output:\n%s\n", output)
		if err != nil {
			p7.Log.Fatal("Target Spawn Failed for some reason %v", err)
		}

		cancel()
	}()

	go func() {
		for {
			conn, err := listener.Accept()
			if err != nil {
				p7.Log.Info("Listener stopped: %v", err)
				return
			}

			handleClient(p7, conn)
		}
	}()

	// Let server run until killed
	<-ctx.Done()
	p7.IsCoreRunning = false
}
