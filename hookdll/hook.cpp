#pragma comment(lib, "user32.lib")

// #include <cstdint>
#include <windows.h>
#include <cfgmgr32.h>
#include <versionHelpers.h>

#include "../builds/debug/detours/detours.h"
#include "hook_utils.cpp"


typedef struct {
    PVOID *og;
    PVOID  hooked;
} Hook;

//  MessageBoxA : -------------------------------------------------------------------- (section)  //
static int(WINAPI *og_MessageBoxA)(HWND   hWnd,
                                   LPCSTR lpText,
                                   LPCSTR lpCaption,
                                   UINT   uType) = MessageBoxA;
static int WINAPI
hooked_MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

    SEND_BEFORE_CALL(1203)

    int result;
    TIME({ result = og_MessageBoxA(hWnd, lpText, lpCaption, uType); });

    SEND_AFTER_CALL

    return result;
}

#include "hooks.hpp"
//  (section) -------------------------------------------------------------------- : MessageBoxA  //



__declspec(dllexport) BOOL APIENTRY
DllMain(HMODULE hModule, DWORD reason, LPVOID _) {

    if (reason == DLL_PROCESS_ATTACH) {

        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        for (int64_t idx = 0; idx < sizeof(GLBL_hooks) / sizeof(GLBL_hooks[0]); idx += 1) {
            DetourAttach(GLBL_hooks[idx].og, GLBL_hooks[idx].hooked);
        }

        DetourTransactionCommit();
        OutputDebugStringA("commited hook");


        // Time Init ---------------------------------------------------------------------------- //
        LARGE_INTEGER FreqStructResult = {};
        QueryPerformanceFrequency(&FreqStructResult);
        PerfCounterFrequency = FreqStructResult.QuadPart;

		IsHookingOn = true;

        // // Rolling the ControlPipe Thread ----------------------------------------- //
        //
        // ThreadStopEvent = CreateEventA(0, TRUE, FALSE, 0);
        // ControlPipeHandle =
        //     CreateNamedPipeA(ControlPipeName,                                       // Pipe Name
        //                      PIPE_ACCESS_DUPLEX,                                    // Access
        //                      Type PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, //
        //                      Config 1,                                                     //
        //                      InstanceCount 1, // OutBuffSize, 1, // InBuffSize 0, NULL);
        //
        // if (ControlPipeHandle == INVALID_HANDLE_VALUE) {
        //     std::cerr << "Couldn't create control pipe\n";
        // }
        //
        // if (ControlPipeHandle != INVALID_HANDLE_VALUE && ThreadStopEvent) {
        //
        //     ThreadHandle = CreateThread(0, 0, ControlListener, 0, 0, 0);
        //
        //     if (ThreadHandle == INVALID_HANDLE_VALUE) {
        //         std::cerr << "Couldn't create control thread \n";
        //     }
        // }
        //
        // // Getting the Sender Running --------------------------------------------- //


        // Why Log when process is yet to attach

        // HookBuffer =
        //     (uint8_t *)VirtualAlloc(NULL, BUFFER_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        // if (HookBuffer == NULL) {
        //     std::cerr << "VirtualAlloc failed with error: " << GetLastError() << '\n';
        //     exit(3);
        // }
        // std::cerr << "Allocated Hook Buffer\n";
        //
        // LOG("STARTED");
		OutputDebugStringA("hooked all");

    } else if (reason == DLL_PROCESS_DETACH) {

		IsHookingOn = false;

        // IsHookingOn = false;
        // VirtualFree(HookBuffer, 0, MEM_RELEASE);
        //
        // // Unrolling Control Pipe Thread ------------------------------------------------ //
        // if (ThreadStopEvent) {
        //     BOOL success = SetEvent(ThreadStopEvent);
        //     if (success) {
        //         LOG("ThreadStopEvent Set");
        //     } else {
        //         LOG("ThreadStopEvent Set Failed");
        //     }
        // }
        //
        // if (ThreadHandle) {
        //     DWORD wait = WaitForSingleObject(ThreadHandle, 150);
        //     switch (wait) {
        //         case (WAIT_OBJECT_0): {
        //             LOG("Normal Stopping, from DllMain\n");
        //         } break;
        //
        //         case (WAIT_ABANDONED):
        //         case (WAIT_FAILED): {
        //             LOG("Dangerous stopping, from DllMain\n");
        //             LOG("The Wait Failed for some reason stopping the thread. dll main\n");
        //             LOG("HERE IS THE WAIT FAILED ERROR: " << GetLastError());
        //         } break;
        //
        //         case (WAIT_TIMEOUT):
        //         default: {
        //         } break;
        //     }
        //     CloseHandle(ThreadHandle);
        //     ThreadHandle = 0;
        // }
        //
        // if (ControlPipeHandle != INVALID_HANDLE_VALUE) {
        //     CloseHandle(ControlPipeHandle);
        //     ControlPipeHandle = INVALID_HANDLE_VALUE;
        // }
        //
        // if (ThreadStopEvent) {
        //     CloseHandle(ThreadStopEvent);
        //     ThreadStopEvent = 0;
        // }
        //
        //
        // Unrolling Hook Pipe Handles -------------------------------------------------- //

        if (HookPipeHandle != INVALID_HANDLE_VALUE) {
            CloseHandle(HookPipeHandle);
            HookPipeHandle = INVALID_HANDLE_VALUE;
        }

        // Unrolling Hooks ---------------------------------------------------------------------- //
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        for (int64_t idx = 0; idx < sizeof(GLBL_hooks) / sizeof(GLBL_hooks[0]); idx += 1) {
            DetourDetach(GLBL_hooks[idx].og, GLBL_hooks[idx].hooked);
        }

        DetourTransactionCommit();
		OutputDebugStringA("un hooked all");

        // LOG("ENDED");
        // if (LogPipeHandle != INVALID_HANDLE_VALUE) {
        //     CloseHandle(LogPipeHandle);
        //     LogPipeHandle = INVALID_HANDLE_VALUE;
        // }
    }

    return TRUE;
}
