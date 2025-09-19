package app

import (
	"net"
	"ui/weblog"

	"github.com/webview/webview_go"
)

type Page string

const (
	IndexPage  Page = "index.html"
	ReportPage Page = "report.html"
	ErrorPage  Page = "error.html"
)

type ApplicationState struct {
	Ui            webview.WebView
	TargetPath    string
	HookDllPath   string
	IsCoreRunning bool
	Title         string
	Port          string
	InPipeName    string
	OutPipeName   string
	StepState     bool
	Log           weblog.Logger
	OutPipe       net.Conn
	Page          Page
}

type Control byte

const (
	Start  Control = 0x21
	Stop   Control = 0x22
	Resume Control = 0x23
	Abort  Control = 0x24
	STEC   Control = 0x25
	STSC   Control = 0x26
)
