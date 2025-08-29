#undef UNICODE
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <iostream>
#include <string>
#include "./builds/debug/detour_include/detours.h"

// Function to handle error messages more clearly
void PrintLastError() {
    DWORD dwError = GetLastError();
    LPVOID lpMsgBuf;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwError,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);
    std::cerr << "Error: " << (char*)lpMsgBuf;
    LocalFree(lpMsgBuf);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: injector.exe <target_exe_path> <hook_dll_path>\n";
        return 1;
    }

    const char* targetExe = argv[1];
    const char* hookDll = argv[2];

    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi = {};

    // Create process suspended and inject hook DLL using Detours
    BOOL result = DetourCreateProcessWithDllEx(
        targetExe,         // lpApplicationName
        NULL,              // lpCommandLine
        NULL,              // lpProcessAttributes
        NULL,              // lpThreadAttributes
        FALSE,             // bInheritHandles
        CREATE_SUSPENDED,  // dwCreationFlags
        NULL,              // lpEnvironment
        NULL,              // lpCurrentDirectory
        &si,               // lpStartupInfo
        &pi,               // lpProcessInformation
        hookDll,           // lpDllName
        NULL           // pfCreateProcessW (optional)
    );

    if (!result) {
        PrintLastError();
        return 1;
    }

    std::cout << "Process created and DLL injected successfully.\n";

    // Resume the suspended main thread to start the process
    
    ResumeThread(pi.hThread);

    // Close handles
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);

    return 0;
}
