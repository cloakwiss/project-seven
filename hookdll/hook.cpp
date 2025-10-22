#pragma comment(lib, "user32.lib")

// #include <cstdint>
#include <windows.h>
#include <iostream>

#include "../builds/debug/detours/detours.h"
#include "./serialization.cpp"
#include "./hook_utils.cpp"


// MessageBoxA --------------------------------------------------------------------------------- //
static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;
static int WINAPI
HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

    SEND_BEFORE_CALL("MessageBoxA", {
        BOIL_HWND(hWnd);
        BOIL_LPCSTR(lpText);
        BOIL_LPCSTR(lpCaption);
        BOIL_UINT(uType);
    })

    int result;
    TIME({ result = TrueMessageBoxA(hWnd, lpText, lpCaption, uType); });

    SEND_AFTER_CALL("MessageBoxA", { BOIL_INT32(result); })


    return result;
}
// --------------------------------------------------------------------------------------------- //


#if 0
// CreateProcessA
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

    SEND_BEFORE_CALL({
        start_json_before("CreateProcessA called");
        log_fields(" lpApplicationName: ", BOIL(lpApplicationName));
        log_fields(" lpCommandLine: ", BOIL(lpCommandLine));
        log_fields(" bInheritHandles: ", BOIL(bInheritHandles));
        log_fields(" dwCreationFlags: ", BOIL(dwCreationFlags));
        log_fields(" lpCurrentDirectory: ", BOIL(lpCurrentDirectory), true);
    })

    BOOL result = TrueCreateProcessA(
        lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes,
        bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo,
        lpProcessInformation);

    SEND_AFTER_CALL({
        start_json_before(" CreateProcessA returned ");
        log_fields(" lpCommandLine: ", BOIL(lpCommandLine));
        log_fields(" PID: ", BOIL(lpProcessInformation));
        log_fields(" returned: ", BOIL(result), true);
    })

    return result;
}



// GetWindow
static HWND(WINAPI *TrueGetWindow)(HWND, UINT) = GetWindow;
static HWND
HookedGetWindow(HWND hWnd, UINT uCmd) {

    SEND_BEFORE_CALL({
        start_json_before("GetWindow");
        log_fields("hWnd", BOIL(hWnd));
        log_fields("uCmd", BOIL(uCmd), true);
    })

    HWND result;
    TIME({ result = TrueGetWindow(hWnd, uCmd); })

    SEND_AFTER_CALL({
        start_json_after("GetWindow");
        log_fields("result ", BOIL(result), true);
    })

    return result;
}



// CreateRemoteThread
static HANDLE(WINAPI *TrueCreateRemoteThread)(HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T,
                                              LPTHREAD_START_ROUTINE, LPVOID, DWORD,
                                              LPDWORD) = CreateRemoteThread;
static HANDLE
HookedCreateRemoteThread(HANDLE hProcess, LPSECURITY_ATTRIBUTES lpThreadAttributes,
                         SIZE_T dwStackSize, LPTHREAD_START_ROUTINE lpStartAddress,
                         LPVOID lpParameter, DWORD dwCreationFlags,
                         LPDWORD lpThreadId // out
) {

    SEND_BEFORE_CALL({
        start_json_before("CreateRemoteThread called");
        log_fields("hProcess: ", BOIL(hProcess));
        log_fields("lpThreadAttributes: ", BOIL(lpThreadAttributes));
        log_fields("dwStackSize: ", BOIL(dwStackSize));
        log_fields("lpStartAddress: ", BOIL(lpStartAddress));
        log_fields("lpParameter: ", BOIL(lpParameter));
        log_fields("dwCreationFlags: ", BOIL(dwCreationFlags), true);
    })

    HANDLE result =
        TrueCreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress,
                               lpParameter, dwCreationFlags, lpThreadId);

    SEND_AFTER_CALL({
        start_json_after("CreateRemoteThread");
        log_fields("lpThreadId: ", BOIL(lpThreadId));
        log_fields("returned: ", BOIL(result), true);
    })

    return result;
}



// LoadLibraryA
static HMODULE(WINAPI *TrueLoadLibraryA)(LPCSTR lpLibFileName) = LoadLibraryA;

static HMODULE WINAPI
HookedLoadLibraryA(LPCSTR lpLibFileName) {

    SEND_BEFORE_CALL({
        start_json_before("LoadLibraryA called");
        log_fields("pLibFileName: ", BOIL(lpLibFileName), true);
    })

    HMODULE result = TrueLoadLibraryA(lpLibFileName);

    SEND_AFTER_CALL({
        start_json_after("LoadLibraryA Returned");
        log_fields("returned: ", BOIL(result), true);
    })

    return result;
}



