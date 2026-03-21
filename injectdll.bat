@echo off

pushd builds\debug\

cl -nologo -D_AMD64_ -EHsc -Zi  ..\..\injectdll\injectdll.cpp -LD /link -EXPORT:InjectHookDll

popd
