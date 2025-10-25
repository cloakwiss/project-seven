param(
	[Alias("i")]
	[switch]$BuildInjectDLL,

	[Alias("hd")]
	[switch]$BuildHookDLL,

	[Alias("d")]
	[switch]$DoNotRun,

	[Alias("h")]
	[switch]$Help
)


function Show-Help
{
	Write-Host @"
Usage: run.ps1 [options]

Options:
  -i           Build the Hook Injector Executable
  -hd          Build HookDLL component
  -d           Do not run the ui
  -h,          Display this help message   

Examples:
  .\run.ps1 -i                  # Build the Hook Injector Executable and run UI
  .\run.ps1 -hd                 # Build HookDLL and run UI
  .\run.ps1 -i -d               # Build the Hook Injector Executable and don't run UI
  .\run.ps1 -hd -d              # Build HookDLL and don't run UI
"@
}


if ($Help)
{
	Show-Help
	exit 0
}


if ($BuildInjectDLL)
{
	Write-Host "Building InjectDll..."
	./scripts/build.ps1 -c debug -t core
}

if ($BuildHookDLL)
{
	Write-Host "Building HookDLL..."
	./scripts/build.ps1 -c debug -t hookdll
}

if (!$DoNotRun)
{
	Push-Location "webui"
	go run .
	Pop-Location
}
