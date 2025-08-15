#include <windows.h>
#include <cstdio>

#include "../builds/debug/detour_include/detours.h"

static HANDLE g_hPipe = INVALID_HANDLE_VALUE;

void SendToServer(const char *text) {
    if (g_hPipe == INVALID_HANDLE_VALUE) {

        g_hPipe = CreateFile(TEXT("\\\\.\\pipe\\MyHookPipe"), GENERIC_WRITE, 0,
                             NULL, OPEN_EXISTING, 0, NULL);

        if (g_hPipe == INVALID_HANDLE_VALUE) {
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(g_hPipe, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
}

static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;

static int WINAPI HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption,
                                    UINT uType) {

    SendToServer(lpText);
    return TrueMessageBoxA(hWnd, lpText, lpCaption, uType);
}

__declspec(dllexport) BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason,
                                            LPVOID _) {
    if (reason == DLL_PROCESS_ATTACH) {
        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(PVOID &)TrueMessageBoxA, HookedMessageBoxA);
        DetourTransactionCommit();
    } else if (reason == DLL_PROCESS_DETACH) {

        if (g_hPipe != INVALID_HANDLE_VALUE) {
            CloseHandle(g_hPipe);
            g_hPipe = INVALID_HANDLE_VALUE;
        }

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourDetach(&(PVOID &)TrueMessageBoxA, HookedMessageBoxA);
        DetourTransactionCommit();
    }
    return TRUE;
}
