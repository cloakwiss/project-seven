param(
    [Alias("c")]
    [switch]$BuildCore,

    [Alias("hd")]
    [switch]$BuildHookDLL,

    [Alias("t")]
    [string]$SampleTargetName,

    [Alias("h")]
    [switch]$Help
)

function Show-Help {
    Write-Host @"
Usage: run.ps1 [options]

Options:
  -c           Build Core component
  -hd          Build HookDLL component
  -t <name>    Specify sample target executable name under ./builds/debug/sample_targets/
  -h,          Display this help message

Examples:
  .\run.ps1 -c -hd -t target.exe   # Build Core and HookDLL and run target.exe
  .\run.ps1 -c                    # Build only Core
  .\run.ps1 -t target.exe          # Run target.exe without building
"@
}

if ($Help) {
    Show-Help
    exit 0
}

if (-not ($BuildCore -or $BuildHookDLL -or $PSBoundParameters.ContainsKey('SampleTargetName'))) {
    throw "No parameters provided. -h for usage information."
}

# Validate SampleTargetName only if provided
if ($PSBoundParameters.ContainsKey('SampleTargetName')) {
    if ([string]::IsNullOrEmpty($SampleTargetName)) {
        throw "Error: SampleTargetName (-t) was provided but is empty. Use -h for more usage information"
    }
}

# Run builds if specified
if ($BuildCore) {
    Write-Host "Building Core..."
    ./scripts/build.ps1 -c debug -t core
}
if ($BuildHookDLL) {
    Write-Host "Building HookDLL..."
    ./scripts/build.ps1 -c debug -t hookdll
}

# Only run withdll command if SampleTargetName is specified
if ($PSBoundParameters.ContainsKey('SampleTargetName')) {
    $withdll_path = "./builds/debug/detour_exe/withdll.exe"
    $hookdll_path = "./builds/debug/hookdll/hook.dll"
    $sample_target_path = "./builds/debug/sample_targets/$SampleTargetName"

    Write-Host "Running with target executable: $sample_target_path"
    Invoke-Expression "$withdll_path -d:`"$hookdll_path`" `"$sample_target_path`""
} else {
    Write-Host "SampleTargetName (-t) not specified; skipping execution of withdll."
}
