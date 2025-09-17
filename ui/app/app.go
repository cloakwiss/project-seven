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
	Log           weblog.Logger
	OutPipe       net.Conn
	Page          Page
}

type Control byte

const (
	Start  Control = 0
	Stop   Control = 1
	Resume Control = 2
	Abort  Control = 3
	STEC   Control = 4
	STSC   Control = 5
	STENC  Control = 6
	STSNC  Control = 7
)
