param(
	[Alias("c")]
	[ValidateSet("debug", "release")]
	[string]$Config,

	[Alias("t")]
	[ValidateSet("core", "detour", "hookdll", "all", "sample_targets")]
	[string[]]$Targets
)

Invoke-Expression .\scripts\setup.ps1


# --- Defaults ---
if (-not $Config)
{ $Config = "debug" 
}
if (-not $Targets)
{ $Targets = @("core") 
}

$CFlags = @("-D_AMD64_", "-EHsc")

Invoke-Expression '.\scripts\clear.ps1 -c $Config -t $Targets'

# --- Utility Functions ---
function Log($msg)
{
	Write-Host "[*] $msg"
}

function ErrorExit($msg)
{
	Write-Error $msg
	exit 1
}

# --- Build Functions ---
function Build-Detour
{
	$source_detour_exe_path = "./Detours/bin.x64"
	$source_detour_include_path= "./Detours/include"
	$source_detour_lib_path= "./Detours/lib.x64"

	$dest_detour_exe_path = "./builds/" + $Config + "/detour_exe"
	$dest_detour_include_path= "./builds/" + $Config + "/detour_include"
	$dest_detour_lib_path= "./builds/" + $Config + "/detour_lib"


	Log "Building Detour ($Config)..."

	New-Item -ItemType Directory -Path $dest_detour_exe_path -Force
	New-Item -ItemType Directory -Path $dest_detour_include_path -Force
	New-Item -ItemType Directory -Path $dest_detour_lib_path -Force

	Push-Location "Detours"
	if ($Config -eq "debug")
	{
		devenv.com .\vc\Detours.sln /Build "DebugMDd|x64"
	} else
	{
		devenv.com .\vc\Detours.sln /Build "ReleaseMD|x64"
	}
	Pop-Location

	Copy-Item -Path "$source_detour_exe_path\*" -Destination $dest_detour_exe_path -Recurse -Force
	Copy-Item -Path "$source_detour_include_path\*" -Destination $dest_detour_include_path -Recurse -Force
	Copy-Item -Path "$source_detour_lib_path\*" -Destination $dest_detour_lib_path -Recurse -Force

	Log "($Config) Build Complete for Detour"
}

function Build-HookDLL
{
	$detour_lib_path = "./builds/" + $Config + "/detour_lib/detours.lib"
	$file_path = "./hookdll/hook.cpp"

	$rel_path_prefix = "../../../"

	if (Test-Path $detour_lib_path)
	{
	} else
	{
		ErrorExit "Detours lib not found, can't compile"
	}

	Log "Building HookDLL ($Config)..."

	$compile_path = "builds/" + $Config + "/hookdll"

	New-Item -ItemType Directory -Path $compile_path -Force

	$file_path = $rel_path_prefix + $file_path
	$detour_lib_path = $rel_path_prefix + $detour_lib_path

	Push-Location $compile_path
	if ($Config -eq "debug")
	{
		cl $CFlags -Zi -LD $file_path -link $detour_lib_path user32.lib
	} else
	{
		cl $CFlags -LD $file_path -link $detour_lib_path user32.lib
	}
	Pop-Location
}

function Build-Core
{
	Log "Building Core ($Config)..."
	# $hookdll_path = "./builds/" + $Config + "/hookdll/hook.dll"
	# if (Test-Path $hookdll_path)
	# {
	# } else
	# {
	# 	ErrorExit "Hook dll not found, can't compile"
	# }

	$rel_path_prefix = "../../../"

	$file_path = "core/main.cpp"

	$compile_path = "builds/" + $Config + "/core"
	New-Item -ItemType Directory -Path $compile_path -Force

	$file_path = $rel_path_prefix + $file_path

	Push-Location $compile_path
	if ($Config -eq "debug")
	{
		cl $CFlags -Zi $file_path
	} else
	{
		cl $CFlags $file_path
	}
	Pop-Location
}

function Build-SampleTargets
{
    $source_dir = "./sample_targets"
    $output_dir = "./builds/debug/sample_targets" 

    # Create output directory
    New-Item -ItemType Directory -Path $output_dir -Force

    # Get all .cpp files in sample_targets folder
    $cpp_files = Get-ChildItem -Path $source_dir -Filter "*.cpp"

    foreach ($file in $cpp_files)
    {
        $source_path = $file.FullName
        $exe_name = [System.IO.Path]::GetFileNameWithoutExtension($file.Name)
        $exe_path = Join-Path $output_dir $exe_name

        Write-Host "Compiling $source_path to $exe_path.exe"

        # Compile using g++
        & g++ -o "$exe_path.exe" $source_path
        if ($LASTEXITCODE -ne 0)
        {
            Write-Error "Compilation failed for $source_path"
            exit 1
        }
    }
}

function Build-All
{
	Build-Detour
	Build-HookDLL
	Build-Core
	Build-SampleTargets
}

# --- Dispatcher ---
foreach ($target in $Targets)
{
	switch ($target.ToLower())
	{
		"core"
		{ Build-Core 
		}
		"detour"
		{ Build-Detour 
		}
		"hookdll"
		{ Build-HookDLL 
		}
		"all"
		{ Build-All 
		}
		"sample_targets"
		{ Build-SampleTargets 
		}
		default
		{ ErrorExit "Unknown target: $target" 
		}
	}
}

Log "Build complete."
