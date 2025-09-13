param(
	[Alias("i")]
	[switch]$BuildInjectDLL,

	[Alias("hd")]
	[switch]$BuildHookDLL,

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
  -t <name>    Specify sample target executable name under ./builds/debug/sample_targets/
  -h,          Display this help message   

Examples:
  .\run.ps1 -i                  # Build the Hook Injector Executable
  .\run.ps1 -hd                 # Build Core and HookDLL and run target.exe
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
