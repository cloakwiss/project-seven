#include <cstdint>
#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>

#include "../builds/debug/detours/detours.h"
#include "./win_to_str.cpp"
#include "./hook_utils.cpp"



// MessageBoxA --------------------------------------------------------------------------------- //
static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;
static int WINAPI
HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {


    SEND_BEFORE_CALL({
        start_json_before("MessageBoxA");
        log_fields("hWnd", BOIL(hWnd));
        log_fields("lpText", BOIL(lpText));
        log_fields("lpCaption", BOIL(lpCaption));
        log_fields("uType", BOIL(uType), true);
    })

    int result;
    TIME({ result = TrueMessageBoxA(hWnd, lpText, lpCaption, uType); });

    SEND_AFTER_CALL({
        start_json_after("MessageBoxA");
        log_fields("result", BOIL(result), true);
    })


    return result;
}
// --------------------------------------------------------------------------------------------- //


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
        logs << "[HOOK] CreateProcessA called.\n";
        logs << "  lpApplicationName: " << BOIL(lpApplicationName) << "\n";
        logs << "  lpCommandLine: " << BOIL(lpCommandLine) << "\n";
        logs << "  bInheritHandles: " << BOIL(bInheritHandles) << "\n";
        logs << "  dwCreationFlags: 0x" << BOIL(dwCreationFlags) << "\n";
        logs << "  lpCurrentDirectory: " << BOIL(lpCurrentDirectory) << "\n";
    })

    BOOL result = TrueCreateProcessA(
        lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
        dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);

    SEND_AFTER_CALL({
        logs << "CreateProcessA returned: \n";
        logs << "  lpCommandLine: " << (lpCommandLine ? lpCommandLine : "NULL") << "\n";
        logs << " ( PID: " << (lpProcessInformation ? lpProcessInformation->dwProcessId : 0)
             << ")\n";
        logs << " returned: " << result << std::endl;
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
        logs << " [HOOK] CreateRemoteThread called \n";
        logs << " hProcess: " << hProcess << std::endl;
        logs << " lpThreadAttributes: " << lpThreadAttributes << std::endl;
        logs << " dwStackSize: " << dwStackSize << std::endl;
        logs << " lpStartAddress: " << reinterpret_cast<uintptr_t>(lpStartAddress) << std::endl;
        logs << " lpParameter: " << lpParameter << std::endl;
        logs << " dwCreationFlags: " << dwCreationFlags << std::endl;
    })

    HANDLE result =
        TrueCreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress,
                               lpParameter, dwCreationFlags, lpThreadId);

    SEND_AFTER_CALL({
        logs << " lpThreadId: " << lpThreadId << std::endl;
        logs << " returned: " << std::hex << result << std::endl;
    })

    return result;
}



// LoadLibraryA
static HMODULE(WINAPI *TrueLoadLibraryA)(LPCSTR lpLibFileName) = LoadLibraryA;

static HMODULE WINAPI
HookedLoadLibraryA(LPCSTR lpLibFileName) {

    SEND_BEFORE_CALL({
        logs << "[HOOK] LoadLibraryA called\n";
        logs << " lpLibFileName: " << (lpLibFileName ? lpLibFileName : "NULL") << std::endl;
    })

    HMODULE result = TrueLoadLibraryA(lpLibFileName);

    SEND_AFTER_CALL({
        logs << " LoadLibraryA Returned\n";
        logs << " returned: 0x" << std::hex << reinterpret_cast<uintptr_t>(result) << std::endl;
    })

    return result;
}



// VirtualAlloc
static LPVOID(WINAPI *TrueVirtualAlloc)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType,
                                        DWORD flProtect) = VirtualAlloc;

static LPVOID WINAPI
HookedVirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) {

    SEND_BEFORE_CALL({
        logs << "[HOOK] VirtualAlloc called\n";
        logs << " lpAddress: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpAddress) << std::dec
             << std::endl;
        logs << " dwSize: " << dwSize << std::endl;
        logs << " flAllocationType: 0x" << std::hex << flAllocationType << std::dec << std::endl;
        logs << " flProtect: 0x" << std::hex << flProtect << std::dec << std::endl;
    })

    LPVOID result = TrueVirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);

    SEND_AFTER_CALL({
        logs << " VirtualAlloc Returned\n";
        logs << " returned: 0x" << std::hex << reinterpret_cast<uintptr_t>(result) << std::dec
             << std::endl;
    })

    return result;
}



// VirtualProtect
static BOOL(WINAPI *TrueVirtualProtect)(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect,
                                        PDWORD lpflOldProtect) = VirtualProtect;

static BOOL WINAPI
HookedVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) {

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
        log_fields("lpflOldProtect", BOIL(*lpflOldProtect), true);
    })

    return result;
}



// Sleep
static VOID(WINAPI *TrueSleep)(DWORD dwMilliseconds) = Sleep;

