param(
	[Alias("c")]
	[ValidateSet("debug", "release")]
	[string]$Config,

	[Alias("t")]
	[ValidateSet("core", "detours", "hookdll", "all", "samples")]
	[string[]]$Targets
)

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


function Clear-Detours
{
	$dest_detours_loc = "./builds/" + $Config + "/detours"

	Log "Clearing Detours ($Config)..."

	Push-Location "Detours"
	nmake realclean
	Pop-Location

	Remove-Item "$dest_detours_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
}


function Clear-HookDLL
{
	Log "Clearing HookDLL ($Config)..."

	$compile_loc = "builds/" + $Config

	Remove-Item "$compile_loc\hook*" -Recurse -Force -ErrorAction SilentlyContinue
}



function Clear-Core
{
	Log "Clearing Core ($Config)..."
	$compile_loc = "builds/" + $Config

	Remove-Item "$compile_loc\main*" -Recurse -Force -ErrorAction SilentlyContinue
}



function Clear-Samples 
{

	Log "Clearing Core ($Config)..."
	$compile_loc = "./builds/debug/samples"

	Remove-Item "$compile_loc\*" -Recurse -Force -ErrorAction SilentlyContinue
}



function Clear-All
{
	Clear-Core
	Clear-HookDLL
	Clear-Detours
	Clear-Samples
}



# --- Dispatcher ---
foreach ($target in $Targets)
{
	switch ($target.ToLower())
	{
		"core"
		{ Clear-Core 
		}
		"detours"
		{ Clear-Detours
		}
		"hookdll"
		{ Clear-HookDLL 
		}
		"all"
		{ Clear-All 
		}
		"samples"
		{ Clear-Samples
		}
		default
		{ ErrorExit "Unknown target: $target" 
		}
	}
}

Log "Clear complete."
