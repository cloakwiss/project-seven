module github.com/cloakwiss/project-seven/ui

go 1.25.3

require (
	github.com/cloakwiss/project-seven/deserialize v0.0.0
	github.com/sqweek/dialog v0.0.0-20240226140203-065105509627
	github.com/webview/webview_go v0.0.0-20240831120633-6173450d4dd6
)

replace github.com/cloakwiss/project-seven/deserialize => ../deserialize

require (
	github.com/Microsoft/go-winio v0.6.2 // direct
	github.com/TheTitanrain/w32 v0.0.0-20180517000239-4f5cfb03fabf // indirect
	golang.org/x/sys v0.10.0 // indirect
)
