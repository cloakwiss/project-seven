package p7

import (
	"fmt"
	"time"

	"github.com/webview/webview_go"
)

type LogLevel string

const ConsoleId string = "console-output"

const (
	LevelInfo  LogLevel = "INFO"
	LevelError LogLevel = "ERROR"
	LevelFatal LogLevel = "FATAL"
	LevelDebug LogLevel = "DEBUG"
)

type Logger struct {
	w *webview.WebView
}

func NewLogger(w *webview.WebView) Logger {
	return Logger{w}
}

func InsertHtmlById(id string, html string, w *webview.WebView) {
	js := fmt.Sprintf(`document.getElementById('%s').innerHTML = %q;`, id, html)
	(*w).Dispatch(func() {
		(*w).Eval(js)
	})
}

func AppendHtmlById(id string, html string, w *webview.WebView) {
	js := fmt.Sprintf(`document.getElementById('%s').innerHTML += %q;`, id, html)
	(*w).Dispatch(func() {
		(*w).Eval(js)
	})
}

func InsertTextById(id string, text string, w *webview.WebView) {
	js := fmt.Sprintf(`document.getElementById('%s').value = %q;`, id, text)
	(*w).Dispatch(func() {
		(*w).Eval(js)
	})
}

func AppendTextById(id string, text string, w *webview.WebView) {
	js := fmt.Sprintf(`document.getElementById('%s').value += %q;`, id, text)
	scrollTop := fmt.Sprintf(
		`
		var textarea = document.getElementById('%s');
		textarea.scrollTop = textarea.scrollHeight;
		`,
		id,
	)

	(*w).Dispatch(func() {
		(*w).Eval(js)
		(*w).Eval(scrollTop)
	})
}

func (l *Logger) log(level LogLevel, msg string, args ...any) {
	timestamp := time.Now().Format("15:04:05")
	line := fmt.Sprintf("\n[%s] %-5s: %s\n", timestamp, level, fmt.Sprintf(msg, args...))

	fmt.Print(line)
	AppendTextById(ConsoleId, line, l.w)
}

func (l *Logger) Info(msg string, args ...any) {
	l.log(LevelInfo, msg, args...)
}

func (l *Logger) Error(msg string, args ...any) {
	l.log(LevelError, msg, args...)
}

func (l *Logger) Fatal(msg string, args ...any) {
	l.log(LevelFatal, msg, args...)
}

func (l *Logger) Debug(msg string, args ...any) {
	l.log(LevelDebug, msg, args...)
}