// VirtualAlloc
static LPVOID(WINAPI *TrueVirtualAlloc)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType,
                                        DWORD flProtect) = VirtualAlloc;

static LPVOID WINAPI
HookedVirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) {

    SEND_BEFORE_CALL({
        start_json_before("VirtualAlloc called");
        log_fields("pAddress: ", BOIL(lpAddress));
        log_fields("wSize: ", BOIL(dwSize));
        log_fields("lAllocationType: ", BOIL(flAllocationType));
        log_fields("lProtect: ", BOIL(flProtect), true);
    })

    LPVOID result = TrueVirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);

    SEND_AFTER_CALL({
        start_json_after("irtualAlloc Returned");
        log_fields("returned: ", BOIL(result), true);
    })

    return result;
}



// VirtualProtect
static BOOL(WINAPI *TrueVirtualProtect)(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect,
                                        PDWORD lpflOldProtect) = VirtualProtect;

static BOOL WINAPI
HookedVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect)
{

    SEND_BEFORE_CALL({
        start_json_before("VirtualProtect");
        log_fields("lpAddress", BOIL(lpAddress));
        log_fields("dwSize", BOIL(dwSize));
        log_fields("flNewProtect", BOIL(flNewProtect));
        log_fields("lpflOldProtect", BOIL(lpflOldProtect), true);
    })

    BOOL result;
    TIME({ result = TrueVirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect); })

    SEND_AFTER_CALL({
        start_json_after("VirtualProtect");
        log_fields("result", BOIL(result));
        log_fields("lpflOldProtect", BOIL(lpflOldProtect), true);
    })

    return result;
}



// Sleep
static VOID(WINAPI *TrueSleep)(DWORD dwMilliseconds) = Sleep;

static VOID WINAPI
HookedSleep(DWORD dwMilliseconds) {

    SEND_BEFORE_CALL({
        start_json_before("Sleep");
        log_fields("dwMilliseconds", BOIL(dwMilliseconds), true);
    })

    TrueSleep(dwMilliseconds);

    SEND_AFTER_CALL({ start_json_after("Sleep"); })
}



// SendMessage
static LRESULT(WINAPI *TrueSendMessage)(HWND hWnd, UINT Msg, WPARAM wParam,
                                        LPARAM lParam) = SendMessage;

static LRESULT WINAPI
HookedSendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

    SEND_BEFORE_CALL({
        start_json_before("SendMessage");
        log_fields("Wnd: ", BOIL(hWnd));
        log_fields("sg: ", BOIL(Msg));
        log_fields("Param: ", BOIL(wParam));
        log_fields("Param: ", BOIL(lParam), true);
    })

    LRESULT result = TrueSendMessage(hWnd, Msg, wParam, lParam);

    SEND_AFTER_CALL({
        start_json_after("sendMessage returned");
        log_fields("return: ", BOIL(result), true);
    })

    return result;
}



// WriteProcessMemory
static BOOL(WINAPI *TrueWriteProcessMemory)(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID
lpBuffer,
                                            SIZE_T nSize,
                                            SIZE_T *lpNumberOfBytesWritten) = WriteProcessMemory;
static BOOL WINAPI
HookedWriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize,
                         SIZE_T *lpNumberOfBytesWritten) {
    SEND_BEFORE_CALL({
        start_json_before("WriteProcessMemory");
        log_fields("Process: ", BOIL(hProcess));
        log_fields("pBaseAddress: ", BOIL(lpBaseAddress));
        log_fields("pBuffer: ", BOIL(lpBuffer));
        log_fields("Size: ", BOIL(nSize), true);
    })

    BOOL result =
        TrueWriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten);

    SEND_AFTER_CALL({
        start_json_after("WriteProcessMemory");
        log_fields("pNumberOfBytesWritten: ", BOIL(lpNumberOfBytesWritten));
        log_fields("esult: ", BOIL(result));
    })

    return result;
}
#endif


