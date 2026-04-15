@echo off
setlocal enabledelayedexpansion

:: -------------------------------
:: Global settings
:: -------------------------------
set CFLAGS=-nologo -D_AMD64_ -EHsc
set CUR_DIR=%CD%
echo %CUR_DIR%
pushd builds\debug\
cl %CFLAGS% -Zi -LD ..\..\hookdll\hook.cpp -link ..\..\builds\debug\detours\detours.lib
popd

builds\debug\main.exe -e:.\builds\debug\samples\MessageBox.exe -d:%CUR_DIR%\builds\debug\hook.dll

raddbg  --project:"hook.rad" builds\debug\samples\MessageBox.exe -q
