param(
	[Alias("c")]
	[ValidateSet("debug", "release")]
	[string]$Config,

	[Alias("t")]
	[ValidateSet("core", "detour", "hookdll", "all")]
	[string[]]$Targets
)

# --- Defaults ---
if (-not $Config)
{ $Config = "debug" 
}
if (-not $Targets)
{ $Targets = @("core") 
}


function Log($msg)
{
	Write-Host "[*] $msg"
}

function ErrorExit($msg)
{
	Write-Error $msg
	exit 1
}

# --- Clear Functions ---
function Clear-Detour
{
	$dest_detour_exe_loc = "./builds/" + $Config + "/detour_exe"
	$dest_detour_include_loc= "./builds/" + $Config + "/detour_include"
	$dest_detour_lib_loc= "./builds/" + $Config + "/detour_lib"

	Log "Clearing Detour ($Config)..."

	Push-Location "Detours"
	nmake realclean
	Pop-Location

	Remove-Item "$dest_detour_exe_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
	Remove-Item "$dest_detour_include_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
	Remove-Item "$dest_detour_lib_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
}

function Clear-HookDLL
{
	Log "Clearing HookDLL ($Config)..."

	$compile_loc = "builds/" + $Config + "/hookdll"

	Remove-Item "$compile_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
}

function Clear-Core
{
	Log "Clearing Core ($Config)..."
	$compile_loc = "builds/" + $Config + "/core"

	Remove-Item "$compile_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
}

function Clear-All
{
	Clear-Core
	Clear-HookDLL
	Clear-Detour
}

# --- Dispatcher ---
foreach ($target in $Targets)
{
	switch ($target.ToLower())
	{
		"core"
		{ Clear-Core 
		}
		"detour"
		{ Clear-Detour 
		}
		"hookdll"
		{ Clear-HookDLL 
		}
		"all"
		{ Clear-All 
		}
		default
		{ ErrorExit "Unknown target: $target" 
		}
	}
}

Log "Clear complete."