static VOID WINAPI
HookedSleep(DWORD dwMilliseconds) {

    SEND_BEFORE_CALL({
        start_json_before("Sleep");
        log_fields("dwMilliseconds", BOIL(dwMilliseconds));
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
        logs << " hWnd: " << std::hex << reinterpret_cast<uintptr_t>(hWnd) << std::dec << std::endl;
        logs << " Msg: " << std::hex << Msg << std::dec << std::endl;
        logs << " wParam: " << std::hex << wParam << std::dec << std::endl;
        logs << " lParam: " << std::hex << lParam << std::dec << std::endl;
    })

    LRESULT result = TrueSendMessage(hWnd, Msg, wParam, lParam);

    SEND_AFTER_CALL({
        logs << "SendMessage returned\n";
        logs << " result: " << std::hex << result << std::dec << std::endl;
    })

    return result;
}



// WriteProcessMemory
static BOOL(WINAPI *TrueWriteProcessMemory)(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer,
                                            SIZE_T nSize,
                                            SIZE_T *lpNumberOfBytesWritten) = WriteProcessMemory;
static BOOL WINAPI
HookedWriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID lpBuffer, SIZE_T nSize,
                         SIZE_T *lpNumberOfBytesWritten) {
    SEND_BEFORE_CALL({
        start_json_before("WriteProcessMemory");
        logs << " hProcess: 0x" << std::hex << reinterpret_cast<uintptr_t>(hProcess) << std::dec
             << "\n";
        logs << " lpBaseAddress: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpBaseAddress)
             << std::dec << "\n";
        logs << " lpBuffer: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpBuffer) << std::dec
             << "\n";
        logs << " nSize: " << nSize << "\n";
    })

    BOOL result =
        TrueWriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten);

    SEND_AFTER_CALL({
        logs << " lpNumberOfBytesWritten: " << *lpNumberOfBytesWritten << "\n";
        logs << " Result: " << result << "\n";
    })

    return result;
}



__declspec(dllexport) BOOL APIENTRY
DllMain(HMODULE hModule, DWORD reason, LPVOID _) {


    if (reason == DLL_PROCESS_ATTACH) {
		register_base();

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

        DetourAttach(&(PVOID &)TrueLoadLibraryA, &(PVOID &)HookedLoadLibraryA);
        OutputDebugStringA("attached LoadLibraryA");

        DetourAttach(&(PVOID &)TrueVirtualAlloc, &(PVOID &)HookedVirtualAlloc);
        OutputDebugStringA("attached VirtualAlloc");

        // DetourAttach(&(PVOID &)TrueVirtualProtect, &(PVOID &)HookedVirtualProtect);
        // OutputDebugStringA("attached VirtualProtect");

        DetourAttach(&(PVOID &)TrueSleep, &(PVOID &)HookedSleep);
        OutputDebugStringA("attached Sleep");

        DetourAttach(&(PVOID &)TrueSendMessage, &(PVOID &)HookedSendMessage);
        OutputDebugStringA("attached SendMessage");

        DetourAttach(&(PVOID &)TrueWriteProcessMemory, &(PVOID &)HookedWriteProcessMemory);
        OutputDebugStringA("attached WriteProcessMemory");

        DetourTransactionCommit();
        OutputDebugStringA("commited hook");


        // Time Init
        LARGE_INTEGER FreqStructResult = {};
        QueryPerformanceFrequency(&FreqStructResult);
        PerfCounterFrequency = FreqStructResult.QuadPart;

        IsLoggingOn = true; // Why Log when process is yet to attach
        SendToServer("\"STARTED\"\n");
    } else if (reason == DLL_PROCESS_DETACH) {

        SendToServer("\"ENDED\"\n");
        IsLoggingOn = false; // Why Log when process detached

        if (GlobalPipeHandle != INVALID_HANDLE_VALUE) {
            CloseHandle(GlobalPipeHandle);
            GlobalPipeHandle = INVALID_HANDLE_VALUE;
        }

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        DetourDetach(&(PVOID &)TrueMessageBoxA, &(PVOID &)HookedMessageBoxA);
        DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourDetach(&(PVOID &)TrueCreateProcessA, &(PVOID &)HookedCreateProcessA);
        DetourDetach(&(PVOID &)TrueCreateRemoteThread, &(PVOID &)HookedCreateRemoteThread);
        DetourDetach(&(PVOID &)TrueLoadLibraryA, &(PVOID &)HookedLoadLibraryA);
        DetourDetach(&(PVOID &)TrueVirtualAlloc, &(PVOID &)HookedVirtualAlloc);
        // DetourDetach(&(PVOID &)TrueVirtualProtect, &(PVOID &)HookedVirtualProtect);
        DetourDetach(&(PVOID &)TrueSleep, &(PVOID &)HookedSleep);
        DetourDetach(&(PVOID &)TrueSendMessage, &(PVOID &)HookedSendMessage);
        DetourDetach(&(PVOID &)TrueWriteProcessMemory, &(PVOID &)HookedWriteProcessMemory);

        DetourTransactionCommit();
    }

    return TRUE;
}
