package weblog

import (
	"fmt"
	"time"

	"ui_server/doman"

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
	// doman.InsertTextById(ConsoleId, "", w)
	return Logger{w}
}

func (l *Logger) log(level LogLevel, msg string, args ...any) {
	timestamp := time.Now().Format("15:04:05")
	line := fmt.Sprintf("\n[%s] %-5s: %s\n", timestamp, level, fmt.Sprintf(msg, args...))

	doman.AppendTextById(ConsoleId, line, l.w)
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
