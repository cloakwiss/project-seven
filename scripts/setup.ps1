
if (Get-Command "cl" -ErrorAction SilentlyContinue)
{
	Write-Host "Environment Setup Is Done"
	return
}


if (Get-Command "vswhere.exe" -ErrorAction SilentlyContinue)
{
	Write-Host "vswhere.exe is available in PATH"
} else
{
	Write-Host "vshwere.exe not found in PATH"
	$Ans = Read-Host "Do you want to continue setup by installing vswhere (Y/n)"

	if ([string]::IsNullOrWhiteSpace($Ans) -or $Ans -ieq "Y")
	{
		winget install vswhere	
	} elseif ($Ans -ieq "N")
	{
		Write-Host "Exitting..."
		return
	} else
	{
		Write-Host "Invalid input"
		return
	}
}

Write-Host "Setting up Developer Environment"

$VS_Install_Path = (vswhere -format json | ConvertFrom-Json)[0].installationPath

if ([string]::IsNullOrWhiteSpace($VS_Install_Path))
{
	Write-Host "Visual Studio not present in the sytem"
	return
}

$DevEnv_Setup_Suffix= "\Common7\Tools\Launch-VsDevShell.ps1"
$DevEnv_Setup_Path = $VS_Install_Path + $DevEnv_Setup_Suffix

$DevEnv_Setup_Flags = " -SkipAutomaticLocation -Arch amd64 | Out-Null"

$command = "$DevEnv_Setup_Path $DevEnv_Setup_Flags"
Write-Host "Running: $command"

& "$DevEnv_Setup_Path" -SkipAutomaticLocation -Arch amd64
