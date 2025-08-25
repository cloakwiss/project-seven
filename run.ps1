./scripts/build.ps1 -c debug -t hookdll

$withdll_path = "./builds/debug/detour_exe/withdll.exe"
$hookdll_path = "./builds/debug/hookdll/hook.dll"

$sample_target_path = "./builds/debug/sample_targets/message_box.exe"

Invoke-Expression "$withdll_path -d:$hookdll_path $sample_target_path"