__declspec(dllexport) BOOL APIENTRY
DllMain(HMODULE hModule, DWORD reason, LPVOID _) {

    if (reason == DLL_PROCESS_ATTACH) {
        AllocateHookBuffer();

        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        DetourAttach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);

        // DetourAttach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);

        // DetourAttach(&(PVOID &)TrueGetWindow, &(PVOID &)HookedGetWindow);

        // DetourAttach(&(PVOID &)TrueCreateRemoteThread, &(PVOID &)HookedCreateRemoteThread);

        // DetourAttach(&(PVOID &)TrueLoadLibraryA, &(PVOID &)HookedLoadLibraryA);

        // DetourAttach(&(PVOID &)TrueVirtualAlloc, &(PVOID &)HookedVirtualAlloc);

        // DetourAttach(&(PVOID &)TrueVirtualProtect, &(PVOID &)HookedVirtualProtect);

        // DetourAttach(&(PVOID &)TrueSleep, &(PVOID &)HookedSleep);

        // DetourAttach(&(PVOID &)TrueSendMessage, &(PVOID &)HookedSendMessage);

        // DetourAttach(&(PVOID &)TrueWriteProcessMemory, &(PVOID &)HookedWriteProcessMemory);

        DetourTransactionCommit();
        OutputDebugStringA("commited hook");


        // Time Init ----------------------------------------------------------- //
        LARGE_INTEGER FreqStructResult = {};
        QueryPerformanceFrequency(&FreqStructResult);
        PerfCounterFrequency = FreqStructResult.QuadPart;


        // Rolling the ControlPipe Thread ----------------------------------------- //

        ThreadStopEvent = CreateEventA(0, TRUE, FALSE, 0);
        ControlPipeHandle =
            CreateNamedPipeA(ControlPipeName,                                       // Pipe Name
                             PIPE_ACCESS_DUPLEX,                                    // Access Type
                             PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, // Config
                             1,                                                     // InstanceCount
                             1,                                                     // OutBuffSize,
                             1,                                                     // InBuffSize
                             0,
                             NULL);

        if (ControlPipeHandle == INVALID_HANDLE_VALUE) {
            std::cerr << "Couldn't create control pipe\n";
        }

        if (ControlPipeHandle != INVALID_HANDLE_VALUE && ThreadStopEvent) {

            ThreadHandle = CreateThread(0, 0, ControlListener, 0, 0, 0);

            if (ThreadHandle == INVALID_HANDLE_VALUE) {
                std::cerr << "Couldn't create control thread \n";
            }
        }

        // Getting the Sender Running --------------------------------------------- //

        // Why Log when process is yet to attach
        IsHookingOn = true;
        SendToServer("\"STARTED\"\n");

    } else if (reason == DLL_PROCESS_DETACH) {

        SendToServer("\"ENDED\"\n");
        IsHookingOn = false;
        // Why Log when process detached

        // Unrolling Control Pipe Thread ------------------------------------------------ //

        if (ThreadStopEvent) {
            BOOL success = SetEvent(ThreadStopEvent);
            if (success) {
                SendToServer("ThreadStopEvent Set\n");
            } else {
                SendToServer("ThreadStopEvent Set Failed\n");
            }
        }

        if (ThreadHandle) {
            DWORD wait = WaitForSingleObject(ThreadHandle, 150);
            switch (wait) {
                case (WAIT_OBJECT_0): {
                    SendToServer("Normal Stopping, from DllMain\n");
                } break;

                case (WAIT_ABANDONED):
                case (WAIT_FAILED): {
                    SendToServer("Dangerous stopping, from DllMain\n");
                    SendToServer("The Wait Failed for some reason stopping the thread. dll main\n");
                    std::cerr << "HERE IS THE WAIT FAILED ERROR: " << GetLastError() << '\n';
                } break;

                case (WAIT_TIMEOUT):
                default: {
                } break;
            }
            CloseHandle(ThreadHandle);
            ThreadHandle = 0;
        }

        if (ControlPipeHandle != INVALID_HANDLE_VALUE) {
            CloseHandle(ControlPipeHandle);
            ControlPipeHandle = INVALID_HANDLE_VALUE;
        }

        if (ThreadStopEvent) {
            CloseHandle(ThreadStopEvent);
            ThreadStopEvent = 0;
        }


        // Unrolling Hook Pipe Handles -------------------------------------------------- //

        if (HookPipeHandle != INVALID_HANDLE_VALUE) {
            CloseHandle(HookPipeHandle);
            HookPipeHandle = INVALID_HANDLE_VALUE;
        }

        // Unrolling Hooks -------------------------------------------------------------- //
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        DetourDetach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        // DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        // DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        // DetourDetach(&(PVOID &)TrueCreateRemoteThread, &(PVOID &)HookedCreateRemoteThread);
        // DetourDetach(&(PVOID &)TrueLoadLibraryA, &(PVOID &)HookedLoadLibraryA);
        // DetourDetach(&(PVOID &)TrueVirtualAlloc, &(PVOID &)HookedVirtualAlloc);
        // DetourDetach(&(PVOID &)TrueVirtualProtect, &(PVOID &)HookedVirtualProtect);
        // DetourDetach(&(PVOID &)TrueSleep, &(PVOID &)HookedSleep);
        // DetourDetach(&(PVOID &)TrueSendMessage, &(PVOID &)HookedSendMessage);
        // DetourDetach(&(PVOID &)TrueWriteProcessMemory, &(PVOID &)HookedWriteProcessMemory);

        DetourTransactionCommit();

        FreeHookBuffer();
    }

    return TRUE;
}
