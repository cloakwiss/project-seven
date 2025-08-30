#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>
#include <cstdio>
#include <sstream>

#include "../builds/debug/detours/detours.h"

static HANDLE GlobalPipeHandle = INVALID_HANDLE_VALUE;
static thread_local unsigned long GlobalCallDepth = 0;

#define SEND_BEFORE_CALL(CODE)                                                                     \
    if (GlobalCallDepth == 0) {                                                                    \
        CODE                                                                                       \
    }                                                                                              \
    GlobalCallDepth += 1;

#define SEND_AFTER_CALL(CODE)                                                                      \
    GlobalCallDepth -= 1;                                                                          \
    if (GlobalCallDepth == 0) {                                                                    \
        CODE                                                                                       \
    }



void
SendToServer(const char *text) {

    if (GlobalPipeHandle == INVALID_HANDLE_VALUE) {

        GlobalPipeHandle = CreateFileA(TEXT("\\\\.\\pipe\\DataPipe"), GENERIC_WRITE, 0, NULL,
                                       OPEN_EXISTING, 0, NULL);

        if (GlobalPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(GlobalPipeHandle, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
}



static int(WINAPI *TrueMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT) = MessageBoxA;
static int WINAPI
HookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

    OutputDebugStringA("Hooked messageBoxA");

    SEND_BEFORE_CALL({
        std::ostringstream oss;

        oss << "[Hook] MessageBoxA. \n";

        oss << " hWnd: " << std::hex
            << (hWnd ? reinterpret_cast<uintptr_t>(hWnd) : static_cast<uintptr_t>(0)) << std::endl;
        oss << " lpText: " << (lpText ? lpText : "NULL") << "\n";
        oss << " lpCaption: " << (lpCaption ? lpCaption : "NULL") << "\n";
        oss << " uType: " << uType << "\n";

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.str().clear();
    })

    int result = TrueMessageBoxA(hWnd, lpText, lpCaption, uType);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;

        ossRet << " MessageBoxA returned : \n";
        ossRet << " returned: " << result << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



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
        std::ostringstream oss;
        oss << "[HOOK] CreateProcessA called.\n";
        oss << "  lpApplicationName: " << (lpApplicationName ? lpApplicationName : "NULL") << "\n";
        oss << "  lpCommandLine: " << (lpCommandLine ? lpCommandLine : "NULL") << "\n";
        oss << "  bInheritHandles: " << bInheritHandles << "\n";
        oss << "  dwCreationFlags: 0x" << std::hex << dwCreationFlags << std::dec << "\n";
        oss << "  lpCurrentDirectory: " << (lpCurrentDirectory ? lpCurrentDirectory : "NULL")
            << "\n";

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    BOOL result = TrueCreateProcessA(
        lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles,
        dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << "CreateProcessA returned: \n";
        ossRet << "  lpCommandLine: " << (lpCommandLine ? lpCommandLine : "NULL") << "\n";
        ossRet << " ( PID: " << (lpProcessInformation ? lpProcessInformation->dwProcessId : 0)
               << ")\n";
        ossRet << " returned: " << result << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



// GetWindow
static HWND(WINAPI *TrueGetWindow)(HWND, UINT) = GetWindow;
static HWND
HookedGetWindow(HWND hWnd, UINT uCmd) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] GetWindow called \n";
        oss << " hWnd: " << std::hex << reinterpret_cast<uintptr_t>(hWnd) << std::endl
            << " uCmd: " << uCmd << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear(); // flush ostringstream
    })

    HWND result = TrueGetWindow(hWnd, uCmd);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << " GetWindow Returned \n";
        ossRet << " returned: " << std::hex << reinterpret_cast<uintptr_t>(result) << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear(); // flush
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
        std::ostringstream oss;

        oss << " [HOOK] CreateRemoteThread called \n";
        oss << " hProcess: " << hProcess << std::endl;
        oss << " lpThreadAttributes: " << lpThreadAttributes << std::endl;
        oss << " dwStackSize: " << dwStackSize << std::endl;
        oss << " lpStartAddress: " << lpStartAddress << std::endl;
        oss << " lpParameter: " << lpParameter << std::endl;
        oss << " dwCreationFlags: " << dwCreationFlags << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    HANDLE result =
        TrueCreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress,
                               lpParameter, dwCreationFlags, lpThreadId);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;

        ossRet << " lpThreadId: " << lpThreadId << std::endl;
        ossRet << " returned: " << std::hex << result << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



// LoadLibraryA
static HMODULE(WINAPI *TrueLoadLibraryA)(LPCSTR lpLibFileName) = LoadLibraryA;

