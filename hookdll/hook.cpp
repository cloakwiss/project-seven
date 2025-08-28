#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

#include "../builds/debug/detour_include/detours.h"

static HANDLE g_hPipe = INVALID_HANDLE_VALUE;

void
// method to send hook messages via pipes( pipeName - DataPipe)

SendToServer(const char *text) {
    if (g_hPipe == INVALID_HANDLE_VALUE) {

        g_hPipe = CreateFile(TEXT("\\\\.\\pipe\\DataPipe"), GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
                             0, NULL);

        if (g_hPipe == INVALID_HANDLE_VALUE) {
            DWORD dwError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << dwError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(g_hPipe, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
}

// Pointer and Hook to MessageBoxA
static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;
static int WINAPI
HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

    OutputDebugStringA("Hooked messageBoxA");

    std::ostringstream oss;
    oss << "[Hook] MessageBoxA. \n";

    oss << " hWnd: "<< std::hex << (hWnd ? reinterpret_cast<uintptr_t>(hWnd) : static_cast<uintptr_t>(0)) << std::endl;
    oss << " lpText: " << (lpText ? lpText: "NULL") << "\n";
    oss << " lpCaption: " << (lpCaption ? lpCaption: "NULL") << "\n";
    oss << " uType: " << uType << "\n";

    SendToServer(oss.str().c_str());
    oss.str(""); oss.str().clear(); // flush ostringstream 
    
    std::ostringstream ossRet;
    int result = TrueMessageBoxA(hWnd, lpText, lpCaption, uType);

    ossRet << " MessageBoxA returned : \n";
    ossRet << " hWnd: "<< std::hex << (hWnd ? reinterpret_cast<uintptr_t>(hWnd) : static_cast<uintptr_t>(0)) << std::endl;
    ossRet << " lpText: " << (lpText ? lpText: "NULL") << "\n";
    ossRet << " lpCaption: " << (lpCaption ? lpCaption: "NULL") << "\n";
    ossRet << " uType: " << uType << "\n";
    ossRet << " Returned: " << result << std::endl;

    SendToServer(ossRet.str().c_str());
    ossRet.str(""); ossRet.clear(); // flush ossRet

    return result;
}

// pointer and Hook to CreateProcessA
static BOOL(WINAPI *TrueCreateProcessA)(
    LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags,
    LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation) = CreateProcessA;

static BOOL WINAPI HookedCreateProcessA(
    LPCSTR lpApplicationName, LPSTR lpCommandLine,
    LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles,
    DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
    LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
    std::ostringstream oss;
    oss << "[HOOK] CreateProcessA called.\n";
    oss << "  lpApplicationName: " << (lpApplicationName ? lpApplicationName : "NULL") << "\n";
    oss << "  lpCommandLine: " << (lpCommandLine ? lpCommandLine : "NULL") << "\n";
    oss << "  bInheritHandles: " << bInheritHandles << "\n";
    oss << "  dwCreationFlags: 0x" << std::hex << dwCreationFlags << std::dec << "\n";
    oss << "  lpCurrentDirectory: " << (lpCurrentDirectory ? lpCurrentDirectory : "NULL") << "\n";

    SendToServer(oss.str().c_str());
    oss.str(""); oss.clear();

    BOOL result = TrueCreateProcessA(
        lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
        dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);

    std::ostringstream ossRet;
    ossRet << "[HOOK] CreateProcessA returned: " << result;
    if (lpProcessInformation) {
        ossRet << " (PID: " << lpProcessInformation->dwProcessId << ")";
    }
    SendToServer(ossRet.str().c_str());
    ossRet.str(""); ossRet.clear(); 

    return result;
}

// pointer and Hook to GetWindow
static HWND (WINAPI *TrueGetWindow) ( HWND , UINT) = GetWindow;

static HWND HookedGetWindow( HWND hWnd, UINT uCmd)
{
    std::ostringstream oss;
    oss <<  "[HOOK] GetWindow called \n";
    oss << " hWnd: " << std::hex << reinterpret_cast<uintptr_t> (hWnd) << std::endl << " uCmd: " << uCmd << std::endl ;
    SendToServer(oss.str().c_str());
    oss.str(""); oss.clear(); // flush ostringstream

    HWND result = TrueGetWindow(hWnd, uCmd);
    std::ostringstream ossRet;

    ossRet <<  " GetWindow Returned \n";
    ossRet << " hWnd: " << std::hex << reinterpret_cast<uintptr_t>(hWnd) << std::endl << " uCmd: " << uCmd << std::endl << " Returned: " << reinterpret_cast<uintptr_t> (result) << std::endl;
    SendToServer(ossRet.str().c_str());
    ossRet.str(""); ossRet.clear(); // flush

    return result;
}

// pointer and hook to CreateRemoteThread
static HANDLE (WINAPI *TrueCreateRemoteThread)
( HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE,
  LPVOID, DWORD, LPDWORD ) = CreateRemoteThread;

static HANDLE HookedCreateRemoteThread(
  HANDLE                 hProcess,
  LPSECURITY_ATTRIBUTES  lpThreadAttributes,
  SIZE_T                 dwStackSize,
  LPTHREAD_START_ROUTINE lpStartAddress,
  LPVOID                 lpParameter,
  DWORD                  dwCreationFlags,
  LPDWORD                lpThreadId //out
)
{
    std::ostringstream oss;
    
    oss << " [HOOK] CreateRemoteThread called \n";
    oss << " hProcess: " << hProcess << std::endl ;
    oss << " lpThreadAttributes: " << lpThreadAttributes << std::endl ;
    oss << " dwStackSize: " << dwStackSize << std::endl ;
    oss << " lpStartAddress: " << lpStartAddress << std::endl;
    oss << " lpParameter: " << lpParameter << std::endl;
    oss << " dwCreationFlags: " << dwCreationFlags << std::endl;
    
    SendToServer(oss.str().c_str());
    oss.str(""); oss.clear();

    HANDLE result = TrueCreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, 
        lpStartAddress, lpParameter, dwCreationFlags, lpThreadId);
    
    std::ostringstream ossRet;

    ossRet << " CreateRemoteThread returned \n";
    ossRet << " hProcess: " << hProcess << std::endl ;
    ossRet << " lpThreadAttributes: " << lpThreadAttributes << std::endl ;
    ossRet << " dwStackSize: " << dwStackSize << std::endl ;
    ossRet << " lpStartAddress: " << lpStartAddress << std::endl;
    ossRet << " lpParameter: " << lpParameter << std::endl;
    ossRet << " dwCreationFlags: " << dwCreationFlags << std::endl;
    ossRet << " lpThreadId: " << lpThreadId << std::endl;
    ossRet << " returned: " << std::hex << result << std::endl;

    SendToServer(oss.str().c_str());
    ossRet.str(""); ossRet.clear();

    return result;
}

__declspec(dllexport) BOOL APIENTRY
DllMain(HMODULE hModule, DWORD reason, LPVOID _) {

    if (reason == DLL_PROCESS_ATTACH) {

        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        OutputDebugStringA("attached MessageBox hook");
        DetourAttach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        OutputDebugStringA("attached CreateProcessA");
        DetourAttach(&(PVOID &)TrueGetWindow, &(PVOID &)HookedGetWindow);
        OutputDebugStringA("attached GetWindow");
        DetourAttach(&(PVOID &)TrueCreateRemoteThread, &(PVOID &)HookedCreateRemoteThread);
        OutputDebugStringA("attached CreateRemoteThread");

        DetourTransactionCommit();
        OutputDebugStringA("commited hook");

    } else if (reason == DLL_PROCESS_DETACH) {

        if (g_hPipe != INVALID_HANDLE_VALUE) {
            CloseHandle(g_hPipe);
            g_hPipe = INVALID_HANDLE_VALUE;
        }

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourDetach(&(PVOID &)TrueCreateRemoteThread, &(PVOID &)HookedCreateRemoteThread);

        DetourTransactionCommit();
    }

    return TRUE;
}
