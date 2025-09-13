param(
	[Alias("c")]
	[ValidateSet("debug", "release")]
	[string]$Config,

	[Alias("t")]
	[ValidateSet("core", "detours", "hookdll", "all", "samples")]
	[string[]]$Targets
)



Invoke-Expression .\scripts\setup.ps1


if (-not $Config)
{ $Config = "debug" 
}
if (-not $Targets)
{ $Targets = @("core") 
}

$CFlags = @("-D_AMD64_", "-EHsc")

Invoke-Expression '.\scripts\clear.ps1 -c $Config -t $Targets'


function Log($msg)
{
	Write-Host "[*] $msg"
}


function ErrorExit($msg)
{
	Write-Error $msg
	exit 1
}



function Build-Detours
{
	$source_detours_include_path= "./Detours/include"
	$source_detours_lib_path= "./Detours/lib.x64"

	$dest_detours_path= "./builds/" + $Config + "/detours"


	Log "Building Detours ($Config)..."

	New-Item -ItemType Directory -Path $dest_detours_path -Force

	Push-Location "Detours"
	if ($Config -eq "debug")
	{
		devenv.com .\vc\Detours.sln /Build "DebugMDd|x64"
	} else
	{
		devenv.com .\vc\Detours.sln /Build "ReleaseMD|x64"
	}
	Pop-Location

	Copy-Item -Path "$source_detours_include_path\*" -Destination $dest_detours_path -Recurse -Force
	Copy-Item -Path "$source_detours_lib_path\*" -Destination $dest_detours_path -Recurse -Force

	Log "($Config) Build Complete for Detours"
}



function Build-HookDLL
{
	$detours_lib_path = "./builds/" + $Config + "/detours/detours.lib"
	$file_path = "./hookdll/hook.cpp"

	$rel_path_prefix = "../../"

	if (Test-Path $detours_lib_path)
	{
	} else
	{
		ErrorExit "Detours lib not found, can't compile"
	}

	Log "Building HookDLL ($Config)..."

	$compile_path = "builds/" + $Config

	New-Item -ItemType Directory -Path $compile_path -Force

	$file_path = $rel_path_prefix + $file_path
	$detours_lib_path = $rel_path_prefix + $detours_lib_path

	Push-Location $compile_path
	if ($Config -eq "debug")
	{
		cl $CFlags -Zi -LD $file_path -link $detours_lib_path
	} else
	{
		cl -O2 $CFlags -LD $file_path -link $detours_lib_path
	}
	Pop-Location
}


function Build-Core
{
	Log "Building Core ($Config)..."
	$hookdll_path = "./builds/" + $Config + "/hook.dll"
	if (Test-Path $hookdll_path)
	{
	} else
	{
		ErrorExit "Hook dll not found, can't compile"
	}

	$rel_path_prefix = "../../"

	$file_path = "injectdll/main.cpp"

	$compile_path = "builds/" + $Config
	New-Item -ItemType Directory -Path $compile_path -Force

	$file_path = $rel_path_prefix + $file_path

	Push-Location $compile_path
	if ($Config -eq "debug")
	{
		cl $CFlags -Zi $file_path
	} else
	{
		cl -O2 $CFlags $file_path
	}
	Pop-Location
}



function Build-Samples
{
	$source_dir = "./sample_targets"
	$output_dir = "./builds/debug/samples" 

	New-Item -ItemType Directory -Path $output_dir -Force

	$cpp_files = Get-ChildItem -Path $source_dir -Filter "*.cpp"

	Push-Location $output_dir

	foreach ($file in $cpp_files)
	{
		$source_path = $file.FullName

		cl $CFlags -Zi  $source_path
		if ($LASTEXITCODE -ne 0)
		{
			Write-Error "Compilation failed for $source_path"
			Pop-Location
			exit 1
		}
	}

	Pop-Location
}



function Build-All
{
	Build-Samples
	Build-Detours
	Build-HookDLL
	Build-Core
}



foreach ($target in $Targets)
{
	switch ($target.ToLower())
	{
		"core"
		{ Build-Core 
		}
		"detours"
		{ Build-Detours
		}
		"hookdll"
		{ Build-HookDLL 
		}
		"all"
		{ Build-All 
		}
		"samples"
		{ Build-Samples
		}
		default
		{ ErrorExit "Unknown target: $target" 
		}
	}
}

Log "Build complete."
