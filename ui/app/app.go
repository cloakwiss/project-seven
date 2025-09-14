package app

import (
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
	Log           weblog.Logger
	Page          Page
}
