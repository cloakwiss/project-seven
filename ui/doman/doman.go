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
