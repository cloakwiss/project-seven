package doman

import (
	"fmt"

	"github.com/webview/webview_go"
)

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

func AppendTextById(id string, text string, w *webview.WebView) {
	js := fmt.Sprintf(`document.getElementById('%s').value += %q;`, id, text)
	(*w).Dispatch(func() {
		fmt.Print(text)
		(*w).Eval(js)
	})
}
