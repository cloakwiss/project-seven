#include <windows.h>
#include <iostream>
#include <cstdio>
#include <iostream>
#include "../builds/debug/detour_include/detours.h"

static HANDLE g_hPipe = INVALID_HANDLE_VALUE;

void
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

static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;
static int WINAPI
HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {


    OutputDebugStringA("Hooked messageBoxA");
    SendToServer(lpText);
    return TrueMessageBoxA(hWnd, lpText, lpCaption, uType);
}

static BOOL(WINAPI *TrueCreateProcessA)(
    LPCSTR lpApplicationName, LPSTR lpCommandLine, LPSECURITY_ATTRIBUTES lpProcessAttributes,
    LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles, DWORD dwCreationFlags,
    LPVOID lpEnvironment, LPCSTR lpCurrentDirectory, LPSTARTUPINFOA lpStartupInfo,
    LPPROCESS_INFORMATION lpProcessInformation) = CreateProcessA;

static BOOL WINAPI
HookedCreateProcessA(LPCSTR lpApplicationName, LPSTR lpCommandLine,
                     LPSECURITY_ATTRIBUTES lpProcessAttributes,
                     LPSECURITY_ATTRIBUTES lpThreadAttributes, BOOL bInheritHandles,
                     DWORD dwCreationFlags, LPVOID lpEnvironment, LPCSTR lpCurrentDirectory,
                     LPSTARTUPINFOA lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation) {
    OutputDebugStringA("hooked CreateProcessA");
    SendToServer("Hooked CreateProcessA");

    return TrueCreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes,
                              lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment,
                              lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
}

__declspec(dllexport) BOOL APIENTRY
DllMain(HMODULE hModule, DWORD reason, LPVOID _) {
    if (reason == DLL_PROCESS_ATTACH) {

        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        DetourAttach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourTransactionCommit();

    } else if (reason == DLL_PROCESS_DETACH) {

        if (g_hPipe != INVALID_HANDLE_VALUE) {
            CloseHandle(g_hPipe);
            g_hPipe = INVALID_HANDLE_VALUE;
        }

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourTransactionCommit();
    }

    return TRUE;
}