static HMODULE WINAPI
HookedLoadLibraryA(LPCSTR lpLibFileName) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] LoadLibraryA called\n";
        oss << " lpLibFileName: " << (lpLibFileName ? lpLibFileName : "NULL") << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    HMODULE result = TrueLoadLibraryA(lpLibFileName);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << " LoadLibraryA Returned\n";
        ossRet << " returned: 0x" << std::hex << reinterpret_cast<uintptr_t>(result) << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



// VirtualAlloc
static LPVOID(WINAPI *TrueVirtualAlloc)(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType,
                                        DWORD flProtect) = VirtualAlloc;

static LPVOID WINAPI
HookedVirtualAlloc(LPVOID lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] VirtualAlloc called\n";
        oss << " lpAddress: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpAddress) << std::dec
            << std::endl;
        oss << " dwSize: " << dwSize << std::endl;
        oss << " flAllocationType: 0x" << std::hex << flAllocationType << std::dec << std::endl;
        oss << " flProtect: 0x" << std::hex << flProtect << std::dec << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    LPVOID result = TrueVirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << " VirtualAlloc Returned\n";
        ossRet << " returned: 0x" << std::hex << reinterpret_cast<uintptr_t>(result) << std::dec
               << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



// VirtualProtect
static BOOL(WINAPI *TrueVirtualProtect)(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect,
                                        PDWORD lpflOldProtect) = VirtualProtect;

static BOOL WINAPI
HookedVirtualProtect(LPVOID lpAddress, SIZE_T dwSize, DWORD flNewProtect, PDWORD lpflOldProtect) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] VirtualProtect called\n";
        oss << " lpAddress: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpAddress) << std::dec
            << std::endl;
        oss << " dwSize: " << dwSize << std::endl;
        oss << " flNewProtect: 0x" << std::hex << flNewProtect << std::dec << std::endl;
        oss << " lpflOldProtect: " << (lpflOldProtect ? "valid pointer" : "NULL") << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    BOOL result = TrueVirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << " VirtualProtect returned \n";
        ossRet << " returned: " << (result ? "TRUE" : "FALSE") << std::endl;
        ossRet << " oldProtection: " << std::hex << (lpflOldProtect && result ? *lpflOldProtect : 0)
               << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })

    return result;
}



// Sleep
static VOID(WINAPI *TrueSleep)(DWORD dwMilliseconds) = Sleep;

static VOID WINAPI
HookedSleep(DWORD dwMilliseconds) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] Sleep called: " << dwMilliseconds << " ms\n";

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    TrueSleep(dwMilliseconds);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << "Sleep returned\n";

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
    })
}



// SendMessage
static LRESULT(WINAPI *TrueSendMessage)(HWND hWnd, UINT Msg, WPARAM wParam,
                                        LPARAM lParam) = SendMessage;

static LRESULT WINAPI
HookedSendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {

    SEND_BEFORE_CALL({
        std::ostringstream oss;
        oss << "[HOOK] SendMessage called\n";
        oss << " hWnd: " << std::hex << reinterpret_cast<uintptr_t>(hWnd) << std::dec << std::endl;
        oss << " Msg: " << std::hex << Msg << std::dec << std::endl;
        oss << " wParam: " << std::hex << wParam << std::dec << std::endl;
        oss << " lParam: " << std::hex << lParam << std::dec << std::endl;

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    LRESULT result = TrueSendMessage(hWnd, Msg, wParam, lParam);

    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << "SendMessage returned\n";
        ossRet << " result: " << std::hex << result << std::dec << std::endl;

        SendToServer(ossRet.str().c_str());

        ossRet.str("");
        ossRet.clear();
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
        std::ostringstream oss;
        oss << "[HOOK] WriteProcessMemory called\n";
        oss << " hProcess: 0x" << std::hex << reinterpret_cast<uintptr_t>(hProcess) << std::dec
            << "\n";
        oss << " lpBaseAddress: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpBaseAddress)
            << std::dec << "\n";
        oss << " lpBuffer: 0x" << std::hex << reinterpret_cast<uintptr_t>(lpBuffer) << std::dec
            << "\n";
        oss << " nSize: " << nSize << "\n";

        SendToServer(oss.str().c_str());

        oss.str("");
        oss.clear();
    })

    BOOL result =
        TrueWriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten);


    SEND_AFTER_CALL({
        std::ostringstream ossRet;
        ossRet << " lpNumberOfBytesWritten: " << *lpNumberOfBytesWritten << "\n";
        ossRet << " Result: " << result << "\n";

        SendToServer(ossRet.str().c_str());
    })

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

    } else if (reason == DLL_PROCESS_DETACH) {

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
