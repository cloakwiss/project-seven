param(
	[Alias("hd")]
	[switch]$BuildHookDLL,

	[Alias("t")]
	[string]$SampleTargetName,

	[Alias("h")]
	[switch]$Help
)

Write-Host "Building Core..."
./scripts/build.ps1 -c debug -t core

function Show-Help
{
	Write-Host @"
Usage: run.ps1 [options]

Options:
  -hd          Build HookDLL component
  -t <name>    Specify sample target executable name under ./builds/debug/sample_targets/
  -h,          Display this help message

Examples:
  .\run.ps1                     # Builds core
  .\run.ps1 -hd -t target.exe   # Build Core and HookDLL and run target.exe
  .\run.ps1 -t target.exe       # Build Core and Run target.exe
"@
}


if ($Help)
{
	Show-Help
	exit 0
}

if (-not ($BuildHookDLL -or $PSBoundParameters.ContainsKey('SampleTargetName')))
{
	Write-Host "Available Samples are: "
	Get-ChildItem "./builds/debug/samples/" -File |
		Select-Object -ExpandProperty BaseName |
		Sort-Object -Unique |
		ForEach-Object { Write-Host " - $_" }
	Show-Help
	exit 1
}

if ($PSBoundParameters.ContainsKey('SampleTargetName'))
{
	if ([string]::IsNullOrEmpty($SampleTargetName))
	{
		throw "Error: SampleTargetName (-t) was provided but is empty. Use -h for more usage information"
	}
}

if ($BuildHookDLL)
{
	Write-Host "Building HookDLL..."
	./scripts/build.ps1 -c debug -t hookdll
}


if ($PSBoundParameters.ContainsKey('SampleTargetName'))
{
	$core_path = "./builds/debug/main.exe"
	$hookdll_path = "./builds/debug/hook.dll"
	$sample_target_path = "./builds/debug/samples/$SampleTargetName.exe"

	if (Test-Path -IsValid $hookdll_path)
	{
		if (Test-Path -IsValid $sample_target_path)
		{
			$sample_target_path = "-e:" + $sample_target_path
			$hookdll_path = "-d:" + $hookdll_path

			Write-Host "Running with target executable: $sample_target_path"
			& $core_path $sample_target_path $hookdll_path
		} else
		{
			Write-Host "SampleTargetName specified is not available:"
			Write-Host "Available Samples are: "
			Get-ChildItem "./builds/debug/samples/" -File |
				Select-Object -ExpandProperty BaseName |
				Sort-Object -Unique |
				ForEach-Object { Write-Host " - $_" }
		}
	} else {
		Write-Host "Hook dll is not available"
	}
} else
{
	Write-Host "SampleTargetName (-t) not specified; showing available samples:`n"
	Write-Host "Available Samples are: "
	Get-ChildItem "./builds/debug/samples/" -File |
		Select-Object -ExpandProperty BaseName |
		Sort-Object -Unique |
		ForEach-Object { Write-Host " - $_" }
}
