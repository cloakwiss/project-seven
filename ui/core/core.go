package core

import (
	"bufio"
	"context"
	// "encoding/hex"
	// "fmt"
	"net"
	"os/exec"
	"runtime"
	"time"

	"ui/app"
	"ui/inject"

	"github.com/Microsoft/go-winio"
)

// ---------------------------------------------------------------------------------------------- //
// Pipe Clients --------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //
func handleHookClient(p7 *app.ApplicationState, conn net.Conn) {
	runtime.LockOSThread()
	defer conn.Close()

	buffer := make([]byte, 1024*1024*2)

	for {
		n, err := conn.Read(buffer)
		if n > 0 {
			addHookCallRet(p7, buffer[:n])
		}
		if err != nil {
			p7.Log.Error("Read error or EOF for hook: %v\n", err)
			break
		}
	}
}

func handleLogClient(p7 *app.ApplicationState, conn net.Conn) {
	defer conn.Close()

	buf := make([]byte, 1024*1024*2)

	for {
		n, err := conn.Read(buf)
		if n > 0 {
			p7.Log.Info("%s", string(buf[:n]))
		}
		if err != nil {
			p7.Log.Error("Read error or EOF for log: %v\n", err)
			break
		}
	}
}

// ---------------------------------------------------------------------------------------------- //

// ---------------------------------------------------------------------------------------------- //
// Spawing Target ------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //
func spawnTarget(p7 *app.ApplicationState, cancel context.CancelFunc) {
	spawn := exec.Command(p7.TargetPath)

	stdoutPipe, err := spawn.StdoutPipe()
	if err != nil {
		p7.Log.Fatal("Failed to get stdout pipe: %v", err)
		return
	}
	stderrPipe, err := spawn.StderrPipe()
	if err != nil {
		p7.Log.Fatal("Failed to get stderr pipe: %v", err)
		return
	}

	if err := spawn.Start(); err != nil {
		p7.Log.Fatal("Target Spawn Failed to start: %v", err)
		cancel()
	}

	p7.Log.Info("Target Output:")

	// Stdout Handling
	go func() {
		scanner := bufio.NewScanner(stdoutPipe)
		for scanner.Scan() {
			p7.Log.Info("[STDOUT] %s", scanner.Text())
		}
		if err := scanner.Err(); err != nil {
			p7.Log.Error("Stdout scan error: %v", err)
		}
	}()

	// Stderr Handling
	go func() {
		scanner := bufio.NewScanner(stderrPipe)
		for scanner.Scan() {
			p7.Log.Error("[STDERR] %s", scanner.Text())
		}
		if err := scanner.Err(); err != nil {
			p7.Log.Error("Stderr scan error: %v", err)
		}
	}()

	if err := spawn.Wait(); err != nil {
		p7.Log.Fatal("Target Spawn Failed: %v", err)
	}

	cancel()
}

// ---------------------------------------------------------------------------------------------- //

// ---------------------------------------------------------------------------------------------- //
// Spawning Core -------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //
func Launch(p7 *app.ApplicationState) {
	inject.InjectDLL(p7)
	defer inject.RemoveDLL(p7)

	ctx, cancel := context.WithCancel(context.Background())

	// Listener to read from the InPipe -------------------------------- //
	pipeCfg := &winio.PipeConfig{
		SecurityDescriptor: "",
		MessageMode:        true,
		InputBufferSize:    1024 * 1024,
		OutputBufferSize:   256,
	}

	logListener, err := winio.ListenPipe(p7.LogPipeName, pipeCfg)
	if err != nil {
		p7.Log.Fatal("Failed to create pipe: %v", err)
	}
	defer logListener.Close()

	hookListener, err := winio.ListenPipe(p7.HookPipeName, pipeCfg)
	if err != nil {
		p7.Log.Fatal("Failed to create pipe: %v", err)
	}
	defer hookListener.Close()

	// Waiting for Target to spawn the listener for controls ----------- //
	notEnded := true
	go func() {
		for p7.ControlPipe == nil && notEnded {
			timeout := 5 * time.Second
			var err error
			p7.ControlPipe, err = winio.DialPipe(p7.ControlPipeName, &timeout)
			if err == nil {
				p7.Log.Info("Connected the control pipe")
				break
			}
			p7.Log.Error("Couldn't connect control pipe retrying: %v", err)
			time.Sleep(500 * time.Millisecond)
		}
	}()
	// ----------------------------------------------------------------- //

	go spawnTarget(p7, cancel)

	p7.Log.Info("Waiting for Hook DLL...")
	go func() {
		for {
			p7.Log.Debug("Looking for hook senders")
			conn, err := hookListener.Accept()
			if err != nil {
				p7.Log.Info("Hook Listener stopped: %v", err)
				return
			} else {
				p7.Log.Debug("Hook Listener Connected")
			}

			go handleHookClient(p7, conn)
		}
	}()

	go func() {
		for {
			p7.Log.Debug("Looking for log senders")
			conn, err := logListener.Accept()
			if err != nil {
				p7.Log.Info("Log Listener stopped: %v", err)
				return
			} else {
				p7.Log.Debug("Log Listener Connected")
			}

			handleLogClient(p7, conn)
		}
	}()

	p7.IsCoreRunning = true

	<-ctx.Done()
	notEnded = false
	p7.IsCoreRunning = false
	if p7.ControlPipe != nil {
		p7.ControlPipe.Close()
		p7.ControlPipe = nil
	}
}

// ---------------------------------------------------------------------------------------------- //
