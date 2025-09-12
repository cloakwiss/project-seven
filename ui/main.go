package main

import (
  "fmt"
  "log"
  "net/http"
  "path/filepath"
  // "runtime"

  "github.com/webview/webview_go"
  "github.com/sqweek/dialog"
)

func main() {

  fs := http.FileServer(http.Dir("./res"))
  go func() {
    addr := ":42069"
    fmt.Printf("Serving static files on http://localhost%s\n", addr)
    if err := http.ListenAndServe(addr, fs); err != nil {
      log.Fatal(err)
    }
  }()

  // Start the webview
  w := webview.New(true)
  defer w.Destroy()

  w.SetTitle("Go + Webview File Picker")
  // w.SetSize(0, 0, webview.HintNone)

  // Navigate to the local html
  w.Navigate("http://localhost:42069/index.html")


  // Bind Go function to JS
  // JS will call window.PickFile() which returns the full path
  w.Bind("PickFile", func() (string, error) {

    selected, err := dialog.File().Title("Choose a file").Load()
    if err != nil {
      return "Error in Picking File", nil
    }

    abs, err := filepath.Abs(selected)
    if err != nil {
      return selected, nil
    }

    return abs, nil
  })

  w.Run()
}
