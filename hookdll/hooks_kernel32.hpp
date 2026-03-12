#pragma comment(lib, "onecore.lib")

// This are not all of hooks I deleted some until the dll compiled
// this is just tentative finalized stuff will be made afterwords
// this is just a store

#include <windows.h>
#include <threadpoollegacyapiset.h>
#include <systemtopologyapi.h>
#include <winbase.h>
#include <versionhelpers.h>
#include <realtimeapiset.h>
#include <handleapi.h>
#include <synchapi.h>
#include <profileapi.h>
#include <winnls.h>
#include <wow64apiset.h>
#include <windowsceip.h>
#include <libloaderapi.h>
#include <enclaveapi.h>
#include <stringapiset.h>
#include <ioapiset.h>
#include <namedpipeapi.h>
#include <processthreadsapi.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <jobapi2.h>
#include <errhandlingapi.h>
#include <oobenotification.h>
#include <namespaceapi.h>
#include <appmodel.h>
#include <werapi.h>
#include <fibersapi.h>
#include <fileapi.h>
#include <stralign.h>
#include <securityappcontainer.h>
#include <datetimeapi.h>
#include <memoryapi.h>
#include <interlockedapi.h>
#include <jobapi.h>
#include <threadpoolapiset.h>
#include <heapapi.h>
#include <utilapiset.h>
#include <processtopologyapi.h>
#include <processenv.h>
#include <securitybaseapi.h>
#include <sysinfoapi.h>
#include <processsnapshot.h>
#include <timezoneapi.h>
#include <winnt.h>
#include "hook_utils.cpp"


static VOID (WINAPI *og_DisassociateCurrentThreadFromCallback)(PTP_CALLBACK_INSTANCE pci) = DisassociateCurrentThreadFromCallback;
static VOID WINAPI hooked_DisassociateCurrentThreadFromCallback(PTP_CALLBACK_INSTANCE pci) {

	SEND_BEFORE_CALL

	
	TIME({ og_DisassociateCurrentThreadFromCallback(pci); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_FreeLibraryWhenCallbackReturns)(PTP_CALLBACK_INSTANCE pci,  HMODULE mod) = FreeLibraryWhenCallbackReturns;
static VOID WINAPI hooked_FreeLibraryWhenCallbackReturns(PTP_CALLBACK_INSTANCE pci,  HMODULE mod) {

	SEND_BEFORE_CALL

	
	TIME({ og_FreeLibraryWhenCallbackReturns(pci, mod); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_IsThreadpoolTimerSet)(PTP_TIMER pti) = IsThreadpoolTimerSet;
static BOOL WINAPI hooked_IsThreadpoolTimerSet(PTP_TIMER pti) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsThreadpoolTimerSet(pti); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_LeaveCriticalSectionWhenCallbackReturns)(PTP_CALLBACK_INSTANCE pci,  PCRITICAL_SECTION pcs) = LeaveCriticalSectionWhenCallbackReturns;
static VOID WINAPI hooked_LeaveCriticalSectionWhenCallbackReturns(PTP_CALLBACK_INSTANCE pci,  PCRITICAL_SECTION pcs) {

	SEND_BEFORE_CALL

	
	TIME({ og_LeaveCriticalSectionWhenCallbackReturns(pci, pcs); });

	SEND_AFTER_CALL
	
}

static int (WINAPI *og_GetDateFormatA)(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCSTR lpFormat,  LPSTR lpDateStr,  int cchDate) = GetDateFormatA;
static int WINAPI hooked_GetDateFormatA(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCSTR lpFormat,  LPSTR lpDateStr,  int cchDate) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetDateFormatA(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetDateFormatEx)(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCWSTR lpFormat,  LPWSTR lpDateStr,  int cchDate,  LPCWSTR lpCalendar) = GetDateFormatEx;
static int WINAPI hooked_GetDateFormatEx(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCWSTR lpFormat,  LPWSTR lpDateStr,  int cchDate,  LPCWSTR lpCalendar) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetDateFormatEx(lpLocaleName, dwFlags, lpDate, lpFormat, lpDateStr, cchDate, lpCalendar); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetDateFormatW)(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCWSTR lpFormat,  LPWSTR lpDateStr,  int cchDate) = GetDateFormatW;
static int WINAPI hooked_GetDateFormatW(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDate,  LPCWSTR lpFormat,  LPWSTR lpDateStr,  int cchDate) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetDateFormatW(Locale, dwFlags, lpDate, lpFormat, lpDateStr, cchDate); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetTimeFormatA)(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCSTR lpFormat,  LPSTR lpTimeStr,  int cchTime) = GetTimeFormatA;
static int WINAPI hooked_GetTimeFormatA(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCSTR lpFormat,  LPSTR lpTimeStr,  int cchTime) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetTimeFormatA(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetTimeFormatW)(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCWSTR lpFormat,  LPWSTR lpTimeStr,  int cchTime) = GetTimeFormatW;
static int WINAPI hooked_GetTimeFormatW(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCWSTR lpFormat,  LPWSTR lpTimeStr,  int cchTime) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetTimeFormatW(Locale, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetTimeFormatEx)(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCWSTR lpFormat,  LPWSTR lpTimeStr,  int cchTime) = GetTimeFormatEx;
static int WINAPI hooked_GetTimeFormatEx(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpTime,  LPCWSTR lpFormat,  LPWSTR lpTimeStr,  int cchTime) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetTimeFormatEx(lpLocaleName, dwFlags, lpTime, lpFormat, lpTimeStr, cchTime); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetSystemWow64DirectoryA)(LPSTR lpBuffer,  UINT uSize) = GetSystemWow64DirectoryA;
static UINT WINAPI hooked_GetSystemWow64DirectoryA(LPSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemWow64DirectoryA(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetSystemWow64DirectoryW)(LPWSTR lpBuffer,  UINT uSize) = GetSystemWow64DirectoryW;
static UINT WINAPI hooked_GetSystemWow64DirectoryW(LPWSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemWow64DirectoryW(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsWow64Process)(HANDLE hProcess,  PBOOL Wow64Process) = IsWow64Process;
static BOOL WINAPI hooked_IsWow64Process(HANDLE hProcess,  PBOOL Wow64Process) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsWow64Process(hProcess, Wow64Process); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsWow64Process2)(HANDLE hProcess,  USHORT *pProcessMachine,  USHORT *pNativeMachine) = IsWow64Process2;
static BOOL WINAPI hooked_IsWow64Process2(HANDLE hProcess,  USHORT *pProcessMachine,  USHORT *pNativeMachine) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsWow64Process2(hProcess, pProcessMachine, pNativeMachine); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Wow64DisableWow64FsRedirection)(PVOID *OldValue) = Wow64DisableWow64FsRedirection;
static BOOL WINAPI hooked_Wow64DisableWow64FsRedirection(PVOID *OldValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Wow64DisableWow64FsRedirection(OldValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Wow64GetThreadContext)(HANDLE hThread,  PWOW64_CONTEXT lpContext) = Wow64GetThreadContext;
static BOOL WINAPI hooked_Wow64GetThreadContext(HANDLE hThread,  PWOW64_CONTEXT lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Wow64GetThreadContext(hThread, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_Wow64EnableWow64FsRedirection)(BOOLEAN Wow64FsEnableRedirection) = Wow64EnableWow64FsRedirection;
static BOOLEAN WINAPI hooked_Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_Wow64EnableWow64FsRedirection(Wow64FsEnableRedirection); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Wow64SetThreadContext)(HANDLE hThread,  const WOW64_CONTEXT *lpContext) = Wow64SetThreadContext;
static BOOL WINAPI hooked_Wow64SetThreadContext(HANDLE hThread,  const WOW64_CONTEXT *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Wow64SetThreadContext(hThread, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Wow64RevertWow64FsRedirection)(PVOID OlValue) = Wow64RevertWow64FsRedirection;
static BOOL WINAPI hooked_Wow64RevertWow64FsRedirection(PVOID OlValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Wow64RevertWow64FsRedirection(OlValue); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_Wow64SuspendThread)(HANDLE hThread) = Wow64SuspendThread;
static DWORD WINAPI hooked_Wow64SuspendThread(HANDLE hThread) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_Wow64SuspendThread(hThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CheckRemoteDebuggerPresent)(HANDLE hProcess,  PBOOL pbDebuggerPresent) = CheckRemoteDebuggerPresent;
static BOOL WINAPI hooked_CheckRemoteDebuggerPresent(HANDLE hProcess,  PBOOL pbDebuggerPresent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CheckRemoteDebuggerPresent(hProcess, pbDebuggerPresent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ContinueDebugEvent)(DWORD dwProcessId,  DWORD dwThreadId,  DWORD dwContinueStatus) = ContinueDebugEvent;
static BOOL WINAPI hooked_ContinueDebugEvent(DWORD dwProcessId,  DWORD dwThreadId,  DWORD dwContinueStatus) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ContinueDebugEvent(dwProcessId, dwThreadId, dwContinueStatus); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DebugActiveProcess)(DWORD dwProcessId) = DebugActiveProcess;
static BOOL WINAPI hooked_DebugActiveProcess(DWORD dwProcessId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DebugActiveProcess(dwProcessId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DebugActiveProcessStop)(DWORD dwProcessId) = DebugActiveProcessStop;
static BOOL WINAPI hooked_DebugActiveProcessStop(DWORD dwProcessId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DebugActiveProcessStop(dwProcessId); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_DebugBreak)() = DebugBreak;
static VOID WINAPI hooked_DebugBreak() {

	SEND_BEFORE_CALL

	
	TIME({ og_DebugBreak(); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_IsDebuggerPresent)() = IsDebuggerPresent;
static BOOL WINAPI hooked_IsDebuggerPresent() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsDebuggerPresent(); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_OutputDebugStringA)(LPCSTR lpOutputString) = OutputDebugStringA;
static VOID WINAPI hooked_OutputDebugStringA(LPCSTR lpOutputString) {

	SEND_BEFORE_CALL

	
	TIME({ og_OutputDebugStringA(lpOutputString); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_WaitForDebugEvent)(LPDEBUG_EVENT lpDebugEvent,  DWORD dwMilliseconds) = WaitForDebugEvent;
static BOOL WINAPI hooked_WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WaitForDebugEvent(lpDebugEvent, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_OutputDebugStringW)(LPCWSTR lpOutputString) = OutputDebugStringW;
static VOID WINAPI hooked_OutputDebugStringW(LPCWSTR lpOutputString) {

	SEND_BEFORE_CALL

	
	TIME({ og_OutputDebugStringW(lpOutputString); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_WaitForDebugEventEx)(LPDEBUG_EVENT lpDebugEvent,  DWORD dwMilliseconds) = WaitForDebugEventEx;
static BOOL WINAPI hooked_WaitForDebugEventEx(LPDEBUG_EVENT lpDebugEvent,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WaitForDebugEventEx(lpDebugEvent, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CallNamedPipeW)(LPCWSTR lpNamedPipeName,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  DWORD nTimeOut) = CallNamedPipeW;
static BOOL WINAPI hooked_CallNamedPipeW(LPCWSTR lpNamedPipeName,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  DWORD nTimeOut) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CallNamedPipeW(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ConnectNamedPipe)(HANDLE hNamedPipe,  LPOVERLAPPED lpOverlapped) = ConnectNamedPipe;
static BOOL WINAPI hooked_ConnectNamedPipe(HANDLE hNamedPipe,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ConnectNamedPipe(hNamedPipe, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreatePipe)(PHANDLE hReadPipe,  PHANDLE hWritePipe,  LPSECURITY_ATTRIBUTES lpPipeAttributes,  DWORD nSize) = CreatePipe;
static BOOL WINAPI hooked_CreatePipe(PHANDLE hReadPipe,  PHANDLE hWritePipe,  LPSECURITY_ATTRIBUTES lpPipeAttributes,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreatePipe(hReadPipe, hWritePipe, lpPipeAttributes, nSize); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateNamedPipeW)(LPCWSTR lpName,  DWORD dwOpenMode,  DWORD dwPipeMode,  DWORD nMaxInstances,  DWORD nOutBufferSize,  DWORD nInBufferSize,  DWORD nDefaultTimeOut,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateNamedPipeW;
static HANDLE WINAPI hooked_CreateNamedPipeW(LPCWSTR lpName,  DWORD dwOpenMode,  DWORD dwPipeMode,  DWORD nMaxInstances,  DWORD nOutBufferSize,  DWORD nInBufferSize,  DWORD nDefaultTimeOut,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateNamedPipeW(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DisconnectNamedPipe)(HANDLE hNamedPipe) = DisconnectNamedPipe;
static BOOL WINAPI hooked_DisconnectNamedPipe(HANDLE hNamedPipe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DisconnectNamedPipe(hNamedPipe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeClientComputerNameW)(HANDLE Pipe,  LPWSTR ClientComputerName,  ULONG ClientComputerNameLength) = GetNamedPipeClientComputerNameW;
static BOOL WINAPI hooked_GetNamedPipeClientComputerNameW(HANDLE Pipe,  LPWSTR ClientComputerName,  ULONG ClientComputerNameLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeClientComputerNameW(Pipe, ClientComputerName, ClientComputerNameLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeHandleStateW)(HANDLE hNamedPipe,  LPDWORD lpState,  LPDWORD lpCurInstances,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout,  LPWSTR lpUserName,  DWORD nMaxUserNameSize) = GetNamedPipeHandleStateW;
static BOOL WINAPI hooked_GetNamedPipeHandleStateW(HANDLE hNamedPipe,  LPDWORD lpState,  LPDWORD lpCurInstances,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout,  LPWSTR lpUserName,  DWORD nMaxUserNameSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeInfo)(HANDLE hNamedPipe,  LPDWORD lpFlags,  LPDWORD lpOutBufferSize,  LPDWORD lpInBufferSize,  LPDWORD lpMaxInstances) = GetNamedPipeInfo;
static BOOL WINAPI hooked_GetNamedPipeInfo(HANDLE hNamedPipe,  LPDWORD lpFlags,  LPDWORD lpOutBufferSize,  LPDWORD lpInBufferSize,  LPDWORD lpMaxInstances) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeInfo(hNamedPipe, lpFlags, lpOutBufferSize, lpInBufferSize, lpMaxInstances); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetNamedPipeHandleState)(HANDLE hNamedPipe,  LPDWORD lpMode,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout) = SetNamedPipeHandleState;
static BOOL WINAPI hooked_SetNamedPipeHandleState(HANDLE hNamedPipe,  LPDWORD lpMode,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetNamedPipeHandleState(hNamedPipe, lpMode, lpMaxCollectionCount, lpCollectDataTimeout); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TransactNamedPipe)(HANDLE hNamedPipe,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  LPOVERLAPPED lpOverlapped) = TransactNamedPipe;
static BOOL WINAPI hooked_TransactNamedPipe(HANDLE hNamedPipe,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TransactNamedPipe(hNamedPipe, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PeekNamedPipe)(HANDLE hNamedPipe,  LPVOID lpBuffer,  DWORD nBufferSize,  LPDWORD lpBytesRead,  LPDWORD lpTotalBytesAvail,  LPDWORD lpBytesLeftThisMessage) = PeekNamedPipe;
static BOOL WINAPI hooked_PeekNamedPipe(HANDLE hNamedPipe,  LPVOID lpBuffer,  DWORD nBufferSize,  LPDWORD lpBytesRead,  LPDWORD lpTotalBytesAvail,  LPDWORD lpBytesLeftThisMessage) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PeekNamedPipe(hNamedPipe, lpBuffer, nBufferSize, lpBytesRead, lpTotalBytesAvail, lpBytesLeftThisMessage); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WaitNamedPipeW)(LPCWSTR lpNamedPipeName,  DWORD nTimeOut) = WaitNamedPipeW;
static BOOL WINAPI hooked_WaitNamedPipeW(LPCWSTR lpNamedPipeName,  DWORD nTimeOut) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WaitNamedPipeW(lpNamedPipeName, nTimeOut); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AddSIDToBoundaryDescriptor)(HANDLE *BoundaryDescriptor,  PSID RequiredSid) = AddSIDToBoundaryDescriptor;
static BOOL WINAPI hooked_AddSIDToBoundaryDescriptor(HANDLE *BoundaryDescriptor,  PSID RequiredSid) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AddSIDToBoundaryDescriptor(BoundaryDescriptor, RequiredSid); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_ClosePrivateNamespace)(HANDLE Handle,  ULONG Flags) = ClosePrivateNamespace;
static BOOLEAN WINAPI hooked_ClosePrivateNamespace(HANDLE Handle,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_ClosePrivateNamespace(Handle, Flags); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateBoundaryDescriptorW)(LPCWSTR Name,  ULONG Flags) = CreateBoundaryDescriptorW;
static HANDLE WINAPI hooked_CreateBoundaryDescriptorW(LPCWSTR Name,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateBoundaryDescriptorW(Name, Flags); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_DeleteBoundaryDescriptor)(HANDLE BoundaryDescriptor) = DeleteBoundaryDescriptor;
static VOID WINAPI hooked_DeleteBoundaryDescriptor(HANDLE BoundaryDescriptor) {

	SEND_BEFORE_CALL

	
	TIME({ og_DeleteBoundaryDescriptor(BoundaryDescriptor); });

	SEND_AFTER_CALL
	
}

static HANDLE (WINAPI *og_CreatePrivateNamespaceW)(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,  LPVOID lpBoundaryDescriptor,  LPCWSTR lpAliasPrefix) = CreatePrivateNamespaceW;
static HANDLE WINAPI hooked_CreatePrivateNamespaceW(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,  LPVOID lpBoundaryDescriptor,  LPCWSTR lpAliasPrefix) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreatePrivateNamespaceW(lpPrivateNamespaceAttributes, lpBoundaryDescriptor, lpAliasPrefix); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenPrivateNamespaceW)(LPVOID lpBoundaryDescriptor,  LPCWSTR lpAliasPrefix) = OpenPrivateNamespaceW;
static HANDLE WINAPI hooked_OpenPrivateNamespaceW(LPVOID lpBoundaryDescriptor,  LPCWSTR lpAliasPrefix) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenPrivateNamespaceW(lpBoundaryDescriptor, lpAliasPrefix); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RegisterWaitUntilOOBECompleted)(OOBE_COMPLETED_CALLBACK OOBECompletedCallback, PVOID CallbackContext, PVOID *WaitHandle) = RegisterWaitUntilOOBECompleted;
static BOOL WINAPI hooked_RegisterWaitUntilOOBECompleted(OOBE_COMPLETED_CALLBACK OOBECompletedCallback, PVOID CallbackContext, PVOID *WaitHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RegisterWaitUntilOOBECompleted(OOBECompletedCallback, CallbackContext, WaitHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_OOBEComplete)(PBOOL isOOBEComplete) = OOBEComplete;
static BOOL WINAPI hooked_OOBEComplete(PBOOL isOOBEComplete) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_OOBEComplete(isOOBEComplete); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnregisterWaitUntilOOBECompleted)(PVOID WaitHandle) = UnregisterWaitUntilOOBECompleted;
static BOOL WINAPI hooked_UnregisterWaitUntilOOBECompleted(PVOID WaitHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnregisterWaitUntilOOBECompleted(WaitHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_ExpandEnvironmentStringsA)(LPCSTR lpSrc,  LPSTR lpDst,  DWORD nSize) = ExpandEnvironmentStringsA;
static DWORD WINAPI hooked_ExpandEnvironmentStringsA(LPCSTR lpSrc,  LPSTR lpDst,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_ExpandEnvironmentStringsA(lpSrc, lpDst, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_ExpandEnvironmentStringsW)(LPCWSTR lpSrc,  LPWSTR lpDst,  DWORD nSize) = ExpandEnvironmentStringsW;
static DWORD WINAPI hooked_ExpandEnvironmentStringsW(LPCWSTR lpSrc,  LPWSTR lpDst,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_ExpandEnvironmentStringsW(lpSrc, lpDst, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FreeEnvironmentStringsA)(LPCH penv) = FreeEnvironmentStringsA;
static BOOL WINAPI hooked_FreeEnvironmentStringsA(LPCH penv) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FreeEnvironmentStringsA(penv); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FreeEnvironmentStringsW)(LPWCH penv) = FreeEnvironmentStringsW;
static BOOL WINAPI hooked_FreeEnvironmentStringsW(LPWCH penv) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FreeEnvironmentStringsW(penv); });

	SEND_AFTER_CALL

    return result;
}

static LPSTR (WINAPI *og_GetCommandLineA)() = GetCommandLineA;
static LPSTR WINAPI hooked_GetCommandLineA() {

	SEND_BEFORE_CALL

	
    LPSTR result;
    TIME({ result = og_GetCommandLineA(); });

	SEND_AFTER_CALL

		IsHookingOn = true;
    return result;
}

static LPWCH (WINAPI *og_GetEnvironmentStringsW)() = GetEnvironmentStringsW;
static LPWCH WINAPI hooked_GetEnvironmentStringsW() {

	SEND_BEFORE_CALL

	
    LPWCH result;
    TIME({ result = og_GetEnvironmentStringsW(); });

	SEND_AFTER_CALL

    return result;
}

static LPCH (WINAPI *og_GetEnvironmentStrings)() = GetEnvironmentStrings;
static LPCH WINAPI hooked_GetEnvironmentStrings() {

	SEND_BEFORE_CALL

	
    LPCH result;
    TIME({ result = og_GetEnvironmentStrings(); });

	SEND_AFTER_CALL

    return result;
}

static LPWSTR (WINAPI *og_GetCommandLineW)() = GetCommandLineW;
static LPWSTR WINAPI hooked_GetCommandLineW() {

	SEND_BEFORE_CALL

	
    LPWSTR result;
    TIME({ result = og_GetCommandLineW(); });

	SEND_AFTER_CALL

		IsHookingOn = true;
    return result;
}

static DWORD (WINAPI *og_GetEnvironmentVariableA)(LPCSTR lpName,  LPSTR lpBuffer,  DWORD nSize) = GetEnvironmentVariableA;
static DWORD WINAPI hooked_GetEnvironmentVariableA(LPCSTR lpName,  LPSTR lpBuffer,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetEnvironmentVariableA(lpName, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetEnvironmentVariableW)(LPCWSTR lpName,  LPWSTR lpBuffer,  DWORD nSize) = GetEnvironmentVariableW;
static DWORD WINAPI hooked_GetEnvironmentVariableW(LPCWSTR lpName,  LPWSTR lpBuffer,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetEnvironmentVariableW(lpName, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_NeedCurrentDirectoryForExePathA)(LPCSTR ExeName) = NeedCurrentDirectoryForExePathA;
static BOOL WINAPI hooked_NeedCurrentDirectoryForExePathA(LPCSTR ExeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_NeedCurrentDirectoryForExePathA(ExeName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_NeedCurrentDirectoryForExePathW)(LPCWSTR ExeName) = NeedCurrentDirectoryForExePathW;
static BOOL WINAPI hooked_NeedCurrentDirectoryForExePathW(LPCWSTR ExeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_NeedCurrentDirectoryForExePathW(ExeName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SearchPathA)(LPCSTR lpPath,  LPCSTR lpFileName,  LPCSTR lpExtension,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart) = SearchPathA;
static DWORD WINAPI hooked_SearchPathA(LPCSTR lpPath,  LPCSTR lpFileName,  LPCSTR lpExtension,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SearchPathW)(LPCWSTR lpPath,  LPCWSTR lpFileName,  LPCWSTR lpExtension,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart) = SearchPathW;
static DWORD WINAPI hooked_SearchPathW(LPCWSTR lpPath,  LPCWSTR lpFileName,  LPCWSTR lpExtension,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetEnvironmentStringsW)(LPWCH NewEnvironment) = SetEnvironmentStringsW;
static BOOL WINAPI hooked_SetEnvironmentStringsW(LPWCH NewEnvironment) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEnvironmentStringsW(NewEnvironment); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetEnvironmentVariableA)(LPCSTR lpName,  LPCSTR lpValue) = SetEnvironmentVariableA;
static BOOL WINAPI hooked_SetEnvironmentVariableA(LPCSTR lpName,  LPCSTR lpValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEnvironmentVariableA(lpName, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetEnvironmentVariableW)(LPCWSTR lpName,  LPCWSTR lpValue) = SetEnvironmentVariableW;
static BOOL WINAPI hooked_SetEnvironmentVariableW(LPCWSTR lpName,  LPCWSTR lpValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEnvironmentVariableW(lpName, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssCaptureSnapshot)(HANDLE ProcessHandle,  PSS_CAPTURE_FLAGS CaptureFlags,  DWORD ThreadContextFlags,  HPSS *SnapshotHandle) = PssCaptureSnapshot;
static DWORD WINAPI hooked_PssCaptureSnapshot(HANDLE ProcessHandle,  PSS_CAPTURE_FLAGS CaptureFlags,  DWORD ThreadContextFlags,  HPSS *SnapshotHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssCaptureSnapshot(ProcessHandle, CaptureFlags, ThreadContextFlags, SnapshotHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssDuplicateSnapshot)(HANDLE SourceProcessHandle,  HPSS SnapshotHandle,  HANDLE TargetProcessHandle,  HPSS *TargetSnapshotHandle,  PSS_DUPLICATE_FLAGS Flags) = PssDuplicateSnapshot;
static DWORD WINAPI hooked_PssDuplicateSnapshot(HANDLE SourceProcessHandle,  HPSS SnapshotHandle,  HANDLE TargetProcessHandle,  HPSS *TargetSnapshotHandle,  PSS_DUPLICATE_FLAGS Flags) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssDuplicateSnapshot(SourceProcessHandle, SnapshotHandle, TargetProcessHandle, TargetSnapshotHandle, Flags); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssQuerySnapshot)(HPSS SnapshotHandle,  PSS_QUERY_INFORMATION_CLASS InformationClass,  void *Buffer,  DWORD BufferLength) = PssQuerySnapshot;
static DWORD WINAPI hooked_PssQuerySnapshot(HPSS SnapshotHandle,  PSS_QUERY_INFORMATION_CLASS InformationClass,  void *Buffer,  DWORD BufferLength) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssQuerySnapshot(SnapshotHandle, InformationClass, Buffer, BufferLength); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssFreeSnapshot)(HANDLE ProcessHandle,  HPSS SnapshotHandle) = PssFreeSnapshot;
static DWORD WINAPI hooked_PssFreeSnapshot(HANDLE ProcessHandle,  HPSS SnapshotHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssFreeSnapshot(ProcessHandle, SnapshotHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkMarkerCreate)(PSS_ALLOCATOR const *Allocator,  HPSSWALK *WalkMarkerHandle) = PssWalkMarkerCreate;
static DWORD WINAPI hooked_PssWalkMarkerCreate(PSS_ALLOCATOR const *Allocator,  HPSSWALK *WalkMarkerHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkMarkerCreate(Allocator, WalkMarkerHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkMarkerSeekToBeginning)(HPSSWALK WalkMarkerHandle) = PssWalkMarkerSeekToBeginning;
static DWORD WINAPI hooked_PssWalkMarkerSeekToBeginning(HPSSWALK WalkMarkerHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkMarkerSeekToBeginning(WalkMarkerHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkMarkerGetPosition)(HPSSWALK WalkMarkerHandle,  ULONG_PTR *Position) = PssWalkMarkerGetPosition;
static DWORD WINAPI hooked_PssWalkMarkerGetPosition(HPSSWALK WalkMarkerHandle,  ULONG_PTR *Position) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkMarkerGetPosition(WalkMarkerHandle, Position); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkMarkerSetPosition)(HPSSWALK WalkMarkerHandle,  ULONG_PTR Position) = PssWalkMarkerSetPosition;
static DWORD WINAPI hooked_PssWalkMarkerSetPosition(HPSSWALK WalkMarkerHandle,  ULONG_PTR Position) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkMarkerSetPosition(WalkMarkerHandle, Position); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkMarkerFree)(HPSSWALK WalkMarkerHandle) = PssWalkMarkerFree;
static DWORD WINAPI hooked_PssWalkMarkerFree(HPSSWALK WalkMarkerHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkMarkerFree(WalkMarkerHandle); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PssWalkSnapshot)(HPSS SnapshotHandle,  PSS_WALK_INFORMATION_CLASS InformationClass,  HPSSWALK WalkMarkerHandle,  void *Buffer,  DWORD BufferLength) = PssWalkSnapshot;
static DWORD WINAPI hooked_PssWalkSnapshot(HPSS SnapshotHandle,  PSS_WALK_INFORMATION_CLASS InformationClass,  HPSSWALK WalkMarkerHandle,  void *Buffer,  DWORD BufferLength) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PssWalkSnapshot(SnapshotHandle, InformationClass, WalkMarkerHandle, Buffer, BufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateProcessW)(LPCWSTR lpApplicationName,  LPWSTR lpCommandLine,  LPSECURITY_ATTRIBUTES lpProcessAttributes,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  BOOL bInheritHandles,  DWORD dwCreationFlags,  LPVOID lpEnvironment,  LPCWSTR lpCurrentDirectory,  LPSTARTUPINFOW lpStartupInfo,  LPPROCESS_INFORMATION lpProcessInformation) = CreateProcessW;
static BOOL WINAPI hooked_CreateProcessW(LPCWSTR lpApplicationName,  LPWSTR lpCommandLine,  LPSECURITY_ATTRIBUTES lpProcessAttributes,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  BOOL bInheritHandles,  DWORD dwCreationFlags,  LPVOID lpEnvironment,  LPCWSTR lpCurrentDirectory,  LPSTARTUPINFOW lpStartupInfo,  LPPROCESS_INFORMATION lpProcessInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateProcessW(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateProcessA)(LPCSTR lpApplicationName,  LPSTR lpCommandLine,  LPSECURITY_ATTRIBUTES lpProcessAttributes,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  BOOL bInheritHandles,  DWORD dwCreationFlags,  LPVOID lpEnvironment,  LPCSTR lpCurrentDirectory,  LPSTARTUPINFOA lpStartupInfo,  LPPROCESS_INFORMATION lpProcessInformation) = CreateProcessA;
static BOOL WINAPI hooked_CreateProcessA(LPCSTR lpApplicationName,  LPSTR lpCommandLine,  LPSECURITY_ATTRIBUTES lpProcessAttributes,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  BOOL bInheritHandles,  DWORD dwCreationFlags,  LPVOID lpEnvironment,  LPCSTR lpCurrentDirectory,  LPSTARTUPINFOA lpStartupInfo,  LPPROCESS_INFORMATION lpProcessInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateProcessA(lpApplicationName, lpCommandLine, lpProcessAttributes, lpThreadAttributes, bInheritHandles, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateRemoteThread)(HANDLE hProcess,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  LPVOID lpParameter,  DWORD dwCreationFlags,  LPDWORD lpThreadId) = CreateRemoteThread;
static HANDLE WINAPI hooked_CreateRemoteThread(HANDLE hProcess,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  LPVOID lpParameter,  DWORD dwCreationFlags,  LPDWORD lpThreadId) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateRemoteThread(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateRemoteThreadEx)(HANDLE hProcess,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  LPVOID lpParameter,  DWORD dwCreationFlags,  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,  LPDWORD lpThreadId) = CreateRemoteThreadEx;
static HANDLE WINAPI hooked_CreateRemoteThreadEx(HANDLE hProcess,  LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  LPVOID lpParameter,  DWORD dwCreationFlags,  LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,  LPDWORD lpThreadId) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateRemoteThreadEx(hProcess, lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpAttributeList, lpThreadId); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateThread)(LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  __drv_aliasesMem LPVOID lpParameter,  DWORD dwCreationFlags,  LPDWORD lpThreadId) = CreateThread;
static HANDLE WINAPI hooked_CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,  SIZE_T dwStackSize,  LPTHREAD_START_ROUTINE lpStartAddress,  __drv_aliasesMem LPVOID lpParameter,  DWORD dwCreationFlags,  LPDWORD lpThreadId) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateThread(lpThreadAttributes, dwStackSize, lpStartAddress, lpParameter, dwCreationFlags, lpThreadId); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_DeleteProcThreadAttributeList)(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList) = DeleteProcThreadAttributeList;
static VOID WINAPI hooked_DeleteProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList) {

	SEND_BEFORE_CALL

	
	TIME({ og_DeleteProcThreadAttributeList(lpAttributeList); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_ExitProcess)(UINT uExitCode) = ExitProcess;
static VOID WINAPI hooked_ExitProcess(UINT uExitCode) {

	SEND_BEFORE_CALL

	
	TIME({ og_ExitProcess(uExitCode); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_FlushInstructionCache)(HANDLE hProcess,  LPCVOID lpBaseAddress,  SIZE_T dwSize) = FlushInstructionCache;
static BOOL WINAPI hooked_FlushInstructionCache(HANDLE hProcess,  LPCVOID lpBaseAddress,  SIZE_T dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FlushInstructionCache(hProcess, lpBaseAddress, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_ExitThread)(DWORD dwExitCode) = ExitThread;
static VOID WINAPI hooked_ExitThread(DWORD dwExitCode) {

	SEND_BEFORE_CALL

	
	TIME({ og_ExitThread(dwExitCode); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_FlushProcessWriteBuffers)() = FlushProcessWriteBuffers;
static VOID WINAPI hooked_FlushProcessWriteBuffers() {

	SEND_BEFORE_CALL

	
	TIME({ og_FlushProcessWriteBuffers(); });

	SEND_AFTER_CALL
	
}

static HANDLE (WINAPI *og_GetCurrentProcess)() = GetCurrentProcess;
static HANDLE WINAPI hooked_GetCurrentProcess() {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_GetCurrentProcess(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCurrentProcessId)() = GetCurrentProcessId;
static DWORD WINAPI hooked_GetCurrentProcessId() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCurrentProcessId(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCurrentProcessorNumber)() = GetCurrentProcessorNumber;
static DWORD WINAPI hooked_GetCurrentProcessorNumber() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCurrentProcessorNumber(); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetCurrentProcessorNumberEx)(PPROCESSOR_NUMBER ProcNumber) = GetCurrentProcessorNumberEx;
static VOID WINAPI hooked_GetCurrentProcessorNumberEx(PPROCESSOR_NUMBER ProcNumber) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetCurrentProcessorNumberEx(ProcNumber); });

	SEND_AFTER_CALL
	
}

static HANDLE (WINAPI *og_GetCurrentThread)() = GetCurrentThread;
static HANDLE WINAPI hooked_GetCurrentThread() {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_GetCurrentThread(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCurrentThreadId)() = GetCurrentThreadId;
static DWORD WINAPI hooked_GetCurrentThreadId() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCurrentThreadId(); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetCurrentThreadStackLimits)(PULONG_PTR LowLimit,  PULONG_PTR HighLimit) = GetCurrentThreadStackLimits;
static VOID WINAPI hooked_GetCurrentThreadStackLimits(PULONG_PTR LowLimit,  PULONG_PTR HighLimit) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetCurrentThreadStackLimits(LowLimit, HighLimit); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_GetExitCodeProcess)(HANDLE hProcess,  LPDWORD lpExitCode) = GetExitCodeProcess;
static BOOL WINAPI hooked_GetExitCodeProcess(HANDLE hProcess,  LPDWORD lpExitCode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetExitCodeProcess(hProcess, lpExitCode); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetExitCodeThread)(HANDLE hThread,  LPDWORD lpExitCode) = GetExitCodeThread;
static BOOL WINAPI hooked_GetExitCodeThread(HANDLE hThread,  LPDWORD lpExitCode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetExitCodeThread(hThread, lpExitCode); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetMachineTypeAttributes)(USHORT Machine, MACHINE_ATTRIBUTES *MachineTypeAttributes) = GetMachineTypeAttributes;
static HRESULT WINAPI hooked_GetMachineTypeAttributes(USHORT Machine, MACHINE_ATTRIBUTES *MachineTypeAttributes) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetMachineTypeAttributes(Machine, MachineTypeAttributes); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPriorityClass)(HANDLE hProcess) = GetPriorityClass;
static DWORD WINAPI hooked_GetPriorityClass(HANDLE hProcess) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPriorityClass(hProcess); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessDefaultCpuSetMasks)(HANDLE Process, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount, PUSHORT RequiredMaskCount) = GetProcessDefaultCpuSetMasks;
static BOOL WINAPI hooked_GetProcessDefaultCpuSetMasks(HANDLE Process, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount, PUSHORT RequiredMaskCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessDefaultCpuSetMasks(Process, CpuSetMasks, CpuSetMaskCount, RequiredMaskCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessDefaultCpuSets)(HANDLE Process, PULONG CpuSetIds, ULONG CpuSetIdCount, PULONG RequiredIdCount) = GetProcessDefaultCpuSets;
static BOOL WINAPI hooked_GetProcessDefaultCpuSets(HANDLE Process, PULONG CpuSetIds, ULONG CpuSetIdCount, PULONG RequiredIdCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessDefaultCpuSets(Process, CpuSetIds, CpuSetIdCount, RequiredIdCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessHandleCount)(HANDLE hProcess,  PDWORD pdwHandleCount) = GetProcessHandleCount;
static BOOL WINAPI hooked_GetProcessHandleCount(HANDLE hProcess,  PDWORD pdwHandleCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessHandleCount(hProcess, pdwHandleCount); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessId)(HANDLE Process) = GetProcessId;
static DWORD WINAPI hooked_GetProcessId(HANDLE Process) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessId(Process); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessIdOfThread)(HANDLE Thread) = GetProcessIdOfThread;
static DWORD WINAPI hooked_GetProcessIdOfThread(HANDLE Thread) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessIdOfThread(Thread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessInformation)(HANDLE hProcess,  PROCESS_INFORMATION_CLASS ProcessInformationClass, LPVOID ProcessInformation,  DWORD ProcessInformationSize) = GetProcessInformation;
static BOOL WINAPI hooked_GetProcessInformation(HANDLE hProcess,  PROCESS_INFORMATION_CLASS ProcessInformationClass, LPVOID ProcessInformation,  DWORD ProcessInformationSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessInformation(hProcess, ProcessInformationClass, ProcessInformation, ProcessInformationSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessMitigationPolicy)(HANDLE hProcess,  PROCESS_MITIGATION_POLICY MitigationPolicy,  PVOID lpBuffer,  SIZE_T dwLength) = GetProcessMitigationPolicy;
static BOOL WINAPI hooked_GetProcessMitigationPolicy(HANDLE hProcess,  PROCESS_MITIGATION_POLICY MitigationPolicy,  PVOID lpBuffer,  SIZE_T dwLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessMitigationPolicy(hProcess, MitigationPolicy, lpBuffer, dwLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessPriorityBoost)(HANDLE hProcess,  PBOOL pDisablePriorityBoost) = GetProcessPriorityBoost;
static BOOL WINAPI hooked_GetProcessPriorityBoost(HANDLE hProcess,  PBOOL pDisablePriorityBoost) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessPriorityBoost(hProcess, pDisablePriorityBoost); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessShutdownParameters)(LPDWORD lpdwLevel,  LPDWORD lpdwFlags) = GetProcessShutdownParameters;
static BOOL WINAPI hooked_GetProcessShutdownParameters(LPDWORD lpdwLevel,  LPDWORD lpdwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessShutdownParameters(lpdwLevel, lpdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessTimes)(HANDLE hProcess,  LPFILETIME lpCreationTime,  LPFILETIME lpExitTime,  LPFILETIME lpKernelTime,  LPFILETIME lpUserTime) = GetProcessTimes;
static BOOL WINAPI hooked_GetProcessTimes(HANDLE hProcess,  LPFILETIME lpCreationTime,  LPFILETIME lpExitTime,  LPFILETIME lpKernelTime,  LPFILETIME lpUserTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessTimes(hProcess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessVersion)(DWORD ProcessId) = GetProcessVersion;
static DWORD WINAPI hooked_GetProcessVersion(DWORD ProcessId) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessVersion(ProcessId); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetStartupInfoW)(LPSTARTUPINFOW lpStartupInfo) = GetStartupInfoW;
static VOID WINAPI hooked_GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetStartupInfoW(lpStartupInfo); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_GetSystemTimes)(PFILETIME lpIdleTime,  PFILETIME lpKernelTime,  PFILETIME lpUserTime) = GetSystemTimes;
static BOOL WINAPI hooked_GetSystemTimes(PFILETIME lpIdleTime,  PFILETIME lpKernelTime,  PFILETIME lpUserTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemTimes(lpIdleTime, lpKernelTime, lpUserTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadContext)(HANDLE hThread,  LPCONTEXT lpContext) = GetThreadContext;
static BOOL WINAPI hooked_GetThreadContext(HANDLE hThread,  LPCONTEXT lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadContext(hThread, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetThreadDescription)(HANDLE hThread,  PWSTR *ppszThreadDescription) = GetThreadDescription;
static HRESULT WINAPI hooked_GetThreadDescription(HANDLE hThread,  PWSTR *ppszThreadDescription) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetThreadDescription(hThread, ppszThreadDescription); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetThreadId)(HANDLE Thread) = GetThreadId;
static DWORD WINAPI hooked_GetThreadId(HANDLE Thread) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetThreadId(Thread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadIOPendingFlag)(HANDLE hThread,  PBOOL lpIOIsPending) = GetThreadIOPendingFlag;
static BOOL WINAPI hooked_GetThreadIOPendingFlag(HANDLE hThread,  PBOOL lpIOIsPending) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadIOPendingFlag(hThread, lpIOIsPending); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadIdealProcessorEx)(HANDLE hThread,  PPROCESSOR_NUMBER lpIdealProcessor) = GetThreadIdealProcessorEx;
static BOOL WINAPI hooked_GetThreadIdealProcessorEx(HANDLE hThread,  PPROCESSOR_NUMBER lpIdealProcessor) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadIdealProcessorEx(hThread, lpIdealProcessor); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadInformation)(HANDLE hThread,  THREAD_INFORMATION_CLASS ThreadInformationClass, LPVOID ThreadInformation,  DWORD ThreadInformationSize) = GetThreadInformation;
static BOOL WINAPI hooked_GetThreadInformation(HANDLE hThread,  THREAD_INFORMATION_CLASS ThreadInformationClass, LPVOID ThreadInformation,  DWORD ThreadInformationSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadInformation(hThread, ThreadInformationClass, ThreadInformation, ThreadInformationSize); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetThreadPriority)(HANDLE hThread) = GetThreadPriority;
static int WINAPI hooked_GetThreadPriority(HANDLE hThread) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetThreadPriority(hThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadPriorityBoost)(HANDLE hThread,  PBOOL pDisablePriorityBoost) = GetThreadPriorityBoost;
static BOOL WINAPI hooked_GetThreadPriorityBoost(HANDLE hThread,  PBOOL pDisablePriorityBoost) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadPriorityBoost(hThread, pDisablePriorityBoost); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadSelectedCpuSetMasks)(HANDLE Thread, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount, PUSHORT RequiredMaskCount) = GetThreadSelectedCpuSetMasks;
static BOOL WINAPI hooked_GetThreadSelectedCpuSetMasks(HANDLE Thread, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount, PUSHORT RequiredMaskCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadSelectedCpuSetMasks(Thread, CpuSetMasks, CpuSetMaskCount, RequiredMaskCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadTimes)(HANDLE hThread,  LPFILETIME lpCreationTime,  LPFILETIME lpExitTime,  LPFILETIME lpKernelTime,  LPFILETIME lpUserTime) = GetThreadTimes;
static BOOL WINAPI hooked_GetThreadTimes(HANDLE hThread,  LPFILETIME lpCreationTime,  LPFILETIME lpExitTime,  LPFILETIME lpKernelTime,  LPFILETIME lpUserTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadTimes(hThread, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitializeProcThreadAttributeList)(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,  DWORD dwAttributeCount, DWORD dwFlags,  PSIZE_T lpSize) = InitializeProcThreadAttributeList;
static BOOL WINAPI hooked_InitializeProcThreadAttributeList(LPPROC_THREAD_ATTRIBUTE_LIST lpAttributeList,  DWORD dwAttributeCount, DWORD dwFlags,  PSIZE_T lpSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeProcThreadAttributeList(lpAttributeList, dwAttributeCount, dwFlags, lpSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsProcessCritical)(HANDLE hProcess,  PBOOL Critical) = IsProcessCritical;
static BOOL WINAPI hooked_IsProcessCritical(HANDLE hProcess,  PBOOL Critical) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsProcessCritical(hProcess, Critical); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadSelectedCpuSets)(HANDLE Thread, PULONG CpuSetIds, ULONG CpuSetIdCount, PULONG RequiredIdCount) = GetThreadSelectedCpuSets;
static BOOL WINAPI hooked_GetThreadSelectedCpuSets(HANDLE Thread, PULONG CpuSetIds, ULONG CpuSetIdCount, PULONG RequiredIdCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadSelectedCpuSets(Thread, CpuSetIds, CpuSetIdCount, RequiredIdCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsProcessorFeaturePresent)(DWORD ProcessorFeature) = IsProcessorFeaturePresent;
static BOOL WINAPI hooked_IsProcessorFeaturePresent(DWORD ProcessorFeature) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsProcessorFeaturePresent(ProcessorFeature); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenProcess)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwProcessId) = OpenProcess;
static HANDLE WINAPI hooked_OpenProcess(DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwProcessId) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ProcessIdToSessionId)(DWORD dwProcessId,  DWORD *pSessionId) = ProcessIdToSessionId;
static BOOL WINAPI hooked_ProcessIdToSessionId(DWORD dwProcessId,  DWORD *pSessionId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ProcessIdToSessionId(dwProcessId, pSessionId); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenThread)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwThreadId) = OpenThread;
static HANDLE WINAPI hooked_OpenThread(DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwThreadId) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenThread(dwDesiredAccess, bInheritHandle, dwThreadId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryProcessAffinityUpdateMode)(HANDLE hProcess,  LPDWORD lpdwFlags) = QueryProcessAffinityUpdateMode;
static BOOL WINAPI hooked_QueryProcessAffinityUpdateMode(HANDLE hProcess,  LPDWORD lpdwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryProcessAffinityUpdateMode(hProcess, lpdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryProtectedPolicy)(LPCGUID PolicyGuid,  PULONG_PTR PolicyValue) = QueryProtectedPolicy;
static BOOL WINAPI hooked_QueryProtectedPolicy(LPCGUID PolicyGuid,  PULONG_PTR PolicyValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryProtectedPolicy(PolicyGuid, PolicyValue); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_QueueUserAPC)(PAPCFUNC pfnAPC,  HANDLE hThread,  ULONG_PTR dwData) = QueueUserAPC;
static DWORD WINAPI hooked_QueueUserAPC(PAPCFUNC pfnAPC,  HANDLE hThread,  ULONG_PTR dwData) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_QueueUserAPC(pfnAPC, hThread, dwData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetPriorityClass)(HANDLE hProcess,  DWORD dwPriorityClass) = SetPriorityClass;
static BOOL WINAPI hooked_SetPriorityClass(HANDLE hProcess,  DWORD dwPriorityClass) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetPriorityClass(hProcess, dwPriorityClass); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_ResumeThread)(HANDLE hThread) = ResumeThread;
static DWORD WINAPI hooked_ResumeThread(HANDLE hThread) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_ResumeThread(hThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueueUserAPC2)(PAPCFUNC ApcRoutine, HANDLE Thread, ULONG_PTR Data, QUEUE_USER_APC_FLAGS Flags) = QueueUserAPC2;
static BOOL WINAPI hooked_QueueUserAPC2(PAPCFUNC ApcRoutine, HANDLE Thread, ULONG_PTR Data, QUEUE_USER_APC_FLAGS Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueueUserAPC2(ApcRoutine, Thread, Data, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessAffinityUpdateMode)(HANDLE hProcess,  DWORD dwFlags) = SetProcessAffinityUpdateMode;
static BOOL WINAPI hooked_SetProcessAffinityUpdateMode(HANDLE hProcess,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessAffinityUpdateMode(hProcess, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessDefaultCpuSetMasks)(HANDLE Process, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount) = SetProcessDefaultCpuSetMasks;
static BOOL WINAPI hooked_SetProcessDefaultCpuSetMasks(HANDLE Process, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessDefaultCpuSetMasks(Process, CpuSetMasks, CpuSetMaskCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessDefaultCpuSets)(HANDLE Process, const ULONG *CpuSetIds, ULONG CpuSetIdCount) = SetProcessDefaultCpuSets;
static BOOL WINAPI hooked_SetProcessDefaultCpuSets(HANDLE Process, const ULONG *CpuSetIds, ULONG CpuSetIdCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessDefaultCpuSets(Process, CpuSetIds, CpuSetIdCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessInformation)(HANDLE hProcess,  PROCESS_INFORMATION_CLASS ProcessInformationClass, LPVOID ProcessInformation,  DWORD ProcessInformationSize) = SetProcessInformation;
static BOOL WINAPI hooked_SetProcessInformation(HANDLE hProcess,  PROCESS_INFORMATION_CLASS ProcessInformationClass, LPVOID ProcessInformation,  DWORD ProcessInformationSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessInformation(hProcess, ProcessInformationClass, ProcessInformation, ProcessInformationSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessMitigationPolicy)(PROCESS_MITIGATION_POLICY MitigationPolicy,  PVOID lpBuffer,  SIZE_T dwLength) = SetProcessMitigationPolicy;
static BOOL WINAPI hooked_SetProcessMitigationPolicy(PROCESS_MITIGATION_POLICY MitigationPolicy,  PVOID lpBuffer,  SIZE_T dwLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessMitigationPolicy(MitigationPolicy, lpBuffer, dwLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessPriorityBoost)(HANDLE hProcess,  BOOL bDisablePriorityBoost) = SetProcessPriorityBoost;
static BOOL WINAPI hooked_SetProcessPriorityBoost(HANDLE hProcess,  BOOL bDisablePriorityBoost) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessPriorityBoost(hProcess, bDisablePriorityBoost); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadContext)(HANDLE hThread,  const CONTEXT *lpContext) = SetThreadContext;
static BOOL WINAPI hooked_SetThreadContext(HANDLE hThread,  const CONTEXT *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadContext(hThread, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessShutdownParameters)(DWORD dwLevel,  DWORD dwFlags) = SetProcessShutdownParameters;
static BOOL WINAPI hooked_SetProcessShutdownParameters(DWORD dwLevel,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessShutdownParameters(dwLevel, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_SetThreadDescription)(HANDLE hThread,  PCWSTR lpThreadDescription) = SetThreadDescription;
static HRESULT WINAPI hooked_SetThreadDescription(HANDLE hThread,  PCWSTR lpThreadDescription) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_SetThreadDescription(hThread, lpThreadDescription); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProtectedPolicy)(LPCGUID PolicyGuid,  ULONG_PTR PolicyValue,  PULONG_PTR OldPolicyValue) = SetProtectedPolicy;
static BOOL WINAPI hooked_SetProtectedPolicy(LPCGUID PolicyGuid,  ULONG_PTR PolicyValue,  PULONG_PTR OldPolicyValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProtectedPolicy(PolicyGuid, PolicyValue, OldPolicyValue); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetThreadIdealProcessor)(HANDLE hThread,  DWORD dwIdealProcessor) = SetThreadIdealProcessor;
static DWORD WINAPI hooked_SetThreadIdealProcessor(HANDLE hThread,  DWORD dwIdealProcessor) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetThreadIdealProcessor(hThread, dwIdealProcessor); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadIdealProcessorEx)(HANDLE hThread,  PPROCESSOR_NUMBER lpIdealProcessor,  PPROCESSOR_NUMBER lpPreviousIdealProcessor) = SetThreadIdealProcessorEx;
static BOOL WINAPI hooked_SetThreadIdealProcessorEx(HANDLE hThread,  PPROCESSOR_NUMBER lpIdealProcessor,  PPROCESSOR_NUMBER lpPreviousIdealProcessor) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadIdealProcessorEx(hThread, lpIdealProcessor, lpPreviousIdealProcessor); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadInformation)(HANDLE hThread,  THREAD_INFORMATION_CLASS ThreadInformationClass, LPVOID ThreadInformation,  DWORD ThreadInformationSize) = SetThreadInformation;
static BOOL WINAPI hooked_SetThreadInformation(HANDLE hThread,  THREAD_INFORMATION_CLASS ThreadInformationClass, LPVOID ThreadInformation,  DWORD ThreadInformationSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadInformation(hThread, ThreadInformationClass, ThreadInformation, ThreadInformationSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadPriority)(HANDLE hThread,  int nPriority) = SetThreadPriority;
static BOOL WINAPI hooked_SetThreadPriority(HANDLE hThread,  int nPriority) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadPriority(hThread, nPriority); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadSelectedCpuSetMasks)(HANDLE Thread, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount) = SetThreadSelectedCpuSetMasks;
static BOOL WINAPI hooked_SetThreadSelectedCpuSetMasks(HANDLE Thread, PGROUP_AFFINITY CpuSetMasks, USHORT CpuSetMaskCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadSelectedCpuSetMasks(Thread, CpuSetMasks, CpuSetMaskCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadPriorityBoost)(HANDLE hThread,  BOOL bDisablePriorityBoost) = SetThreadPriorityBoost;
static BOOL WINAPI hooked_SetThreadPriorityBoost(HANDLE hThread,  BOOL bDisablePriorityBoost) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadPriorityBoost(hThread, bDisablePriorityBoost); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadSelectedCpuSets)(HANDLE Thread, const ULONG *CpuSetIds, ULONG CpuSetIdCount) = SetThreadSelectedCpuSets;
static BOOL WINAPI hooked_SetThreadSelectedCpuSets(HANDLE Thread, const ULONG *CpuSetIds, ULONG CpuSetIdCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadSelectedCpuSets(Thread, CpuSetIds, CpuSetIdCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadStackGuarantee)(PULONG StackSizeInBytes) = SetThreadStackGuarantee;
static BOOL WINAPI hooked_SetThreadStackGuarantee(PULONG StackSizeInBytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadStackGuarantee(StackSizeInBytes); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SuspendThread)(HANDLE hThread) = SuspendThread;
static DWORD WINAPI hooked_SuspendThread(HANDLE hThread) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SuspendThread(hThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SwitchToThread)() = SwitchToThread;
static BOOL WINAPI hooked_SwitchToThread() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SwitchToThread(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TerminateProcess)(HANDLE hProcess,  UINT uExitCode) = TerminateProcess;
static BOOL WINAPI hooked_TerminateProcess(HANDLE hProcess,  UINT uExitCode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TerminateProcess(hProcess, uExitCode); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_TlsAlloc)() = TlsAlloc;
static DWORD WINAPI hooked_TlsAlloc() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_TlsAlloc(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TerminateThread)(HANDLE hThread,  DWORD dwExitCode) = TerminateThread;
static BOOL WINAPI hooked_TerminateThread(HANDLE hThread,  DWORD dwExitCode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TerminateThread(hThread, dwExitCode); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TlsFree)(DWORD dwTlsIndex) = TlsFree;
static BOOL WINAPI hooked_TlsFree(DWORD dwTlsIndex) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TlsFree(dwTlsIndex); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_TlsGetValue)(DWORD dwTlsIndex) = TlsGetValue;
static LPVOID WINAPI hooked_TlsGetValue(DWORD dwTlsIndex) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_TlsGetValue(dwTlsIndex); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_TlsGetValue2)(DWORD dwTlsIndex) = TlsGetValue2;
static LPVOID WINAPI hooked_TlsGetValue2(DWORD dwTlsIndex) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_TlsGetValue2(dwTlsIndex); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TlsSetValue)(DWORD dwTlsIndex,  LPVOID lpTlsValue) = TlsSetValue;
static BOOL WINAPI hooked_TlsSetValue(DWORD dwTlsIndex,  LPVOID lpTlsValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TlsSetValue(dwTlsIndex, lpTlsValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessGroupAffinity)(HANDLE hProcess,  PUSHORT GroupCount,  PUSHORT GroupArray) = GetProcessGroupAffinity;
static BOOL WINAPI hooked_GetProcessGroupAffinity(HANDLE hProcess,  PUSHORT GroupCount,  PUSHORT GroupArray) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessGroupAffinity(hProcess, GroupCount, GroupArray); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadGroupAffinity)(HANDLE hThread,  PGROUP_AFFINITY GroupAffinity) = GetThreadGroupAffinity;
static BOOL WINAPI hooked_GetThreadGroupAffinity(HANDLE hThread,  PGROUP_AFFINITY GroupAffinity) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadGroupAffinity(hThread, GroupAffinity); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadGroupAffinity)(HANDLE hThread,  const GROUP_AFFINITY *GroupAffinity,  PGROUP_AFFINITY PreviousGroupAffinity) = SetThreadGroupAffinity;
static BOOL WINAPI hooked_SetThreadGroupAffinity(HANDLE hThread,  const GROUP_AFFINITY *GroupAffinity,  PGROUP_AFFINITY PreviousGroupAffinity) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadGroupAffinity(hThread, GroupAffinity, PreviousGroupAffinity); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryPerformanceCounter)(LARGE_INTEGER *lpPerformanceCount) = QueryPerformanceCounter;
static BOOL WINAPI hooked_QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    result = og_QueryPerformanceCounter(lpPerformanceCount);

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryPerformanceFrequency)(LARGE_INTEGER *lpFrequency) = QueryPerformanceFrequency;
static BOOL WINAPI hooked_QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryPerformanceFrequency(lpFrequency); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EmptyWorkingSet)(HANDLE hProcess) = EmptyWorkingSet;
static BOOL WINAPI hooked_EmptyWorkingSet(HANDLE hProcess) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EmptyWorkingSet(hProcess); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDeviceDrivers)(LPVOID *lpImageBase,  DWORD cb,  LPDWORD lpcbNeeded) = EnumDeviceDrivers;
static BOOL WINAPI hooked_EnumDeviceDrivers(LPVOID *lpImageBase,  DWORD cb,  LPDWORD lpcbNeeded) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDeviceDrivers(lpImageBase, cb, lpcbNeeded); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumPageFilesA)(PENUM_PAGE_FILE_CALLBACKA pCallBackRoutine,  LPVOID pContext) = EnumPageFilesA;
static BOOL WINAPI hooked_EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA pCallBackRoutine,  LPVOID pContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumPageFilesA(pCallBackRoutine, pContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumPageFilesW)(PENUM_PAGE_FILE_CALLBACKW pCallBackRoutine,  LPVOID pContext) = EnumPageFilesW;
static BOOL WINAPI hooked_EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW pCallBackRoutine,  LPVOID pContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumPageFilesW(pCallBackRoutine, pContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumProcesses)(DWORD *lpidProcess,  DWORD cb,  LPDWORD lpcbNeeded) = EnumProcesses;
static BOOL WINAPI hooked_EnumProcesses(DWORD *lpidProcess,  DWORD cb,  LPDWORD lpcbNeeded) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumProcesses(lpidProcess, cb, lpcbNeeded); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumProcessModulesEx)(HANDLE hProcess,  HMODULE *lphModule,  DWORD cb,  LPDWORD lpcbNeeded,  DWORD dwFilterFlag) = EnumProcessModulesEx;
static BOOL WINAPI hooked_EnumProcessModulesEx(HANDLE hProcess,  HMODULE *lphModule,  DWORD cb,  LPDWORD lpcbNeeded,  DWORD dwFilterFlag) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumProcessModulesEx(hProcess, lphModule, cb, lpcbNeeded, dwFilterFlag); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumProcessModules)(HANDLE hProcess,  HMODULE *lphModule,  DWORD cb,  LPDWORD lpcbNeeded) = EnumProcessModules;
static BOOL WINAPI hooked_EnumProcessModules(HANDLE hProcess,  HMODULE *lphModule,  DWORD cb,  LPDWORD lpcbNeeded) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumProcessModules(hProcess, lphModule, cb, lpcbNeeded); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDeviceDriverBaseNameA)(LPVOID ImageBase, LPSTR lpFilename,  DWORD nSize) = GetDeviceDriverBaseNameA;
static DWORD WINAPI hooked_GetDeviceDriverBaseNameA(LPVOID ImageBase, LPSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDeviceDriverBaseNameA(ImageBase, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDeviceDriverBaseNameW)(LPVOID ImageBase,  LPWSTR lpBaseName,  DWORD nSize) = GetDeviceDriverBaseNameW;
static DWORD WINAPI hooked_GetDeviceDriverBaseNameW(LPVOID ImageBase,  LPWSTR lpBaseName,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDeviceDriverBaseNameW(ImageBase, lpBaseName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDeviceDriverFileNameA)(LPVOID ImageBase,  LPSTR lpFilename,  DWORD nSize) = GetDeviceDriverFileNameA;
static DWORD WINAPI hooked_GetDeviceDriverFileNameA(LPVOID ImageBase,  LPSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDeviceDriverFileNameA(ImageBase, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDeviceDriverFileNameW)(LPVOID ImageBase,  LPWSTR lpFilename,  DWORD nSize) = GetDeviceDriverFileNameW;
static DWORD WINAPI hooked_GetDeviceDriverFileNameW(LPVOID ImageBase,  LPWSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDeviceDriverFileNameW(ImageBase, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetModuleBaseNameA)(HANDLE hProcess,  HMODULE hModule,  LPSTR lpBaseName,  DWORD nSize) = GetModuleBaseNameA;
static DWORD WINAPI hooked_GetModuleBaseNameA(HANDLE hProcess,  HMODULE hModule,  LPSTR lpBaseName,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleBaseNameA(hProcess, hModule, lpBaseName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetMappedFileNameA)(HANDLE hProcess,  LPVOID lpv,  LPSTR lpFilename,  DWORD nSize) = GetMappedFileNameA;
static DWORD WINAPI hooked_GetMappedFileNameA(HANDLE hProcess,  LPVOID lpv,  LPSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetMappedFileNameA(hProcess, lpv, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetMappedFileNameW)(HANDLE hProcess,  LPVOID lpv,  LPWSTR lpFilename,  DWORD nSize) = GetMappedFileNameW;
static DWORD WINAPI hooked_GetMappedFileNameW(HANDLE hProcess,  LPVOID lpv,  LPWSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetMappedFileNameW(hProcess, lpv, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetModuleBaseNameW)(HANDLE hProcess,  HMODULE hModule,  LPWSTR lpBaseName,  DWORD nSize) = GetModuleBaseNameW;
static DWORD WINAPI hooked_GetModuleBaseNameW(HANDLE hProcess,  HMODULE hModule,  LPWSTR lpBaseName,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleBaseNameW(hProcess, hModule, lpBaseName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetModuleFileNameExA)(HANDLE hProcess,  HMODULE hModule,  LPSTR lpFilename,  DWORD nSize) = GetModuleFileNameExA;
static DWORD WINAPI hooked_GetModuleFileNameExA(HANDLE hProcess,  HMODULE hModule,  LPSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleFileNameExA(hProcess, hModule, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetModuleFileNameExW)(HANDLE hProcess,  HMODULE hModule,  LPWSTR lpFilename,  DWORD nSize) = GetModuleFileNameExW;
static DWORD WINAPI hooked_GetModuleFileNameExW(HANDLE hProcess,  HMODULE hModule,  LPWSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleFileNameExW(hProcess, hModule, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetModuleInformation)(HANDLE hProcess,  HMODULE hModule,  LPMODULEINFO lpmodinfo,  DWORD cb) = GetModuleInformation;
static BOOL WINAPI hooked_GetModuleInformation(HANDLE hProcess,  HMODULE hModule,  LPMODULEINFO lpmodinfo,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetModuleInformation(hProcess, hModule, lpmodinfo, cb); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessImageFileNameA)(HANDLE hProcess,  LPSTR lpImageFileName,  DWORD nSize) = GetProcessImageFileNameA;
static DWORD WINAPI hooked_GetProcessImageFileNameA(HANDLE hProcess,  LPSTR lpImageFileName,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessImageFileNameA(hProcess, lpImageFileName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetPerformanceInfo)(PPERFORMANCE_INFORMATION pPerformanceInformation,  DWORD cb) = GetPerformanceInfo;
static BOOL WINAPI hooked_GetPerformanceInfo(PPERFORMANCE_INFORMATION pPerformanceInformation,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetPerformanceInfo(pPerformanceInformation, cb); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessImageFileNameW)(HANDLE hProcess,  LPWSTR lpImageFileName,  DWORD nSize) = GetProcessImageFileNameW;
static DWORD WINAPI hooked_GetProcessImageFileNameW(HANDLE hProcess,  LPWSTR lpImageFileName,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessImageFileNameW(hProcess, lpImageFileName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessMemoryInfo)(HANDLE Process,  PPROCESS_MEMORY_COUNTERS ppsmemCounters,  DWORD cb) = GetProcessMemoryInfo;
static BOOL WINAPI hooked_GetProcessMemoryInfo(HANDLE Process,  PPROCESS_MEMORY_COUNTERS ppsmemCounters,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessMemoryInfo(Process, ppsmemCounters, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetWsChanges)(HANDLE hProcess,  PPSAPI_WS_WATCH_INFORMATION lpWatchInfo,  DWORD cb) = GetWsChanges;
static BOOL WINAPI hooked_GetWsChanges(HANDLE hProcess,  PPSAPI_WS_WATCH_INFORMATION lpWatchInfo,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetWsChanges(hProcess, lpWatchInfo, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetWsChangesEx)(HANDLE hProcess,  PPSAPI_WS_WATCH_INFORMATION_EX lpWatchInfoEx,  PDWORD cb) = GetWsChangesEx;
static BOOL WINAPI hooked_GetWsChangesEx(HANDLE hProcess,  PPSAPI_WS_WATCH_INFORMATION_EX lpWatchInfoEx,  PDWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetWsChangesEx(hProcess, lpWatchInfoEx, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitializeProcessForWsWatch)(HANDLE hProcess) = InitializeProcessForWsWatch;
static BOOL WINAPI hooked_InitializeProcessForWsWatch(HANDLE hProcess) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeProcessForWsWatch(hProcess); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryWorkingSet)(HANDLE hProcess,  PVOID pv,  DWORD cb) = QueryWorkingSet;
static BOOL WINAPI hooked_QueryWorkingSet(HANDLE hProcess,  PVOID pv,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryWorkingSet(hProcess, pv, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryWorkingSetEx)(HANDLE hProcess,  PVOID pv,  DWORD cb) = QueryWorkingSetEx;
static BOOL WINAPI hooked_QueryWorkingSetEx(HANDLE hProcess,  PVOID pv,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryWorkingSetEx(hProcess, pv, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileBandwidthReservation)(HANDLE hFile,  DWORD nPeriodMilliseconds,  DWORD nBytesPerPeriod,  BOOL bDiscardable,  LPDWORD lpTransferSize,  LPDWORD lpNumOutstandingRequests) = SetFileBandwidthReservation;
static BOOL WINAPI hooked_SetFileBandwidthReservation(HANDLE hFile,  DWORD nPeriodMilliseconds,  DWORD nBytesPerPeriod,  BOOL bDiscardable,  LPDWORD lpTransferSize,  LPDWORD lpNumOutstandingRequests) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileBandwidthReservation(hFile, nPeriodMilliseconds, nBytesPerPeriod, bDiscardable, lpTransferSize, lpNumOutstandingRequests); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileCompletionNotificationModes)(HANDLE FileHandle,  UCHAR Flags) = SetFileCompletionNotificationModes;
static BOOL WINAPI hooked_SetFileCompletionNotificationModes(HANDLE FileHandle,  UCHAR Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileCompletionNotificationModes(FileHandle, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileAttributesTransactedA)(LPCSTR lpFileName,  DWORD dwFileAttributes,  HANDLE hTransaction) = SetFileAttributesTransactedA;
static BOOL WINAPI hooked_SetFileAttributesTransactedA(LPCSTR lpFileName,  DWORD dwFileAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileAttributesTransactedA(lpFileName, dwFileAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetEnvironmentVariable)(LPCTSTR lpName,  LPCTSTR lpValue) = SetEnvironmentVariable;
static BOOL WINAPI hooked_SetEnvironmentVariable(LPCTSTR lpName,  LPCTSTR lpValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEnvironmentVariable(lpName, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileAttributesTransactedW)(LPCWSTR lpFileName,  DWORD dwFileAttributes,  HANDLE hTransaction) = SetFileAttributesTransactedW;
static BOOL WINAPI hooked_SetFileAttributesTransactedW(LPCWSTR lpFileName,  DWORD dwFileAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileAttributesTransactedW(lpFileName, dwFileAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFirmwareEnvironmentVariableExW)(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pValue,  DWORD nSize,  DWORD dwAttributes) = SetFirmwareEnvironmentVariableExW;
static BOOL WINAPI hooked_SetFirmwareEnvironmentVariableExW(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pValue,  DWORD nSize,  DWORD dwAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFirmwareEnvironmentVariableExW(lpName, lpGuid, pValue, nSize, dwAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFirmwareEnvironmentVariableExA)(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pValue,  DWORD nSize,  DWORD dwAttributes) = SetFirmwareEnvironmentVariableExA;
static BOOL WINAPI hooked_SetFirmwareEnvironmentVariableExA(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pValue,  DWORD nSize,  DWORD dwAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFirmwareEnvironmentVariableExA(lpName, lpGuid, pValue, nSize, dwAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileShortNameA)(HANDLE hFile,  LPCSTR lpShortName) = SetFileShortNameA;
static BOOL WINAPI hooked_SetFileShortNameA(HANDLE hFile,  LPCSTR lpShortName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileShortNameA(hFile, lpShortName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFirmwareEnvironmentVariableW)(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pValue,  DWORD nSize) = SetFirmwareEnvironmentVariableW;
static BOOL WINAPI hooked_SetFirmwareEnvironmentVariableW(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pValue,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFirmwareEnvironmentVariableW(lpName, lpGuid, pValue, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileShortNameW)(HANDLE hFile,  LPCWSTR lpShortName) = SetFileShortNameW;
static BOOL WINAPI hooked_SetFileShortNameW(HANDLE hFile,  LPCWSTR lpShortName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileShortNameW(hFile, lpShortName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFirmwareEnvironmentVariableA)(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pValue,  DWORD nSize) = SetFirmwareEnvironmentVariableA;
static BOOL WINAPI hooked_SetFirmwareEnvironmentVariableA(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pValue,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFirmwareEnvironmentVariableA(lpName, lpGuid, pValue, nSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_SetHandleCount)(UINT uNumber) = SetHandleCount;
static UINT WINAPI hooked_SetHandleCount(UINT uNumber) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_SetHandleCount(uNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessDEPPolicy)(DWORD dwFlags) = SetProcessDEPPolicy;
static BOOL WINAPI hooked_SetProcessDEPPolicy(DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessDEPPolicy(dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetMailslotInfo)(HANDLE hMailslot,  DWORD lReadTimeout) = SetMailslotInfo;
static BOOL WINAPI hooked_SetMailslotInfo(HANDLE hMailslot,  DWORD lReadTimeout) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetMailslotInfo(hMailslot, lReadTimeout); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetSearchPathMode)(DWORD Flags) = SetSearchPathMode;
static BOOL WINAPI hooked_SetSearchPathMode(DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetSearchPathMode(Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessAffinityMask)(HANDLE hProcess,  DWORD_PTR dwProcessAffinityMask) = SetProcessAffinityMask;
static BOOL WINAPI hooked_SetProcessAffinityMask(HANDLE hProcess,  DWORD_PTR dwProcessAffinityMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessAffinityMask(hProcess, dwProcessAffinityMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetSystemPowerState)(BOOL fSuspend,  BOOL fForce) = SetSystemPowerState;
static BOOL WINAPI hooked_SetSystemPowerState(BOOL fSuspend,  BOOL fForce) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetSystemPowerState(fSuspend, fForce); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetTapeParameters)(HANDLE hDevice,  DWORD dwOperation,  LPVOID lpTapeInformation) = SetTapeParameters;
static DWORD WINAPI hooked_SetTapeParameters(HANDLE hDevice,  DWORD dwOperation,  LPVOID lpTapeInformation) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetTapeParameters(hDevice, dwOperation, lpTapeInformation); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetTapePosition)(HANDLE hDevice,  DWORD dwPositionMethod,  DWORD dwPartition,  DWORD dwOffsetLow,  DWORD dwOffsetHigh,  BOOL bImmediate) = SetTapePosition;
static DWORD WINAPI hooked_SetTapePosition(HANDLE hDevice,  DWORD dwPositionMethod,  DWORD dwPartition,  DWORD dwOffsetLow,  DWORD dwOffsetHigh,  BOOL bImmediate) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetTapePosition(hDevice, dwPositionMethod, dwPartition, dwOffsetLow, dwOffsetHigh, bImmediate); });

	SEND_AFTER_CALL

    return result;
}

static DWORD_PTR (WINAPI *og_SetThreadAffinityMask)(HANDLE hThread,  DWORD_PTR dwThreadAffinityMask) = SetThreadAffinityMask;
static DWORD_PTR WINAPI hooked_SetThreadAffinityMask(HANDLE hThread,  DWORD_PTR dwThreadAffinityMask) {

	SEND_BEFORE_CALL

	
    DWORD_PTR result;
    TIME({ result = og_SetThreadAffinityMask(hThread, dwThreadAffinityMask); });

	SEND_AFTER_CALL

    return result;
}

static EXECUTION_STATE (WINAPI *og_SetThreadExecutionState)(EXECUTION_STATE esFlags) = SetThreadExecutionState;
static EXECUTION_STATE WINAPI hooked_SetThreadExecutionState(EXECUTION_STATE esFlags) {

	SEND_BEFORE_CALL

	
    EXECUTION_STATE result;
    TIME({ result = og_SetThreadExecutionState(esFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetUmsThreadInformation)(PUMS_CONTEXT UmsThread,  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,  PVOID UmsThreadInformation,  ULONG UmsThreadInformationLength) = SetUmsThreadInformation;
static BOOL WINAPI hooked_SetUmsThreadInformation(PUMS_CONTEXT UmsThread,  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,  PVOID UmsThreadInformation,  ULONG UmsThreadInformationLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetUmsThreadInformation(UmsThread, UmsThreadInfoClass, UmsThreadInformation, UmsThreadInformationLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetupComm)(HANDLE hFile,  DWORD dwInQueue,  DWORD dwOutQueue) = SetupComm;
static BOOL WINAPI hooked_SetupComm(HANDLE hFile,  DWORD dwInQueue,  DWORD dwOutQueue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetupComm(hFile, dwInQueue, dwOutQueue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetVolumeLabelA)(LPCSTR lpRootPathName,  LPCSTR lpVolumeName) = SetVolumeLabelA;
static BOOL WINAPI hooked_SetVolumeLabelA(LPCSTR lpRootPathName,  LPCSTR lpVolumeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetVolumeLabelA(lpRootPathName, lpVolumeName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetVolumeLabelW)(LPCWSTR lpRootPathName,  LPCWSTR lpVolumeName) = SetVolumeLabelW;
static BOOL WINAPI hooked_SetVolumeLabelW(LPCWSTR lpRootPathName,  LPCWSTR lpVolumeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetVolumeLabelW(lpRootPathName, lpVolumeName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetVolumeMountPointA)(LPCSTR lpszVolumeMountPoint,  LPCSTR lpszVolumeName) = SetVolumeMountPointA;
static BOOL WINAPI hooked_SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,  LPCSTR lpszVolumeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetVolumeMountPointA(lpszVolumeMountPoint, lpszVolumeName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetVolumeMountPointW)(LPCWSTR lpszVolumeMountPoint,  LPCWSTR lpszVolumeName) = SetVolumeMountPointW;
static BOOL WINAPI hooked_SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,  LPCWSTR lpszVolumeName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetVolumeMountPointW(lpszVolumeMountPoint, lpszVolumeName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetXStateFeaturesMask)(PCONTEXT Context,  DWORD64 FeatureMask) = SetXStateFeaturesMask;
static BOOL WINAPI hooked_SetXStateFeaturesMask(PCONTEXT Context,  DWORD64 FeatureMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetXStateFeaturesMask(Context, FeatureMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TransmitCommChar)(HANDLE hFile,  char cChar) = TransmitCommChar;
static BOOL WINAPI hooked_TransmitCommChar(HANDLE hFile,  char cChar) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TransmitCommChar(hFile, cChar); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SwitchToFiber)(LPVOID lpFiber) = SwitchToFiber;
static VOID WINAPI hooked_SwitchToFiber(LPVOID lpFiber) {

	SEND_BEFORE_CALL

	
	TIME({ og_SwitchToFiber(lpFiber); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_UmsThreadYield)(PVOID SchedulerParam) = UmsThreadYield;
static BOOL WINAPI hooked_UmsThreadYield(PVOID SchedulerParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UmsThreadYield(SchedulerParam); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_UnregisterApplicationRestart)() = UnregisterApplicationRestart;
static HRESULT WINAPI hooked_UnregisterApplicationRestart() {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_UnregisterApplicationRestart(); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_UnregisterApplicationRecoveryCallback)() = UnregisterApplicationRecoveryCallback;
static HRESULT WINAPI hooked_UnregisterApplicationRecoveryCallback() {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_UnregisterApplicationRecoveryCallback(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnregisterWait)(HANDLE WaitHandle) = UnregisterWait;
static BOOL WINAPI hooked_UnregisterWait(HANDLE WaitHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnregisterWait(WaitHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UpdateResourceA)(HANDLE hUpdate,  LPCSTR lpType,  LPCSTR lpName,  WORD wLanguage,  LPVOID lpData,  DWORD cb) = UpdateResourceA;
static BOOL WINAPI hooked_UpdateResourceA(HANDLE hUpdate,  LPCSTR lpType,  LPCSTR lpName,  WORD wLanguage,  LPVOID lpData,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UpdateResourceW)(HANDLE hUpdate,  LPCWSTR lpType,  LPCWSTR lpName,  WORD wLanguage,  LPVOID lpData,  DWORD cb) = UpdateResourceW;
static BOOL WINAPI hooked_UpdateResourceW(HANDLE hUpdate,  LPCWSTR lpType,  LPCWSTR lpName,  WORD wLanguage,  LPVOID lpData,  DWORD cb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VerifyVersionInfoW)(LPOSVERSIONINFOEXW lpVersionInformation,  DWORD dwTypeMask,  DWORDLONG dwlConditionMask) = VerifyVersionInfoW;
static BOOL WINAPI hooked_VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,  DWORD dwTypeMask,  DWORDLONG dwlConditionMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VerifyVersionInfoW(lpVersionInformation, dwTypeMask, dwlConditionMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VerifyVersionInfoA)(LPOSVERSIONINFOEXA lpVersionInformation,  DWORD dwTypeMask,  DWORDLONG dwlConditionMask) = VerifyVersionInfoA;
static BOOL WINAPI hooked_VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,  DWORD dwTypeMask,  DWORDLONG dwlConditionMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VerifyVersionInfoA(lpVersionInformation, dwTypeMask, dwlConditionMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WaitCommEvent)(HANDLE hFile,  LPDWORD lpEvtMask,  LPOVERLAPPED lpOverlapped) = WaitCommEvent;
static BOOL WINAPI hooked_WaitCommEvent(HANDLE hFile,  LPDWORD lpEvtMask,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WaitCommEvent(hFile, lpEvtMask, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WaitNamedPipeA)(LPCSTR lpNamedPipeName,  DWORD nTimeOut) = WaitNamedPipeA;
static BOOL WINAPI hooked_WaitNamedPipeA(LPCSTR lpNamedPipeName,  DWORD nTimeOut) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WaitNamedPipeA(lpNamedPipeName, nTimeOut); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Wow64GetThreadSelectorEntry)(HANDLE hThread,  DWORD dwSelector,  PWOW64_LDT_ENTRY lpSelectorEntry) = Wow64GetThreadSelectorEntry;
static BOOL WINAPI hooked_Wow64GetThreadSelectorEntry(HANDLE hThread,  DWORD dwSelector,  PWOW64_LDT_ENTRY lpSelectorEntry) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Wow64GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_WinExec)(LPCSTR lpCmdLine,  UINT uCmdShow) = WinExec;
static UINT WINAPI hooked_WinExec(LPCSTR lpCmdLine,  UINT uCmdShow) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_WinExec(lpCmdLine, uCmdShow); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileSectionA)(LPCSTR lpAppName,  LPCSTR lpString,  LPCSTR lpFileName) = WritePrivateProfileSectionA;
static BOOL WINAPI hooked_WritePrivateProfileSectionA(LPCSTR lpAppName,  LPCSTR lpString,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileSectionA(lpAppName, lpString, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileStringA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpString,  LPCSTR lpFileName) = WritePrivateProfileStringA;
static BOOL WINAPI hooked_WritePrivateProfileStringA(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpString,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileStringA(lpAppName, lpKeyName, lpString, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileSectionW)(LPCWSTR lpAppName,  LPCWSTR lpString,  LPCWSTR lpFileName) = WritePrivateProfileSectionW;
static BOOL WINAPI hooked_WritePrivateProfileSectionW(LPCWSTR lpAppName,  LPCWSTR lpString,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileSectionW(lpAppName, lpString, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileStructA)(LPCSTR lpszSection,  LPCSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCSTR szFile) = WritePrivateProfileStructA;
static BOOL WINAPI hooked_WritePrivateProfileStructA(LPCSTR lpszSection,  LPCSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCSTR szFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileStringW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpString,  LPCWSTR lpFileName) = WritePrivateProfileStringW;
static BOOL WINAPI hooked_WritePrivateProfileStringW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpString,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileStringW(lpAppName, lpKeyName, lpString, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteProfileSectionA)(LPCSTR lpAppName,  LPCSTR lpString) = WriteProfileSectionA;
static BOOL WINAPI hooked_WriteProfileSectionA(LPCSTR lpAppName,  LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteProfileSectionA(lpAppName, lpString); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WritePrivateProfileStructW)(LPCWSTR lpszSection,  LPCWSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCWSTR szFile) = WritePrivateProfileStructW;
static BOOL WINAPI hooked_WritePrivateProfileStructW(LPCWSTR lpszSection,  LPCWSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCWSTR szFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WritePrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteProfileSectionW)(LPCWSTR lpAppName,  LPCWSTR lpString) = WriteProfileSectionW;
static BOOL WINAPI hooked_WriteProfileSectionW(LPCWSTR lpAppName,  LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteProfileSectionW(lpAppName, lpString); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WTSGetActiveConsoleSessionId)() = WTSGetActiveConsoleSessionId;
static DWORD WINAPI hooked_WTSGetActiveConsoleSessionId() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WTSGetActiveConsoleSessionId(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteProfileStringA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpString) = WriteProfileStringA;
static BOOL WINAPI hooked_WriteProfileStringA(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteProfileStringA(lpAppName, lpKeyName, lpString); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteProfileStringW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpString) = WriteProfileStringW;
static BOOL WINAPI hooked_WriteProfileStringW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteProfileStringW(lpAppName, lpKeyName, lpString); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WriteTapemark)(HANDLE hDevice,  DWORD dwTapemarkType,  DWORD dwTapemarkCount,  BOOL bImmediate) = WriteTapemark;
static DWORD WINAPI hooked_WriteTapemark(HANDLE hDevice,  DWORD dwTapemarkType,  DWORD dwTapemarkCount,  BOOL bImmediate) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WriteTapemark(hDevice, dwTapemarkType, dwTapemarkCount, bImmediate); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ZombifyActCtx)(HANDLE hActCtx) = ZombifyActCtx;
static BOOL WINAPI hooked_ZombifyActCtx(HANDLE hActCtx) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ZombifyActCtx(hActCtx); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_ConvertAuxiliaryCounterToPerformanceCounter)(ULONGLONG ullAuxiliaryCounterValue,  PULONGLONG lpPerformanceCounterValue,  PULONGLONG lpConversionError) = ConvertAuxiliaryCounterToPerformanceCounter;
static HRESULT WINAPI hooked_ConvertAuxiliaryCounterToPerformanceCounter(ULONGLONG ullAuxiliaryCounterValue,  PULONGLONG lpPerformanceCounterValue,  PULONGLONG lpConversionError) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_ConvertAuxiliaryCounterToPerformanceCounter(ullAuxiliaryCounterValue, lpPerformanceCounterValue, lpConversionError); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_ConvertPerformanceCounterToAuxiliaryCounter)(ULONGLONG ullPerformanceCounterValue,  PULONGLONG lpAuxiliaryCounterValue,  PULONGLONG lpConversionError) = ConvertPerformanceCounterToAuxiliaryCounter;
static HRESULT WINAPI hooked_ConvertPerformanceCounterToAuxiliaryCounter(ULONGLONG ullPerformanceCounterValue,  PULONGLONG lpAuxiliaryCounterValue,  PULONGLONG lpConversionError) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_ConvertPerformanceCounterToAuxiliaryCounter(ullPerformanceCounterValue, lpAuxiliaryCounterValue, lpConversionError); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_QueryAuxiliaryCounterFrequency)(PULONGLONG lpAuxiliaryCounterFrequency) = QueryAuxiliaryCounterFrequency;
static HRESULT WINAPI hooked_QueryAuxiliaryCounterFrequency(PULONGLONG lpAuxiliaryCounterFrequency) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_QueryAuxiliaryCounterFrequency(lpAuxiliaryCounterFrequency); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryIdleProcessorCycleTimeEx)(USHORT Group,  PULONG BufferLength,  PULONG64 ProcessorIdleCycleTime) = QueryIdleProcessorCycleTimeEx;
static BOOL WINAPI hooked_QueryIdleProcessorCycleTimeEx(USHORT Group,  PULONG BufferLength,  PULONG64 ProcessorIdleCycleTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryIdleProcessorCycleTimeEx(Group, BufferLength, ProcessorIdleCycleTime); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_QueryInterruptTimePrecise)(PULONGLONG lpInterruptTimePrecise) = QueryInterruptTimePrecise;
static VOID WINAPI hooked_QueryInterruptTimePrecise(PULONGLONG lpInterruptTimePrecise) {

	SEND_BEFORE_CALL

	
	TIME({ og_QueryInterruptTimePrecise(lpInterruptTimePrecise); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_QueryIdleProcessorCycleTime)(PULONG BufferLength,  PULONG64 ProcessorIdleCycleTime) = QueryIdleProcessorCycleTime;
static BOOL WINAPI hooked_QueryIdleProcessorCycleTime(PULONG BufferLength,  PULONG64 ProcessorIdleCycleTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryIdleProcessorCycleTime(BufferLength, ProcessorIdleCycleTime); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_QueryInterruptTime)(PULONGLONG lpInterruptTime) = QueryInterruptTime;
static VOID WINAPI hooked_QueryInterruptTime(PULONGLONG lpInterruptTime) {

	SEND_BEFORE_CALL

	
	TIME({ og_QueryInterruptTime(lpInterruptTime); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_QueryProcessCycleTime)(HANDLE ProcessHandle,  PULONG64 CycleTime) = QueryProcessCycleTime;
static BOOL WINAPI hooked_QueryProcessCycleTime(HANDLE ProcessHandle,  PULONG64 CycleTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryProcessCycleTime(ProcessHandle, CycleTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryThreadCycleTime)(HANDLE ThreadHandle,  PULONG64 CycleTime) = QueryThreadCycleTime;
static BOOL WINAPI hooked_QueryThreadCycleTime(HANDLE ThreadHandle,  PULONG64 CycleTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryThreadCycleTime(ThreadHandle, CycleTime); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_QueryUnbiasedInterruptTimePrecise)(PULONGLONG lpUnbiasedInterruptTimePrecise) = QueryUnbiasedInterruptTimePrecise;
static VOID WINAPI hooked_QueryUnbiasedInterruptTimePrecise(PULONGLONG lpUnbiasedInterruptTimePrecise) {

	SEND_BEFORE_CALL

	
	TIME({ og_QueryUnbiasedInterruptTimePrecise(lpUnbiasedInterruptTimePrecise); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_QueryUnbiasedInterruptTime)(PULONGLONG UnbiasedTime) = QueryUnbiasedInterruptTime;
static BOOL WINAPI hooked_QueryUnbiasedInterruptTime(PULONGLONG UnbiasedTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryUnbiasedInterruptTime(UnbiasedTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceNamesExW)(HMODULE hModule, LPCWSTR lpType,  ENUMRESNAMEPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceNamesExW;
static BOOL WINAPI hooked_EnumResourceNamesExW(HMODULE hModule, LPCWSTR lpType,  ENUMRESNAMEPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceNamesExW(hModule, lpType, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceNamesW)(HMODULE hModule,  LPCWSTR lpType,  ENUMRESNAMEPROCW lpEnumFunc,  LONG_PTR lParam) = EnumResourceNamesW;
static BOOL WINAPI hooked_EnumResourceNamesW(HMODULE hModule,  LPCWSTR lpType,  ENUMRESNAMEPROCW lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceNamesW(hModule, lpType, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceTypesExA)(HMODULE hModule,  ENUMRESTYPEPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceTypesExA;
static BOOL WINAPI hooked_EnumResourceTypesExA(HMODULE hModule,  ENUMRESTYPEPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceTypesExA(hModule, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static HRSRC (WINAPI *og_FindResourceExW)(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  WORD wLanguage) = FindResourceExW;
static HRSRC WINAPI hooked_FindResourceExW(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  WORD wLanguage) {

	SEND_BEFORE_CALL

	
    HRSRC result;
    TIME({ result = og_FindResourceExW(hModule, lpType, lpName, wLanguage); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceTypesExW)(HMODULE hModule,  ENUMRESTYPEPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceTypesExW;
static BOOL WINAPI hooked_EnumResourceTypesExW(HMODULE hModule,  ENUMRESTYPEPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceTypesExW(hModule, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static HRSRC (WINAPI *og_FindResourceW)(HMODULE hModule,  LPCWSTR lpName,  LPCWSTR lpType) = FindResourceW;
static HRSRC WINAPI hooked_FindResourceW(HMODULE hModule,  LPCWSTR lpName,  LPCWSTR lpType) {

	SEND_BEFORE_CALL

	
    HRSRC result;
    TIME({ result = og_FindResourceW(hModule, lpName, lpType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FreeLibrary)(HMODULE hLibModule) = FreeLibrary;
static BOOL WINAPI hooked_FreeLibrary(HMODULE hLibModule) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FreeLibrary(hLibModule); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_FindStringOrdinal)(DWORD dwFindStringOrdinalFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  BOOL bIgnoreCase) = FindStringOrdinal;
static int WINAPI hooked_FindStringOrdinal(DWORD dwFindStringOrdinalFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  BOOL bIgnoreCase) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_FindStringOrdinal(dwFindStringOrdinalFlags, lpStringSource, cchSource, lpStringValue, cchValue, bIgnoreCase); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FreeResource)(HGLOBAL hResData) = FreeResource;
static BOOL WINAPI hooked_FreeResource(HGLOBAL hResData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FreeResource(hResData); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_FreeLibraryAndExitThread)(HMODULE hLibModule,  DWORD dwExitCode) = FreeLibraryAndExitThread;
static VOID WINAPI hooked_FreeLibraryAndExitThread(HMODULE hLibModule,  DWORD dwExitCode) {

	SEND_BEFORE_CALL

	
	TIME({ og_FreeLibraryAndExitThread(hLibModule, dwExitCode); });

	SEND_AFTER_CALL
	
}

static DWORD (WINAPI *og_GetModuleFileNameW)(HMODULE hModule,  LPWSTR lpFilename,  DWORD nSize) = GetModuleFileNameW;
static DWORD WINAPI hooked_GetModuleFileNameW(HMODULE hModule,  LPWSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleFileNameW(hModule, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetModuleFileNameA)(HMODULE hModule,  LPSTR lpFilename,  DWORD nSize) = GetModuleFileNameA;
static DWORD WINAPI hooked_GetModuleFileNameA(HMODULE hModule,  LPSTR lpFilename,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetModuleFileNameA(hModule, lpFilename, nSize); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_GetModuleHandleA)(LPCSTR lpModuleName) = GetModuleHandleA;
static HMODULE WINAPI hooked_GetModuleHandleA(LPCSTR lpModuleName) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_GetModuleHandleA(lpModuleName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetModuleHandleExA)(DWORD dwFlags,  LPCSTR lpModuleName,  HMODULE *phModule) = GetModuleHandleExA;
static BOOL WINAPI hooked_GetModuleHandleExA(DWORD dwFlags,  LPCSTR lpModuleName,  HMODULE *phModule) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetModuleHandleExA(dwFlags, lpModuleName, phModule); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetModuleHandleExW)(DWORD dwFlags,  LPCWSTR lpModuleName,  HMODULE *phModule) = GetModuleHandleExW;
static BOOL WINAPI hooked_GetModuleHandleExW(DWORD dwFlags,  LPCWSTR lpModuleName,  HMODULE *phModule) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetModuleHandleExW(dwFlags, lpModuleName, phModule); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_GetModuleHandleW)(LPCWSTR lpModuleName) = GetModuleHandleW;
static HMODULE WINAPI hooked_GetModuleHandleW(LPCWSTR lpModuleName) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_GetModuleHandleW(lpModuleName); });

	SEND_AFTER_CALL

    return result;
}

static FARPROC (WINAPI *og_GetProcAddress)(HMODULE hModule,  LPCSTR lpProcName) = GetProcAddress;
static FARPROC WINAPI hooked_GetProcAddress(HMODULE hModule,  LPCSTR lpProcName) {

	SEND_BEFORE_CALL

	
    FARPROC result;
    TIME({ result = og_GetProcAddress(hModule, lpProcName); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_LoadLibraryA)(LPCSTR lpLibFileName) = LoadLibraryA;
static HMODULE WINAPI hooked_LoadLibraryA(LPCSTR lpLibFileName) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_LoadLibraryA(lpLibFileName); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_LoadLibraryExA)(LPCSTR lpLibFileName, HANDLE hFile,  DWORD dwFlags) = LoadLibraryExA;
static HMODULE WINAPI hooked_LoadLibraryExA(LPCSTR lpLibFileName, HANDLE hFile,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_LoadLibraryExA(lpLibFileName, hFile, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_LoadLibraryExW)(LPCWSTR lpLibFileName, HANDLE hFile,  DWORD dwFlags) = LoadLibraryExW;
static HMODULE WINAPI hooked_LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_LoadLibraryExW(lpLibFileName, hFile, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_LoadLibraryW)(LPCWSTR lpLibFileName) = LoadLibraryW;
static HMODULE WINAPI hooked_LoadLibraryW(LPCWSTR lpLibFileName) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_LoadLibraryW(lpLibFileName); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_LockResource)(HGLOBAL hResData) = LockResource;
static LPVOID WINAPI hooked_LockResource(HGLOBAL hResData) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_LockResource(hResData); });

	SEND_AFTER_CALL

    return result;
}

static HGLOBAL (WINAPI *og_LoadResource)(HMODULE hModule,  HRSRC hResInfo) = LoadResource;
static HGLOBAL WINAPI hooked_LoadResource(HMODULE hModule,  HRSRC hResInfo) {

	SEND_BEFORE_CALL

	
    HGLOBAL result;
    TIME({ result = og_LoadResource(hModule, hResInfo); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDllDirectory)(DLL_DIRECTORY_COOKIE Cookie) = RemoveDllDirectory;
static BOOL WINAPI hooked_RemoveDllDirectory(DLL_DIRECTORY_COOKIE Cookie) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDllDirectory(Cookie); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDefaultDllDirectories)(DWORD DirectoryFlags) = SetDefaultDllDirectories;
static BOOL WINAPI hooked_SetDefaultDllDirectories(DWORD DirectoryFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDefaultDllDirectories(DirectoryFlags); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SizeofResource)(HMODULE hModule,  HRSRC hResInfo) = SizeofResource;
static DWORD WINAPI hooked_SizeofResource(HMODULE hModule,  HRSRC hResInfo) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SizeofResource(hModule, hResInfo); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AllocateUserPhysicalPages)(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray) = AllocateUserPhysicalPages;
static BOOL WINAPI hooked_AllocateUserPhysicalPages(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AllocateUserPhysicalPages(hProcess, NumberOfPages, PageArray); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AllocateUserPhysicalPagesNuma)(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray,  DWORD nndPreferred) = AllocateUserPhysicalPagesNuma;
static BOOL WINAPI hooked_AllocateUserPhysicalPagesNuma(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray,  DWORD nndPreferred) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AllocateUserPhysicalPagesNuma(hProcess, NumberOfPages, PageArray, nndPreferred); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMapping2)(HANDLE File, SECURITY_ATTRIBUTES *SecurityAttributes, ULONG DesiredAccess, ULONG PageProtection, ULONG AllocationAttributes, ULONG64 MaximumSize, PCWSTR Name, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount) = CreateFileMapping2;
static HANDLE WINAPI hooked_CreateFileMapping2(HANDLE File, SECURITY_ATTRIBUTES *SecurityAttributes, ULONG DesiredAccess, ULONG PageProtection, ULONG AllocationAttributes, ULONG64 MaximumSize, PCWSTR Name, MEM_EXTENDED_PARAMETER *ExtendedParameters, ULONG ParameterCount) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMapping2(File, SecurityAttributes, DesiredAccess, PageProtection, AllocationAttributes, MaximumSize, Name, ExtendedParameters, ParameterCount); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMappingFromApp)(HANDLE hFile,  PSECURITY_ATTRIBUTES SecurityAttributes,  ULONG PageProtection,  ULONG64 MaximumSize,  PCWSTR Name) = CreateFileMappingFromApp;
static HANDLE WINAPI hooked_CreateFileMappingFromApp(HANDLE hFile,  PSECURITY_ATTRIBUTES SecurityAttributes,  ULONG PageProtection,  ULONG64 MaximumSize,  PCWSTR Name) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMappingFromApp(hFile, SecurityAttributes, PageProtection, MaximumSize, Name); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMappingW)(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCWSTR lpName) = CreateFileMappingW;
static HANDLE WINAPI hooked_CreateFileMappingW(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMappingW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMappingNumaW)(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCWSTR lpName,  DWORD nndPreferred) = CreateFileMappingNumaW;
static HANDLE WINAPI hooked_CreateFileMappingNumaW(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCWSTR lpName,  DWORD nndPreferred) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMappingNumaW(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMemoryResourceNotification)(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType) = CreateMemoryResourceNotification;
static HANDLE WINAPI hooked_CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMemoryResourceNotification(NotificationType); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_DiscardVirtualMemory)(PVOID VirtualAddress,  SIZE_T Size) = DiscardVirtualMemory;
static DWORD WINAPI hooked_DiscardVirtualMemory(PVOID VirtualAddress,  SIZE_T Size) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_DiscardVirtualMemory(VirtualAddress, Size); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FlushViewOfFile)(LPCVOID lpBaseAddress,  SIZE_T dwNumberOfBytesToFlush) = FlushViewOfFile;
static BOOL WINAPI hooked_FlushViewOfFile(LPCVOID lpBaseAddress,  SIZE_T dwNumberOfBytesToFlush) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FlushViewOfFile(lpBaseAddress, dwNumberOfBytesToFlush); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_GetLargePageMinimum)() = GetLargePageMinimum;
static SIZE_T WINAPI hooked_GetLargePageMinimum() {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_GetLargePageMinimum(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetMemoryErrorHandlingCapabilities)(PULONG Capabilities) = GetMemoryErrorHandlingCapabilities;
static BOOL WINAPI hooked_GetMemoryErrorHandlingCapabilities(PULONG Capabilities) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetMemoryErrorHandlingCapabilities(Capabilities); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FreeUserPhysicalPages)(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray) = FreeUserPhysicalPages;
static BOOL WINAPI hooked_FreeUserPhysicalPages(HANDLE hProcess,  PULONG_PTR NumberOfPages,  PULONG_PTR PageArray) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FreeUserPhysicalPages(hProcess, NumberOfPages, PageArray); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessWorkingSetSize)(HANDLE hProcess,  PSIZE_T lpMinimumWorkingSetSize,  PSIZE_T lpMaximumWorkingSetSize) = GetProcessWorkingSetSize;
static BOOL WINAPI hooked_GetProcessWorkingSetSize(HANDLE hProcess,  PSIZE_T lpMinimumWorkingSetSize,  PSIZE_T lpMaximumWorkingSetSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessWorkingSetSize(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessWorkingSetSizeEx)(HANDLE hProcess,  PSIZE_T lpMinimumWorkingSetSize,  PSIZE_T lpMaximumWorkingSetSize,  PDWORD Flags) = GetProcessWorkingSetSizeEx;
static BOOL WINAPI hooked_GetProcessWorkingSetSizeEx(HANDLE hProcess,  PSIZE_T lpMinimumWorkingSetSize,  PSIZE_T lpMaximumWorkingSetSize,  PDWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessWorkingSetSizeEx(hProcess, lpMinimumWorkingSetSize, lpMaximumWorkingSetSize, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetSystemFileCacheSize)(PSIZE_T lpMinimumFileCacheSize,  PSIZE_T lpMaximumFileCacheSize,  PDWORD lpFlags) = GetSystemFileCacheSize;
static BOOL WINAPI hooked_GetSystemFileCacheSize(PSIZE_T lpMinimumFileCacheSize,  PSIZE_T lpMaximumFileCacheSize,  PDWORD lpFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemFileCacheSize(lpMinimumFileCacheSize, lpMaximumFileCacheSize, lpFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MapUserPhysicalPages)(PVOID VirtualAddress,  ULONG_PTR NumberOfPages,  PULONG_PTR PageArray) = MapUserPhysicalPages;
static BOOL WINAPI hooked_MapUserPhysicalPages(PVOID VirtualAddress,  ULONG_PTR NumberOfPages,  PULONG_PTR PageArray) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MapUserPhysicalPages(VirtualAddress, NumberOfPages, PageArray); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_MapViewOfFile)(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap) = MapViewOfFile;
static LPVOID WINAPI hooked_MapViewOfFile(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_MapViewOfFile(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetWriteWatch)(DWORD dwFlags,  PVOID lpBaseAddress,  SIZE_T dwRegionSize,  PVOID *lpAddresses,  ULONG_PTR *lpdwCount,  LPDWORD lpdwGranularity) = GetWriteWatch;
static UINT WINAPI hooked_GetWriteWatch(DWORD dwFlags,  PVOID lpBaseAddress,  SIZE_T dwRegionSize,  PVOID *lpAddresses,  ULONG_PTR *lpdwCount,  LPDWORD lpdwGranularity) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetWriteWatch(dwFlags, lpBaseAddress, dwRegionSize, lpAddresses, lpdwCount, lpdwGranularity); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_MapViewOfFile2)(HANDLE FileMappingHandle,  HANDLE ProcessHandle,  ULONG64 Offset,  PVOID BaseAddress,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection) = MapViewOfFile2;
static PVOID WINAPI hooked_MapViewOfFile2(HANDLE FileMappingHandle,  HANDLE ProcessHandle,  ULONG64 Offset,  PVOID BaseAddress,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_MapViewOfFile2(FileMappingHandle, ProcessHandle, Offset, BaseAddress, ViewSize, AllocationType, PageProtection); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_MapViewOfFile3)(HANDLE FileMapping,  HANDLE Process,  PVOID BaseAddress,  ULONG64 Offset,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) = MapViewOfFile3;
static PVOID WINAPI hooked_MapViewOfFile3(HANDLE FileMapping,  HANDLE Process,  PVOID BaseAddress,  ULONG64 Offset,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_MapViewOfFile3(FileMapping, Process, BaseAddress, Offset, ViewSize, AllocationType, PageProtection, ExtendedParameters, ParameterCount); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_MapViewOfFile3FromApp)(HANDLE FileMapping,  HANDLE Process,  PVOID BaseAddress,  ULONG64 Offset,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) = MapViewOfFile3FromApp;
static PVOID WINAPI hooked_MapViewOfFile3FromApp(HANDLE FileMapping,  HANDLE Process,  PVOID BaseAddress,  ULONG64 Offset,  SIZE_T ViewSize,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_MapViewOfFile3FromApp(FileMapping, Process, BaseAddress, Offset, ViewSize, AllocationType, PageProtection, ExtendedParameters, ParameterCount); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_MapViewOfFileFromApp)(HANDLE hFileMappingObject,  ULONG DesiredAccess,  ULONG64 FileOffset,  SIZE_T NumberOfBytesToMap) = MapViewOfFileFromApp;
static PVOID WINAPI hooked_MapViewOfFileFromApp(HANDLE hFileMappingObject,  ULONG DesiredAccess,  ULONG64 FileOffset,  SIZE_T NumberOfBytesToMap) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_MapViewOfFileFromApp(hFileMappingObject, DesiredAccess, FileOffset, NumberOfBytesToMap); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_MapViewOfFileEx)(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap,  LPVOID lpBaseAddress) = MapViewOfFileEx;
static LPVOID WINAPI hooked_MapViewOfFileEx(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap,  LPVOID lpBaseAddress) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_MapViewOfFileEx(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_OfferVirtualMemory)(PVOID VirtualAddress,  SIZE_T Size,  OFFER_PRIORITY Priority) = OfferVirtualMemory;
static DWORD WINAPI hooked_OfferVirtualMemory(PVOID VirtualAddress,  SIZE_T Size,  OFFER_PRIORITY Priority) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_OfferVirtualMemory(VirtualAddress, Size, Priority); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenFileMappingFromApp)(ULONG DesiredAccess,  BOOL InheritHandle,  PCWSTR Name) = OpenFileMappingFromApp;
static HANDLE WINAPI hooked_OpenFileMappingFromApp(ULONG DesiredAccess,  BOOL InheritHandle,  PCWSTR Name) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenFileMappingFromApp(DesiredAccess, InheritHandle, Name); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenFileMappingW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) = OpenFileMappingW;
static HANDLE WINAPI hooked_OpenFileMappingW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenFileMappingW(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryMemoryResourceNotification)(HANDLE ResourceNotificationHandle,  PBOOL ResourceState) = QueryMemoryResourceNotification;
static BOOL WINAPI hooked_QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle,  PBOOL ResourceState) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryMemoryResourceNotification(ResourceNotificationHandle, ResourceState); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PrefetchVirtualMemory)(HANDLE hProcess,  ULONG_PTR NumberOfEntries,  PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses,  ULONG Flags) = PrefetchVirtualMemory;
static BOOL WINAPI hooked_PrefetchVirtualMemory(HANDLE hProcess,  ULONG_PTR NumberOfEntries,  PWIN32_MEMORY_RANGE_ENTRY VirtualAddresses,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PrefetchVirtualMemory(hProcess, NumberOfEntries, VirtualAddresses, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadProcessMemory)(HANDLE hProcess,  LPCVOID lpBaseAddress,  LPVOID lpBuffer,  SIZE_T nSize,  SIZE_T *lpNumberOfBytesRead) = ReadProcessMemory;
static BOOL WINAPI hooked_ReadProcessMemory(HANDLE hProcess,  LPCVOID lpBaseAddress,  LPVOID lpBuffer,  SIZE_T nSize,  SIZE_T *lpNumberOfBytesRead) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesRead); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_RegisterBadMemoryNotification)(PBAD_MEMORY_CALLBACK_ROUTINE Callback) = RegisterBadMemoryNotification;
static PVOID WINAPI hooked_RegisterBadMemoryNotification(PBAD_MEMORY_CALLBACK_ROUTINE Callback) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_RegisterBadMemoryNotification(Callback); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_ReclaimVirtualMemory)(void const *VirtualAddress,  SIZE_T Size) = ReclaimVirtualMemory;
static DWORD WINAPI hooked_ReclaimVirtualMemory(void const *VirtualAddress,  SIZE_T Size) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_ReclaimVirtualMemory(VirtualAddress, Size); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_ResetWriteWatch)(LPVOID lpBaseAddress,  SIZE_T dwRegionSize) = ResetWriteWatch;
static UINT WINAPI hooked_ResetWriteWatch(LPVOID lpBaseAddress,  SIZE_T dwRegionSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_ResetWriteWatch(lpBaseAddress, dwRegionSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessWorkingSetSize)(HANDLE hProcess,  SIZE_T dwMinimumWorkingSetSize,  SIZE_T dwMaximumWorkingSetSize) = SetProcessWorkingSetSize;
static BOOL WINAPI hooked_SetProcessWorkingSetSize(HANDLE hProcess,  SIZE_T dwMinimumWorkingSetSize,  SIZE_T dwMaximumWorkingSetSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessWorkingSetSize(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessWorkingSetSizeEx)(HANDLE hProcess,  SIZE_T dwMinimumWorkingSetSize,  SIZE_T dwMaximumWorkingSetSize,  DWORD Flags) = SetProcessWorkingSetSizeEx;
static BOOL WINAPI hooked_SetProcessWorkingSetSizeEx(HANDLE hProcess,  SIZE_T dwMinimumWorkingSetSize,  SIZE_T dwMaximumWorkingSetSize,  DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessWorkingSetSizeEx(hProcess, dwMinimumWorkingSetSize, dwMaximumWorkingSetSize, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnmapViewOfFile)(LPCVOID lpBaseAddress) = UnmapViewOfFile;
static BOOL WINAPI hooked_UnmapViewOfFile(LPCVOID lpBaseAddress) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnmapViewOfFile(lpBaseAddress); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetSystemFileCacheSize)(SIZE_T MinimumFileCacheSize,  SIZE_T MaximumFileCacheSize,  DWORD Flags) = SetSystemFileCacheSize;
static BOOL WINAPI hooked_SetSystemFileCacheSize(SIZE_T MinimumFileCacheSize,  SIZE_T MaximumFileCacheSize,  DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetSystemFileCacheSize(MinimumFileCacheSize, MaximumFileCacheSize, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnregisterBadMemoryNotification)(PVOID RegistrationHandle) = UnregisterBadMemoryNotification;
static BOOL WINAPI hooked_UnregisterBadMemoryNotification(PVOID RegistrationHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnregisterBadMemoryNotification(RegistrationHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnmapViewOfFileEx)(PVOID BaseAddress,  ULONG UnmapFlags) = UnmapViewOfFileEx;
static BOOL WINAPI hooked_UnmapViewOfFileEx(PVOID BaseAddress,  ULONG UnmapFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnmapViewOfFileEx(BaseAddress, UnmapFlags); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_VirtualAlloc)(LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect) = VirtualAlloc;
static LPVOID WINAPI hooked_VirtualAlloc(LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_VirtualAlloc(lpAddress, dwSize, flAllocationType, flProtect); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_VirtualAlloc2)(HANDLE Process,  PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) = VirtualAlloc2;
static PVOID WINAPI hooked_VirtualAlloc2(HANDLE Process,  PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_VirtualAlloc2(Process, BaseAddress, Size, AllocationType, PageProtection, ExtendedParameters, ParameterCount); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_VirtualAllocEx)(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect) = VirtualAllocEx;
static LPVOID WINAPI hooked_VirtualAllocEx(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_VirtualAllocEx(hProcess, lpAddress, dwSize, flAllocationType, flProtect); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_VirtualAlloc2FromApp)(HANDLE Process,  PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) = VirtualAlloc2FromApp;
static PVOID WINAPI hooked_VirtualAlloc2FromApp(HANDLE Process,  PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG PageProtection,  MEM_EXTENDED_PARAMETER *ExtendedParameters,  ULONG ParameterCount) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_VirtualAlloc2FromApp(Process, BaseAddress, Size, AllocationType, PageProtection, ExtendedParameters, ParameterCount); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_VirtualAllocExNuma)(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect,  DWORD nndPreferred) = VirtualAllocExNuma;
static LPVOID WINAPI hooked_VirtualAllocExNuma(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flAllocationType,  DWORD flProtect,  DWORD nndPreferred) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_VirtualAllocExNuma(hProcess, lpAddress, dwSize, flAllocationType, flProtect, nndPreferred); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_VirtualAllocFromApp)(PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG Protection) = VirtualAllocFromApp;
static PVOID WINAPI hooked_VirtualAllocFromApp(PVOID BaseAddress,  SIZE_T Size,  ULONG AllocationType,  ULONG Protection) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_VirtualAllocFromApp(BaseAddress, Size, AllocationType, Protection); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualFree)(LPVOID lpAddress,  SIZE_T dwSize,  DWORD dwFreeType) = VirtualFree;
static BOOL WINAPI hooked_VirtualFree(LPVOID lpAddress,  SIZE_T dwSize,  DWORD dwFreeType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualFree(lpAddress, dwSize, dwFreeType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualFreeEx)(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD dwFreeType) = VirtualFreeEx;
static BOOL WINAPI hooked_VirtualFreeEx(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD dwFreeType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualFreeEx(hProcess, lpAddress, dwSize, dwFreeType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualLock)(LPVOID lpAddress,  SIZE_T dwSize) = VirtualLock;
static BOOL WINAPI hooked_VirtualLock(LPVOID lpAddress,  SIZE_T dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualLock(lpAddress, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualProtect)(LPVOID lpAddress,  SIZE_T dwSize,  DWORD flNewProtect,  PDWORD lpflOldProtect) = VirtualProtect;
static BOOL WINAPI hooked_VirtualProtect(LPVOID lpAddress,  SIZE_T dwSize,  DWORD flNewProtect,  PDWORD lpflOldProtect) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualProtect(lpAddress, dwSize, flNewProtect, lpflOldProtect); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualProtectEx)(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flNewProtect,  PDWORD lpflOldProtect) = VirtualProtectEx;
static BOOL WINAPI hooked_VirtualProtectEx(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  DWORD flNewProtect,  PDWORD lpflOldProtect) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualProtectEx(hProcess, lpAddress, dwSize, flNewProtect, lpflOldProtect); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualProtectFromApp)(PVOID Address,  SIZE_T Size,  ULONG NewProtection,  PULONG OldProtection) = VirtualProtectFromApp;
static BOOL WINAPI hooked_VirtualProtectFromApp(PVOID Address,  SIZE_T Size,  ULONG NewProtection,  PULONG OldProtection) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualProtectFromApp(Address, Size, NewProtection, OldProtection); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VirtualUnlock)(LPVOID lpAddress,  SIZE_T dwSize) = VirtualUnlock;
static BOOL WINAPI hooked_VirtualUnlock(LPVOID lpAddress,  SIZE_T dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VirtualUnlock(lpAddress, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_VirtualQueryEx)(HANDLE hProcess,  LPCVOID lpAddress,  PMEMORY_BASIC_INFORMATION lpBuffer,  SIZE_T dwLength) = VirtualQueryEx;
static SIZE_T WINAPI hooked_VirtualQueryEx(HANDLE hProcess,  LPCVOID lpAddress,  PMEMORY_BASIC_INFORMATION lpBuffer,  SIZE_T dwLength) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_VirtualQueryEx(hProcess, lpAddress, lpBuffer, dwLength); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_VirtualQuery)(LPCVOID lpAddress,  PMEMORY_BASIC_INFORMATION lpBuffer,  SIZE_T dwLength) = VirtualQuery;
static SIZE_T WINAPI hooked_VirtualQuery(LPCVOID lpAddress,  PMEMORY_BASIC_INFORMATION lpBuffer,  SIZE_T dwLength) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_VirtualQuery(lpAddress, lpBuffer, dwLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteProcessMemory)(HANDLE hProcess,  LPVOID lpBaseAddress,  LPCVOID lpBuffer,  SIZE_T nSize,  SIZE_T *lpNumberOfBytesWritten) = WriteProcessMemory;
static BOOL WINAPI hooked_WriteProcessMemory(HANDLE hProcess,  LPVOID lpBaseAddress,  LPCVOID lpBuffer,  SIZE_T nSize,  SIZE_T *lpNumberOfBytesWritten) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteProcessMemory(hProcess, lpBaseAddress, lpBuffer, nSize, lpNumberOfBytesWritten); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_EraseTape)(HANDLE hDevice,  DWORD dwEraseType,  BOOL bImmediate) = EraseTape;
static DWORD WINAPI hooked_EraseTape(HANDLE hDevice,  DWORD dwEraseType,  BOOL bImmediate) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_EraseTape(hDevice, dwEraseType, bImmediate); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceTypesW)(HMODULE hModule,  ENUMRESTYPEPROCW lpEnumFunc,  LONG_PTR lParam) = EnumResourceTypesW;
static BOOL WINAPI hooked_EnumResourceTypesW(HMODULE hModule,  ENUMRESTYPEPROCW lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceTypesW(hModule, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceLanguagesW)(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  ENUMRESLANGPROCW lpEnumFunc,  LONG_PTR lParam) = EnumResourceLanguagesW;
static BOOL WINAPI hooked_EnumResourceLanguagesW(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  ENUMRESLANGPROCW lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceLanguagesW(hModule, lpType, lpName, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EscapeCommFunction)(HANDLE hFile,  DWORD dwFunc) = EscapeCommFunction;
static BOOL WINAPI hooked_EscapeCommFunction(HANDLE hFile,  DWORD dwFunc) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EscapeCommFunction(hFile, dwFunc); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceTypesA)(HMODULE hModule,  ENUMRESTYPEPROCA lpEnumFunc,  LONG_PTR lParam) = EnumResourceTypesA;
static BOOL WINAPI hooked_EnumResourceTypesA(HMODULE hModule,  ENUMRESTYPEPROCA lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceTypesA(hModule, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ExecuteUmsThread)(PUMS_CONTEXT UmsThread) = ExecuteUmsThread;
static BOOL WINAPI hooked_ExecuteUmsThread(PUMS_CONTEXT UmsThread) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ExecuteUmsThread(UmsThread); });

	SEND_AFTER_CALL

    return result;
}

static __analysis_noreturn VOID (WINAPI *og_FatalExit)(int ExitCode) = FatalExit;
static __analysis_noreturn VOID WINAPI hooked_FatalExit(int ExitCode) {

	SEND_BEFORE_CALL

	
    TIME({ og_FatalExit(ExitCode); });

	SEND_AFTER_CALL
}

static BOOL (WINAPI *og_FileTimeToDosDateTime)(const FILETIME *lpFileTime,  LPWORD lpFatDate,  LPWORD lpFatTime) = FileTimeToDosDateTime;
static BOOL WINAPI hooked_FileTimeToDosDateTime(const FILETIME *lpFileTime,  LPWORD lpFatDate,  LPWORD lpFatTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FileTimeToDosDateTime(lpFileTime, lpFatDate, lpFatTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindActCtxSectionStringA)(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  LPCSTR lpStringToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) = FindActCtxSectionStringA;
static BOOL WINAPI hooked_FindActCtxSectionStringA(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  LPCSTR lpStringToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindActCtxSectionStringA(dwFlags, lpExtensionGuid, ulSectionId, lpStringToFind, ReturnedData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindActCtxSectionGuid)(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  const GUID *lpGuidToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) = FindActCtxSectionGuid;
static BOOL WINAPI hooked_FindActCtxSectionGuid(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  const GUID *lpGuidToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindActCtxSectionGuid(dwFlags, lpExtensionGuid, ulSectionId, lpGuidToFind, ReturnedData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindActCtxSectionStringW)(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  LPCWSTR lpStringToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) = FindActCtxSectionStringW;
static BOOL WINAPI hooked_FindActCtxSectionStringW(DWORD dwFlags,  const GUID *lpExtensionGuid,  ULONG ulSectionId,  LPCWSTR lpStringToFind,  PACTCTX_SECTION_KEYED_DATA ReturnedData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindActCtxSectionStringW(dwFlags, lpExtensionGuid, ulSectionId, lpStringToFind, ReturnedData); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_FindAtomA)(LPCSTR lpString) = FindAtomA;
static ATOM WINAPI hooked_FindAtomA(LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_FindAtomA(lpString); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_FindAtomW)(LPCWSTR lpString) = FindAtomW;
static ATOM WINAPI hooked_FindAtomW(LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_FindAtomW(lpString); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileTransactedA)(LPCSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags,  HANDLE hTransaction) = FindFirstFileTransactedA;
static HANDLE WINAPI hooked_FindFirstFileTransactedA(LPCSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileTransactedA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileNameTransactedW)(LPCWSTR lpFileName,  DWORD dwFlags,  LPDWORD StringLength,  PWSTR LinkName,  HANDLE hTransaction) = FindFirstFileNameTransactedW;
static HANDLE WINAPI hooked_FindFirstFileNameTransactedW(LPCWSTR lpFileName,  DWORD dwFlags,  LPDWORD StringLength,  PWSTR LinkName,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileNameTransactedW(lpFileName, dwFlags, StringLength, LinkName, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileTransactedW)(LPCWSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags,  HANDLE hTransaction) = FindFirstFileTransactedW;
static HANDLE WINAPI hooked_FindFirstFileTransactedW(LPCWSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileTransactedW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstStreamTransactedW)(LPCWSTR lpFileName,  STREAM_INFO_LEVELS InfoLevel,  LPVOID lpFindStreamData, DWORD dwFlags,  HANDLE hTransaction) = FindFirstStreamTransactedW;
static HANDLE WINAPI hooked_FindFirstStreamTransactedW(LPCWSTR lpFileName,  STREAM_INFO_LEVELS InfoLevel,  LPVOID lpFindStreamData, DWORD dwFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstStreamTransactedW(lpFileName, InfoLevel, lpFindStreamData, dwFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstVolumeA)(LPSTR lpszVolumeName,  DWORD cchBufferLength) = FindFirstVolumeA;
static HANDLE WINAPI hooked_FindFirstVolumeA(LPSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstVolumeA(lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstVolumeMountPointA)(LPCSTR lpszRootPathName,  LPSTR lpszVolumeMountPoint,  DWORD cchBufferLength) = FindFirstVolumeMountPointA;
static HANDLE WINAPI hooked_FindFirstVolumeMountPointA(LPCSTR lpszRootPathName,  LPSTR lpszVolumeMountPoint,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstVolumeMountPointA(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextVolumeA)(HANDLE hFindVolume,  LPSTR lpszVolumeName,  DWORD cchBufferLength) = FindNextVolumeA;
static BOOL WINAPI hooked_FindNextVolumeA(HANDLE hFindVolume,  LPSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextVolumeA(hFindVolume, lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextVolumeMountPointA)(HANDLE hFindVolumeMountPoint,  LPSTR lpszVolumeMountPoint,  DWORD cchBufferLength) = FindNextVolumeMountPointA;
static BOOL WINAPI hooked_FindNextVolumeMountPointA(HANDLE hFindVolumeMountPoint,  LPSTR lpszVolumeMountPoint,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextVolumeMountPointA(hFindVolumeMountPoint, lpszVolumeMountPoint, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstVolumeMountPointW)(LPCWSTR lpszRootPathName,  LPWSTR lpszVolumeMountPoint,  DWORD cchBufferLength) = FindFirstVolumeMountPointW;
static HANDLE WINAPI hooked_FindFirstVolumeMountPointW(LPCWSTR lpszRootPathName,  LPWSTR lpszVolumeMountPoint,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstVolumeMountPointW(lpszRootPathName, lpszVolumeMountPoint, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextVolumeMountPointW)(HANDLE hFindVolumeMountPoint,  LPWSTR lpszVolumeMountPoint,  DWORD cchBufferLength) = FindNextVolumeMountPointW;
static BOOL WINAPI hooked_FindNextVolumeMountPointW(HANDLE hFindVolumeMountPoint,  LPWSTR lpszVolumeMountPoint,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextVolumeMountPointW(hFindVolumeMountPoint, lpszVolumeMountPoint, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_FormatMessage)(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPTSTR lpBuffer,  DWORD nSize,  va_list *Arguments) = FormatMessage;
static DWORD WINAPI hooked_FormatMessage(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPTSTR lpBuffer,  DWORD nSize,  va_list *Arguments) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_FormatMessage(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments); });

	SEND_AFTER_CALL

    return result;
}

static HRSRC (WINAPI *og_FindResourceA)(HMODULE hModule,  LPCSTR lpName,  LPCSTR lpType) = FindResourceA;
static HRSRC WINAPI hooked_FindResourceA(HMODULE hModule,  LPCSTR lpName,  LPCSTR lpType) {

	SEND_BEFORE_CALL

	
    HRSRC result;
    TIME({ result = og_FindResourceA(hModule, lpName, lpType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindVolumeMountPointClose)(HANDLE hFindVolumeMountPoint) = FindVolumeMountPointClose;
static BOOL WINAPI hooked_FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindVolumeMountPointClose(hFindVolumeMountPoint); });

	SEND_AFTER_CALL

    return result;
}

static HRSRC (WINAPI *og_FindResourceExA)(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  WORD wLanguage) = FindResourceExA;
static HRSRC WINAPI hooked_FindResourceExA(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  WORD wLanguage) {

	SEND_BEFORE_CALL

	
    HRSRC result;
    TIME({ result = og_FindResourceExA(hModule, lpType, lpName, wLanguage); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_FormatMessageA)(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPSTR lpBuffer,  DWORD nSize,  va_list *Arguments) = FormatMessageA;
static DWORD WINAPI hooked_FormatMessageA(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPSTR lpBuffer,  DWORD nSize,  va_list *Arguments) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_FormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_FormatMessageW)(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPWSTR lpBuffer,  DWORD nSize,  va_list *Arguments) = FormatMessageW;
static DWORD WINAPI hooked_FormatMessageW(DWORD dwFlags,  LPCVOID lpSource,  DWORD dwMessageId,  DWORD dwLanguageId,  LPWSTR lpBuffer,  DWORD nSize,  va_list *Arguments) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_FormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, Arguments); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetActiveProcessorCount)(WORD GroupNumber) = GetActiveProcessorCount;
static DWORD WINAPI hooked_GetActiveProcessorCount(WORD GroupNumber) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetActiveProcessorCount(GroupNumber); });

	SEND_AFTER_CALL

    return result;
}

static WORD (WINAPI *og_GetActiveProcessorGroupCount)() = GetActiveProcessorGroupCount;
static WORD WINAPI hooked_GetActiveProcessorGroupCount() {

	SEND_BEFORE_CALL

	
    WORD result;
    TIME({ result = og_GetActiveProcessorGroupCount(); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetApplicationRecoveryCallback)(HANDLE hProcess,  APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback,  PVOID *ppvParameter,  PDWORD pdwPingInterval,  PDWORD pdwFlags) = GetApplicationRecoveryCallback;
static HRESULT WINAPI hooked_GetApplicationRecoveryCallback(HANDLE hProcess,  APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback,  PVOID *ppvParameter,  PDWORD pdwPingInterval,  PDWORD pdwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetApplicationRecoveryCallback(hProcess, pRecoveryCallback, ppvParameter, pdwPingInterval, pdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetApplicationRestartSettings)(HANDLE hProcess,  PWSTR pwzCommandline,  PDWORD pcchSize,  PDWORD pdwFlags) = GetApplicationRestartSettings;
static HRESULT WINAPI hooked_GetApplicationRestartSettings(HANDLE hProcess,  PWSTR pwzCommandline,  PDWORD pcchSize,  PDWORD pdwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetApplicationRestartSettings(hProcess, pwzCommandline, pcchSize, pdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetAtomNameA)(ATOM nAtom,  LPSTR lpBuffer,  int nSize) = GetAtomNameA;
static UINT WINAPI hooked_GetAtomNameA(ATOM nAtom,  LPSTR lpBuffer,  int nSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetAtomNameA(nAtom, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetAtomNameW)(ATOM nAtom,  LPWSTR lpBuffer,  int nSize) = GetAtomNameW;
static UINT WINAPI hooked_GetAtomNameW(ATOM nAtom,  LPWSTR lpBuffer,  int nSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetAtomNameW(nAtom, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetBinaryTypeA)(LPCSTR lpApplicationName,  LPDWORD lpBinaryType) = GetBinaryTypeA;
static BOOL WINAPI hooked_GetBinaryTypeA(LPCSTR lpApplicationName,  LPDWORD lpBinaryType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetBinaryTypeA(lpApplicationName, lpBinaryType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommConfig)(HANDLE hCommDev,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) = GetCommConfig;
static BOOL WINAPI hooked_GetCommConfig(HANDLE hCommDev,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommConfig(hCommDev, lpCC, lpdwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetBinaryTypeW)(LPCWSTR lpApplicationName,  LPDWORD lpBinaryType) = GetBinaryTypeW;
static BOOL WINAPI hooked_GetBinaryTypeW(LPCWSTR lpApplicationName,  LPDWORD lpBinaryType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetBinaryTypeW(lpApplicationName, lpBinaryType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommMask)(HANDLE hFile,  LPDWORD lpEvtMask) = GetCommMask;
static BOOL WINAPI hooked_GetCommMask(HANDLE hFile,  LPDWORD lpEvtMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommMask(hFile, lpEvtMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommModemStatus)(HANDLE hFile,  LPDWORD lpModemStat) = GetCommModemStatus;
static BOOL WINAPI hooked_GetCommModemStatus(HANDLE hFile,  LPDWORD lpModemStat) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommModemStatus(hFile, lpModemStat); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommProperties)(HANDLE hFile,  LPCOMMPROP lpCommProp) = GetCommProperties;
static BOOL WINAPI hooked_GetCommProperties(HANDLE hFile,  LPCOMMPROP lpCommProp) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommProperties(hFile, lpCommProp); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommState)(HANDLE hFile,  LPDCB lpDCB) = GetCommState;
static BOOL WINAPI hooked_GetCommState(HANDLE hFile,  LPDCB lpDCB) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommState(hFile, lpDCB); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCommTimeouts)(HANDLE hFile,  LPCOMMTIMEOUTS lpCommTimeouts) = GetCommTimeouts;
static BOOL WINAPI hooked_GetCommTimeouts(HANDLE hFile,  LPCOMMTIMEOUTS lpCommTimeouts) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCommTimeouts(hFile, lpCommTimeouts); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCompressedFileSizeTransactedA)(LPCSTR lpFileName,  LPDWORD lpFileSizeHigh,  HANDLE hTransaction) = GetCompressedFileSizeTransactedA;
static DWORD WINAPI hooked_GetCompressedFileSizeTransactedA(LPCSTR lpFileName,  LPDWORD lpFileSizeHigh,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCompressedFileSizeTransactedA(lpFileName, lpFileSizeHigh, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCompressedFileSizeTransactedW)(LPCWSTR lpFileName,  LPDWORD lpFileSizeHigh,  HANDLE hTransaction) = GetCompressedFileSizeTransactedW;
static DWORD WINAPI hooked_GetCompressedFileSizeTransactedW(LPCWSTR lpFileName,  LPDWORD lpFileSizeHigh,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCompressedFileSizeTransactedW(lpFileName, lpFileSizeHigh, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetComputerNameA)(LPSTR lpBuffer,  LPDWORD nSize) = GetComputerNameA;
static BOOL WINAPI hooked_GetComputerNameA(LPSTR lpBuffer,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetComputerNameA(lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetComputerNameW)(LPWSTR lpBuffer,  LPDWORD nSize) = GetComputerNameW;
static BOOL WINAPI hooked_GetComputerNameW(LPWSTR lpBuffer,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetComputerNameW(lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCurrentActCtx)(HANDLE *lphActCtx) = GetCurrentActCtx;
static BOOL WINAPI hooked_GetCurrentActCtx(HANDLE *lphActCtx) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCurrentActCtx(lphActCtx); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCurrentDirectory)(DWORD nBufferLength,  LPTSTR lpBuffer) = GetCurrentDirectory;
static DWORD WINAPI hooked_GetCurrentDirectory(DWORD nBufferLength,  LPTSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCurrentDirectory(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDefaultCommConfigA)(LPCSTR lpszName,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) = GetDefaultCommConfigA;
static BOOL WINAPI hooked_GetDefaultCommConfigA(LPCSTR lpszName,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDefaultCommConfigA(lpszName, lpCC, lpdwSize); });

	SEND_AFTER_CALL

    return result;
}

static PUMS_CONTEXT (WINAPI *og_GetCurrentUmsThread)() = GetCurrentUmsThread;
static PUMS_CONTEXT WINAPI hooked_GetCurrentUmsThread() {

	SEND_BEFORE_CALL

	
    PUMS_CONTEXT result;
    TIME({ result = og_GetCurrentUmsThread(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDefaultCommConfigW)(LPCWSTR lpszName,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) = GetDefaultCommConfigW;
static BOOL WINAPI hooked_GetDefaultCommConfigW(LPCWSTR lpszName,  LPCOMMCONFIG lpCC,  LPDWORD lpdwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDefaultCommConfigW(lpszName, lpCC, lpdwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDevicePowerState)(HANDLE hDevice,  BOOL *pfOn) = GetDevicePowerState;
static BOOL WINAPI hooked_GetDevicePowerState(HANDLE hDevice,  BOOL *pfOn) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDevicePowerState(hDevice, pfOn); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDllDirectoryA)(DWORD nBufferLength,  LPSTR lpBuffer) = GetDllDirectoryA;
static DWORD WINAPI hooked_GetDllDirectoryA(DWORD nBufferLength,  LPSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDllDirectoryA(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDllDirectoryW)(DWORD nBufferLength,  LPWSTR lpBuffer) = GetDllDirectoryW;
static DWORD WINAPI hooked_GetDllDirectoryW(DWORD nBufferLength,  LPWSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDllDirectoryW(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD64 (WINAPI *og_GetEnabledXStateFeatures)() = GetEnabledXStateFeatures;
static DWORD64 WINAPI hooked_GetEnabledXStateFeatures() {

	SEND_BEFORE_CALL

	
    DWORD64 result;
    TIME({ result = og_GetEnabledXStateFeatures(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetEnvironmentVariable)(LPCTSTR lpName,  LPTSTR lpBuffer,  DWORD nSize) = GetEnvironmentVariable;
static DWORD WINAPI hooked_GetEnvironmentVariable(LPCTSTR lpName,  LPTSTR lpBuffer,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetEnvironmentVariable(lpName, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileAttributesTransactedA)(LPCSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation,  HANDLE hTransaction) = GetFileAttributesTransactedA;
static BOOL WINAPI hooked_GetFileAttributesTransactedA(LPCSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileAttributesTransactedA(lpFileName, fInfoLevelId, lpFileInformation, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileAttributesTransactedW)(LPCWSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation,  HANDLE hTransaction) = GetFileAttributesTransactedW;
static BOOL WINAPI hooked_GetFileAttributesTransactedW(LPCWSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileAttributesTransactedW(lpFileName, fInfoLevelId, lpFileInformation, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileBandwidthReservation)(HANDLE hFile,  LPDWORD lpPeriodMilliseconds,  LPDWORD lpBytesPerPeriod,  LPBOOL pDiscardable,  LPDWORD lpTransferSize,  LPDWORD lpNumOutstandingRequests) = GetFileBandwidthReservation;
static BOOL WINAPI hooked_GetFileBandwidthReservation(HANDLE hFile,  LPDWORD lpPeriodMilliseconds,  LPDWORD lpBytesPerPeriod,  LPBOOL pDiscardable,  LPDWORD lpTransferSize,  LPDWORD lpNumOutstandingRequests) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileBandwidthReservation(hFile, lpPeriodMilliseconds, lpBytesPerPeriod, pDiscardable, lpTransferSize, lpNumOutstandingRequests); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileInformationByHandleEx)(HANDLE hFile,  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,  LPVOID lpFileInformation,  DWORD dwBufferSize) = GetFileInformationByHandleEx;
static BOOL WINAPI hooked_GetFileInformationByHandleEx(HANDLE hFile,  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,  LPVOID lpFileInformation,  DWORD dwBufferSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileInformationByHandleEx(hFile, FileInformationClass, lpFileInformation, dwBufferSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileInformationByName)(PCWSTR FileName, FILE_INFO_BY_NAME_CLASS FileInformationClass, PVOID FileInfoBuffer, ULONG FileInfoBufferSize) = GetFileInformationByName;
static BOOL WINAPI hooked_GetFileInformationByName(PCWSTR FileName, FILE_INFO_BY_NAME_CLASS FileInformationClass, PVOID FileInfoBuffer, ULONG FileInfoBufferSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileInformationByName(FileName, FileInformationClass, FileInfoBuffer, FileInfoBufferSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFirmwareEnvironmentVariableA)(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pBuffer,  DWORD nSize) = GetFirmwareEnvironmentVariableA;
static DWORD WINAPI hooked_GetFirmwareEnvironmentVariableA(LPCSTR lpName,  LPCSTR lpGuid,  PVOID pBuffer,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFirmwareEnvironmentVariableA(lpName, lpGuid, pBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFirmwareEnvironmentVariableExA)(LPCSTR lpName, LPCSTR lpGuid, PVOID pBuffer, DWORD nSize, PDWORD pdwAttribubutes) = GetFirmwareEnvironmentVariableExA;
static DWORD WINAPI hooked_GetFirmwareEnvironmentVariableExA(LPCSTR lpName, LPCSTR lpGuid, PVOID pBuffer, DWORD nSize, PDWORD pdwAttribubutes) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFirmwareEnvironmentVariableExA(lpName, lpGuid, pBuffer, nSize, pdwAttribubutes); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFirmwareEnvironmentVariableExW)(LPCWSTR lpName, LPCWSTR lpGuid, PVOID pBuffer, DWORD nSize, PDWORD pdwAttribubutes) = GetFirmwareEnvironmentVariableExW;
static DWORD WINAPI hooked_GetFirmwareEnvironmentVariableExW(LPCWSTR lpName, LPCWSTR lpGuid, PVOID pBuffer, DWORD nSize, PDWORD pdwAttribubutes) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFirmwareEnvironmentVariableExW(lpName, lpGuid, pBuffer, nSize, pdwAttribubutes); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFirmwareEnvironmentVariableW)(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pBuffer,  DWORD nSize) = GetFirmwareEnvironmentVariableW;
static DWORD WINAPI hooked_GetFirmwareEnvironmentVariableW(LPCWSTR lpName,  LPCWSTR lpGuid,  PVOID pBuffer,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFirmwareEnvironmentVariableW(lpName, lpGuid, pBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFirmwareType)(PFIRMWARE_TYPE FirmwareType) = GetFirmwareType;
static BOOL WINAPI hooked_GetFirmwareType(PFIRMWARE_TYPE FirmwareType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFirmwareType(FirmwareType); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFullPathNameTransactedA)(LPCSTR lpFileName,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart,  HANDLE hTransaction) = GetFullPathNameTransactedA;
static DWORD WINAPI hooked_GetFullPathNameTransactedA(LPCSTR lpFileName,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFullPathNameTransactedA(lpFileName, nBufferLength, lpBuffer, lpFilePart, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFullPathNameTransactedW)(LPCWSTR lpFileName,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart,  HANDLE hTransaction) = GetFullPathNameTransactedW;
static DWORD WINAPI hooked_GetFullPathNameTransactedW(LPCWSTR lpFileName,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFullPathNameTransactedW(lpFileName, nBufferLength, lpBuffer, lpFilePart, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLogicalDriveStringsA)(DWORD nBufferLength,  LPSTR lpBuffer) = GetLogicalDriveStringsA;
static DWORD WINAPI hooked_GetLogicalDriveStringsA(DWORD nBufferLength,  LPSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLogicalDriveStringsA(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLongPathNameTransactedA)(LPCSTR lpszShortPath,  LPSTR lpszLongPath,  DWORD cchBuffer,  HANDLE hTransaction) = GetLongPathNameTransactedA;
static DWORD WINAPI hooked_GetLongPathNameTransactedA(LPCSTR lpszShortPath,  LPSTR lpszLongPath,  DWORD cchBuffer,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLongPathNameTransactedA(lpszShortPath, lpszLongPath, cchBuffer, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLongPathNameTransactedW)(LPCWSTR lpszShortPath,  LPWSTR lpszLongPath,  DWORD cchBuffer,  HANDLE hTransaction) = GetLongPathNameTransactedW;
static DWORD WINAPI hooked_GetLongPathNameTransactedW(LPCWSTR lpszShortPath,  LPWSTR lpszLongPath,  DWORD cchBuffer,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLongPathNameTransactedW(lpszShortPath, lpszLongPath, cchBuffer, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetMailslotInfo)(HANDLE hMailslot,  LPDWORD lpMaxMessageSize,  LPDWORD lpNextSize,  LPDWORD lpMessageCount,  LPDWORD lpReadTimeout) = GetMailslotInfo;
static BOOL WINAPI hooked_GetMailslotInfo(HANDLE hMailslot,  LPDWORD lpMaxMessageSize,  LPDWORD lpNextSize,  LPDWORD lpMessageCount,  LPDWORD lpReadTimeout) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetMaximumProcessorCount)(WORD GroupNumber) = GetMaximumProcessorCount;
static DWORD WINAPI hooked_GetMaximumProcessorCount(WORD GroupNumber) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetMaximumProcessorCount(GroupNumber); });

	SEND_AFTER_CALL

    return result;
}

static WORD (WINAPI *og_GetMaximumProcessorGroupCount)() = GetMaximumProcessorGroupCount;
static WORD WINAPI hooked_GetMaximumProcessorGroupCount() {

	SEND_BEFORE_CALL

	
    WORD result;
    TIME({ result = og_GetMaximumProcessorGroupCount(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeClientComputerNameA)(HANDLE Pipe,  LPSTR ClientComputerName,  ULONG ClientComputerNameLength) = GetNamedPipeClientComputerNameA;
static BOOL WINAPI hooked_GetNamedPipeClientComputerNameA(HANDLE Pipe,  LPSTR ClientComputerName,  ULONG ClientComputerNameLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeClientComputerNameA(Pipe, ClientComputerName, ClientComputerNameLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeClientProcessId)(HANDLE Pipe,  PULONG ClientProcessId) = GetNamedPipeClientProcessId;
static BOOL WINAPI hooked_GetNamedPipeClientProcessId(HANDLE Pipe,  PULONG ClientProcessId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeClientProcessId(Pipe, ClientProcessId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeClientSessionId)(HANDLE Pipe,  PULONG ClientSessionId) = GetNamedPipeClientSessionId;
static BOOL WINAPI hooked_GetNamedPipeClientSessionId(HANDLE Pipe,  PULONG ClientSessionId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeClientSessionId(Pipe, ClientSessionId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeHandleStateA)(HANDLE hNamedPipe,  LPDWORD lpState,  LPDWORD lpCurInstances,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout,  LPSTR lpUserName,  DWORD nMaxUserNameSize) = GetNamedPipeHandleStateA;
static BOOL WINAPI hooked_GetNamedPipeHandleStateA(HANDLE hNamedPipe,  LPDWORD lpState,  LPDWORD lpCurInstances,  LPDWORD lpMaxCollectionCount,  LPDWORD lpCollectDataTimeout,  LPSTR lpUserName,  DWORD nMaxUserNameSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUserName, nMaxUserNameSize); });

	SEND_AFTER_CALL

    return result;
}

static PUMS_CONTEXT (WINAPI *og_GetNextUmsListItem)(PUMS_CONTEXT UmsContext) = GetNextUmsListItem;
static PUMS_CONTEXT WINAPI hooked_GetNextUmsListItem(PUMS_CONTEXT UmsContext) {

	SEND_BEFORE_CALL

	
    PUMS_CONTEXT result;
    TIME({ result = og_GetNextUmsListItem(UmsContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeServerSessionId)(HANDLE Pipe,  PULONG ServerSessionId) = GetNamedPipeServerSessionId;
static BOOL WINAPI hooked_GetNamedPipeServerSessionId(HANDLE Pipe,  PULONG ServerSessionId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeServerSessionId(Pipe, ServerSessionId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNamedPipeServerProcessId)(HANDLE Pipe,  PULONG ServerProcessId) = GetNamedPipeServerProcessId;
static BOOL WINAPI hooked_GetNamedPipeServerProcessId(HANDLE Pipe,  PULONG ServerProcessId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNamedPipeServerProcessId(Pipe, ServerProcessId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaAvailableMemoryNode)(UCHAR Node,  PULONGLONG AvailableBytes) = GetNumaAvailableMemoryNode;
static BOOL WINAPI hooked_GetNumaAvailableMemoryNode(UCHAR Node,  PULONGLONG AvailableBytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaAvailableMemoryNode(Node, AvailableBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaAvailableMemoryNodeEx)(USHORT Node,  PULONGLONG AvailableBytes) = GetNumaAvailableMemoryNodeEx;
static BOOL WINAPI hooked_GetNumaAvailableMemoryNodeEx(USHORT Node,  PULONGLONG AvailableBytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaAvailableMemoryNodeEx(Node, AvailableBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaNodeNumberFromHandle)(HANDLE hFile,  PUSHORT NodeNumber) = GetNumaNodeNumberFromHandle;
static BOOL WINAPI hooked_GetNumaNodeNumberFromHandle(HANDLE hFile,  PUSHORT NodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaNodeNumberFromHandle(hFile, NodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaProcessorNode)(UCHAR Processor,  PUCHAR NodeNumber) = GetNumaProcessorNode;
static BOOL WINAPI hooked_GetNumaProcessorNode(UCHAR Processor,  PUCHAR NodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaProcessorNode(Processor, NodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaNodeProcessorMask)(UCHAR Node,  PULONGLONG ProcessorMask) = GetNumaNodeProcessorMask;
static BOOL WINAPI hooked_GetNumaNodeProcessorMask(UCHAR Node,  PULONGLONG ProcessorMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaNodeProcessorMask(Node, ProcessorMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaProcessorNodeEx)(PPROCESSOR_NUMBER Processor,  PUSHORT NodeNumber) = GetNumaProcessorNodeEx;
static BOOL WINAPI hooked_GetNumaProcessorNodeEx(PPROCESSOR_NUMBER Processor,  PUSHORT NodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaProcessorNodeEx(Processor, NodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaProximityNode)(ULONG ProximityId,  PUCHAR NodeNumber) = GetNumaProximityNode;
static BOOL WINAPI hooked_GetNumaProximityNode(ULONG ProximityId,  PUCHAR NodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaProximityNode(ProximityId, NodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetPrivateProfileInt)(LPCTSTR lpAppName,  LPCTSTR lpKeyName,  INT nDefault,  LPCTSTR lpFileName) = GetPrivateProfileInt;
static UINT WINAPI hooked_GetPrivateProfileInt(LPCTSTR lpAppName,  LPCTSTR lpKeyName,  INT nDefault,  LPCTSTR lpFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetPrivateProfileInt(lpAppName, lpKeyName, nDefault, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetPrivateProfileIntA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  INT nDefault,  LPCSTR lpFileName) = GetPrivateProfileIntA;
static UINT WINAPI hooked_GetPrivateProfileIntA(LPCSTR lpAppName,  LPCSTR lpKeyName,  INT nDefault,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetPrivateProfileIntA(lpAppName, lpKeyName, nDefault, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetPrivateProfileIntW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  INT nDefault,  LPCWSTR lpFileName) = GetPrivateProfileIntW;
static UINT WINAPI hooked_GetPrivateProfileIntW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  INT nDefault,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetPrivateProfileIntW(lpAppName, lpKeyName, nDefault, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSection)(LPCTSTR lpAppName,  LPTSTR lpReturnedString,  DWORD nSize,  LPCTSTR lpFileName) = GetPrivateProfileSection;
static DWORD WINAPI hooked_GetPrivateProfileSection(LPCTSTR lpAppName,  LPTSTR lpReturnedString,  DWORD nSize,  LPCTSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSection(lpAppName, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSectionNames)(LPTSTR lpszReturnBuffer,  DWORD nSize,  LPCTSTR lpFileName) = GetPrivateProfileSectionNames;
static DWORD WINAPI hooked_GetPrivateProfileSectionNames(LPTSTR lpszReturnBuffer,  DWORD nSize,  LPCTSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSectionNames(lpszReturnBuffer, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSectionA)(LPCSTR lpAppName,  LPSTR lpReturnedString,  DWORD nSize,  LPCSTR lpFileName) = GetPrivateProfileSectionA;
static DWORD WINAPI hooked_GetPrivateProfileSectionA(LPCSTR lpAppName,  LPSTR lpReturnedString,  DWORD nSize,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSectionA(lpAppName, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSectionNamesA)(LPSTR lpszReturnBuffer,  DWORD nSize,  LPCSTR lpFileName) = GetPrivateProfileSectionNamesA;
static DWORD WINAPI hooked_GetPrivateProfileSectionNamesA(LPSTR lpszReturnBuffer,  DWORD nSize,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSectionNamesA(lpszReturnBuffer, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSectionNamesW)(LPWSTR lpszReturnBuffer,  DWORD nSize,  LPCWSTR lpFileName) = GetPrivateProfileSectionNamesW;
static DWORD WINAPI hooked_GetPrivateProfileSectionNamesW(LPWSTR lpszReturnBuffer,  DWORD nSize,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSectionNamesW(lpszReturnBuffer, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileSectionW)(LPCWSTR lpAppName,  LPWSTR lpReturnedString,  DWORD nSize,  LPCWSTR lpFileName) = GetPrivateProfileSectionW;
static DWORD WINAPI hooked_GetPrivateProfileSectionW(LPCWSTR lpAppName,  LPWSTR lpReturnedString,  DWORD nSize,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileSectionW(lpAppName, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileString)(LPCTSTR lpAppName,  LPCTSTR lpKeyName,  LPCTSTR lpDefault,  LPTSTR lpReturnedString,  DWORD nSize,  LPCTSTR lpFileName) = GetPrivateProfileString;
static DWORD WINAPI hooked_GetPrivateProfileString(LPCTSTR lpAppName,  LPCTSTR lpKeyName,  LPCTSTR lpDefault,  LPTSTR lpReturnedString,  DWORD nSize,  LPCTSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileString(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileStringA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpDefault,  LPSTR lpReturnedString,  DWORD nSize,  LPCSTR lpFileName) = GetPrivateProfileStringA;
static DWORD WINAPI hooked_GetPrivateProfileStringA(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpDefault,  LPSTR lpReturnedString,  DWORD nSize,  LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetPrivateProfileStringW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpDefault,  LPWSTR lpReturnedString,  DWORD nSize,  LPCWSTR lpFileName) = GetPrivateProfileStringW;
static DWORD WINAPI hooked_GetPrivateProfileStringW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpDefault,  LPWSTR lpReturnedString,  DWORD nSize,  LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetPrivateProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize, lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetPrivateProfileStruct)(LPCTSTR lpszSection,  LPCTSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCTSTR szFile) = GetPrivateProfileStruct;
static BOOL WINAPI hooked_GetPrivateProfileStruct(LPCTSTR lpszSection,  LPCTSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCTSTR szFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetPrivateProfileStruct(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetPrivateProfileStructA)(LPCSTR lpszSection,  LPCSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCSTR szFile) = GetPrivateProfileStructA;
static BOOL WINAPI hooked_GetPrivateProfileStructA(LPCSTR lpszSection,  LPCSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCSTR szFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetPrivateProfileStructA(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetPrivateProfileStructW)(LPCWSTR lpszSection,  LPCWSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCWSTR szFile) = GetPrivateProfileStructW;
static BOOL WINAPI hooked_GetPrivateProfileStructW(LPCWSTR lpszSection,  LPCWSTR lpszKey,  LPVOID lpStruct,  UINT uSizeStruct,  LPCWSTR szFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetPrivateProfileStructW(lpszSection, lpszKey, lpStruct, uSizeStruct, szFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessAffinityMask)(HANDLE hProcess,  PDWORD_PTR lpProcessAffinityMask,  PDWORD_PTR lpSystemAffinityMask) = GetProcessAffinityMask;
static BOOL WINAPI hooked_GetProcessAffinityMask(HANDLE hProcess,  PDWORD_PTR lpProcessAffinityMask,  PDWORD_PTR lpSystemAffinityMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessAffinityMask(hProcess, lpProcessAffinityMask, lpSystemAffinityMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessDEPPolicy)(HANDLE hProcess,  LPDWORD lpFlags,  PBOOL lpPermanent) = GetProcessDEPPolicy;
static BOOL WINAPI hooked_GetProcessDEPPolicy(HANDLE hProcess,  LPDWORD lpFlags,  PBOOL lpPermanent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessDEPPolicy(hProcess, lpFlags, lpPermanent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessIoCounters)(HANDLE hProcess,  PIO_COUNTERS lpIoCounters) = GetProcessIoCounters;
static BOOL WINAPI hooked_GetProcessIoCounters(HANDLE hProcess,  PIO_COUNTERS lpIoCounters) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessIoCounters(hProcess, lpIoCounters); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetProfileIntA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  INT nDefault) = GetProfileIntA;
static UINT WINAPI hooked_GetProfileIntA(LPCSTR lpAppName,  LPCSTR lpKeyName,  INT nDefault) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetProfileIntA(lpAppName, lpKeyName, nDefault); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetProfileIntW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  INT nDefault) = GetProfileIntW;
static UINT WINAPI hooked_GetProfileIntW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  INT nDefault) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetProfileIntW(lpAppName, lpKeyName, nDefault); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProfileSectionA)(LPCSTR lpAppName,  LPSTR lpReturnedString,  DWORD nSize) = GetProfileSectionA;
static DWORD WINAPI hooked_GetProfileSectionA(LPCSTR lpAppName,  LPSTR lpReturnedString,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProfileSectionA(lpAppName, lpReturnedString, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProfileSectionW)(LPCWSTR lpAppName,  LPWSTR lpReturnedString,  DWORD nSize) = GetProfileSectionW;
static DWORD WINAPI hooked_GetProfileSectionW(LPCWSTR lpAppName,  LPWSTR lpReturnedString,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProfileSectionW(lpAppName, lpReturnedString, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProfileStringA)(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpDefault,  LPSTR lpReturnedString,  DWORD nSize) = GetProfileStringA;
static DWORD WINAPI hooked_GetProfileStringA(LPCSTR lpAppName,  LPCSTR lpKeyName,  LPCSTR lpDefault,  LPSTR lpReturnedString,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProfileStringA(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetShortPathNameA)(LPCSTR lpszLongPath,  LPSTR lpszShortPath,  DWORD cchBuffer) = GetShortPathNameA;
static DWORD WINAPI hooked_GetShortPathNameA(LPCSTR lpszLongPath,  LPSTR lpszShortPath,  DWORD cchBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetShortPathNameA(lpszLongPath, lpszShortPath, cchBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProfileStringW)(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpDefault,  LPWSTR lpReturnedString,  DWORD nSize) = GetProfileStringW;
static DWORD WINAPI hooked_GetProfileStringW(LPCWSTR lpAppName,  LPCWSTR lpKeyName,  LPCWSTR lpDefault,  LPWSTR lpReturnedString,  DWORD nSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProfileStringW(lpAppName, lpKeyName, lpDefault, lpReturnedString, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetSystemPowerStatus)(LPSYSTEM_POWER_STATUS lpSystemPowerStatus) = GetSystemPowerStatus;
static BOOL WINAPI hooked_GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemPowerStatus(lpSystemPowerStatus); });

	SEND_AFTER_CALL

    return result;
}

static DEP_SYSTEM_POLICY_TYPE (WINAPI *og_GetSystemDEPPolicy)() = GetSystemDEPPolicy;
static DEP_SYSTEM_POLICY_TYPE WINAPI hooked_GetSystemDEPPolicy() {

	SEND_BEFORE_CALL

	
    DEP_SYSTEM_POLICY_TYPE result;
    TIME({ result = og_GetSystemDEPPolicy(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetSystemRegistryQuota)(PDWORD pdwQuotaAllowed,  PDWORD pdwQuotaUsed) = GetSystemRegistryQuota;
static BOOL WINAPI hooked_GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,  PDWORD pdwQuotaUsed) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemRegistryQuota(pdwQuotaAllowed, pdwQuotaUsed); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTapeParameters)(HANDLE hDevice,  DWORD dwOperation,  LPDWORD lpdwSize,  LPVOID lpTapeInformation) = GetTapeParameters;
static DWORD WINAPI hooked_GetTapeParameters(HANDLE hDevice,  DWORD dwOperation,  LPDWORD lpdwSize,  LPVOID lpTapeInformation) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTapeParameters(hDevice, dwOperation, lpdwSize, lpTapeInformation); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTapePosition)(HANDLE hDevice,  DWORD dwPositionType,  LPDWORD lpdwPartition,  LPDWORD lpdwOffsetLow,  LPDWORD lpdwOffsetHigh) = GetTapePosition;
static DWORD WINAPI hooked_GetTapePosition(HANDLE hDevice,  DWORD dwPositionType,  LPDWORD lpdwPartition,  LPDWORD lpdwOffsetLow,  LPDWORD lpdwOffsetHigh) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTapePosition(hDevice, dwPositionType, lpdwPartition, lpdwOffsetLow, lpdwOffsetHigh); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTapeStatus)(HANDLE hDevice) = GetTapeStatus;
static DWORD WINAPI hooked_GetTapeStatus(HANDLE hDevice) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTapeStatus(hDevice); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetTempFileName)(LPCTSTR lpPathName,  LPCTSTR lpPrefixString,  UINT uUnique,  LPTSTR lpTempFileName) = GetTempFileName;
static UINT WINAPI hooked_GetTempFileName(LPCTSTR lpPathName,  LPCTSTR lpPrefixString,  UINT uUnique,  LPTSTR lpTempFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetTempFileName(lpPathName, lpPrefixString, uUnique, lpTempFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadSelectorEntry)(HANDLE hThread,  DWORD dwSelector,  LPLDT_ENTRY lpSelectorEntry) = GetThreadSelectorEntry;
static BOOL WINAPI hooked_GetThreadSelectorEntry(HANDLE hThread,  DWORD dwSelector,  LPLDT_ENTRY lpSelectorEntry) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadSelectorEntry(hThread, dwSelector, lpSelectorEntry); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetUmsSystemThreadInformation)(HANDLE ThreadHandle,  PUMS_SYSTEM_THREAD_INFORMATION SystemThreadInfo) = GetUmsSystemThreadInformation;
static BOOL WINAPI hooked_GetUmsSystemThreadInformation(HANDLE ThreadHandle,  PUMS_SYSTEM_THREAD_INFORMATION SystemThreadInfo) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetUmsSystemThreadInformation(ThreadHandle, SystemThreadInfo); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetUmsCompletionListEvent)(PUMS_COMPLETION_LIST UmsCompletionList,  PHANDLE UmsCompletionEvent) = GetUmsCompletionListEvent;
static BOOL WINAPI hooked_GetUmsCompletionListEvent(PUMS_COMPLETION_LIST UmsCompletionList,  PHANDLE UmsCompletionEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetUmsCompletionListEvent(UmsCompletionList, UmsCompletionEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumeNameForVolumeMountPointA)(LPCSTR lpszVolumeMountPoint,  LPSTR lpszVolumeName,  DWORD cchBufferLength) = GetVolumeNameForVolumeMountPointA;
static BOOL WINAPI hooked_GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,  LPSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumeNameForVolumeMountPointA(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetXStateFeaturesMask)(PCONTEXT Context,  PDWORD64 FeatureMask) = GetXStateFeaturesMask;
static BOOL WINAPI hooked_GetXStateFeaturesMask(PCONTEXT Context,  PDWORD64 FeatureMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetXStateFeaturesMask(Context, FeatureMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumePathNamesForVolumeNameA)(LPCSTR lpszVolumeName,  LPCH lpszVolumePathNames,  DWORD cchBufferLength,  PDWORD lpcchReturnLength) = GetVolumePathNamesForVolumeNameA;
static BOOL WINAPI hooked_GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,  LPCH lpszVolumePathNames,  DWORD cchBufferLength,  PDWORD lpcchReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumePathNamesForVolumeNameA(lpszVolumeName, lpszVolumePathNames, cchBufferLength, lpcchReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalAddAtomA)(LPCSTR lpString) = GlobalAddAtomA;
static ATOM WINAPI hooked_GlobalAddAtomA(LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalAddAtomA(lpString); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalAddAtomExA)(LPCSTR lpString,  DWORD Flags) = GlobalAddAtomExA;
static ATOM WINAPI hooked_GlobalAddAtomExA(LPCSTR lpString,  DWORD Flags) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalAddAtomExA(lpString, Flags); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalAddAtomExW)(LPCWSTR lpString,  DWORD Flags) = GlobalAddAtomExW;
static ATOM WINAPI hooked_GlobalAddAtomExW(LPCWSTR lpString,  DWORD Flags) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalAddAtomExW(lpString, Flags); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalAddAtomW)(LPCWSTR lpString) = GlobalAddAtomW;
static ATOM WINAPI hooked_GlobalAddAtomW(LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalAddAtomW(lpString); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalFindAtomA)(LPCSTR lpString) = GlobalFindAtomA;
static ATOM WINAPI hooked_GlobalFindAtomA(LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalFindAtomA(lpString); });

	SEND_AFTER_CALL

    return result;
}

static  HGLOBAL (WINAPI *og_GlobalAlloc)(UINT uFlags,  SIZE_T dwBytes) = GlobalAlloc;
static  HGLOBAL WINAPI hooked_GlobalAlloc(UINT uFlags,  SIZE_T dwBytes) {

	SEND_BEFORE_CALL

	
     HGLOBAL result;
    TIME({ result = og_GlobalAlloc(uFlags, dwBytes); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalDeleteAtom)(ATOM nAtom) = GlobalDeleteAtom;
static ATOM WINAPI hooked_GlobalDeleteAtom(ATOM nAtom) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalDeleteAtom(nAtom); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_GlobalFindAtomW)(LPCWSTR lpString) = GlobalFindAtomW;
static ATOM WINAPI hooked_GlobalFindAtomW(LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_GlobalFindAtomW(lpString); });

	SEND_AFTER_CALL

    return result;
}

static HGLOBAL (WINAPI *og_GlobalFree)(_Frees_ptr_opt_ HGLOBAL hMem) = GlobalFree;
static HGLOBAL WINAPI hooked_GlobalFree(_Frees_ptr_opt_ HGLOBAL hMem) {

	SEND_BEFORE_CALL

	
    HGLOBAL result;
    TIME({ result = og_GlobalFree(hMem); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GlobalFlags)(HGLOBAL hMem) = GlobalFlags;
static UINT WINAPI hooked_GlobalFlags(HGLOBAL hMem) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GlobalFlags(hMem); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GlobalGetAtomNameW)(ATOM nAtom,  LPWSTR lpBuffer,  int nSize) = GlobalGetAtomNameW;
static UINT WINAPI hooked_GlobalGetAtomNameW(ATOM nAtom,  LPWSTR lpBuffer,  int nSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GlobalGetAtomNameW(nAtom, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GlobalGetAtomNameA)(ATOM nAtom,  LPSTR lpBuffer,  int nSize) = GlobalGetAtomNameA;
static UINT WINAPI hooked_GlobalGetAtomNameA(ATOM nAtom,  LPSTR lpBuffer,  int nSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GlobalGetAtomNameA(nAtom, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_GlobalLock)(HGLOBAL hMem) = GlobalLock;
static LPVOID WINAPI hooked_GlobalLock(HGLOBAL hMem) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_GlobalLock(hMem); });

	SEND_AFTER_CALL

    return result;
}

static HGLOBAL (WINAPI *og_GlobalHandle)(LPCVOID pMem) = GlobalHandle;
static HGLOBAL WINAPI hooked_GlobalHandle(LPCVOID pMem) {

	SEND_BEFORE_CALL

	
    HGLOBAL result;
    TIME({ result = og_GlobalHandle(pMem); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GlobalMemoryStatus)(LPMEMORYSTATUS lpBuffer) = GlobalMemoryStatus;
static VOID WINAPI hooked_GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer) {

	SEND_BEFORE_CALL

	
	TIME({ og_GlobalMemoryStatus(lpBuffer); });

	SEND_AFTER_CALL
	
}

static  HGLOBAL (WINAPI *og_GlobalReAlloc)(_Frees_ptr_ HGLOBAL hMem,  SIZE_T dwBytes,  UINT uFlags) = GlobalReAlloc;
static  HGLOBAL WINAPI hooked_GlobalReAlloc(_Frees_ptr_ HGLOBAL hMem,  SIZE_T dwBytes,  UINT uFlags) {

	SEND_BEFORE_CALL

	
     HGLOBAL result;
    TIME({ result = og_GlobalReAlloc(hMem, dwBytes, uFlags); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_GlobalSize)(HGLOBAL hMem) = GlobalSize;
static SIZE_T WINAPI hooked_GlobalSize(HGLOBAL hMem) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_GlobalSize(hMem); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitAtomTable)(DWORD nSize) = InitAtomTable;
static BOOL WINAPI hooked_InitAtomTable(DWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitAtomTable(nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitializeContext)(PVOID Buffer,  DWORD ContextFlags,  PCONTEXT *Context,  PDWORD ContextLength) = InitializeContext;
static BOOL WINAPI hooked_InitializeContext(PVOID Buffer,  DWORD ContextFlags,  PCONTEXT *Context,  PDWORD ContextLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeContext(Buffer, ContextFlags, Context, ContextLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GlobalUnlock)(HGLOBAL hMem) = GlobalUnlock;
static BOOL WINAPI hooked_GlobalUnlock(HGLOBAL hMem) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GlobalUnlock(hMem); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsBadCodePtr)(FARPROC lpfn) = IsBadCodePtr;
static BOOL WINAPI hooked_IsBadCodePtr(FARPROC lpfn) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsBadCodePtr(lpfn); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsBadReadPtr)(const VOID *lp,  UINT_PTR ucb) = IsBadReadPtr;
static BOOL WINAPI hooked_IsBadReadPtr(const VOID *lp,  UINT_PTR ucb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsBadReadPtr(lp, ucb); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsBadStringPtrA)(LPCSTR lpsz,  UINT_PTR ucchMax) = IsBadStringPtrA;
static BOOL WINAPI hooked_IsBadStringPtrA(LPCSTR lpsz,  UINT_PTR ucchMax) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsBadStringPtrA(lpsz, ucchMax); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsBadStringPtrW)(LPCWSTR lpsz,  UINT_PTR ucchMax) = IsBadStringPtrW;
static BOOL WINAPI hooked_IsBadStringPtrW(LPCWSTR lpsz,  UINT_PTR ucchMax) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsBadStringPtrW(lpsz, ucchMax); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsNativeVhdBoot)(PBOOL NativeVhdBoot) = IsNativeVhdBoot;
static BOOL WINAPI hooked_IsNativeVhdBoot(PBOOL NativeVhdBoot) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsNativeVhdBoot(NativeVhdBoot); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsBadWritePtr)(LPVOID lp,  UINT_PTR ucb) = IsBadWritePtr;
static BOOL WINAPI hooked_IsBadWritePtr(LPVOID lp,  UINT_PTR ucb) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsBadWritePtr(lp, ucb); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_LoadModule)(LPCSTR lpModuleName,  LPVOID lpParameterBlock) = LoadModule;
static DWORD WINAPI hooked_LoadModule(LPCSTR lpModuleName,  LPVOID lpParameterBlock) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_LoadModule(lpModuleName, lpParameterBlock); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsSystemResumeAutomatic)() = IsSystemResumeAutomatic;
static BOOL WINAPI hooked_IsSystemResumeAutomatic() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsSystemResumeAutomatic(); });

	SEND_AFTER_CALL

    return result;
}

static HMODULE (WINAPI *og_LoadPackagedLibrary)(LPCWSTR lpwLibFileName, DWORD Reserved) = LoadPackagedLibrary;
static HMODULE WINAPI hooked_LoadPackagedLibrary(LPCWSTR lpwLibFileName, DWORD Reserved) {

	SEND_BEFORE_CALL

	
    HMODULE result;
    TIME({ result = og_LoadPackagedLibrary(lpwLibFileName, Reserved); });

	SEND_AFTER_CALL

    return result;
}

static  HLOCAL (WINAPI *og_LocalAlloc)(UINT uFlags,  SIZE_T uBytes) = LocalAlloc;
static  HLOCAL WINAPI hooked_LocalAlloc(UINT uFlags,  SIZE_T uBytes) {

	SEND_BEFORE_CALL

	
     HLOCAL result;
    TIME({ result = og_LocalAlloc(uFlags, uBytes); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_LocalFlags)(HLOCAL hMem) = LocalFlags;
static UINT WINAPI hooked_LocalFlags(HLOCAL hMem) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_LocalFlags(hMem); });

	SEND_AFTER_CALL

    return result;
}

static HLOCAL (WINAPI *og_LocalFree)(_Frees_ptr_opt_ HLOCAL hMem) = LocalFree;
static HLOCAL WINAPI hooked_LocalFree(_Frees_ptr_opt_ HLOCAL hMem) {

	SEND_BEFORE_CALL

	
    HLOCAL result;
    TIME({ result = og_LocalFree(hMem); });

	SEND_AFTER_CALL

    return result;
}

static HLOCAL (WINAPI *og_LocalHandle)(LPCVOID pMem) = LocalHandle;
static HLOCAL WINAPI hooked_LocalHandle(LPCVOID pMem) {

	SEND_BEFORE_CALL

	
    HLOCAL result;
    TIME({ result = og_LocalHandle(pMem); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_LocalLock)(HLOCAL hMem) = LocalLock;
static LPVOID WINAPI hooked_LocalLock(HLOCAL hMem) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_LocalLock(hMem); });

	SEND_AFTER_CALL

    return result;
}

static  HLOCAL (WINAPI *og_LocalReAlloc)(_Frees_ptr_opt_ HLOCAL hMem,  SIZE_T uBytes,  UINT uFlags) = LocalReAlloc;
static  HLOCAL WINAPI hooked_LocalReAlloc(_Frees_ptr_opt_ HLOCAL hMem,  SIZE_T uBytes,  UINT uFlags) {

	SEND_BEFORE_CALL

	
     HLOCAL result;
    TIME({ result = og_LocalReAlloc(hMem, uBytes, uFlags); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_LocalSize)(HLOCAL hMem) = LocalSize;
static SIZE_T WINAPI hooked_LocalSize(HLOCAL hMem) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_LocalSize(hMem); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LocalUnlock)(HLOCAL hMem) = LocalUnlock;
static BOOL WINAPI hooked_LocalUnlock(HLOCAL hMem) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LocalUnlock(hMem); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_LocateXStateFeature)(PCONTEXT Context,  DWORD FeatureId,  PDWORD Length) = LocateXStateFeature;
static PVOID WINAPI hooked_LocateXStateFeature(PCONTEXT Context,  DWORD FeatureId,  PDWORD Length) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_LocateXStateFeature(Context, FeatureId, Length); });

	SEND_AFTER_CALL

    return result;
}

static LPSTR (WINAPI *og_lstrcatA)(LPSTR lpString1,  LPCSTR lpString2) = lstrcatA;
static LPSTR WINAPI hooked_lstrcatA(LPSTR lpString1,  LPCSTR lpString2) {

	SEND_BEFORE_CALL

	
    LPSTR result;
    TIME({ result = og_lstrcatA(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static LPWSTR (WINAPI *og_lstrcatW)(LPWSTR lpString1,  LPCWSTR lpString2) = lstrcatW;
static LPWSTR WINAPI hooked_lstrcatW(LPWSTR lpString1,  LPCWSTR lpString2) {

	SEND_BEFORE_CALL

	
    LPWSTR result;
    TIME({ result = og_lstrcatW(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrcmpiA)(LPCSTR lpString1,  LPCSTR lpString2) = lstrcmpiA;
static int WINAPI hooked_lstrcmpiA(LPCSTR lpString1,  LPCSTR lpString2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrcmpiA(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrcmpA)(LPCSTR lpString1,  LPCSTR lpString2) = lstrcmpA;
static int WINAPI hooked_lstrcmpA(LPCSTR lpString1,  LPCSTR lpString2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrcmpA(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrcmpiW)(LPCWSTR lpString1,  LPCWSTR lpString2) = lstrcmpiW;
static int WINAPI hooked_lstrcmpiW(LPCWSTR lpString1,  LPCWSTR lpString2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrcmpiW(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrcmpW)(LPCWSTR lpString1,  LPCWSTR lpString2) = lstrcmpW;
static int WINAPI hooked_lstrcmpW(LPCWSTR lpString1,  LPCWSTR lpString2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrcmpW(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static LPSTR (WINAPI *og_lstrcpynA)(LPSTR lpString1,  LPCSTR lpString2,  int iMaxLength) = lstrcpynA;
static LPSTR WINAPI hooked_lstrcpynA(LPSTR lpString1,  LPCSTR lpString2,  int iMaxLength) {

	SEND_BEFORE_CALL

	
    LPSTR result;
    TIME({ result = og_lstrcpynA(lpString1, lpString2, iMaxLength); });

	SEND_AFTER_CALL

    return result;
}

static LPSTR (WINAPI *og_lstrcpyA)(LPSTR lpString1,  LPCSTR lpString2) = lstrcpyA;
static LPSTR WINAPI hooked_lstrcpyA(LPSTR lpString1,  LPCSTR lpString2) {

	SEND_BEFORE_CALL

	
    LPSTR result;
    TIME({ result = og_lstrcpyA(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static LPWSTR (WINAPI *og_lstrcpyW)(LPWSTR lpString1,  LPCWSTR lpString2) = lstrcpyW;
static LPWSTR WINAPI hooked_lstrcpyW(LPWSTR lpString1,  LPCWSTR lpString2) {

	SEND_BEFORE_CALL

	
    LPWSTR result;
    TIME({ result = og_lstrcpyW(lpString1, lpString2); });

	SEND_AFTER_CALL

    return result;
}

static LPWSTR (WINAPI *og_lstrcpynW)(LPWSTR lpString1,  LPCWSTR lpString2,  int iMaxLength) = lstrcpynW;
static LPWSTR WINAPI hooked_lstrcpynW(LPWSTR lpString1,  LPCWSTR lpString2,  int iMaxLength) {

	SEND_BEFORE_CALL

	
    LPWSTR result;
    TIME({ result = og_lstrcpynW(lpString1, lpString2, iMaxLength); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrlenA)(LPCSTR lpString) = lstrlenA;
static int WINAPI hooked_lstrlenA(LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrlenA(lpString); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_lstrlenW)(LPCWSTR lpString) = lstrlenW;
static int WINAPI hooked_lstrlenW(LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_lstrlenW(lpString); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MapUserPhysicalPagesScatter)(PVOID *VirtualAddresses,  ULONG_PTR NumberOfPages,  PULONG_PTR PageArray) = MapUserPhysicalPagesScatter;
static BOOL WINAPI hooked_MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,  ULONG_PTR NumberOfPages,  PULONG_PTR PageArray) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MapUserPhysicalPagesScatter(VirtualAddresses, NumberOfPages, PageArray); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_MapViewOfFileExNuma)(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap,  LPVOID lpBaseAddress,  DWORD nndPreferred) = MapViewOfFileExNuma;
static LPVOID WINAPI hooked_MapViewOfFileExNuma(HANDLE hFileMappingObject,  DWORD dwDesiredAccess,  DWORD dwFileOffsetHigh,  DWORD dwFileOffsetLow,  SIZE_T dwNumberOfBytesToMap,  LPVOID lpBaseAddress,  DWORD nndPreferred) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_MapViewOfFileExNuma(hFileMappingObject, dwDesiredAccess, dwFileOffsetHigh, dwFileOffsetLow, dwNumberOfBytesToMap, lpBaseAddress, nndPreferred); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFile)(LPCTSTR lpExistingFileName,  LPCTSTR lpNewFileName) = MoveFile;
static BOOL WINAPI hooked_MoveFile(LPCTSTR lpExistingFileName,  LPCTSTR lpNewFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFile(lpExistingFileName, lpNewFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName) = MoveFileA;
static BOOL WINAPI hooked_MoveFileA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileA(lpExistingFileName, lpNewFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileExA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  DWORD dwFlags) = MoveFileExA;
static BOOL WINAPI hooked_MoveFileExA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileExA(lpExistingFileName, lpNewFileName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileExW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  DWORD dwFlags) = MoveFileExW;
static BOOL WINAPI hooked_MoveFileExW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileExW(lpExistingFileName, lpNewFileName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileTransactedA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags,  HANDLE hTransaction) = MoveFileTransactedA;
static BOOL WINAPI hooked_MoveFileTransactedA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileTransactedA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, dwFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileTransactedW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags,  HANDLE hTransaction) = MoveFileTransactedW;
static BOOL WINAPI hooked_MoveFileTransactedW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileTransactedW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, dwFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName) = MoveFileW;
static BOOL WINAPI hooked_MoveFileW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileW(lpExistingFileName, lpNewFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileWithProgressA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags) = MoveFileWithProgressA;
static BOOL WINAPI hooked_MoveFileWithProgressA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileWithProgressA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_MoveFileWithProgressW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags) = MoveFileWithProgressW;
static BOOL WINAPI hooked_MoveFileWithProgressW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_MoveFileWithProgressW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_MulDiv)(int nNumber,  int nNumerator,  int nDenominator) = MulDiv;
static int WINAPI hooked_MulDiv(int nNumber,  int nNumerator,  int nDenominator) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_MulDiv(nNumber, nNumerator, nDenominator); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenFileById)(HANDLE hVolumeHint,  LPFILE_ID_DESCRIPTOR lpFileId,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwFlagsAndAttributes) = OpenFileById;
static HANDLE WINAPI hooked_OpenFileById(HANDLE hVolumeHint,  LPFILE_ID_DESCRIPTOR lpFileId,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwFlagsAndAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenFileById(hVolumeHint, lpFileId, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwFlagsAndAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HFILE (WINAPI *og_OpenFile)(LPCSTR lpFileName,  LPOFSTRUCT lpReOpenBuff,  UINT uStyle) = OpenFile;
static HFILE WINAPI hooked_OpenFile(LPCSTR lpFileName,  LPOFSTRUCT lpReOpenBuff,  UINT uStyle) {

	SEND_BEFORE_CALL

	
    HFILE result;
    TIME({ result = og_OpenFile(lpFileName, lpReOpenBuff, uStyle); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenFileMappingA)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) = OpenFileMappingA;
static HANDLE WINAPI hooked_OpenFileMappingA(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenFileMappingA(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenJobObjectA)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) = OpenJobObjectA;
static HANDLE WINAPI hooked_OpenJobObjectA(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenJobObjectA(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenPrivateNamespaceA)(LPVOID lpBoundaryDescriptor,  LPCSTR lpAliasPrefix) = OpenPrivateNamespaceA;
static HANDLE WINAPI hooked_OpenPrivateNamespaceA(LPVOID lpBoundaryDescriptor,  LPCSTR lpAliasPrefix) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenPrivateNamespaceA(lpBoundaryDescriptor, lpAliasPrefix); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PowerClearRequest)(HANDLE PowerRequest,  POWER_REQUEST_TYPE RequestType) = PowerClearRequest;
static BOOL WINAPI hooked_PowerClearRequest(HANDLE PowerRequest,  POWER_REQUEST_TYPE RequestType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PowerClearRequest(PowerRequest, RequestType); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_PowerCreateRequest)(PREASON_CONTEXT Context) = PowerCreateRequest;
static HANDLE WINAPI hooked_PowerCreateRequest(PREASON_CONTEXT Context) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_PowerCreateRequest(Context); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PowerSetRequest)(HANDLE PowerRequest,  POWER_REQUEST_TYPE RequestType) = PowerSetRequest;
static BOOL WINAPI hooked_PowerSetRequest(HANDLE PowerRequest,  POWER_REQUEST_TYPE RequestType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PowerSetRequest(PowerRequest, RequestType); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_PrepareTape)(HANDLE hDevice,  DWORD dwOperation,  BOOL bImmediate) = PrepareTape;
static DWORD WINAPI hooked_PrepareTape(HANDLE hDevice,  DWORD dwOperation,  BOOL bImmediate) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_PrepareTape(hDevice, dwOperation, bImmediate); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PulseEvent)(HANDLE hEvent) = PulseEvent;
static BOOL WINAPI hooked_PulseEvent(HANDLE hEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PulseEvent(hEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PurgeComm)(HANDLE hFile,  DWORD dwFlags) = PurgeComm;
static BOOL WINAPI hooked_PurgeComm(HANDLE hFile,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PurgeComm(hFile, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryActCtxSettingsW)(DWORD dwFlags,  HANDLE hActCtx,  PCWSTR settingsNameSpace,  PCWSTR settingName,  PWSTR pvBuffer,  SIZE_T dwBuffer,  SIZE_T *pdwWrittenOrRequired) = QueryActCtxSettingsW;
static BOOL WINAPI hooked_QueryActCtxSettingsW(DWORD dwFlags,  HANDLE hActCtx,  PCWSTR settingsNameSpace,  PCWSTR settingName,  PWSTR pvBuffer,  SIZE_T dwBuffer,  SIZE_T *pdwWrittenOrRequired) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryActCtxSettingsW(dwFlags, hActCtx, settingsNameSpace, settingName, pvBuffer, dwBuffer, pdwWrittenOrRequired); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryActCtxW)(DWORD dwFlags,  HANDLE hActCtx,  PVOID pvSubInstance,  ULONG ulInfoClass,  PVOID pvBuffer,  SIZE_T cbBuffer,  SIZE_T *pcbWrittenOrRequired) = QueryActCtxW;
static BOOL WINAPI hooked_QueryActCtxW(DWORD dwFlags,  HANDLE hActCtx,  PVOID pvSubInstance,  ULONG ulInfoClass,  PVOID pvBuffer,  SIZE_T cbBuffer,  SIZE_T *pcbWrittenOrRequired) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryActCtxW(dwFlags, hActCtx, pvSubInstance, ulInfoClass, pvBuffer, cbBuffer, pcbWrittenOrRequired); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_QueryDosDeviceA)(LPCSTR lpDeviceName,  LPSTR lpTargetPath,  DWORD ucchMax) = QueryDosDeviceA;
static DWORD WINAPI hooked_QueryDosDeviceA(LPCSTR lpDeviceName,  LPSTR lpTargetPath,  DWORD ucchMax) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_QueryDosDeviceA(lpDeviceName, lpTargetPath, ucchMax); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryFullProcessImageNameW)(HANDLE hProcess,  DWORD dwFlags,  LPWSTR lpExeName,  PDWORD lpdwSize) = QueryFullProcessImageNameW;
static BOOL WINAPI hooked_QueryFullProcessImageNameW(HANDLE hProcess,  DWORD dwFlags,  LPWSTR lpExeName,  PDWORD lpdwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryFullProcessImageNameW(hProcess, dwFlags, lpExeName, lpdwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryFullProcessImageNameA)(HANDLE hProcess,  DWORD dwFlags,  LPSTR lpExeName,  PDWORD lpdwSize) = QueryFullProcessImageNameA;
static BOOL WINAPI hooked_QueryFullProcessImageNameA(HANDLE hProcess,  DWORD dwFlags,  LPSTR lpExeName,  PDWORD lpdwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryFullProcessImageNameA(hProcess, dwFlags, lpExeName, lpdwSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_QueryThreadProfiling)(HANDLE ThreadHandle,  PBOOLEAN Enabled) = QueryThreadProfiling;
static DWORD WINAPI hooked_QueryThreadProfiling(HANDLE ThreadHandle,  PBOOLEAN Enabled) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_QueryThreadProfiling(ThreadHandle, Enabled); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadDirectoryChangesExW)(HANDLE hDirectory,  LPVOID lpBuffer,  DWORD nBufferLength,  BOOL bWatchSubtree,  DWORD dwNotifyFilter,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,  READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass) = ReadDirectoryChangesExW;
static BOOL WINAPI hooked_ReadDirectoryChangesExW(HANDLE hDirectory,  LPVOID lpBuffer,  DWORD nBufferLength,  BOOL bWatchSubtree,  DWORD dwNotifyFilter,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,  READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadDirectoryChangesExW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine, ReadDirectoryNotifyInformationClass); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryUmsThreadInformation)(PUMS_CONTEXT UmsThread,  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,  PVOID UmsThreadInformation,  ULONG UmsThreadInformationLength,  PULONG ReturnLength) = QueryUmsThreadInformation;
static BOOL WINAPI hooked_QueryUmsThreadInformation(PUMS_CONTEXT UmsThread,  UMS_THREAD_INFO_CLASS UmsThreadInfoClass,  PVOID UmsThreadInformation,  ULONG UmsThreadInformationLength,  PULONG ReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryUmsThreadInformation(UmsThread, UmsThreadInfoClass, UmsThreadInformation, UmsThreadInformationLength, ReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadDirectoryChangesW)(HANDLE hDirectory,  LPVOID lpBuffer,  DWORD nBufferLength,  BOOL bWatchSubtree,  DWORD dwNotifyFilter,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = ReadDirectoryChangesW;
static BOOL WINAPI hooked_ReadDirectoryChangesW(HANDLE hDirectory,  LPVOID lpBuffer,  DWORD nBufferLength,  BOOL bWatchSubtree,  DWORD dwNotifyFilter,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadDirectoryChangesW(hDirectory, lpBuffer, nBufferLength, bWatchSubtree, dwNotifyFilter, lpBytesReturned, lpOverlapped, lpCompletionRoutine); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_RegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK pRecoveyCallback,  PVOID pvParameter,  DWORD dwPingInterval,  DWORD dwFlags) = RegisterApplicationRecoveryCallback;
static HRESULT WINAPI hooked_RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK pRecoveyCallback,  PVOID pvParameter,  DWORD dwPingInterval,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_RegisterApplicationRecoveryCallback(pRecoveyCallback, pvParameter, dwPingInterval, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_ReadThreadProfilingData)(HANDLE PerformanceDataHandle,  DWORD Flags,  PPERFORMANCE_DATA PerformanceData) = ReadThreadProfilingData;
static DWORD WINAPI hooked_ReadThreadProfilingData(HANDLE PerformanceDataHandle,  DWORD Flags,  PPERFORMANCE_DATA PerformanceData) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_ReadThreadProfilingData(PerformanceDataHandle, Flags, PerformanceData); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_RegisterApplicationRestart)(PCWSTR pwzCommandline,  DWORD dwFlags) = RegisterApplicationRestart;
static HRESULT WINAPI hooked_RegisterApplicationRestart(PCWSTR pwzCommandline,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_RegisterApplicationRestart(pwzCommandline, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RegisterWaitForSingleObject)(PHANDLE phNewWaitObject,  HANDLE hObject,  WAITORTIMERCALLBACK Callback,  PVOID Context,  ULONG dwMilliseconds,  ULONG dwFlags) = RegisterWaitForSingleObject;
static BOOL WINAPI hooked_RegisterWaitForSingleObject(PHANDLE phNewWaitObject,  HANDLE hObject,  WAITORTIMERCALLBACK Callback,  PVOID Context,  ULONG dwMilliseconds,  ULONG dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RegisterWaitForSingleObject(phNewWaitObject, hObject, Callback, Context, dwMilliseconds, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_ReleaseActCtx)(HANDLE hActCtx) = ReleaseActCtx;
static VOID WINAPI hooked_ReleaseActCtx(HANDLE hActCtx) {

	SEND_BEFORE_CALL

	
	TIME({ og_ReleaseActCtx(hActCtx); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_RemoveDirectoryTransactedW)(LPCWSTR lpPathName,  HANDLE hTransaction) = RemoveDirectoryTransactedW;
static BOOL WINAPI hooked_RemoveDirectoryTransactedW(LPCWSTR lpPathName,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectoryTransactedW(lpPathName, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDirectoryTransactedA)(LPCSTR lpPathName,  HANDLE hTransaction) = RemoveDirectoryTransactedA;
static BOOL WINAPI hooked_RemoveDirectoryTransactedA(LPCSTR lpPathName,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectoryTransactedA(lpPathName, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveSecureMemoryCacheCallback)(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack) = RemoveSecureMemoryCacheCallback;
static BOOL WINAPI hooked_RemoveSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveSecureMemoryCacheCallback(pfnCallBack); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_ReOpenFile)(HANDLE hOriginalFile,  DWORD dwDesiredAccess,  DWORD dwShareMode,  DWORD dwFlagsAndAttributes) = ReOpenFile;
static HANDLE WINAPI hooked_ReOpenFile(HANDLE hOriginalFile,  DWORD dwDesiredAccess,  DWORD dwShareMode,  DWORD dwFlagsAndAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_ReOpenFile(hOriginalFile, dwDesiredAccess, dwShareMode, dwFlagsAndAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReplaceFileA)(LPCSTR lpReplacedFileName,  LPCSTR lpReplacementFileName,  LPCSTR lpBackupFileName,  DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) = ReplaceFileA;
static BOOL WINAPI hooked_ReplaceFileA(LPCSTR lpReplacedFileName,  LPCSTR lpReplacementFileName,  LPCSTR lpBackupFileName,  DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReplaceFileA(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReplaceFileW)(LPCWSTR lpReplacedFileName,  LPCWSTR lpReplacementFileName,  LPCWSTR lpBackupFileName,  DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) = ReplaceFileW;
static BOOL WINAPI hooked_ReplaceFileW(LPCWSTR lpReplacedFileName,  LPCWSTR lpReplacementFileName,  LPCWSTR lpBackupFileName,  DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReplaceFileW(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RequestWakeupLatency)(LATENCY_TIME latency) = RequestWakeupLatency;
static BOOL WINAPI hooked_RequestWakeupLatency(LATENCY_TIME latency) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RequestWakeupLatency(latency); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCommBreak)(HANDLE hFile) = SetCommBreak;
static BOOL WINAPI hooked_SetCommBreak(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCommBreak(hFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCommConfig)(HANDLE hCommDev,  LPCOMMCONFIG lpCC,  DWORD dwSize) = SetCommConfig;
static BOOL WINAPI hooked_SetCommConfig(HANDLE hCommDev,  LPCOMMCONFIG lpCC,  DWORD dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCommConfig(hCommDev, lpCC, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCommMask)(HANDLE hFile,  DWORD dwEvtMask) = SetCommMask;
static BOOL WINAPI hooked_SetCommMask(HANDLE hFile,  DWORD dwEvtMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCommMask(hFile, dwEvtMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCurrentDirectory)(LPCTSTR lpPathName) = SetCurrentDirectory;
static BOOL WINAPI hooked_SetCurrentDirectory(LPCTSTR lpPathName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCurrentDirectory(lpPathName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCommState)(HANDLE hFile,  LPDCB lpDCB) = SetCommState;
static BOOL WINAPI hooked_SetCommState(HANDLE hFile,  LPDCB lpDCB) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCommState(hFile, lpDCB); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCommTimeouts)(HANDLE hFile,  LPCOMMTIMEOUTS lpCommTimeouts) = SetCommTimeouts;
static BOOL WINAPI hooked_SetCommTimeouts(HANDLE hFile,  LPCOMMTIMEOUTS lpCommTimeouts) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCommTimeouts(hFile, lpCommTimeouts); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDefaultCommConfigA)(LPCSTR lpszName,  LPCOMMCONFIG lpCC,  DWORD dwSize) = SetDefaultCommConfigA;
static BOOL WINAPI hooked_SetDefaultCommConfigA(LPCSTR lpszName,  LPCOMMCONFIG lpCC,  DWORD dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDefaultCommConfigA(lpszName, lpCC, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDefaultCommConfigW)(LPCWSTR lpszName,  LPCOMMCONFIG lpCC,  DWORD dwSize) = SetDefaultCommConfigW;
static BOOL WINAPI hooked_SetDefaultCommConfigW(LPCWSTR lpszName,  LPCOMMCONFIG lpCC,  DWORD dwSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDefaultCommConfigW(lpszName, lpCC, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDllDirectoryA)(LPCSTR lpPathName) = SetDllDirectoryA;
static BOOL WINAPI hooked_SetDllDirectoryA(LPCSTR lpPathName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDllDirectoryA(lpPathName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDllDirectoryW)(LPCWSTR lpPathName) = SetDllDirectoryW;
static BOOL WINAPI hooked_SetDllDirectoryW(LPCWSTR lpPathName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDllDirectoryW(lpPathName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CeipIsOptedIn)() = CeipIsOptedIn;
static BOOL WINAPI hooked_CeipIsOptedIn() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CeipIsOptedIn(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_CompareString)(LCID Locale,  DWORD dwCmpFlags,  LPCTSTR lpString1,  int cchCount1,  LPCTSTR lpString2,  int cchCount2) = CompareString;
static int WINAPI hooked_CompareString(LCID Locale,  DWORD dwCmpFlags,  LPCTSTR lpString1,  int cchCount1,  LPCTSTR lpString2,  int cchCount2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_CompareString(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_CompareStringA)(LCID Locale,  DWORD dwCmpFlags,  PCNZCH lpString1,  int cchCount1,  PCNZCH lpString2,  int cchCount2) = CompareStringA;
static int WINAPI hooked_CompareStringA(LCID Locale,  DWORD dwCmpFlags,  PCNZCH lpString1,  int cchCount1,  PCNZCH lpString2,  int cchCount2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_CompareStringA(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2); });

	SEND_AFTER_CALL

    return result;
}

static LCID (WINAPI *og_ConvertDefaultLocale)(LCID Locale) = ConvertDefaultLocale;
static LCID WINAPI hooked_ConvertDefaultLocale(LCID Locale) {

	SEND_BEFORE_CALL

	
    LCID result;
    TIME({ result = og_ConvertDefaultLocale(Locale); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumCalendarInfoA)(CALINFO_ENUMPROCA lpCalInfoEnumProc,  LCID Locale,  CALID Calendar,  CALTYPE CalType) = EnumCalendarInfoA;
static BOOL WINAPI hooked_EnumCalendarInfoA(CALINFO_ENUMPROCA lpCalInfoEnumProc,  LCID Locale,  CALID Calendar,  CALTYPE CalType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumCalendarInfoA(lpCalInfoEnumProc, Locale, Calendar, CalType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumCalendarInfoExA)(CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx,  LCID Locale,  CALID Calendar,  CALTYPE CalType) = EnumCalendarInfoExA;
static BOOL WINAPI hooked_EnumCalendarInfoExA(CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx,  LCID Locale,  CALID Calendar,  CALTYPE CalType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumCalendarInfoExA(lpCalInfoEnumProcEx, Locale, Calendar, CalType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumCalendarInfoExEx)(CALINFO_ENUMPROCEXEX pCalInfoEnumProcExEx,  LPCWSTR lpLocaleName,  CALID Calendar,  LPCWSTR lpReserved,  CALTYPE CalType,  LPARAM lParam) = EnumCalendarInfoExEx;
static BOOL WINAPI hooked_EnumCalendarInfoExEx(CALINFO_ENUMPROCEXEX pCalInfoEnumProcExEx,  LPCWSTR lpLocaleName,  CALID Calendar,  LPCWSTR lpReserved,  CALTYPE CalType,  LPARAM lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumCalendarInfoExEx(pCalInfoEnumProcExEx, lpLocaleName, Calendar, lpReserved, CalType, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumCalendarInfoExW)(CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx,  LCID Locale,  CALID Calendar,  CALTYPE CalType) = EnumCalendarInfoExW;
static BOOL WINAPI hooked_EnumCalendarInfoExW(CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx,  LCID Locale,  CALID Calendar,  CALTYPE CalType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumCalendarInfoExW(lpCalInfoEnumProcEx, Locale, Calendar, CalType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumCalendarInfoW)(CALINFO_ENUMPROCW lpCalInfoEnumProc,  LCID Locale,  CALID Calendar,  CALTYPE CalType) = EnumCalendarInfoW;
static BOOL WINAPI hooked_EnumCalendarInfoW(CALINFO_ENUMPROCW lpCalInfoEnumProc,  LCID Locale,  CALID Calendar,  CALTYPE CalType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumCalendarInfoW(lpCalInfoEnumProc, Locale, Calendar, CalType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDateFormatsA)(DATEFMT_ENUMPROCA lpDateFmtEnumProc,  LCID Locale,  DWORD dwFlags) = EnumDateFormatsA;
static BOOL WINAPI hooked_EnumDateFormatsA(DATEFMT_ENUMPROCA lpDateFmtEnumProc,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDateFormatsA(lpDateFmtEnumProc, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDateFormatsExA)(DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx,  LCID Locale,  DWORD dwFlags) = EnumDateFormatsExA;
static BOOL WINAPI hooked_EnumDateFormatsExA(DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDateFormatsExA(lpDateFmtEnumProcEx, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDateFormatsW)(DATEFMT_ENUMPROCW lpDateFmtEnumProc,  LCID Locale,  DWORD dwFlags) = EnumDateFormatsW;
static BOOL WINAPI hooked_EnumDateFormatsW(DATEFMT_ENUMPROCW lpDateFmtEnumProc,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDateFormatsW(lpDateFmtEnumProc, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDateFormatsExW)(DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx,  LCID Locale,  DWORD dwFlags) = EnumDateFormatsExW;
static BOOL WINAPI hooked_EnumDateFormatsExW(DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDateFormatsExW(lpDateFmtEnumProcEx, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumDateFormatsExEx)(DATEFMT_ENUMPROCEXEX lpDateFmtEnumProcExEx,  LPCWSTR lpLocaleName,  DWORD dwFlags,  LPARAM lParam) = EnumDateFormatsExEx;
static BOOL WINAPI hooked_EnumDateFormatsExEx(DATEFMT_ENUMPROCEXEX lpDateFmtEnumProcExEx,  LPCWSTR lpLocaleName,  DWORD dwFlags,  LPARAM lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumDateFormatsExEx(lpDateFmtEnumProcExEx, lpLocaleName, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumLanguageGroupLocalesA)(LANGGROUPLOCALE_ENUMPROCA lpLangGroupLocaleEnumProc,  LGRPID LanguageGroup,  DWORD dwFlags,  LONG_PTR lParam) = EnumLanguageGroupLocalesA;
static BOOL WINAPI hooked_EnumLanguageGroupLocalesA(LANGGROUPLOCALE_ENUMPROCA lpLangGroupLocaleEnumProc,  LGRPID LanguageGroup,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumLanguageGroupLocalesA(lpLangGroupLocaleEnumProc, LanguageGroup, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumLanguageGroupLocalesW)(LANGGROUPLOCALE_ENUMPROCW lpLangGroupLocaleEnumProc,  LGRPID LanguageGroup,  DWORD dwFlags,  LONG_PTR lParam) = EnumLanguageGroupLocalesW;
static BOOL WINAPI hooked_EnumLanguageGroupLocalesW(LANGGROUPLOCALE_ENUMPROCW lpLangGroupLocaleEnumProc,  LGRPID LanguageGroup,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumLanguageGroupLocalesW(lpLangGroupLocaleEnumProc, LanguageGroup, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemCodePagesA)(CODEPAGE_ENUMPROCA lpCodePageEnumProc,  DWORD dwFlags) = EnumSystemCodePagesA;
static BOOL WINAPI hooked_EnumSystemCodePagesA(CODEPAGE_ENUMPROCA lpCodePageEnumProc,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemCodePagesA(lpCodePageEnumProc, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemCodePagesW)(CODEPAGE_ENUMPROCW lpCodePageEnumProc,  DWORD dwFlags) = EnumSystemCodePagesW;
static BOOL WINAPI hooked_EnumSystemCodePagesW(CODEPAGE_ENUMPROCW lpCodePageEnumProc,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemCodePagesW(lpCodePageEnumProc, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemGeoID)(GEOCLASS GeoClass,  GEOID ParentGeoId,  GEO_ENUMPROC lpGeoEnumProc) = EnumSystemGeoID;
static BOOL WINAPI hooked_EnumSystemGeoID(GEOCLASS GeoClass,  GEOID ParentGeoId,  GEO_ENUMPROC lpGeoEnumProc) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemGeoID(GeoClass, ParentGeoId, lpGeoEnumProc); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemGeoNames)(GEOCLASS geoClass,  GEO_ENUMNAMEPROC geoEnumProc,  LPARAM data) = EnumSystemGeoNames;
static BOOL WINAPI hooked_EnumSystemGeoNames(GEOCLASS geoClass,  GEO_ENUMNAMEPROC geoEnumProc,  LPARAM data) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemGeoNames(geoClass, geoEnumProc, data); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemLanguageGroupsA)(LANGUAGEGROUP_ENUMPROCA lpLanguageGroupEnumProc,  DWORD dwFlags,  LONG_PTR lParam) = EnumSystemLanguageGroupsA;
static BOOL WINAPI hooked_EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA lpLanguageGroupEnumProc,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemLanguageGroupsA(lpLanguageGroupEnumProc, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemLanguageGroupsW)(LANGUAGEGROUP_ENUMPROCW lpLanguageGroupEnumProc,  DWORD dwFlags,  LONG_PTR lParam) = EnumSystemLanguageGroupsW;
static BOOL WINAPI hooked_EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW lpLanguageGroupEnumProc,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemLanguageGroupsW(lpLanguageGroupEnumProc, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemLocalesA)(LOCALE_ENUMPROCA lpLocaleEnumProc,  DWORD dwFlags) = EnumSystemLocalesA;
static BOOL WINAPI hooked_EnumSystemLocalesA(LOCALE_ENUMPROCA lpLocaleEnumProc,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemLocalesA(lpLocaleEnumProc, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemLocalesEx)(LOCALE_ENUMPROCEX lpLocaleEnumProcEx,  DWORD dwFlags,  LPARAM lParam,  LPVOID lpReserved) = EnumSystemLocalesEx;
static BOOL WINAPI hooked_EnumSystemLocalesEx(LOCALE_ENUMPROCEX lpLocaleEnumProcEx,  DWORD dwFlags,  LPARAM lParam,  LPVOID lpReserved) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemLocalesEx(lpLocaleEnumProcEx, dwFlags, lParam, lpReserved); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumSystemLocalesW)(LOCALE_ENUMPROCW lpLocaleEnumProc,  DWORD dwFlags) = EnumSystemLocalesW;
static BOOL WINAPI hooked_EnumSystemLocalesW(LOCALE_ENUMPROCW lpLocaleEnumProc,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumSystemLocalesW(lpLocaleEnumProc, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumTimeFormatsA)(TIMEFMT_ENUMPROCA lpTimeFmtEnumProc,  LCID Locale,  DWORD dwFlags) = EnumTimeFormatsA;
static BOOL WINAPI hooked_EnumTimeFormatsA(TIMEFMT_ENUMPROCA lpTimeFmtEnumProc,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumTimeFormatsA(lpTimeFmtEnumProc, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumTimeFormatsEx)(TIMEFMT_ENUMPROCEX lpTimeFmtEnumProcEx,  LPCWSTR lpLocaleName,  DWORD dwFlags,  LPARAM lParam) = EnumTimeFormatsEx;
static BOOL WINAPI hooked_EnumTimeFormatsEx(TIMEFMT_ENUMPROCEX lpTimeFmtEnumProcEx,  LPCWSTR lpLocaleName,  DWORD dwFlags,  LPARAM lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumTimeFormatsEx(lpTimeFmtEnumProcEx, lpLocaleName, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumUILanguagesA)(UILANGUAGE_ENUMPROCA lpUILanguageEnumProc,  DWORD dwFlags,  LONG_PTR lParam) = EnumUILanguagesA;
static BOOL WINAPI hooked_EnumUILanguagesA(UILANGUAGE_ENUMPROCA lpUILanguageEnumProc,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumUILanguagesA(lpUILanguageEnumProc, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumTimeFormatsW)(TIMEFMT_ENUMPROCW lpTimeFmtEnumProc,  LCID Locale,  DWORD dwFlags) = EnumTimeFormatsW;
static BOOL WINAPI hooked_EnumTimeFormatsW(TIMEFMT_ENUMPROCW lpTimeFmtEnumProc,  LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumTimeFormatsW(lpTimeFmtEnumProc, Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumUILanguagesW)(UILANGUAGE_ENUMPROCW lpUILanguageEnumProc,  DWORD dwFlags,  LONG_PTR lParam) = EnumUILanguagesW;
static BOOL WINAPI hooked_EnumUILanguagesW(UILANGUAGE_ENUMPROCW lpUILanguageEnumProc,  DWORD dwFlags,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumUILanguagesW(lpUILanguageEnumProc, dwFlags, lParam); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_FindNLSString)(LCID Locale,  DWORD dwFindNLSStringFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  LPINT pcchFound) = FindNLSString;
static int WINAPI hooked_FindNLSString(LCID Locale,  DWORD dwFindNLSStringFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  LPINT pcchFound) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_FindNLSString(Locale, dwFindNLSStringFlags, lpStringSource, cchSource, lpStringValue, cchValue, pcchFound); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_FindNLSStringEx)(LPCWSTR lpLocaleName,  DWORD dwFindNLSStringFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  LPINT pcchFound,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM sortHandle) = FindNLSStringEx;
static int WINAPI hooked_FindNLSStringEx(LPCWSTR lpLocaleName,  DWORD dwFindNLSStringFlags,  LPCWSTR lpStringSource,  int cchSource,  LPCWSTR lpStringValue,  int cchValue,  LPINT pcchFound,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM sortHandle) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_FindNLSStringEx(lpLocaleName, dwFindNLSStringFlags, lpStringSource, cchSource, lpStringValue, cchValue, pcchFound, lpVersionInformation, lpReserved, sortHandle); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_FoldStringA)(DWORD dwMapFlags,  LPCSTR lpSrcStr,  int cchSrc,  LPSTR lpDestStr,  int cchDest) = FoldStringA;
static int WINAPI hooked_FoldStringA(DWORD dwMapFlags,  LPCSTR lpSrcStr,  int cchSrc,  LPSTR lpDestStr,  int cchDest) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_FoldStringA(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetACP)() = GetACP;
static UINT WINAPI hooked_GetACP() {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetACP(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCalendarInfoA)(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPSTR lpCalData,  int cchData,  LPDWORD lpValue) = GetCalendarInfoA;
static int WINAPI hooked_GetCalendarInfoA(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPSTR lpCalData,  int cchData,  LPDWORD lpValue) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCalendarInfoA(Locale, Calendar, CalType, lpCalData, cchData, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCalendarInfoEx)(LPCWSTR lpLocaleName,  CALID Calendar,  LPCWSTR lpReserved,  CALTYPE CalType,  LPWSTR lpCalData,  int cchData,  LPDWORD lpValue) = GetCalendarInfoEx;
static int WINAPI hooked_GetCalendarInfoEx(LPCWSTR lpLocaleName,  CALID Calendar,  LPCWSTR lpReserved,  CALTYPE CalType,  LPWSTR lpCalData,  int cchData,  LPDWORD lpValue) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCalendarInfoEx(lpLocaleName, Calendar, lpReserved, CalType, lpCalData, cchData, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCPInfo)(UINT CodePage,  LPCPINFO lpCPInfo) = GetCPInfo;
static BOOL WINAPI hooked_GetCPInfo(UINT CodePage,  LPCPINFO lpCPInfo) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCPInfo(CodePage, lpCPInfo); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCalendarInfoW)(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPWSTR lpCalData,  int cchData,  LPDWORD lpValue) = GetCalendarInfoW;
static int WINAPI hooked_GetCalendarInfoW(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPWSTR lpCalData,  int cchData,  LPDWORD lpValue) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCalendarInfoW(Locale, Calendar, CalType, lpCalData, cchData, lpValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCPInfoExA)(UINT CodePage,  DWORD dwFlags,  LPCPINFOEXA lpCPInfoEx) = GetCPInfoExA;
static BOOL WINAPI hooked_GetCPInfoExA(UINT CodePage,  DWORD dwFlags,  LPCPINFOEXA lpCPInfoEx) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCPInfoExA(CodePage, dwFlags, lpCPInfoEx); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCPInfoExW)(UINT CodePage,  DWORD dwFlags,  LPCPINFOEXW lpCPInfoEx) = GetCPInfoExW;
static BOOL WINAPI hooked_GetCPInfoExW(UINT CodePage,  DWORD dwFlags,  LPCPINFOEXW lpCPInfoEx) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCPInfoExW(CodePage, dwFlags, lpCPInfoEx); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCurrencyFormatA)(LCID Locale,  DWORD dwFlags,  LPCSTR lpValue,  const CURRENCYFMTA *lpFormat,  LPSTR lpCurrencyStr,  int cchCurrency) = GetCurrencyFormatA;
static int WINAPI hooked_GetCurrencyFormatA(LCID Locale,  DWORD dwFlags,  LPCSTR lpValue,  const CURRENCYFMTA *lpFormat,  LPSTR lpCurrencyStr,  int cchCurrency) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCurrencyFormatA(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCurrencyFormatEx)(LPCWSTR lpLocaleName,  DWORD dwFlags,  LPCWSTR lpValue,  const CURRENCYFMTW *lpFormat,  LPWSTR lpCurrencyStr,  int cchCurrency) = GetCurrencyFormatEx;
static int WINAPI hooked_GetCurrencyFormatEx(LPCWSTR lpLocaleName,  DWORD dwFlags,  LPCWSTR lpValue,  const CURRENCYFMTW *lpFormat,  LPWSTR lpCurrencyStr,  int cchCurrency) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCurrencyFormatEx(lpLocaleName, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetCurrencyFormatW)(LCID Locale,  DWORD dwFlags,  LPCWSTR lpValue,  const CURRENCYFMTW *lpFormat,  LPWSTR lpCurrencyStr,  int cchCurrency) = GetCurrencyFormatW;
static int WINAPI hooked_GetCurrencyFormatW(LCID Locale,  DWORD dwFlags,  LPCWSTR lpValue,  const CURRENCYFMTW *lpFormat,  LPWSTR lpCurrencyStr,  int cchCurrency) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetCurrencyFormatW(Locale, dwFlags, lpValue, lpFormat, lpCurrencyStr, cchCurrency); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetDurationFormat)(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDuration,  ULONGLONG ullDuration,  LPCWSTR lpFormat,  LPWSTR lpDurationStr,  int cchDuration) = GetDurationFormat;
static int WINAPI hooked_GetDurationFormat(LCID Locale,  DWORD dwFlags,  const SYSTEMTIME *lpDuration,  ULONGLONG ullDuration,  LPCWSTR lpFormat,  LPWSTR lpDurationStr,  int cchDuration) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetDurationFormat(Locale, dwFlags, lpDuration, ullDuration, lpFormat, lpDurationStr, cchDuration); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileMUIInfo)(DWORD dwFlags,  PCWSTR pcwszFilePath,  PFILEMUIINFO pFileMUIInfo,  DWORD *pcbFileMUIInfo) = GetFileMUIInfo;
static BOOL WINAPI hooked_GetFileMUIInfo(DWORD dwFlags,  PCWSTR pcwszFilePath,  PFILEMUIINFO pFileMUIInfo,  DWORD *pcbFileMUIInfo) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileMUIInfo(dwFlags, pcwszFilePath, pFileMUIInfo, pcbFileMUIInfo); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetDurationFormatEx)(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpDuration,  ULONGLONG ullDuration,  LPCWSTR lpFormat,  LPWSTR lpDurationStr,  int cchDuration) = GetDurationFormatEx;
static int WINAPI hooked_GetDurationFormatEx(LPCWSTR lpLocaleName,  DWORD dwFlags,  const SYSTEMTIME *lpDuration,  ULONGLONG ullDuration,  LPCWSTR lpFormat,  LPWSTR lpDurationStr,  int cchDuration) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetDurationFormatEx(lpLocaleName, dwFlags, lpDuration, ullDuration, lpFormat, lpDurationStr, cchDuration); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileMUIPath)(DWORD dwFlags,  PCWSTR pcwszFilePath,  PWSTR pwszLanguage,  PULONG pcchLanguage,  PWSTR pwszFileMUIPath,  PULONG pcchFileMUIPath,  PULONGLONG pululEnumerator) = GetFileMUIPath;
static BOOL WINAPI hooked_GetFileMUIPath(DWORD dwFlags,  PCWSTR pcwszFilePath,  PWSTR pwszLanguage,  PULONG pcchLanguage,  PWSTR pwszFileMUIPath,  PULONG pcchFileMUIPath,  PULONGLONG pululEnumerator) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileMUIPath(dwFlags, pcwszFilePath, pwszLanguage, pcchLanguage, pwszFileMUIPath, pcchFileMUIPath, pululEnumerator); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetGeoInfoA)(GEOID Location,  GEOTYPE GeoType,  LPSTR lpGeoData,  int cchData,  LANGID LangId) = GetGeoInfoA;
static int WINAPI hooked_GetGeoInfoA(GEOID Location,  GEOTYPE GeoType,  LPSTR lpGeoData,  int cchData,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetGeoInfoA(Location, GeoType, lpGeoData, cchData, LangId); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetGeoInfoEx)(PWSTR location,  GEOTYPE geoType,  PWSTR geoData,  int geoDataCount) = GetGeoInfoEx;
static int WINAPI hooked_GetGeoInfoEx(PWSTR location,  GEOTYPE geoType,  PWSTR geoData,  int geoDataCount) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetGeoInfoEx(location, geoType, geoData, geoDataCount); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetGeoInfoW)(GEOID Location,  GEOTYPE GeoType,  LPWSTR lpGeoData,  int cchData,  LANGID LangId) = GetGeoInfoW;
static int WINAPI hooked_GetGeoInfoW(GEOID Location,  GEOTYPE GeoType,  LPWSTR lpGeoData,  int cchData,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetGeoInfoW(Location, GeoType, lpGeoData, cchData, LangId); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetLocaleInfoA)(LCID Locale,  LCTYPE LCType,  LPSTR lpLCData,  int cchData) = GetLocaleInfoA;
static int WINAPI hooked_GetLocaleInfoA(LCID Locale,  LCTYPE LCType,  LPSTR lpLCData,  int cchData) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetLocaleInfoA(Locale, LCType, lpLCData, cchData); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetLocaleInfoEx)(LPCWSTR lpLocaleName,  LCTYPE LCType,  LPWSTR lpLCData,  int cchData) = GetLocaleInfoEx;
static int WINAPI hooked_GetLocaleInfoEx(LPCWSTR lpLocaleName,  LCTYPE LCType,  LPWSTR lpLCData,  int cchData) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetLocaleInfoEx(lpLocaleName, LCType, lpLCData, cchData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNLSVersionEx)(NLS_FUNCTION function,  LPCWSTR lpLocaleName,  LPNLSVERSIONINFOEX lpVersionInformation) = GetNLSVersionEx;
static BOOL WINAPI hooked_GetNLSVersionEx(NLS_FUNCTION function,  LPCWSTR lpLocaleName,  LPNLSVERSIONINFOEX lpVersionInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNLSVersionEx(function, lpLocaleName, lpVersionInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNLSVersion)(NLS_FUNCTION Function,  LCID Locale,  LPNLSVERSIONINFO lpVersionInformation) = GetNLSVersion;
static BOOL WINAPI hooked_GetNLSVersion(NLS_FUNCTION Function,  LCID Locale,  LPNLSVERSIONINFO lpVersionInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNLSVersion(Function, Locale, lpVersionInformation); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetLocaleInfoW)(LCID Locale,  LCTYPE LCType,  LPWSTR lpLCData,  int cchData) = GetLocaleInfoW;
static int WINAPI hooked_GetLocaleInfoW(LCID Locale,  LCTYPE LCType,  LPWSTR lpLCData,  int cchData) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetLocaleInfoW(Locale, LCType, lpLCData, cchData); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetNumberFormatA)(LCID Locale,  DWORD dwFlags,  LPCSTR lpValue,  const NUMBERFMTA *lpFormat,  LPSTR lpNumberStr,  int cchNumber) = GetNumberFormatA;
static int WINAPI hooked_GetNumberFormatA(LCID Locale,  DWORD dwFlags,  LPCSTR lpValue,  const NUMBERFMTA *lpFormat,  LPSTR lpNumberStr,  int cchNumber) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetNumberFormatA(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetNumberFormatEx)(LPCWSTR lpLocaleName,  DWORD dwFlags,  LPCWSTR lpValue,  const NUMBERFMTW *lpFormat,  LPWSTR lpNumberStr,  int cchNumber) = GetNumberFormatEx;
static int WINAPI hooked_GetNumberFormatEx(LPCWSTR lpLocaleName,  DWORD dwFlags,  LPCWSTR lpValue,  const NUMBERFMTW *lpFormat,  LPWSTR lpNumberStr,  int cchNumber) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetNumberFormatEx(lpLocaleName, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetOEMCP)() = GetOEMCP;
static UINT WINAPI hooked_GetOEMCP() {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetOEMCP(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetNumberFormatW)(LCID Locale,  DWORD dwFlags,  LPCWSTR lpValue,  const NUMBERFMTW *lpFormat,  LPWSTR lpNumberStr,  int cchNumber) = GetNumberFormatW;
static int WINAPI hooked_GetNumberFormatW(LCID Locale,  DWORD dwFlags,  LPCWSTR lpValue,  const NUMBERFMTW *lpFormat,  LPWSTR lpNumberStr,  int cchNumber) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetNumberFormatW(Locale, dwFlags, lpValue, lpFormat, lpNumberStr, cchNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProcessPreferredUILanguages)(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) = GetProcessPreferredUILanguages;
static BOOL WINAPI hooked_GetProcessPreferredUILanguages(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetStringScripts)(DWORD dwFlags,  LPCWSTR lpString,  int cchString,  LPWSTR lpScripts,  int cchScripts) = GetStringScripts;
static int WINAPI hooked_GetStringScripts(DWORD dwFlags,  LPCWSTR lpString,  int cchString,  LPWSTR lpScripts,  int cchScripts) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetStringScripts(dwFlags, lpString, cchString, lpScripts, cchScripts); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetStringTypeA)(LCID Locale,  DWORD dwInfoType,  LPCSTR lpSrcStr,  int cchSrc,  LPWORD lpCharType) = GetStringTypeA;
static BOOL WINAPI hooked_GetStringTypeA(LCID Locale,  DWORD dwInfoType,  LPCSTR lpSrcStr,  int cchSrc,  LPWORD lpCharType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetStringTypeA(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_GetSystemDefaultLangID)() = GetSystemDefaultLangID;
static LANGID WINAPI hooked_GetSystemDefaultLangID() {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_GetSystemDefaultLangID(); });

	SEND_AFTER_CALL

    return result;
}

static LCID (WINAPI *og_GetSystemDefaultLCID)() = GetSystemDefaultLCID;
static LCID WINAPI hooked_GetSystemDefaultLCID() {

	SEND_BEFORE_CALL

	
    LCID result;
    TIME({ result = og_GetSystemDefaultLCID(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetSystemDefaultLocaleName)(LPWSTR lpLocaleName,  int cchLocaleName) = GetSystemDefaultLocaleName;
static int WINAPI hooked_GetSystemDefaultLocaleName(LPWSTR lpLocaleName,  int cchLocaleName) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetSystemDefaultLocaleName(lpLocaleName, cchLocaleName); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_GetSystemDefaultUILanguage)() = GetSystemDefaultUILanguage;
static LANGID WINAPI hooked_GetSystemDefaultUILanguage() {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_GetSystemDefaultUILanguage(); });

	SEND_AFTER_CALL

    return result;
}

static LCID (WINAPI *og_GetThreadLocale)() = GetThreadLocale;
static LCID WINAPI hooked_GetThreadLocale() {

	SEND_BEFORE_CALL

	
    LCID result;
    TIME({ result = og_GetThreadLocale(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetSystemPreferredUILanguages)(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) = GetSystemPreferredUILanguages;
static BOOL WINAPI hooked_GetSystemPreferredUILanguages(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetThreadPreferredUILanguages)(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) = GetThreadPreferredUILanguages;
static BOOL WINAPI hooked_GetThreadPreferredUILanguages(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetThreadPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_GetThreadUILanguage)() = GetThreadUILanguage;
static LANGID WINAPI hooked_GetThreadUILanguage() {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_GetThreadUILanguage(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetUserDefaultGeoName)(LPWSTR geoName,  int geoNameCount) = GetUserDefaultGeoName;
static int WINAPI hooked_GetUserDefaultGeoName(LPWSTR geoName,  int geoNameCount) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetUserDefaultGeoName(geoName, geoNameCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetUILanguageInfo)(DWORD dwFlags,  PCZZWSTR pwmszLanguage,  PZZWSTR pwszFallbackLanguages,  PDWORD pcchFallbackLanguages,  PDWORD pAttributes) = GetUILanguageInfo;
static BOOL WINAPI hooked_GetUILanguageInfo(DWORD dwFlags,  PCZZWSTR pwmszLanguage,  PZZWSTR pwszFallbackLanguages,  PDWORD pcchFallbackLanguages,  PDWORD pAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetUILanguageInfo(dwFlags, pwmszLanguage, pwszFallbackLanguages, pcchFallbackLanguages, pAttributes); });

	SEND_AFTER_CALL

    return result;
}

static LCID (WINAPI *og_GetUserDefaultLCID)() = GetUserDefaultLCID;
static LCID WINAPI hooked_GetUserDefaultLCID() {

	SEND_BEFORE_CALL

	
    LCID result;
    TIME({ result = og_GetUserDefaultLCID(); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_GetUserDefaultLocaleName)(LPWSTR lpLocaleName,  int cchLocaleName) = GetUserDefaultLocaleName;
static int WINAPI hooked_GetUserDefaultLocaleName(LPWSTR lpLocaleName,  int cchLocaleName) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_GetUserDefaultLocaleName(lpLocaleName, cchLocaleName); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_GetUserDefaultLangID)() = GetUserDefaultLangID;
static LANGID WINAPI hooked_GetUserDefaultLangID() {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_GetUserDefaultLangID(); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_GetUserDefaultUILanguage)() = GetUserDefaultUILanguage;
static LANGID WINAPI hooked_GetUserDefaultUILanguage() {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_GetUserDefaultUILanguage(); });

	SEND_AFTER_CALL

    return result;
}

static GEOID (WINAPI *og_GetUserGeoID)(GEOCLASS GeoClass) = GetUserGeoID;
static GEOID WINAPI hooked_GetUserGeoID(GEOCLASS GeoClass) {

	SEND_BEFORE_CALL

	
    GEOID result;
    TIME({ result = og_GetUserGeoID(GeoClass); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetUserPreferredUILanguages)(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) = GetUserPreferredUILanguages;
static BOOL WINAPI hooked_GetUserPreferredUILanguages(DWORD dwFlags,  PULONG pulNumLanguages,  PZZWSTR pwszLanguagesBuffer,  PULONG pcchLanguagesBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetUserPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsDBCSLeadByte)(BYTE TestChar) = IsDBCSLeadByte;
static BOOL WINAPI hooked_IsDBCSLeadByte(BYTE TestChar) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsDBCSLeadByte(TestChar); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsDBCSLeadByteEx)(UINT CodePage,  BYTE TestChar) = IsDBCSLeadByteEx;
static BOOL WINAPI hooked_IsDBCSLeadByteEx(UINT CodePage,  BYTE TestChar) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsDBCSLeadByteEx(CodePage, TestChar); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsNLSDefinedString)(NLS_FUNCTION Function,  DWORD dwFlags,  LPNLSVERSIONINFO lpVersionInformation,  LPCWSTR lpString,  INT cchStr) = IsNLSDefinedString;
static BOOL WINAPI hooked_IsNLSDefinedString(NLS_FUNCTION Function,  DWORD dwFlags,  LPNLSVERSIONINFO lpVersionInformation,  LPCWSTR lpString,  INT cchStr) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsNLSDefinedString(Function, dwFlags, lpVersionInformation, lpString, cchStr); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsValidCodePage)(UINT CodePage) = IsValidCodePage;
static BOOL WINAPI hooked_IsValidCodePage(UINT CodePage) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsValidCodePage(CodePage); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsValidLanguageGroup)(LGRPID LanguageGroup,  DWORD dwFlags) = IsValidLanguageGroup;
static BOOL WINAPI hooked_IsValidLanguageGroup(LGRPID LanguageGroup,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsValidLanguageGroup(LanguageGroup, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsValidLocale)(LCID Locale,  DWORD dwFlags) = IsValidLocale;
static BOOL WINAPI hooked_IsValidLocale(LCID Locale,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsValidLocale(Locale, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsValidLocaleName)(LPCWSTR lpLocaleName) = IsValidLocaleName;
static BOOL WINAPI hooked_IsValidLocaleName(LPCWSTR lpLocaleName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsValidLocaleName(lpLocaleName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_IsValidNLSVersion)(NLS_FUNCTION function,  LPCWSTR lpLocaleName,  LPNLSVERSIONINFOEX lpVersionInformation) = IsValidNLSVersion;
static DWORD WINAPI hooked_IsValidNLSVersion(NLS_FUNCTION function,  LPCWSTR lpLocaleName,  LPNLSVERSIONINFOEX lpVersionInformation) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_IsValidNLSVersion(function, lpLocaleName, lpVersionInformation); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_LCMapStringA)(LCID Locale,  DWORD dwMapFlags,  LPCSTR lpSrcStr,  int cchSrc,  LPSTR lpDestStr,  int cchDest) = LCMapStringA;
static int WINAPI hooked_LCMapStringA(LCID Locale,  DWORD dwMapFlags,  LPCSTR lpSrcStr,  int cchSrc,  LPSTR lpDestStr,  int cchDest) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_LCIDToLocaleName)(LCID Locale,  LPWSTR lpName,  int cchName,  DWORD dwFlags) = LCIDToLocaleName;
static int WINAPI hooked_LCIDToLocaleName(LCID Locale,  LPWSTR lpName,  int cchName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_LCIDToLocaleName(Locale, lpName, cchName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsActiveSessionCountLimited)() = IsActiveSessionCountLimited;
static bool WINAPI hooked_IsActiveSessionCountLimited() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsActiveSessionCountLimited(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindows10OrGreater)() = IsWindows10OrGreater;
static bool WINAPI hooked_IsWindows10OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindows10OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindows7OrGreater)() = IsWindows7OrGreater;
static bool WINAPI hooked_IsWindows7OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindows7OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindows7SP1OrGreater)() = IsWindows7SP1OrGreater;
static bool WINAPI hooked_IsWindows7SP1OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindows7SP1OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindows8OrGreater)() = IsWindows8OrGreater;
static bool WINAPI hooked_IsWindows8OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindows8OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindows8Point1OrGreater)() = IsWindows8Point1OrGreater;
static bool WINAPI hooked_IsWindows8Point1OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindows8Point1OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsServer)() = IsWindowsServer;
static bool WINAPI hooked_IsWindowsServer() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsServer(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsVistaOrGreater)() = IsWindowsVistaOrGreater;
static bool WINAPI hooked_IsWindowsVistaOrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsVistaOrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsVistaSP1OrGreater)() = IsWindowsVistaSP1OrGreater;
static bool WINAPI hooked_IsWindowsVistaSP1OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsVistaSP1OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsVistaSP2OrGreater)() = IsWindowsVistaSP2OrGreater;
static bool WINAPI hooked_IsWindowsVistaSP2OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsVistaSP2OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsXPSP2OrGreater)() = IsWindowsXPSP2OrGreater;
static bool WINAPI hooked_IsWindowsXPSP2OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsXPSP2OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsXPOrGreater)() = IsWindowsXPOrGreater;
static bool WINAPI hooked_IsWindowsXPOrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsXPOrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsXPSP1OrGreater)() = IsWindowsXPSP1OrGreater;
static bool WINAPI hooked_IsWindowsXPSP1OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsXPSP1OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static bool (WINAPI *og_IsWindowsXPSP3OrGreater)() = IsWindowsXPSP3OrGreater;
static bool WINAPI hooked_IsWindowsXPSP3OrGreater() {

	SEND_BEFORE_CALL

	
    bool result;
    TIME({ result = og_IsWindowsXPSP3OrGreater(); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterAdditionalProcess)(DWORD processId,  DWORD captureExtraInfoForThreadId) = WerRegisterAdditionalProcess;
static HRESULT WINAPI hooked_WerRegisterAdditionalProcess(DWORD processId,  DWORD captureExtraInfoForThreadId) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterAdditionalProcess(processId, captureExtraInfoForThreadId); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerGetFlags)(HANDLE hProcess,  PDWORD pdwFlags) = WerGetFlags;
static HRESULT WINAPI hooked_WerGetFlags(HANDLE hProcess,  PDWORD pdwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerGetFlags(hProcess, pdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterCustomMetadata)(PCWSTR key, PCWSTR value) = WerRegisterCustomMetadata;
static HRESULT WINAPI hooked_WerRegisterCustomMetadata(PCWSTR key, PCWSTR value) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterCustomMetadata(key, value); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterExcludedMemoryBlock)(const void *address, DWORD size) = WerRegisterExcludedMemoryBlock;
static HRESULT WINAPI hooked_WerRegisterExcludedMemoryBlock(const void *address, DWORD size) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterExcludedMemoryBlock(address, size); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterFile)(PCWSTR pwzFile,  WER_REGISTER_FILE_TYPE regFileType,  DWORD dwFlags) = WerRegisterFile;
static HRESULT WINAPI hooked_WerRegisterFile(PCWSTR pwzFile,  WER_REGISTER_FILE_TYPE regFileType,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterFile(pwzFile, regFileType, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterMemoryBlock)(PVOID pvAddress,  DWORD dwSize) = WerRegisterMemoryBlock;
static HRESULT WINAPI hooked_WerRegisterMemoryBlock(PVOID pvAddress,  DWORD dwSize) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterMemoryBlock(pvAddress, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerRegisterRuntimeExceptionModule)(PCWSTR pwszOutOfProcessCallbackDll,  PVOID pContext) = WerRegisterRuntimeExceptionModule;
static HRESULT WINAPI hooked_WerRegisterRuntimeExceptionModule(PCWSTR pwszOutOfProcessCallbackDll,  PVOID pContext) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerRegisterRuntimeExceptionModule(pwszOutOfProcessCallbackDll, pContext); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerSetFlags)(DWORD dwFlags) = WerSetFlags;
static HRESULT WINAPI hooked_WerSetFlags(DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerSetFlags(dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterAdditionalProcess)(DWORD processId) = WerUnregisterAdditionalProcess;
static HRESULT WINAPI hooked_WerUnregisterAdditionalProcess(DWORD processId) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterAdditionalProcess(processId); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterCustomMetadata)(PCWSTR key) = WerUnregisterCustomMetadata;
static HRESULT WINAPI hooked_WerUnregisterCustomMetadata(PCWSTR key) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterCustomMetadata(key); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterExcludedMemoryBlock)(const void *address) = WerUnregisterExcludedMemoryBlock;
static HRESULT WINAPI hooked_WerUnregisterExcludedMemoryBlock(const void *address) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterExcludedMemoryBlock(address); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterFile)(PCWSTR pwzFilePath) = WerUnregisterFile;
static HRESULT WINAPI hooked_WerUnregisterFile(PCWSTR pwzFilePath) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterFile(pwzFilePath); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterMemoryBlock)(PVOID pvAddress) = WerUnregisterMemoryBlock;
static HRESULT WINAPI hooked_WerUnregisterMemoryBlock(PVOID pvAddress) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterMemoryBlock(pvAddress); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_WerUnregisterRuntimeExceptionModule)(PCWSTR pwszOutOfProcessCallbackDll,  PVOID pContext) = WerUnregisterRuntimeExceptionModule;
static HRESULT WINAPI hooked_WerUnregisterRuntimeExceptionModule(PCWSTR pwszOutOfProcessCallbackDll,  PVOID pContext) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_WerUnregisterRuntimeExceptionModule(pwszOutOfProcessCallbackDll, pContext); });

	SEND_AFTER_CALL

    return result;
}

static HFILE (WINAPI *og__lclose)(HFILE hFile) = _lclose;
static HFILE WINAPI hooked__lclose(HFILE hFile) {

	SEND_BEFORE_CALL

	
    HFILE result;
    TIME({ result = og__lclose(hFile); });

	SEND_AFTER_CALL

    return result;
}

static HFILE (WINAPI *og__lcreat)(LPCSTR lpPathName, int iAttribute) = _lcreat;
static HFILE WINAPI hooked__lcreat(LPCSTR lpPathName, int iAttribute) {

	SEND_BEFORE_CALL

	
    HFILE result;
    TIME({ result = og__lcreat(lpPathName, iAttribute); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og__llseek)(HFILE hFile, LONG lOffset, int iOrigin) = _llseek;
static LONG WINAPI hooked__llseek(HFILE hFile, LONG lOffset, int iOrigin) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og__llseek(hFile, lOffset, iOrigin); });

	SEND_AFTER_CALL

    return result;
}

static HFILE (WINAPI *og__lopen)(LPCSTR lpPathName, int iReadWrite) = _lopen;
static HFILE WINAPI hooked__lopen(LPCSTR lpPathName, int iReadWrite) {

	SEND_BEFORE_CALL

	
    HFILE result;
    TIME({ result = og__lopen(lpPathName, iReadWrite); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og__lread)(HFILE hFile, LPVOID lpBuffer, UINT uBytes) = _lread;
static UINT WINAPI hooked__lread(HFILE hFile, LPVOID lpBuffer, UINT uBytes) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og__lread(hFile, lpBuffer, uBytes); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og__lwrite)(HFILE hFile, LPCCH lpBuffer, UINT uBytes) = _lwrite;
static UINT WINAPI hooked__lwrite(HFILE hFile, LPCCH lpBuffer, UINT uBytes) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og__lwrite(hFile, lpBuffer, uBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ActivateActCtx)(HANDLE hActCtx,  ULONG_PTR *lpCookie) = ActivateActCtx;
static BOOL WINAPI hooked_ActivateActCtx(HANDLE hActCtx,  ULONG_PTR *lpCookie) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ActivateActCtx(hActCtx, lpCookie); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_AddAtomA)(LPCSTR lpString) = AddAtomA;
static ATOM WINAPI hooked_AddAtomA(LPCSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_AddAtomA(lpString); });

	SEND_AFTER_CALL

    return result;
}

static ATOM (WINAPI *og_AddAtomW)(LPCWSTR lpString) = AddAtomW;
static ATOM WINAPI hooked_AddAtomW(LPCWSTR lpString) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_AddAtomW(lpString); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AddIntegrityLabelToBoundaryDescriptor)(HANDLE *BoundaryDescriptor,  PSID IntegrityLabel) = AddIntegrityLabelToBoundaryDescriptor;
static BOOL WINAPI hooked_AddIntegrityLabelToBoundaryDescriptor(HANDLE *BoundaryDescriptor,  PSID IntegrityLabel) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AddIntegrityLabelToBoundaryDescriptor(BoundaryDescriptor, IntegrityLabel); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_AddRefActCtx)(HANDLE hActCtx) = AddRefActCtx;
static VOID WINAPI hooked_AddRefActCtx(HANDLE hActCtx) {

	SEND_BEFORE_CALL

	
	TIME({ og_AddRefActCtx(hActCtx); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_AddSecureMemoryCacheCallback)(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack) = AddSecureMemoryCacheCallback;
static BOOL WINAPI hooked_AddSecureMemoryCacheCallback(PSECURE_MEMORY_CACHE_CALLBACK pfnCallBack) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AddSecureMemoryCacheCallback(pfnCallBack); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_ApplicationRecoveryFinished)(BOOL bSuccess) = ApplicationRecoveryFinished;
static VOID WINAPI hooked_ApplicationRecoveryFinished(BOOL bSuccess) {

	SEND_BEFORE_CALL

	
	TIME({ og_ApplicationRecoveryFinished(bSuccess); });

	SEND_AFTER_CALL
	
}

static HRESULT (WINAPI *og_ApplicationRecoveryInProgress)(PBOOL pbCancelled) = ApplicationRecoveryInProgress;
static HRESULT WINAPI hooked_ApplicationRecoveryInProgress(PBOOL pbCancelled) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_ApplicationRecoveryInProgress(pbCancelled); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BackupRead)(HANDLE hFile,  LPBYTE lpBuffer,  DWORD nNumberOfBytesToRead,  LPDWORD lpNumberOfBytesRead,  BOOL bAbort,  BOOL bProcessSecurity,  LPVOID *lpContext) = BackupRead;
static BOOL WINAPI hooked_BackupRead(HANDLE hFile,  LPBYTE lpBuffer,  DWORD nNumberOfBytesToRead,  LPDWORD lpNumberOfBytesRead,  BOOL bAbort,  BOOL bProcessSecurity,  LPVOID *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BackupRead(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, bAbort, bProcessSecurity, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BackupSeek)(HANDLE hFile,  DWORD dwLowBytesToSeek,  DWORD dwHighBytesToSeek,  LPDWORD lpdwLowByteSeeked,  LPDWORD lpdwHighByteSeeked,  LPVOID *lpContext) = BackupSeek;
static BOOL WINAPI hooked_BackupSeek(HANDLE hFile,  DWORD dwLowBytesToSeek,  DWORD dwHighBytesToSeek,  LPDWORD lpdwLowByteSeeked,  LPDWORD lpdwHighByteSeeked,  LPVOID *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BackupSeek(hFile, dwLowBytesToSeek, dwHighBytesToSeek, lpdwLowByteSeeked, lpdwHighByteSeeked, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BackupWrite)(HANDLE hFile,  LPBYTE lpBuffer,  DWORD nNumberOfBytesToWrite,  LPDWORD lpNumberOfBytesWritten,  BOOL bAbort,  BOOL bProcessSecurity,  LPVOID *lpContext) = BackupWrite;
static BOOL WINAPI hooked_BackupWrite(HANDLE hFile,  LPBYTE lpBuffer,  DWORD nNumberOfBytesToWrite,  LPDWORD lpNumberOfBytesWritten,  BOOL bAbort,  BOOL bProcessSecurity,  LPVOID *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BackupWrite(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, bAbort, bProcessSecurity, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_BeginUpdateResourceA)(LPCSTR pFileName,  BOOL bDeleteExistingResources) = BeginUpdateResourceA;
static HANDLE WINAPI hooked_BeginUpdateResourceA(LPCSTR pFileName,  BOOL bDeleteExistingResources) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_BeginUpdateResourceA(pFileName, bDeleteExistingResources); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_BeginUpdateResourceW)(LPCWSTR pFileName,  BOOL bDeleteExistingResources) = BeginUpdateResourceW;
static HANDLE WINAPI hooked_BeginUpdateResourceW(LPCWSTR pFileName,  BOOL bDeleteExistingResources) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_BeginUpdateResourceW(pFileName, bDeleteExistingResources); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BindIoCompletionCallback)(HANDLE FileHandle,  LPOVERLAPPED_COMPLETION_ROUTINE Function,  ULONG Flags) = BindIoCompletionCallback;
static BOOL WINAPI hooked_BindIoCompletionCallback(HANDLE FileHandle,  LPOVERLAPPED_COMPLETION_ROUTINE Function,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BindIoCompletionCallback(FileHandle, Function, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BuildCommDCBA)(LPCSTR lpDef,  LPDCB lpDCB) = BuildCommDCBA;
static BOOL WINAPI hooked_BuildCommDCBA(LPCSTR lpDef,  LPDCB lpDCB) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BuildCommDCBA(lpDef, lpDCB); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BuildCommDCBAndTimeoutsA)(LPCSTR lpDef,  LPDCB lpDCB,  LPCOMMTIMEOUTS lpCommTimeouts) = BuildCommDCBAndTimeoutsA;
static BOOL WINAPI hooked_BuildCommDCBAndTimeoutsA(LPCSTR lpDef,  LPDCB lpDCB,  LPCOMMTIMEOUTS lpCommTimeouts) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BuildCommDCBAndTimeoutsA(lpDef, lpDCB, lpCommTimeouts); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BuildCommDCBAndTimeoutsW)(LPCWSTR lpDef,  LPDCB lpDCB,  LPCOMMTIMEOUTS lpCommTimeouts) = BuildCommDCBAndTimeoutsW;
static BOOL WINAPI hooked_BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,  LPDCB lpDCB,  LPCOMMTIMEOUTS lpCommTimeouts) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BuildCommDCBAndTimeoutsW(lpDef, lpDCB, lpCommTimeouts); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CallNamedPipeA)(LPCSTR lpNamedPipeName,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  DWORD nTimeOut) = CallNamedPipeA;
static BOOL WINAPI hooked_CallNamedPipeA(LPCSTR lpNamedPipeName,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesRead,  DWORD nTimeOut) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CallNamedPipeA(lpNamedPipeName, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesRead, nTimeOut); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_BuildCommDCBW)(LPCWSTR lpDef,  LPDCB lpDCB) = BuildCommDCBW;
static BOOL WINAPI hooked_BuildCommDCBW(LPCWSTR lpDef,  LPDCB lpDCB) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_BuildCommDCBW(lpDef, lpDCB); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CheckNameLegalDOS8Dot3A)(LPCSTR lpName,  LPSTR lpOemName,  DWORD OemNameSize,  PBOOL pbNameContainsSpaces,  PBOOL pbNameLegal) = CheckNameLegalDOS8Dot3A;
static BOOL WINAPI hooked_CheckNameLegalDOS8Dot3A(LPCSTR lpName,  LPSTR lpOemName,  DWORD OemNameSize,  PBOOL pbNameContainsSpaces,  PBOOL pbNameLegal) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CheckNameLegalDOS8Dot3A(lpName, lpOemName, OemNameSize, pbNameContainsSpaces, pbNameLegal); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CheckNameLegalDOS8Dot3W)(LPCWSTR lpName,  LPSTR lpOemName,  DWORD OemNameSize,  PBOOL pbNameContainsSpaces,  PBOOL pbNameLegal) = CheckNameLegalDOS8Dot3W;
static BOOL WINAPI hooked_CheckNameLegalDOS8Dot3W(LPCWSTR lpName,  LPSTR lpOemName,  DWORD OemNameSize,  PBOOL pbNameContainsSpaces,  PBOOL pbNameLegal) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CheckNameLegalDOS8Dot3W(lpName, lpOemName, OemNameSize, pbNameContainsSpaces, pbNameLegal); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ClearCommBreak)(HANDLE hFile) = ClearCommBreak;
static BOOL WINAPI hooked_ClearCommBreak(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ClearCommBreak(hFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ClearCommError)(HANDLE hFile,  LPDWORD lpErrors,  LPCOMSTAT lpStat) = ClearCommError;
static BOOL WINAPI hooked_ClearCommError(HANDLE hFile,  LPDWORD lpErrors,  LPCOMSTAT lpStat) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ClearCommError(hFile, lpErrors, lpStat); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CommConfigDialogA)(LPCSTR lpszName,  HWND hWnd,  LPCOMMCONFIG lpCC) = CommConfigDialogA;
static BOOL WINAPI hooked_CommConfigDialogA(LPCSTR lpszName,  HWND hWnd,  LPCOMMCONFIG lpCC) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CommConfigDialogA(lpszName, hWnd, lpCC); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CommConfigDialogW)(LPCWSTR lpszName,  HWND hWnd,  LPCOMMCONFIG lpCC) = CommConfigDialogW;
static BOOL WINAPI hooked_CommConfigDialogW(LPCWSTR lpszName,  HWND hWnd,  LPCOMMCONFIG lpCC) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CommConfigDialogW(lpszName, hWnd, lpCC); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ConvertFiberToThread)() = ConvertFiberToThread;
static BOOL WINAPI hooked_ConvertFiberToThread() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ConvertFiberToThread(); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_ConvertThreadToFiber)(LPVOID lpParameter) = ConvertThreadToFiber;
static LPVOID WINAPI hooked_ConvertThreadToFiber(LPVOID lpParameter) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_ConvertThreadToFiber(lpParameter); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_ConvertThreadToFiberEx)(LPVOID lpParameter,  DWORD dwFlags) = ConvertThreadToFiberEx;
static LPVOID WINAPI hooked_ConvertThreadToFiberEx(LPVOID lpParameter,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_ConvertThreadToFiberEx(lpParameter, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyContext)(PCONTEXT Destination,  DWORD ContextFlags,  PCONTEXT Source) = CopyContext;
static BOOL WINAPI hooked_CopyContext(PCONTEXT Destination,  DWORD ContextFlags,  PCONTEXT Source) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyContext(Destination, ContextFlags, Source); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFile)(LPCTSTR lpExistingFileName,  LPCTSTR lpNewFileName,  BOOL bFailIfExists) = CopyFile;
static BOOL WINAPI hooked_CopyFile(LPCTSTR lpExistingFileName,  LPCTSTR lpNewFileName,  BOOL bFailIfExists) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFile(lpExistingFileName, lpNewFileName, bFailIfExists); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_CopyFile2)(PCWSTR pwszExistingFileName,  PCWSTR pwszNewFileName,  COPYFILE2_EXTENDED_PARAMETERS *pExtendedParameters) = CopyFile2;
static HRESULT WINAPI hooked_CopyFile2(PCWSTR pwszExistingFileName,  PCWSTR pwszNewFileName,  COPYFILE2_EXTENDED_PARAMETERS *pExtendedParameters) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_CopyFile2(pwszExistingFileName, pwszNewFileName, pExtendedParameters); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  BOOL bFailIfExists) = CopyFileA;
static BOOL WINAPI hooked_CopyFileA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  BOOL bFailIfExists) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileA(lpExistingFileName, lpNewFileName, bFailIfExists); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileExA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags) = CopyFileExA;
static BOOL WINAPI hooked_CopyFileExA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileExA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileExW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags) = CopyFileExW;
static BOOL WINAPI hooked_CopyFileExW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileExW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileTransactedA)(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags,  HANDLE hTransaction) = CopyFileTransactedA;
static BOOL WINAPI hooked_CopyFileTransactedA(LPCSTR lpExistingFileName,  LPCSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileTransactedA(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileTransactedW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags,  HANDLE hTransaction) = CopyFileTransactedW;
static BOOL WINAPI hooked_CopyFileTransactedW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  LPPROGRESS_ROUTINE lpProgressRoutine,  LPVOID lpData,  LPBOOL pbCancel,  DWORD dwCopyFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileTransactedW(lpExistingFileName, lpNewFileName, lpProgressRoutine, lpData, pbCancel, dwCopyFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateActCtxA)(PCACTCTXA pActCtx) = CreateActCtxA;
static HANDLE WINAPI hooked_CreateActCtxA(PCACTCTXA pActCtx) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateActCtxA(pActCtx); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CopyFileW)(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  BOOL bFailIfExists) = CopyFileW;
static BOOL WINAPI hooked_CopyFileW(LPCWSTR lpExistingFileName,  LPCWSTR lpNewFileName,  BOOL bFailIfExists) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CopyFileW(lpExistingFileName, lpNewFileName, bFailIfExists); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateActCtxW)(PCACTCTXW pActCtx) = CreateActCtxW;
static HANDLE WINAPI hooked_CreateActCtxW(PCACTCTXW pActCtx) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateActCtxW(pActCtx); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateBoundaryDescriptorA)(LPCSTR Name,  ULONG Flags) = CreateBoundaryDescriptorA;
static HANDLE WINAPI hooked_CreateBoundaryDescriptorA(LPCSTR Name,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateBoundaryDescriptorA(Name, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectory)(LPCTSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectory;
static BOOL WINAPI hooked_CreateDirectory(LPCTSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectory(lpPathName, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryExA)(LPCSTR lpTemplateDirectory,  LPCSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryExA;
static BOOL WINAPI hooked_CreateDirectoryExA(LPCSTR lpTemplateDirectory,  LPCSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryExA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryExW)(LPCWSTR lpTemplateDirectory,  LPCWSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryExW;
static BOOL WINAPI hooked_CreateDirectoryExW(LPCWSTR lpTemplateDirectory,  LPCWSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryExW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryTransactedA)(LPCSTR lpTemplateDirectory,  LPCSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) = CreateDirectoryTransactedA;
static BOOL WINAPI hooked_CreateDirectoryTransactedA(LPCSTR lpTemplateDirectory,  LPCSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryTransactedA(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_CreateFiber)(SIZE_T dwStackSize,  LPFIBER_START_ROUTINE lpStartAddress,  LPVOID lpParameter) = CreateFiber;
static LPVOID WINAPI hooked_CreateFiber(SIZE_T dwStackSize,  LPFIBER_START_ROUTINE lpStartAddress,  LPVOID lpParameter) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_CreateFiber(dwStackSize, lpStartAddress, lpParameter); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryTransactedW)(LPCWSTR lpTemplateDirectory,  LPCWSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) = CreateDirectoryTransactedW;
static BOOL WINAPI hooked_CreateDirectoryTransactedW(LPCWSTR lpTemplateDirectory,  LPCWSTR lpNewDirectory,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryTransactedW(lpTemplateDirectory, lpNewDirectory, lpSecurityAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_CreateFiberEx)(SIZE_T dwStackCommitSize,  SIZE_T dwStackReserveSize,  DWORD dwFlags,  LPFIBER_START_ROUTINE lpStartAddress,  LPVOID lpParameter) = CreateFiberEx;
static LPVOID WINAPI hooked_CreateFiberEx(SIZE_T dwStackCommitSize,  SIZE_T dwStackReserveSize,  DWORD dwFlags,  LPFIBER_START_ROUTINE lpStartAddress,  LPVOID lpParameter) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_CreateFiberEx(dwStackCommitSize, dwStackReserveSize, dwFlags, lpStartAddress, lpParameter); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMappingA)(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCSTR lpName) = CreateFileMappingA;
static HANDLE WINAPI hooked_CreateFileMappingA(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMappingA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileMappingNumaA)(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCSTR lpName,  DWORD nndPreferred) = CreateFileMappingNumaA;
static HANDLE WINAPI hooked_CreateFileMappingNumaA(HANDLE hFile,  LPSECURITY_ATTRIBUTES lpFileMappingAttributes,  DWORD flProtect,  DWORD dwMaximumSizeHigh,  DWORD dwMaximumSizeLow,  LPCSTR lpName,  DWORD nndPreferred) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileMappingNumaA(hFile, lpFileMappingAttributes, flProtect, dwMaximumSizeHigh, dwMaximumSizeLow, lpName, nndPreferred); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileTransactedA)(LPCSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile,  HANDLE hTransaction,  PUSHORT pusMiniVersion, PVOID lpExtendedParameter) = CreateFileTransactedA;
static HANDLE WINAPI hooked_CreateFileTransactedA(LPCSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile,  HANDLE hTransaction,  PUSHORT pusMiniVersion, PVOID lpExtendedParameter) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileTransactedA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, hTransaction, pusMiniVersion, lpExtendedParameter); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileTransactedW)(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile,  HANDLE hTransaction,  PUSHORT pusMiniVersion, PVOID lpExtendedParameter) = CreateFileTransactedW;
static HANDLE WINAPI hooked_CreateFileTransactedW(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile,  HANDLE hTransaction,  PUSHORT pusMiniVersion, PVOID lpExtendedParameter) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileTransactedW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, hTransaction, pusMiniVersion, lpExtendedParameter); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateHardLinkA)(LPCSTR lpFileName,  LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateHardLinkA;
static BOOL WINAPI hooked_CreateHardLinkA(LPCSTR lpFileName,  LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateHardLinkA(lpFileName, lpExistingFileName, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateHardLinkTransactedA)(LPCSTR lpFileName,  LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) = CreateHardLinkTransactedA;
static BOOL WINAPI hooked_CreateHardLinkTransactedA(LPCSTR lpFileName,  LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateHardLinkTransactedA(lpFileName, lpExistingFileName, lpSecurityAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateHardLinkTransactedW)(LPCWSTR lpFileName,  LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) = CreateHardLinkTransactedW;
static BOOL WINAPI hooked_CreateHardLinkTransactedW(LPCWSTR lpFileName,  LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateHardLinkTransactedW(lpFileName, lpExistingFileName, lpSecurityAttributes, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateJobObjectA)(LPSECURITY_ATTRIBUTES lpJobAttributes,  LPCSTR lpName) = CreateJobObjectA;
static HANDLE WINAPI hooked_CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateJobObjectA(lpJobAttributes, lpName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateHardLinkW)(LPCWSTR lpFileName,  LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateHardLinkW;
static BOOL WINAPI hooked_CreateHardLinkW(LPCWSTR lpFileName,  LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateHardLinkW(lpFileName, lpExistingFileName, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMailslotA)(LPCSTR lpName,  DWORD nMaxMessageSize,  DWORD lReadTimeout,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateMailslotA;
static HANDLE WINAPI hooked_CreateMailslotA(LPCSTR lpName,  DWORD nMaxMessageSize,  DWORD lReadTimeout,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMailslotW)(LPCWSTR lpName,  DWORD nMaxMessageSize,  DWORD lReadTimeout,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateMailslotW;
static HANDLE WINAPI hooked_CreateMailslotW(LPCWSTR lpName,  DWORD nMaxMessageSize,  DWORD lReadTimeout,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateNamedPipeA)(LPCSTR lpName,  DWORD dwOpenMode,  DWORD dwPipeMode,  DWORD nMaxInstances,  DWORD nOutBufferSize,  DWORD nInBufferSize,  DWORD nDefaultTimeOut,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateNamedPipeA;
static HANDLE WINAPI hooked_CreateNamedPipeA(LPCSTR lpName,  DWORD dwOpenMode,  DWORD dwPipeMode,  DWORD nMaxInstances,  DWORD nOutBufferSize,  DWORD nInBufferSize,  DWORD nDefaultTimeOut,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateNamedPipeA(lpName, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreatePrivateNamespaceA)(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,  LPVOID lpBoundaryDescriptor,  LPCSTR lpAliasPrefix) = CreatePrivateNamespaceA;
static HANDLE WINAPI hooked_CreatePrivateNamespaceA(LPSECURITY_ATTRIBUTES lpPrivateNamespaceAttributes,  LPVOID lpBoundaryDescriptor,  LPCSTR lpAliasPrefix) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreatePrivateNamespaceA(lpPrivateNamespaceAttributes, lpBoundaryDescriptor, lpAliasPrefix); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateSemaphoreA)(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCSTR lpName) = CreateSemaphoreA;
static HANDLE WINAPI hooked_CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateSemaphoreA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateSemaphoreExA)(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCSTR lpName, DWORD dwFlags,  DWORD dwDesiredAccess) = CreateSemaphoreExA;
static HANDLE WINAPI hooked_CreateSemaphoreExA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCSTR lpName, DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateSemaphoreExA(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_CreateSymbolicLinkA)(LPCSTR lpSymlinkFileName,  LPCSTR lpTargetFileName,  DWORD dwFlags) = CreateSymbolicLinkA;
static BOOLEAN WINAPI hooked_CreateSymbolicLinkA(LPCSTR lpSymlinkFileName,  LPCSTR lpTargetFileName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_CreateSymbolicLinkA(lpSymlinkFileName, lpTargetFileName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_CreateSymbolicLinkTransactedA)(LPCSTR lpSymlinkFileName,  LPCSTR lpTargetFileName,  DWORD dwFlags,  HANDLE hTransaction) = CreateSymbolicLinkTransactedA;
static BOOLEAN WINAPI hooked_CreateSymbolicLinkTransactedA(LPCSTR lpSymlinkFileName,  LPCSTR lpTargetFileName,  DWORD dwFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_CreateSymbolicLinkTransactedA(lpSymlinkFileName, lpTargetFileName, dwFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_CreateSymbolicLinkTransactedW)(LPCWSTR lpSymlinkFileName,  LPCWSTR lpTargetFileName,  DWORD dwFlags,  HANDLE hTransaction) = CreateSymbolicLinkTransactedW;
static BOOLEAN WINAPI hooked_CreateSymbolicLinkTransactedW(LPCWSTR lpSymlinkFileName,  LPCWSTR lpTargetFileName,  DWORD dwFlags,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_CreateSymbolicLinkTransactedW(lpSymlinkFileName, lpTargetFileName, dwFlags, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_CreateTapePartition)(HANDLE hDevice,  DWORD dwPartitionMethod,  DWORD dwCount,  DWORD dwSize) = CreateTapePartition;
static DWORD WINAPI hooked_CreateTapePartition(HANDLE hDevice,  DWORD dwPartitionMethod,  DWORD dwCount,  DWORD dwSize) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_CreateTapePartition(hDevice, dwPartitionMethod, dwCount, dwSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_CreateSymbolicLinkW)(LPCWSTR lpSymlinkFileName,  LPCWSTR lpTargetFileName,  DWORD dwFlags) = CreateSymbolicLinkW;
static BOOLEAN WINAPI hooked_CreateSymbolicLinkW(LPCWSTR lpSymlinkFileName,  LPCWSTR lpTargetFileName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_CreateSymbolicLinkW(lpSymlinkFileName, lpTargetFileName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeactivateActCtx)(DWORD dwFlags,  ULONG_PTR ulCookie) = DeactivateActCtx;
static BOOL WINAPI hooked_DeactivateActCtx(DWORD dwFlags,  ULONG_PTR ulCookie) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeactivateActCtx(dwFlags, ulCookie); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateUmsCompletionList)(PUMS_COMPLETION_LIST *UmsCompletionList) = CreateUmsCompletionList;
static BOOL WINAPI hooked_CreateUmsCompletionList(PUMS_COMPLETION_LIST *UmsCompletionList) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateUmsCompletionList(UmsCompletionList); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateUmsThreadContext)(PUMS_CONTEXT *lpUmsThread) = CreateUmsThreadContext;
static BOOL WINAPI hooked_CreateUmsThreadContext(PUMS_CONTEXT *lpUmsThread) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateUmsThreadContext(lpUmsThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DebugBreakProcess)(HANDLE Process) = DebugBreakProcess;
static BOOL WINAPI hooked_DebugBreakProcess(HANDLE Process) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DebugBreakProcess(Process); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DebugSetProcessKillOnExit)(BOOL KillOnExit) = DebugSetProcessKillOnExit;
static BOOL WINAPI hooked_DebugSetProcessKillOnExit(BOOL KillOnExit) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DebugSetProcessKillOnExit(KillOnExit); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DefineDosDeviceA)(DWORD dwFlags,  LPCSTR lpDeviceName,  LPCSTR lpTargetPath) = DefineDosDeviceA;
static BOOL WINAPI hooked_DefineDosDeviceA(DWORD dwFlags,  LPCSTR lpDeviceName,  LPCSTR lpTargetPath) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DefineDosDeviceA(dwFlags, lpDeviceName, lpTargetPath); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_DeleteFiber)(LPVOID lpFiber) = DeleteFiber;
static VOID WINAPI hooked_DeleteFiber(LPVOID lpFiber) {

	SEND_BEFORE_CALL

	
	TIME({ og_DeleteFiber(lpFiber); });

	SEND_AFTER_CALL
	
}

static ATOM (WINAPI *og_DeleteAtom)(ATOM nAtom) = DeleteAtom;
static ATOM WINAPI hooked_DeleteAtom(ATOM nAtom) {

	SEND_BEFORE_CALL

	
    ATOM result;
    TIME({ result = og_DeleteAtom(nAtom); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFile)(LPCTSTR lpFileName) = DeleteFile;
static BOOL WINAPI hooked_DeleteFile(LPCTSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFile(lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFileTransactedA)(LPCSTR lpFileName,  HANDLE hTransaction) = DeleteFileTransactedA;
static BOOL WINAPI hooked_DeleteFileTransactedA(LPCSTR lpFileName,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFileTransactedA(lpFileName, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFileTransactedW)(LPCWSTR lpFileName,  HANDLE hTransaction) = DeleteFileTransactedW;
static BOOL WINAPI hooked_DeleteFileTransactedW(LPCWSTR lpFileName,  HANDLE hTransaction) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFileTransactedW(lpFileName, hTransaction); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteUmsCompletionList)(PUMS_COMPLETION_LIST UmsCompletionList) = DeleteUmsCompletionList;
static BOOL WINAPI hooked_DeleteUmsCompletionList(PUMS_COMPLETION_LIST UmsCompletionList) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteUmsCompletionList(UmsCompletionList); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteUmsThreadContext)(PUMS_CONTEXT UmsThread) = DeleteUmsThreadContext;
static BOOL WINAPI hooked_DeleteUmsThreadContext(PUMS_CONTEXT UmsThread) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteUmsThreadContext(UmsThread); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteVolumeMountPointA)(LPCSTR lpszVolumeMountPoint) = DeleteVolumeMountPointA;
static BOOL WINAPI hooked_DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteVolumeMountPointA(lpszVolumeMountPoint); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DequeueUmsCompletionListItems)(PUMS_COMPLETION_LIST UmsCompletionList,  DWORD WaitTimeOut,  PUMS_CONTEXT *UmsThreadList) = DequeueUmsCompletionListItems;
static BOOL WINAPI hooked_DequeueUmsCompletionListItems(PUMS_COMPLETION_LIST UmsCompletionList,  DWORD WaitTimeOut,  PUMS_CONTEXT *UmsThreadList) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DequeueUmsCompletionListItems(UmsCompletionList, WaitTimeOut, UmsThreadList); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_DisableThreadProfiling)(HANDLE PerformanceDataHandle) = DisableThreadProfiling;
static DWORD WINAPI hooked_DisableThreadProfiling(HANDLE PerformanceDataHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_DisableThreadProfiling(PerformanceDataHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DnsHostnameToComputerNameA)(LPCSTR Hostname,  LPSTR ComputerName,  LPDWORD nSize) = DnsHostnameToComputerNameA;
static BOOL WINAPI hooked_DnsHostnameToComputerNameA(LPCSTR Hostname,  LPSTR ComputerName,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DnsHostnameToComputerNameA(Hostname, ComputerName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DnsHostnameToComputerNameW)(LPCWSTR Hostname,  LPWSTR ComputerName,  LPDWORD nSize) = DnsHostnameToComputerNameW;
static BOOL WINAPI hooked_DnsHostnameToComputerNameW(LPCWSTR Hostname,  LPWSTR ComputerName,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DnsHostnameToComputerNameW(Hostname, ComputerName, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DosDateTimeToFileTime)(WORD wFatDate,  WORD wFatTime,  LPFILETIME lpFileTime) = DosDateTimeToFileTime;
static BOOL WINAPI hooked_DosDateTimeToFileTime(WORD wFatDate,  WORD wFatTime,  LPFILETIME lpFileTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DosDateTimeToFileTime(wFatDate, wFatTime, lpFileTime); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_EnableThreadProfiling)(HANDLE ThreadHandle,  DWORD Flags,  DWORD64 HardwareCounters,  HANDLE *PerformanceDataHandle) = EnableThreadProfiling;
static DWORD WINAPI hooked_EnableThreadProfiling(HANDLE ThreadHandle,  DWORD Flags,  DWORD64 HardwareCounters,  HANDLE *PerformanceDataHandle) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_EnableThreadProfiling(ThreadHandle, Flags, HardwareCounters, PerformanceDataHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EndUpdateResourceA)(HANDLE hUpdate,  BOOL fDiscard) = EndUpdateResourceA;
static BOOL WINAPI hooked_EndUpdateResourceA(HANDLE hUpdate,  BOOL fDiscard) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EndUpdateResourceA(hUpdate, fDiscard); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EndUpdateResourceW)(HANDLE hUpdate,  BOOL fDiscard) = EndUpdateResourceW;
static BOOL WINAPI hooked_EndUpdateResourceW(HANDLE hUpdate,  BOOL fDiscard) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EndUpdateResourceW(hUpdate, fDiscard); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnterUmsSchedulingMode)(PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo) = EnterUmsSchedulingMode;
static BOOL WINAPI hooked_EnterUmsSchedulingMode(PUMS_SCHEDULER_STARTUP_INFO SchedulerStartupInfo) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnterUmsSchedulingMode(SchedulerStartupInfo); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceLanguagesA)(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  ENUMRESLANGPROCA lpEnumFunc,  LONG_PTR lParam) = EnumResourceLanguagesA;
static BOOL WINAPI hooked_EnumResourceLanguagesA(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  ENUMRESLANGPROCA lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceLanguagesA(hModule, lpType, lpName, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_LCMapStringEx)(LPCWSTR lpLocaleName,  DWORD dwMapFlags,  LPCWSTR lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM sortHandle) = LCMapStringEx;
static int WINAPI hooked_LCMapStringEx(LPCWSTR lpLocaleName,  DWORD dwMapFlags,  LPCWSTR lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM sortHandle) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_LCMapStringEx(lpLocaleName, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, lpVersionInformation, lpReserved, sortHandle); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_LCMapStringW)(LCID Locale,  DWORD dwMapFlags,  LPCWSTR lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest) = LCMapStringW;
static int WINAPI hooked_LCMapStringW(LCID Locale,  DWORD dwMapFlags,  LPCWSTR lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_LCMapStringW(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest); });

	SEND_AFTER_CALL

    return result;
}


static LCID (WINAPI *og_LocaleNameToLCID)(LPCWSTR lpName,  DWORD dwFlags) = LocaleNameToLCID;
static LCID WINAPI hooked_LocaleNameToLCID(LPCWSTR lpName,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    LCID result;
    TIME({ result = og_LocaleNameToLCID(lpName, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_NotifyUILanguageChange)(DWORD dwFlags,  PCWSTR pcwstrNewLanguage,  PCWSTR pcwstrPreviousLanguage,  DWORD dwReserved,  PDWORD pdwStatusRtrn) = NotifyUILanguageChange;
static BOOL WINAPI hooked_NotifyUILanguageChange(DWORD dwFlags,  PCWSTR pcwstrNewLanguage,  PCWSTR pcwstrPreviousLanguage,  DWORD dwReserved,  PDWORD pdwStatusRtrn) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_NotifyUILanguageChange(dwFlags, pcwstrNewLanguage, pcwstrPreviousLanguage, dwReserved, pdwStatusRtrn); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_ResolveLocaleName)(LPCWSTR lpNameToResolve,  LPWSTR lpLocaleName,  int cchLocaleName) = ResolveLocaleName;
static int WINAPI hooked_ResolveLocaleName(LPCWSTR lpNameToResolve,  LPWSTR lpLocaleName,  int cchLocaleName) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_ResolveLocaleName(lpNameToResolve, lpLocaleName, cchLocaleName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCalendarInfoA)(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPCSTR lpCalData) = SetCalendarInfoA;
static BOOL WINAPI hooked_SetCalendarInfoA(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPCSTR lpCalData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCalendarInfoA(Locale, Calendar, CalType, lpCalData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetLocaleInfoA)(LCID Locale,  LCTYPE LCType,  LPCSTR lpLCData) = SetLocaleInfoA;
static BOOL WINAPI hooked_SetLocaleInfoA(LCID Locale,  LCTYPE LCType,  LPCSTR lpLCData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetLocaleInfoA(Locale, LCType, lpLCData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCalendarInfoW)(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPCWSTR lpCalData) = SetCalendarInfoW;
static BOOL WINAPI hooked_SetCalendarInfoW(LCID Locale,  CALID Calendar,  CALTYPE CalType,  LPCWSTR lpCalData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCalendarInfoW(Locale, Calendar, CalType, lpCalData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetProcessPreferredUILanguages)(DWORD dwFlags,  PCZZWSTR pwszLanguagesBuffer,  PULONG pulNumLanguages) = SetProcessPreferredUILanguages;
static BOOL WINAPI hooked_SetProcessPreferredUILanguages(DWORD dwFlags,  PCZZWSTR pwszLanguagesBuffer,  PULONG pulNumLanguages) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetProcessPreferredUILanguages(dwFlags, pwszLanguagesBuffer, pulNumLanguages); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetLocaleInfoW)(LCID Locale,  LCTYPE LCType,  LPCWSTR lpLCData) = SetLocaleInfoW;
static BOOL WINAPI hooked_SetLocaleInfoW(LCID Locale,  LCTYPE LCType,  LPCWSTR lpLCData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetLocaleInfoW(Locale, LCType, lpLCData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadLocale)(LCID Locale) = SetThreadLocale;
static BOOL WINAPI hooked_SetThreadLocale(LCID Locale) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadLocale(Locale); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadPreferredUILanguages)(DWORD dwFlags,  PCZZWSTR pwszLanguagesBuffer,  PULONG pulNumLanguages) = SetThreadPreferredUILanguages;
static BOOL WINAPI hooked_SetThreadPreferredUILanguages(DWORD dwFlags,  PCZZWSTR pwszLanguagesBuffer,  PULONG pulNumLanguages) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadPreferredUILanguages(dwFlags, pwszLanguagesBuffer, pulNumLanguages); });

	SEND_AFTER_CALL

    return result;
}

static LANGID (WINAPI *og_SetThreadUILanguage)(LANGID LangId) = SetThreadUILanguage;
static LANGID WINAPI hooked_SetThreadUILanguage(LANGID LangId) {

	SEND_BEFORE_CALL

	
    LANGID result;
    TIME({ result = og_SetThreadUILanguage(LangId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetUserGeoID)(GEOID GeoId) = SetUserGeoID;
static BOOL WINAPI hooked_SetUserGeoID(GEOID GeoId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetUserGeoID(GeoId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetUserGeoName)(PWSTR geoName) = SetUserGeoName;
static BOOL WINAPI hooked_SetUserGeoName(PWSTR geoName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetUserGeoName(geoName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_VerifyScripts)(DWORD dwFlags,  LPCWSTR lpLocaleScripts,  int cchLocaleScripts,  LPCWSTR lpTestScripts,  int cchTestScripts) = VerifyScripts;
static BOOL WINAPI hooked_VerifyScripts(DWORD dwFlags,  LPCWSTR lpLocaleScripts,  int cchLocaleScripts,  LPCWSTR lpTestScripts,  int cchTestScripts) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_VerifyScripts(dwFlags, lpLocaleScripts, cchLocaleScripts, lpTestScripts, cchTestScripts); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_ClosePackageInfo)(PACKAGE_INFO_REFERENCE packageInfoReference) = ClosePackageInfo;
static LONG WINAPI hooked_ClosePackageInfo(PACKAGE_INFO_REFERENCE packageInfoReference) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_ClosePackageInfo(packageInfoReference); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_FindPackagesByPackageFamily)(PCWSTR packageFamilyName,  UINT32 packageFilters,  UINT32 *count,  PWSTR *packageFullNames,  UINT32 *bufferLength,  WCHAR *buffer,  UINT32 *packageProperties) = FindPackagesByPackageFamily;
static LONG WINAPI hooked_FindPackagesByPackageFamily(PCWSTR packageFamilyName,  UINT32 packageFilters,  UINT32 *count,  PWSTR *packageFullNames,  UINT32 *bufferLength,  WCHAR *buffer,  UINT32 *packageProperties) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_FindPackagesByPackageFamily(packageFamilyName, packageFilters, count, packageFullNames, bufferLength, buffer, packageProperties); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_FormatApplicationUserModelId)(PCWSTR packageFamilyName,  PCWSTR packageRelativeApplicationId,  UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) = FormatApplicationUserModelId;
static LONG WINAPI hooked_FormatApplicationUserModelId(PCWSTR packageFamilyName,  PCWSTR packageRelativeApplicationId,  UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_FormatApplicationUserModelId(packageFamilyName, packageRelativeApplicationId, applicationUserModelIdLength, applicationUserModelId); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetApplicationUserModelId)(HANDLE hProcess,  UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) = GetApplicationUserModelId;
static LONG WINAPI hooked_GetApplicationUserModelId(HANDLE hProcess,  UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetApplicationUserModelId(hProcess, applicationUserModelIdLength, applicationUserModelId); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_GetCurrentPackageFamilyName)(UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) = GetCurrentPackageFamilyName;
static LONG WINAPI hooked_GetCurrentPackageFamilyName(UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentPackageFamilyName(packageFamilyNameLength, packageFamilyName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetCurrentApplicationUserModelId)(UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) = GetCurrentApplicationUserModelId;
static LONG WINAPI hooked_GetCurrentApplicationUserModelId(UINT32 *applicationUserModelIdLength,  PWSTR applicationUserModelId) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentApplicationUserModelId(applicationUserModelIdLength, applicationUserModelId); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetCurrentPackageFullName)(UINT32 *packageFullNameLength,  PWSTR packageFullName) = GetCurrentPackageFullName;
static LONG WINAPI hooked_GetCurrentPackageFullName(UINT32 *packageFullNameLength,  PWSTR packageFullName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentPackageFullName(packageFullNameLength, packageFullName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetCurrentPackageId)(UINT32 *bufferLength,  BYTE *buffer) = GetCurrentPackageId;
static LONG WINAPI hooked_GetCurrentPackageId(UINT32 *bufferLength,  BYTE *buffer) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentPackageId(bufferLength, buffer); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetCurrentPackageInfo)(const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) = GetCurrentPackageInfo;
static LONG WINAPI hooked_GetCurrentPackageInfo(const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentPackageInfo(flags, bufferLength, buffer, count); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetCurrentPackagePath)(UINT32 *pathLength,  PWSTR path) = GetCurrentPackagePath;
static LONG WINAPI hooked_GetCurrentPackagePath(UINT32 *pathLength,  PWSTR path) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetCurrentPackagePath(pathLength, path); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetPackageFamilyName)(HANDLE hProcess,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) = GetPackageFamilyName;
static LONG WINAPI hooked_GetPackageFamilyName(HANDLE hProcess,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackageFamilyName(hProcess, packageFamilyNameLength, packageFamilyName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetPackageApplicationIds)(PACKAGE_INFO_REFERENCE packageInfoReference,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) = GetPackageApplicationIds;
static LONG WINAPI hooked_GetPackageApplicationIds(PACKAGE_INFO_REFERENCE packageInfoReference,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackageApplicationIds(packageInfoReference, bufferLength, buffer, count); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_GetPackageFullName)(HANDLE hProcess,  UINT32 *packageFullNameLength,  PWSTR packageFullName) = GetPackageFullName;
static LONG WINAPI hooked_GetPackageFullName(HANDLE hProcess,  UINT32 *packageFullNameLength,  PWSTR packageFullName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackageFullName(hProcess, packageFullNameLength, packageFullName); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_GetPackageId)(HANDLE hProcess,  UINT32 *bufferLength,  BYTE *buffer) = GetPackageId;
static LONG WINAPI hooked_GetPackageId(HANDLE hProcess,  UINT32 *bufferLength,  BYTE *buffer) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackageId(hProcess, bufferLength, buffer); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_GetPackageInfo)(PACKAGE_INFO_REFERENCE packageInfoReference,  const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) = GetPackageInfo;
static LONG WINAPI hooked_GetPackageInfo(PACKAGE_INFO_REFERENCE packageInfoReference,  const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer,  UINT32 *count) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackageInfo(packageInfoReference, flags, bufferLength, buffer, count); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetPackagePath)(const PACKAGE_ID *packageId, const UINT32 reserved,  UINT32 *pathLength,  PWSTR path) = GetPackagePath;
static LONG WINAPI hooked_GetPackagePath(const PACKAGE_ID *packageId, const UINT32 reserved,  UINT32 *pathLength,  PWSTR path) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackagePath(packageId, reserved, pathLength, path); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetPackagePathByFullName)(PCWSTR packageFullName,  UINT32 *pathLength,  PWSTR path) = GetPackagePathByFullName;
static LONG WINAPI hooked_GetPackagePathByFullName(PCWSTR packageFullName,  UINT32 *pathLength,  PWSTR path) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackagePathByFullName(packageFullName, pathLength, path); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetPackagesByPackageFamily)(PCWSTR packageFamilyName,  UINT32 *count,  PWSTR *packageFullNames,  UINT32 *bufferLength,  WCHAR *buffer) = GetPackagesByPackageFamily;
static LONG WINAPI hooked_GetPackagesByPackageFamily(PCWSTR packageFamilyName,  UINT32 *count,  PWSTR *packageFullNames,  UINT32 *bufferLength,  WCHAR *buffer) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetPackagesByPackageFamily(packageFamilyName, count, packageFullNames, bufferLength, buffer); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_GetStagedPackagePathByFullName)(PCWSTR packageFullName,  UINT32 *pathLength,  PWSTR path) = GetStagedPackagePathByFullName;
static LONG WINAPI hooked_GetStagedPackagePathByFullName(PCWSTR packageFullName,  UINT32 *pathLength,  PWSTR path) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_GetStagedPackagePathByFullName(packageFullName, pathLength, path); });

	SEND_AFTER_CALL

    return result;
}


static LONG (WINAPI *og_OpenPackageInfoByFullName)(PCWSTR packageFullName, const UINT32 reserved,  PACKAGE_INFO_REFERENCE *packageInfoReference) = OpenPackageInfoByFullName;
static LONG WINAPI hooked_OpenPackageInfoByFullName(PCWSTR packageFullName, const UINT32 reserved,  PACKAGE_INFO_REFERENCE *packageInfoReference) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_OpenPackageInfoByFullName(packageFullName, reserved, packageInfoReference); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_PackageFamilyNameFromFullName)(PCWSTR packageFullName,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) = PackageFamilyNameFromFullName;
static LONG WINAPI hooked_PackageFamilyNameFromFullName(PCWSTR packageFullName,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_PackageFamilyNameFromFullName(packageFullName, packageFamilyNameLength, packageFamilyName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_PackageFamilyNameFromId)(const PACKAGE_ID *packageId,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) = PackageFamilyNameFromId;
static LONG WINAPI hooked_PackageFamilyNameFromId(const PACKAGE_ID *packageId,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_PackageFamilyNameFromId(packageId, packageFamilyNameLength, packageFamilyName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_PackageNameAndPublisherIdFromFamilyName)(PCWSTR packageFamilyName,  UINT32 *packageNameLength,  PWSTR packageName,  UINT32 *packagePublisherIdLength,  PWSTR packagePublisherId) = PackageNameAndPublisherIdFromFamilyName;
static LONG WINAPI hooked_PackageNameAndPublisherIdFromFamilyName(PCWSTR packageFamilyName,  UINT32 *packageNameLength,  PWSTR packageName,  UINT32 *packagePublisherIdLength,  PWSTR packagePublisherId) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_PackageNameAndPublisherIdFromFamilyName(packageFamilyName, packageNameLength, packageName, packagePublisherIdLength, packagePublisherId); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_PackageFullNameFromId)(const PACKAGE_ID *packageId,  UINT32 *packageFullNameLength,  PWSTR packageFullName) = PackageFullNameFromId;
static LONG WINAPI hooked_PackageFullNameFromId(const PACKAGE_ID *packageId,  UINT32 *packageFullNameLength,  PWSTR packageFullName) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_PackageFullNameFromId(packageId, packageFullNameLength, packageFullName); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_PackageIdFromFullName)(PCWSTR packageFullName,  const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer) = PackageIdFromFullName;
static LONG WINAPI hooked_PackageIdFromFullName(PCWSTR packageFullName,  const UINT32 flags,  UINT32 *bufferLength,  BYTE *buffer) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_PackageIdFromFullName(packageFullName, flags, bufferLength, buffer); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_ParseApplicationUserModelId)(PCWSTR applicationUserModelId,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName,  UINT32 *packageRelativeApplicationIdLength,  PWSTR packageRelativeApplicationId) = ParseApplicationUserModelId;
static LONG WINAPI hooked_ParseApplicationUserModelId(PCWSTR applicationUserModelId,  UINT32 *packageFamilyNameLength,  PWSTR packageFamilyName,  UINT32 *packageRelativeApplicationIdLength,  PWSTR packageRelativeApplicationId) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_ParseApplicationUserModelId(applicationUserModelId, packageFamilyNameLength, packageFamilyName, packageRelativeApplicationIdLength, packageRelativeApplicationId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CallEnclave)(LPENCLAVE_ROUTINE lpRoutine,  LPVOID lpParameter,  BOOL fWaitForThread,  LPVOID *lpReturnValue) = CallEnclave;
static BOOL WINAPI hooked_CallEnclave(LPENCLAVE_ROUTINE lpRoutine,  LPVOID lpParameter,  BOOL fWaitForThread,  LPVOID *lpReturnValue) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CallEnclave(lpRoutine, lpParameter, fWaitForThread, lpReturnValue); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteEnclave)(LPVOID lpAddress) = DeleteEnclave;
static BOOL WINAPI hooked_DeleteEnclave(LPVOID lpAddress) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteEnclave(lpAddress); });

	SEND_AFTER_CALL

    return result;
}

static LPVOID (WINAPI *og_CreateEnclave)(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  SIZE_T dwInitialCommitment,  DWORD flEnclaveType,  LPCVOID lpEnclaveInformation,  DWORD dwInfoLength,  LPDWORD lpEnclaveError) = CreateEnclave;
static LPVOID WINAPI hooked_CreateEnclave(HANDLE hProcess,  LPVOID lpAddress,  SIZE_T dwSize,  SIZE_T dwInitialCommitment,  DWORD flEnclaveType,  LPCVOID lpEnclaveInformation,  DWORD dwInfoLength,  LPDWORD lpEnclaveError) {

	SEND_BEFORE_CALL

	
    LPVOID result;
    TIME({ result = og_CreateEnclave(hProcess, lpAddress, dwSize, dwInitialCommitment, flEnclaveType, lpEnclaveInformation, dwInfoLength, lpEnclaveError); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsEnclaveTypeSupported)(DWORD flEnclaveType) = IsEnclaveTypeSupported;
static BOOL WINAPI hooked_IsEnclaveTypeSupported(DWORD flEnclaveType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsEnclaveTypeSupported(flEnclaveType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitializeEnclave)(HANDLE hProcess,  LPVOID lpAddress,  LPCVOID lpEnclaveInformation,  DWORD dwInfoLength,  LPDWORD lpEnclaveError) = InitializeEnclave;
static BOOL WINAPI hooked_InitializeEnclave(HANDLE hProcess,  LPVOID lpAddress,  LPCVOID lpEnclaveInformation,  DWORD dwInfoLength,  LPDWORD lpEnclaveError) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeEnclave(hProcess, lpAddress, lpEnclaveInformation, dwInfoLength, lpEnclaveError); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LoadEnclaveData)(HANDLE hProcess,  LPVOID lpAddress,  LPCVOID lpBuffer,  SIZE_T nSize,  DWORD flProtect,  LPCVOID lpPageInformation,  DWORD dwInfoLength,  PSIZE_T lpNumberOfBytesWritten,  LPDWORD lpEnclaveError) = LoadEnclaveData;
static BOOL WINAPI hooked_LoadEnclaveData(HANDLE hProcess,  LPVOID lpAddress,  LPCVOID lpBuffer,  SIZE_T nSize,  DWORD flProtect,  LPCVOID lpPageInformation,  DWORD dwInfoLength,  PSIZE_T lpNumberOfBytesWritten,  LPDWORD lpEnclaveError) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LoadEnclaveData(hProcess, lpAddress, lpBuffer, nSize, flProtect, lpPageInformation, dwInfoLength, lpNumberOfBytesWritten, lpEnclaveError); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LoadEnclaveImageA)(LPVOID lpEnclaveAddress,  LPCSTR lpImageName) = LoadEnclaveImageA;
static BOOL WINAPI hooked_LoadEnclaveImageA(LPVOID lpEnclaveAddress,  LPCSTR lpImageName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LoadEnclaveImageA(lpEnclaveAddress, lpImageName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TerminateEnclave)(LPVOID lpAddress,  BOOL fWait) = TerminateEnclave;
static BOOL WINAPI hooked_TerminateEnclave(LPVOID lpAddress,  BOOL fWait) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TerminateEnclave(lpAddress, fWait); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LoadEnclaveImageW)(LPVOID lpEnclaveAddress,  LPCWSTR lpImageName) = LoadEnclaveImageW;
static BOOL WINAPI hooked_LoadEnclaveImageW(LPVOID lpEnclaveAddress,  LPCWSTR lpImageName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LoadEnclaveImageW(lpEnclaveAddress, lpImageName); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_AddVectoredContinueHandler)(ULONG First, PVECTORED_EXCEPTION_HANDLER Handler) = AddVectoredContinueHandler;
static PVOID WINAPI hooked_AddVectoredContinueHandler(ULONG First, PVECTORED_EXCEPTION_HANDLER Handler) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_AddVectoredContinueHandler(First, Handler); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_AddVectoredExceptionHandler)(ULONG First, PVECTORED_EXCEPTION_HANDLER Handler) = AddVectoredExceptionHandler;
static PVOID WINAPI hooked_AddVectoredExceptionHandler(ULONG First, PVECTORED_EXCEPTION_HANDLER Handler) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_AddVectoredExceptionHandler(First, Handler); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_FatalAppExitA)(UINT uAction,  LPCSTR lpMessageText) = FatalAppExitA;
static VOID WINAPI hooked_FatalAppExitA(UINT uAction,  LPCSTR lpMessageText) {

	SEND_BEFORE_CALL

	
	TIME({ og_FatalAppExitA(uAction, lpMessageText); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_FatalAppExitW)(UINT uAction,  LPCWSTR lpMessageText) = FatalAppExitW;
static VOID WINAPI hooked_FatalAppExitW(UINT uAction,  LPCWSTR lpMessageText) {

	SEND_BEFORE_CALL

	
	TIME({ og_FatalAppExitW(uAction, lpMessageText); });

	SEND_AFTER_CALL
	
}

static UINT (WINAPI *og_GetErrorMode)() = GetErrorMode;
static UINT WINAPI hooked_GetErrorMode() {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetErrorMode(); });

	SEND_AFTER_CALL

    return result;
}

static _Post_equals_last_error_ DWORD (WINAPI *og_GetLastError)() = GetLastError;
static _Post_equals_last_error_ DWORD WINAPI hooked_GetLastError() {

	SEND_BEFORE_CALL

	
    _Post_equals_last_error_ DWORD result;
    TIME({ result = og_GetLastError(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetThreadErrorMode)() = GetThreadErrorMode;
static DWORD WINAPI hooked_GetThreadErrorMode() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetThreadErrorMode(); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_RaiseException)(DWORD dwExceptionCode,  DWORD dwExceptionFlags,  DWORD nNumberOfArguments,  const ULONG_PTR *lpArguments) = RaiseException;
static VOID WINAPI hooked_RaiseException(DWORD dwExceptionCode,  DWORD dwExceptionFlags,  DWORD nNumberOfArguments,  const ULONG_PTR *lpArguments) {

	SEND_BEFORE_CALL

	
	TIME({ og_RaiseException(dwExceptionCode, dwExceptionFlags, nNumberOfArguments, lpArguments); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_RaiseFailFastException)(PEXCEPTION_RECORD pExceptionRecord,  PCONTEXT pContextRecord,  DWORD dwFlags) = RaiseFailFastException;
static VOID WINAPI hooked_RaiseFailFastException(PEXCEPTION_RECORD pExceptionRecord,  PCONTEXT pContextRecord,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
	TIME({ og_RaiseFailFastException(pExceptionRecord, pContextRecord, dwFlags); });

	SEND_AFTER_CALL
	
}

static ULONG (WINAPI *og_RemoveVectoredContinueHandler)(PVOID Handle) = RemoveVectoredContinueHandler;
static ULONG WINAPI hooked_RemoveVectoredContinueHandler(PVOID Handle) {

	SEND_BEFORE_CALL

	
    ULONG result;
    TIME({ result = og_RemoveVectoredContinueHandler(Handle); });

	SEND_AFTER_CALL

    return result;
}

static ULONG (WINAPI *og_RemoveVectoredExceptionHandler)(PVOID Handle) = RemoveVectoredExceptionHandler;
static ULONG WINAPI hooked_RemoveVectoredExceptionHandler(PVOID Handle) {

	SEND_BEFORE_CALL

	
    ULONG result;
    TIME({ result = og_RemoveVectoredExceptionHandler(Handle); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_SetErrorMode)(UINT uMode) = SetErrorMode;
static UINT WINAPI hooked_SetErrorMode(UINT uMode) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_SetErrorMode(uMode); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SetLastError)(DWORD dwErrCode) = SetLastError;
static VOID WINAPI hooked_SetLastError(DWORD dwErrCode) {

	SEND_BEFORE_CALL

	
	TIME({ og_SetLastError(dwErrCode); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetThreadErrorMode)(DWORD dwNewMode,  LPDWORD lpOldMode) = SetThreadErrorMode;
static BOOL WINAPI hooked_SetThreadErrorMode(DWORD dwNewMode,  LPDWORD lpOldMode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadErrorMode(dwNewMode, lpOldMode); });

	SEND_AFTER_CALL

    return result;
}

static LPTOP_LEVEL_EXCEPTION_FILTER (WINAPI *og_SetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) = SetUnhandledExceptionFilter;
static LPTOP_LEVEL_EXCEPTION_FILTER WINAPI hooked_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {

	SEND_BEFORE_CALL

	
    LPTOP_LEVEL_EXCEPTION_FILTER result;
    TIME({ result = og_SetUnhandledExceptionFilter(lpTopLevelExceptionFilter); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_UnhandledExceptionFilter)(_EXCEPTION_POINTERS *ExceptionInfo) = UnhandledExceptionFilter;
static LONG WINAPI hooked_UnhandledExceptionFilter(_EXCEPTION_POINTERS *ExceptionInfo) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_UnhandledExceptionFilter(ExceptionInfo); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_FlsAlloc)(PFLS_CALLBACK_FUNCTION lpCallback) = FlsAlloc;
static DWORD WINAPI hooked_FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_FlsAlloc(lpCallback); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FlsFree)(DWORD dwFlsIndex) = FlsFree;
static BOOL WINAPI hooked_FlsFree(DWORD dwFlsIndex) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FlsFree(dwFlsIndex); });

	SEND_AFTER_CALL

    return result;
}

static PVOID (WINAPI *og_FlsGetValue)(DWORD dwFlsIndex) = FlsGetValue;
static PVOID WINAPI hooked_FlsGetValue(DWORD dwFlsIndex) {

	SEND_BEFORE_CALL

	
    PVOID result;
    TIME({ result = og_FlsGetValue(dwFlsIndex); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FlsSetValue)(DWORD dwFlsIndex,  PVOID lpFlsData) = FlsSetValue;
static BOOL WINAPI hooked_FlsSetValue(DWORD dwFlsIndex,  PVOID lpFlsData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FlsSetValue(dwFlsIndex, lpFlsData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsThreadAFiber)() = IsThreadAFiber;
static BOOL WINAPI hooked_IsThreadAFiber() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsThreadAFiber(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AreFileApisANSI)() = AreFileApisANSI;
static BOOL WINAPI hooked_AreFileApisANSI() {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AreFileApisANSI(); });

	SEND_AFTER_CALL

    return result;
}

static LONG (WINAPI *og_CompareFileTime)(const FILETIME *lpFileTime1,  const FILETIME *lpFileTime2) = CompareFileTime;
static LONG WINAPI hooked_CompareFileTime(const FILETIME *lpFileTime1,  const FILETIME *lpFileTime2) {

	SEND_BEFORE_CALL

	
    LONG result;
    TIME({ result = og_CompareFileTime(lpFileTime1, lpFileTime2); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateDirectory2A)(LPCSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode, DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectory2A;
static HANDLE WINAPI hooked_CreateDirectory2A(LPCSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode, DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateDirectory2A(lpPathName, dwDesiredAccess, dwShareMode, DirectoryFlags, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateDirectory2W)(LPCWSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode, DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectory2W;
static HANDLE WINAPI hooked_CreateDirectory2W(LPCWSTR lpPathName, DWORD dwDesiredAccess, DWORD dwShareMode, DIRECTORY_FLAGS DirectoryFlags, LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateDirectory2W(lpPathName, dwDesiredAccess, dwShareMode, DirectoryFlags, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryA)(LPCSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryA;
static BOOL WINAPI hooked_CreateDirectoryA(LPCSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryA(lpPathName, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateDirectoryW)(LPCWSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) = CreateDirectoryW;
static BOOL WINAPI hooked_CreateDirectoryW(LPCWSTR lpPathName,  LPSECURITY_ATTRIBUTES lpSecurityAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateDirectoryW(lpPathName, lpSecurityAttributes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFile2)(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  DWORD dwCreationDisposition,  LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams) = CreateFile2;
static HANDLE WINAPI hooked_CreateFile2(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  DWORD dwCreationDisposition,  LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFile2(lpFileName, dwDesiredAccess, dwShareMode, dwCreationDisposition, pCreateExParams); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFile3)(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE3_EXTENDED_PARAMETERS pCreateExParams) = CreateFile3;
static HANDLE WINAPI hooked_CreateFile3(LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, DWORD dwCreationDisposition, LPCREATEFILE3_EXTENDED_PARAMETERS pCreateExParams) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFile3(lpFileName, dwDesiredAccess, dwShareMode, dwCreationDisposition, pCreateExParams); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileW)(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile) = CreateFileW;
static HANDLE WINAPI hooked_CreateFileW(LPCWSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateFileA)(LPCSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile) = CreateFileA;
static HANDLE WINAPI hooked_CreateFileA(LPCSTR lpFileName,  DWORD dwDesiredAccess,  DWORD dwShareMode,  LPSECURITY_ATTRIBUTES lpSecurityAttributes,  DWORD dwCreationDisposition,  DWORD dwFlagsAndAttributes,  HANDLE hTemplateFile) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DefineDosDeviceW)(DWORD dwFlags,  LPCWSTR lpDeviceName,  LPCWSTR lpTargetPath) = DefineDosDeviceW;
static BOOL WINAPI hooked_DefineDosDeviceW(DWORD dwFlags,  LPCWSTR lpDeviceName,  LPCWSTR lpTargetPath) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DefineDosDeviceW(dwFlags, lpDeviceName, lpTargetPath); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFile2A)(LPCSTR lpFileName, DWORD Flags) = DeleteFile2A;
static BOOL WINAPI hooked_DeleteFile2A(LPCSTR lpFileName, DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFile2A(lpFileName, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFileA)(LPCSTR lpFileName) = DeleteFileA;
static BOOL WINAPI hooked_DeleteFileA(LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFileA(lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFile2W)(LPCWSTR lpFileName, DWORD Flags) = DeleteFile2W;
static BOOL WINAPI hooked_DeleteFile2W(LPCWSTR lpFileName, DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFile2W(lpFileName, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteFileW)(LPCWSTR lpFileName) = DeleteFileW;
static BOOL WINAPI hooked_DeleteFileW(LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteFileW(lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteVolumeMountPointW)(LPCWSTR lpszVolumeMountPoint) = DeleteVolumeMountPointW;
static BOOL WINAPI hooked_DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteVolumeMountPointW(lpszVolumeMountPoint); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FileTimeToLocalFileTime)(const FILETIME *lpFileTime,  LPFILETIME lpLocalFileTime) = FileTimeToLocalFileTime;
static BOOL WINAPI hooked_FileTimeToLocalFileTime(const FILETIME *lpFileTime,  LPFILETIME lpLocalFileTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindClose)(HANDLE hFindFile) = FindClose;
static BOOL WINAPI hooked_FindClose(HANDLE hFindFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindClose(hFindFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindCloseChangeNotification)(HANDLE hChangeHandle) = FindCloseChangeNotification;
static BOOL WINAPI hooked_FindCloseChangeNotification(HANDLE hChangeHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindCloseChangeNotification(hChangeHandle); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstChangeNotificationA)(LPCSTR lpPathName,  BOOL bWatchSubtree,  DWORD dwNotifyFilter) = FindFirstChangeNotificationA;
static HANDLE WINAPI hooked_FindFirstChangeNotificationA(LPCSTR lpPathName,  BOOL bWatchSubtree,  DWORD dwNotifyFilter) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileA)(LPCSTR lpFileName,  LPWIN32_FIND_DATAA lpFindFileData) = FindFirstFileA;
static HANDLE WINAPI hooked_FindFirstFileA(LPCSTR lpFileName,  LPWIN32_FIND_DATAA lpFindFileData) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileA(lpFileName, lpFindFileData); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstChangeNotificationW)(LPCWSTR lpPathName,  BOOL bWatchSubtree,  DWORD dwNotifyFilter) = FindFirstChangeNotificationW;
static HANDLE WINAPI hooked_FindFirstChangeNotificationW(LPCWSTR lpPathName,  BOOL bWatchSubtree,  DWORD dwNotifyFilter) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileExA)(LPCSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags) = FindFirstFileExA;
static HANDLE WINAPI hooked_FindFirstFileExA(LPCSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileExW)(LPCWSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags) = FindFirstFileExW;
static HANDLE WINAPI hooked_FindFirstFileExW(LPCWSTR lpFileName,  FINDEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFindFileData,  FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter,  DWORD dwAdditionalFlags) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileExW(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileNameW)(LPCWSTR lpFileName,  DWORD dwFlags,  LPDWORD StringLength,  PWSTR LinkName) = FindFirstFileNameW;
static HANDLE WINAPI hooked_FindFirstFileNameW(LPCWSTR lpFileName,  DWORD dwFlags,  LPDWORD StringLength,  PWSTR LinkName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileNameW(lpFileName, dwFlags, StringLength, LinkName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstFileW)(LPCWSTR lpFileName,  LPWIN32_FIND_DATAW lpFindFileData) = FindFirstFileW;
static HANDLE WINAPI hooked_FindFirstFileW(LPCWSTR lpFileName,  LPWIN32_FIND_DATAW lpFindFileData) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstFileW(lpFileName, lpFindFileData); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstStreamW)(LPCWSTR lpFileName,  STREAM_INFO_LEVELS InfoLevel,  LPVOID lpFindStreamData, DWORD dwFlags) = FindFirstStreamW;
static HANDLE WINAPI hooked_FindFirstStreamW(LPCWSTR lpFileName,  STREAM_INFO_LEVELS InfoLevel,  LPVOID lpFindStreamData, DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstStreamW(lpFileName, InfoLevel, lpFindStreamData, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_FindFirstVolumeW)(LPWSTR lpszVolumeName,  DWORD cchBufferLength) = FindFirstVolumeW;
static HANDLE WINAPI hooked_FindFirstVolumeW(LPWSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_FindFirstVolumeW(lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextChangeNotification)(HANDLE hChangeHandle) = FindNextChangeNotification;
static BOOL WINAPI hooked_FindNextChangeNotification(HANDLE hChangeHandle) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextChangeNotification(hChangeHandle); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextFileA)(HANDLE hFindFile,  LPWIN32_FIND_DATAA lpFindFileData) = FindNextFileA;
static BOOL WINAPI hooked_FindNextFileA(HANDLE hFindFile,  LPWIN32_FIND_DATAA lpFindFileData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextFileA(hFindFile, lpFindFileData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextFileNameW)(HANDLE hFindStream,  LPDWORD StringLength,  PWSTR LinkName) = FindNextFileNameW;
static BOOL WINAPI hooked_FindNextFileNameW(HANDLE hFindStream,  LPDWORD StringLength,  PWSTR LinkName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextFileNameW(hFindStream, StringLength, LinkName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextStreamW)(HANDLE hFindStream,  LPVOID lpFindStreamData) = FindNextStreamW;
static BOOL WINAPI hooked_FindNextStreamW(HANDLE hFindStream,  LPVOID lpFindStreamData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextStreamW(hFindStream, lpFindStreamData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextFileW)(HANDLE hFindFile,  LPWIN32_FIND_DATAW lpFindFileData) = FindNextFileW;
static BOOL WINAPI hooked_FindNextFileW(HANDLE hFindFile,  LPWIN32_FIND_DATAW lpFindFileData) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextFileW(hFindFile, lpFindFileData); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindNextVolumeW)(HANDLE hFindVolume,  LPWSTR lpszVolumeName,  DWORD cchBufferLength) = FindNextVolumeW;
static BOOL WINAPI hooked_FindNextVolumeW(HANDLE hFindVolume,  LPWSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindNextVolumeW(hFindVolume, lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FindVolumeClose)(HANDLE hFindVolume) = FindVolumeClose;
static BOOL WINAPI hooked_FindVolumeClose(HANDLE hFindVolume) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FindVolumeClose(hFindVolume); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FlushFileBuffers)(HANDLE hFile) = FlushFileBuffers;
static BOOL WINAPI hooked_FlushFileBuffers(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FlushFileBuffers(hFile); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCompressedFileSizeA)(LPCSTR lpFileName,  LPDWORD lpFileSizeHigh) = GetCompressedFileSizeA;
static DWORD WINAPI hooked_GetCompressedFileSizeA(LPCSTR lpFileName,  LPDWORD lpFileSizeHigh) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCompressedFileSizeA(lpFileName, lpFileSizeHigh); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDiskFreeSpaceA)(LPCSTR lpRootPathName,  LPDWORD lpSectorsPerCluster,  LPDWORD lpBytesPerSector,  LPDWORD lpNumberOfFreeClusters,  LPDWORD lpTotalNumberOfClusters) = GetDiskFreeSpaceA;
static BOOL WINAPI hooked_GetDiskFreeSpaceA(LPCSTR lpRootPathName,  LPDWORD lpSectorsPerCluster,  LPDWORD lpBytesPerSector,  LPDWORD lpNumberOfFreeClusters,  LPDWORD lpTotalNumberOfClusters) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetCompressedFileSizeW)(LPCWSTR lpFileName,  LPDWORD lpFileSizeHigh) = GetCompressedFileSizeW;
static DWORD WINAPI hooked_GetCompressedFileSizeW(LPCWSTR lpFileName,  LPDWORD lpFileSizeHigh) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetCompressedFileSizeW(lpFileName, lpFileSizeHigh); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDiskFreeSpaceExA)(LPCSTR lpDirectoryName,  PULARGE_INTEGER lpFreeBytesAvailableToCaller,  PULARGE_INTEGER lpTotalNumberOfBytes,  PULARGE_INTEGER lpTotalNumberOfFreeBytes) = GetDiskFreeSpaceExA;
static BOOL WINAPI hooked_GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,  PULARGE_INTEGER lpFreeBytesAvailableToCaller,  PULARGE_INTEGER lpTotalNumberOfBytes,  PULARGE_INTEGER lpTotalNumberOfFreeBytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDiskFreeSpaceExA(lpDirectoryName, lpFreeBytesAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDiskFreeSpaceExW)(LPCWSTR lpDirectoryName,  PULARGE_INTEGER lpFreeBytesAvailableToCaller,  PULARGE_INTEGER lpTotalNumberOfBytes,  PULARGE_INTEGER lpTotalNumberOfFreeBytes) = GetDiskFreeSpaceExW;
static BOOL WINAPI hooked_GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,  PULARGE_INTEGER lpFreeBytesAvailableToCaller,  PULARGE_INTEGER lpTotalNumberOfBytes,  PULARGE_INTEGER lpTotalNumberOfFreeBytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDiskFreeSpaceExW(lpDirectoryName, lpFreeBytesAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetDiskFreeSpaceW)(LPCWSTR lpRootPathName,  LPDWORD lpSectorsPerCluster,  LPDWORD lpBytesPerSector,  LPDWORD lpNumberOfFreeClusters,  LPDWORD lpTotalNumberOfClusters) = GetDiskFreeSpaceW;
static BOOL WINAPI hooked_GetDiskFreeSpaceW(LPCWSTR lpRootPathName,  LPDWORD lpSectorsPerCluster,  LPDWORD lpBytesPerSector,  LPDWORD lpNumberOfFreeClusters,  LPDWORD lpTotalNumberOfClusters) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetDiskFreeSpaceW(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetDiskSpaceInformationA)(LPCSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo) = GetDiskSpaceInformationA;
static HRESULT WINAPI hooked_GetDiskSpaceInformationA(LPCSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetDiskSpaceInformationA(rootPath, diskSpaceInfo); });

	SEND_AFTER_CALL

    return result;
}

static HRESULT (WINAPI *og_GetDiskSpaceInformationW)(LPCWSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo) = GetDiskSpaceInformationW;
static HRESULT WINAPI hooked_GetDiskSpaceInformationW(LPCWSTR rootPath, DISK_SPACE_INFORMATION *diskSpaceInfo) {

	SEND_BEFORE_CALL

	
    HRESULT result;
    TIME({ result = og_GetDiskSpaceInformationW(rootPath, diskSpaceInfo); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetDriveTypeW)(LPCWSTR lpRootPathName) = GetDriveTypeW;
static UINT WINAPI hooked_GetDriveTypeW(LPCWSTR lpRootPathName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetDriveTypeW(lpRootPathName); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetDriveTypeA)(LPCSTR lpRootPathName) = GetDriveTypeA;
static UINT WINAPI hooked_GetDriveTypeA(LPCSTR lpRootPathName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetDriveTypeA(lpRootPathName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFileAttributesA)(LPCSTR lpFileName) = GetFileAttributesA;
static DWORD WINAPI hooked_GetFileAttributesA(LPCSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFileAttributesA(lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileAttributesExA)(LPCSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation) = GetFileAttributesExA;
static BOOL WINAPI hooked_GetFileAttributesExA(LPCSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileAttributesExA(lpFileName, fInfoLevelId, lpFileInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileAttributesExW)(LPCWSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation) = GetFileAttributesExW;
static BOOL WINAPI hooked_GetFileAttributesExW(LPCWSTR lpFileName,  GET_FILEEX_INFO_LEVELS fInfoLevelId,  LPVOID lpFileInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileAttributesExW(lpFileName, fInfoLevelId, lpFileInformation); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFileAttributesW)(LPCWSTR lpFileName) = GetFileAttributesW;
static DWORD WINAPI hooked_GetFileAttributesW(LPCWSTR lpFileName) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFileAttributesW(lpFileName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileInformationByHandle)(HANDLE hFile,  LPBY_HANDLE_FILE_INFORMATION lpFileInformation) = GetFileInformationByHandle;
static BOOL WINAPI hooked_GetFileInformationByHandle(HANDLE hFile,  LPBY_HANDLE_FILE_INFORMATION lpFileInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileInformationByHandle(hFile, lpFileInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileSizeEx)(HANDLE hFile,  PLARGE_INTEGER lpFileSize) = GetFileSizeEx;
static BOOL WINAPI hooked_GetFileSizeEx(HANDLE hFile,  PLARGE_INTEGER lpFileSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileSizeEx(hFile, lpFileSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFileSize)(HANDLE hFile,  LPDWORD lpFileSizeHigh) = GetFileSize;
static DWORD WINAPI hooked_GetFileSize(HANDLE hFile,  LPDWORD lpFileSizeHigh) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFileSize(hFile, lpFileSizeHigh); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFileType)(HANDLE hFile) = GetFileType;
static DWORD WINAPI hooked_GetFileType(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFileType(hFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetFileTime)(HANDLE hFile,  LPFILETIME lpCreationTime,  LPFILETIME lpLastAccessTime,  LPFILETIME lpLastWriteTime) = GetFileTime;
static BOOL WINAPI hooked_GetFileTime(HANDLE hFile,  LPFILETIME lpCreationTime,  LPFILETIME lpLastAccessTime,  LPFILETIME lpLastWriteTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFinalPathNameByHandleA)(HANDLE hFile,  LPSTR lpszFilePath,  DWORD cchFilePath,  DWORD dwFlags) = GetFinalPathNameByHandleA;
static DWORD WINAPI hooked_GetFinalPathNameByHandleA(HANDLE hFile,  LPSTR lpszFilePath,  DWORD cchFilePath,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFinalPathNameByHandleA(hFile, lpszFilePath, cchFilePath, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFinalPathNameByHandleW)(HANDLE hFile,  LPWSTR lpszFilePath,  DWORD cchFilePath,  DWORD dwFlags) = GetFinalPathNameByHandleW;
static DWORD WINAPI hooked_GetFinalPathNameByHandleW(HANDLE hFile,  LPWSTR lpszFilePath,  DWORD cchFilePath,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFinalPathNameByHandleW(hFile, lpszFilePath, cchFilePath, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFullPathNameA)(LPCSTR lpFileName,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart) = GetFullPathNameA;
static DWORD WINAPI hooked_GetFullPathNameA(LPCSTR lpFileName,  DWORD nBufferLength,  LPSTR lpBuffer,  LPSTR *lpFilePart) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFullPathNameA(lpFileName, nBufferLength, lpBuffer, lpFilePart); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLogicalDriveStringsW)(DWORD nBufferLength,  LPWSTR lpBuffer) = GetLogicalDriveStringsW;
static DWORD WINAPI hooked_GetLogicalDriveStringsW(DWORD nBufferLength,  LPWSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLogicalDriveStringsW(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLogicalDrives)() = GetLogicalDrives;
static DWORD WINAPI hooked_GetLogicalDrives() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLogicalDrives(); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetFullPathNameW)(LPCWSTR lpFileName,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart) = GetFullPathNameW;
static DWORD WINAPI hooked_GetFullPathNameW(LPCWSTR lpFileName,  DWORD nBufferLength,  LPWSTR lpBuffer,  LPWSTR *lpFilePart) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetFullPathNameW(lpFileName, nBufferLength, lpBuffer, lpFilePart); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLongPathNameA)(LPCSTR lpszShortPath,  LPSTR lpszLongPath,  DWORD cchBuffer) = GetLongPathNameA;
static DWORD WINAPI hooked_GetLongPathNameA(LPCSTR lpszShortPath,  LPSTR lpszLongPath,  DWORD cchBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLongPathNameA(lpszShortPath, lpszLongPath, cchBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetLongPathNameW)(LPCWSTR lpszShortPath,  LPWSTR lpszLongPath,  DWORD cchBuffer) = GetLongPathNameW;
static DWORD WINAPI hooked_GetLongPathNameW(LPCWSTR lpszShortPath,  LPWSTR lpszLongPath,  DWORD cchBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetLongPathNameW(lpszShortPath, lpszLongPath, cchBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetShortPathNameW)(LPCWSTR lpszLongPath,  LPWSTR lpszShortPath,  DWORD cchBuffer) = GetShortPathNameW;
static DWORD WINAPI hooked_GetShortPathNameW(LPCWSTR lpszLongPath,  LPWSTR lpszShortPath,  DWORD cchBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetShortPathNameW(lpszLongPath, lpszShortPath, cchBuffer); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetTempFileNameA)(LPCSTR lpPathName,  LPCSTR lpPrefixString,  UINT uUnique,  LPSTR lpTempFileName) = GetTempFileNameA;
static UINT WINAPI hooked_GetTempFileNameA(LPCSTR lpPathName,  LPCSTR lpPrefixString,  UINT uUnique,  LPSTR lpTempFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetTempFileNameA(lpPathName, lpPrefixString, uUnique, lpTempFileName); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetTempFileNameW)(LPCWSTR lpPathName,  LPCWSTR lpPrefixString,  UINT uUnique,  LPWSTR lpTempFileName) = GetTempFileNameW;
static UINT WINAPI hooked_GetTempFileNameW(LPCWSTR lpPathName,  LPCWSTR lpPrefixString,  UINT uUnique,  LPWSTR lpTempFileName) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTempPath2A)(DWORD BufferLength,  LPSTR Buffer) = GetTempPath2A;
static DWORD WINAPI hooked_GetTempPath2A(DWORD BufferLength,  LPSTR Buffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTempPath2A(BufferLength, Buffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTempPath2W)(DWORD BufferLength,  LPWSTR Buffer) = GetTempPath2W;
static DWORD WINAPI hooked_GetTempPath2W(DWORD BufferLength,  LPWSTR Buffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTempPath2W(BufferLength, Buffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTempPathA)(DWORD nBufferLength,  LPSTR lpBuffer) = GetTempPathA;
static DWORD WINAPI hooked_GetTempPathA(DWORD nBufferLength,  LPSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTempPathA(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTempPathW)(DWORD nBufferLength,  LPWSTR lpBuffer) = GetTempPathW;
static DWORD WINAPI hooked_GetTempPathW(DWORD nBufferLength,  LPWSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTempPathW(nBufferLength, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumeInformationA)(LPCSTR lpRootPathName,  LPSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) = GetVolumeInformationA;
static BOOL WINAPI hooked_GetVolumeInformationA(LPCSTR lpRootPathName,  LPSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumeInformationA(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumeInformationByHandleW)(HANDLE hFile,  LPWSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPWSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) = GetVolumeInformationByHandleW;
static BOOL WINAPI hooked_GetVolumeInformationByHandleW(HANDLE hFile,  LPWSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPWSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumeInformationByHandleW(hFile, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumeInformationW)(LPCWSTR lpRootPathName,  LPWSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPWSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) = GetVolumeInformationW;
static BOOL WINAPI hooked_GetVolumeInformationW(LPCWSTR lpRootPathName,  LPWSTR lpVolumeNameBuffer,  DWORD nVolumeNameSize,  LPDWORD lpVolumeSerialNumber,  LPDWORD lpMaximumComponentLength,  LPDWORD lpFileSystemFlags,  LPWSTR lpFileSystemNameBuffer,  DWORD nFileSystemNameSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumeInformationW(lpRootPathName, lpVolumeNameBuffer, nVolumeNameSize, lpVolumeSerialNumber, lpMaximumComponentLength, lpFileSystemFlags, lpFileSystemNameBuffer, nFileSystemNameSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumeNameForVolumeMountPointW)(LPCWSTR lpszVolumeMountPoint,  LPWSTR lpszVolumeName,  DWORD cchBufferLength) = GetVolumeNameForVolumeMountPointW;
static BOOL WINAPI hooked_GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,  LPWSTR lpszVolumeName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumeNameForVolumeMountPointW(lpszVolumeMountPoint, lpszVolumeName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumePathNamesForVolumeNameW)(LPCWSTR lpszVolumeName,  LPWCH lpszVolumePathNames,  DWORD cchBufferLength,  PDWORD lpcchReturnLength) = GetVolumePathNamesForVolumeNameW;
static BOOL WINAPI hooked_GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,  LPWCH lpszVolumePathNames,  DWORD cchBufferLength,  PDWORD lpcchReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumePathNamesForVolumeNameW(lpszVolumeName, lpszVolumePathNames, cchBufferLength, lpcchReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetVolumePathNameW)(LPCWSTR lpszFileName,  LPWSTR lpszVolumePathName,  DWORD cchBufferLength) = GetVolumePathNameW;
static BOOL WINAPI hooked_GetVolumePathNameW(LPCWSTR lpszFileName,  LPWSTR lpszVolumePathName,  DWORD cchBufferLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVolumePathNameW(lpszFileName, lpszVolumePathName, cchBufferLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LockFile)(HANDLE hFile,  DWORD dwFileOffsetLow,  DWORD dwFileOffsetHigh,  DWORD nNumberOfBytesToLockLow,  DWORD nNumberOfBytesToLockHigh) = LockFile;
static BOOL WINAPI hooked_LockFile(HANDLE hFile,  DWORD dwFileOffsetLow,  DWORD dwFileOffsetHigh,  DWORD nNumberOfBytesToLockLow,  DWORD nNumberOfBytesToLockHigh) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LockFileEx)(HANDLE hFile,  DWORD dwFlags, DWORD dwReserved,  DWORD nNumberOfBytesToLockLow,  DWORD nNumberOfBytesToLockHigh,  LPOVERLAPPED lpOverlapped) = LockFileEx;
static BOOL WINAPI hooked_LockFileEx(HANDLE hFile,  DWORD dwFlags, DWORD dwReserved,  DWORD nNumberOfBytesToLockLow,  DWORD nNumberOfBytesToLockHigh,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LockFileEx(hFile, dwFlags, dwReserved, nNumberOfBytesToLockLow, nNumberOfBytesToLockHigh, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_LocalFileTimeToFileTime)(const FILETIME *lpLocalFileTime,  LPFILETIME lpFileTime) = LocalFileTimeToFileTime;
static BOOL WINAPI hooked_LocalFileTimeToFileTime(const FILETIME *lpLocalFileTime,  LPFILETIME lpFileTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_QueryDosDeviceW)(LPCWSTR lpDeviceName,  LPWSTR lpTargetPath,  DWORD ucchMax) = QueryDosDeviceW;
static DWORD WINAPI hooked_QueryDosDeviceW(LPCWSTR lpDeviceName,  LPWSTR lpTargetPath,  DWORD ucchMax) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_QueryDosDeviceW(lpDeviceName, lpTargetPath, ucchMax); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadFile)(HANDLE hFile,  LPVOID lpBuffer,  DWORD nNumberOfBytesToRead,  LPDWORD lpNumberOfBytesRead,  LPOVERLAPPED lpOverlapped) = ReadFile;
static BOOL WINAPI hooked_ReadFile(HANDLE hFile,  LPVOID lpBuffer,  DWORD nNumberOfBytesToRead,  LPDWORD lpNumberOfBytesRead,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDirectory2A)(LPCSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags) = RemoveDirectory2A;
static BOOL WINAPI hooked_RemoveDirectory2A(LPCSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectory2A(lpPathName, DirectoryFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadFileEx)(HANDLE hFile,  LPVOID lpBuffer,  DWORD nNumberOfBytesToRead,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = ReadFileEx;
static BOOL WINAPI hooked_ReadFileEx(HANDLE hFile,  LPVOID lpBuffer,  DWORD nNumberOfBytesToRead,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadFileEx(hFile, lpBuffer, nNumberOfBytesToRead, lpOverlapped, lpCompletionRoutine); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReadFileScatter)(HANDLE hFile,  FILE_SEGMENT_ELEMENT  *aSegmentArray,  DWORD nNumberOfBytesToRead, LPDWORD lpReserved,  LPOVERLAPPED lpOverlapped) = ReadFileScatter;
static BOOL WINAPI hooked_ReadFileScatter(HANDLE hFile,  FILE_SEGMENT_ELEMENT  *aSegmentArray,  DWORD nNumberOfBytesToRead, LPDWORD lpReserved,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReadFileScatter(hFile, aSegmentArray, nNumberOfBytesToRead, lpReserved, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDirectoryA)(LPCSTR lpPathName) = RemoveDirectoryA;
static BOOL WINAPI hooked_RemoveDirectoryA(LPCSTR lpPathName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectoryA(lpPathName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDirectory2W)(LPCWSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags) = RemoveDirectory2W;
static BOOL WINAPI hooked_RemoveDirectory2W(LPCWSTR lpPathName, DIRECTORY_FLAGS DirectoryFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectory2W(lpPathName, DirectoryFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_RemoveDirectoryW)(LPCWSTR lpPathName) = RemoveDirectoryW;
static BOOL WINAPI hooked_RemoveDirectoryW(LPCWSTR lpPathName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_RemoveDirectoryW(lpPathName); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SetFileApisToANSI)() = SetFileApisToANSI;
static VOID WINAPI hooked_SetFileApisToANSI() {

	SEND_BEFORE_CALL

	
	TIME({ og_SetFileApisToANSI(); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetEndOfFile)(HANDLE hFile) = SetEndOfFile;
static BOOL WINAPI hooked_SetEndOfFile(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEndOfFile(hFile); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SetFileApisToOEM)() = SetFileApisToOEM;
static VOID WINAPI hooked_SetFileApisToOEM() {

	SEND_BEFORE_CALL

	
	TIME({ og_SetFileApisToOEM(); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetFileAttributesA)(LPCSTR lpFileName,  DWORD dwFileAttributes) = SetFileAttributesA;
static BOOL WINAPI hooked_SetFileAttributesA(LPCSTR lpFileName,  DWORD dwFileAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileAttributesA(lpFileName, dwFileAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileAttributesW)(LPCWSTR lpFileName,  DWORD dwFileAttributes) = SetFileAttributesW;
static BOOL WINAPI hooked_SetFileAttributesW(LPCWSTR lpFileName,  DWORD dwFileAttributes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileAttributesW(lpFileName, dwFileAttributes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileInformationByHandle)(HANDLE hFile,  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,  LPVOID lpFileInformation,  DWORD dwBufferSize) = SetFileInformationByHandle;
static BOOL WINAPI hooked_SetFileInformationByHandle(HANDLE hFile,  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,  LPVOID lpFileInformation,  DWORD dwBufferSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileInformationByHandle(hFile, FileInformationClass, lpFileInformation, dwBufferSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileIoOverlappedRange)(HANDLE FileHandle,  PUCHAR OverlappedRangeStart,  ULONG Length) = SetFileIoOverlappedRange;
static BOOL WINAPI hooked_SetFileIoOverlappedRange(HANDLE FileHandle,  PUCHAR OverlappedRangeStart,  ULONG Length) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileIoOverlappedRange(FileHandle, OverlappedRangeStart, Length); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetFilePointer)(HANDLE hFile,  LONG lDistanceToMove,  PLONG lpDistanceToMoveHigh,  DWORD dwMoveMethod) = SetFilePointer;
static DWORD WINAPI hooked_SetFilePointer(HANDLE hFile,  LONG lDistanceToMove,  PLONG lpDistanceToMoveHigh,  DWORD dwMoveMethod) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetFilePointer(hFile, lDistanceToMove, lpDistanceToMoveHigh, dwMoveMethod); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFilePointerEx)(HANDLE hFile,  LARGE_INTEGER liDistanceToMove,  PLARGE_INTEGER lpNewFilePointer,  DWORD dwMoveMethod) = SetFilePointerEx;
static BOOL WINAPI hooked_SetFilePointerEx(HANDLE hFile,  LARGE_INTEGER liDistanceToMove,  PLARGE_INTEGER lpNewFilePointer,  DWORD dwMoveMethod) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnlockFile)(HANDLE hFile,  DWORD dwFileOffsetLow,  DWORD dwFileOffsetHigh,  DWORD nNumberOfBytesToUnlockLow,  DWORD nNumberOfBytesToUnlockHigh) = UnlockFile;
static BOOL WINAPI hooked_UnlockFile(HANDLE hFile,  DWORD dwFileOffsetLow,  DWORD dwFileOffsetHigh,  DWORD nNumberOfBytesToUnlockLow,  DWORD nNumberOfBytesToUnlockHigh) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnlockFile(hFile, dwFileOffsetLow, dwFileOffsetHigh, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileTime)(HANDLE hFile,  const FILETIME *lpCreationTime,  const FILETIME *lpLastAccessTime,  const FILETIME *lpLastWriteTime) = SetFileTime;
static BOOL WINAPI hooked_SetFileTime(HANDLE hFile,  const FILETIME *lpCreationTime,  const FILETIME *lpLastAccessTime,  const FILETIME *lpLastWriteTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetFileValidData)(HANDLE hFile,  LONGLONG ValidDataLength) = SetFileValidData;
static BOOL WINAPI hooked_SetFileValidData(HANDLE hFile,  LONGLONG ValidDataLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetFileValidData(hFile, ValidDataLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteFile)(HANDLE hFile,  LPCVOID lpBuffer,  DWORD nNumberOfBytesToWrite,  LPDWORD lpNumberOfBytesWritten,  LPOVERLAPPED lpOverlapped) = WriteFile;
static BOOL WINAPI hooked_WriteFile(HANDLE hFile,  LPCVOID lpBuffer,  DWORD nNumberOfBytesToWrite,  LPDWORD lpNumberOfBytesWritten,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnlockFileEx)(HANDLE hFile, DWORD dwReserved,  DWORD nNumberOfBytesToUnlockLow,  DWORD nNumberOfBytesToUnlockHigh,  LPOVERLAPPED lpOverlapped) = UnlockFileEx;
static BOOL WINAPI hooked_UnlockFileEx(HANDLE hFile, DWORD dwReserved,  DWORD nNumberOfBytesToUnlockLow,  DWORD nNumberOfBytesToUnlockHigh,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnlockFileEx(hFile, dwReserved, nNumberOfBytesToUnlockLow, nNumberOfBytesToUnlockHigh, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteFileEx)(HANDLE hFile,  LPCVOID lpBuffer,  DWORD nNumberOfBytesToWrite,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = WriteFileEx;
static BOOL WINAPI hooked_WriteFileEx(HANDLE hFile,  LPCVOID lpBuffer,  DWORD nNumberOfBytesToWrite,  LPOVERLAPPED lpOverlapped,  LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteFileEx(hFile, lpBuffer, nNumberOfBytesToWrite, lpOverlapped, lpCompletionRoutine); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_WriteFileGather)(HANDLE hFile,  FILE_SEGMENT_ELEMENT  *aSegmentArray,  DWORD nNumberOfBytesToWrite, LPDWORD lpReserved,  LPOVERLAPPED lpOverlapped) = WriteFileGather;
static BOOL WINAPI hooked_WriteFileGather(HANDLE hFile,  FILE_SEGMENT_ELEMENT  *aSegmentArray,  DWORD nNumberOfBytesToWrite, LPDWORD lpReserved,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_WriteFileGather(hFile, aSegmentArray, nNumberOfBytesToWrite, lpReserved, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CloseHandle)(HANDLE hObject) = CloseHandle;
static BOOL WINAPI hooked_CloseHandle(HANDLE hObject) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CloseHandle(hObject); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DuplicateHandle)(HANDLE hSourceProcessHandle,  HANDLE hSourceHandle,  HANDLE hTargetProcessHandle,  LPHANDLE lpTargetHandle,  DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwOptions) = DuplicateHandle;
static BOOL WINAPI hooked_DuplicateHandle(HANDLE hSourceProcessHandle,  HANDLE hSourceHandle,  HANDLE hTargetProcessHandle,  LPHANDLE lpTargetHandle,  DWORD dwDesiredAccess,  BOOL bInheritHandle,  DWORD dwOptions) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DuplicateHandle(hSourceProcessHandle, hSourceHandle, hTargetProcessHandle, lpTargetHandle, dwDesiredAccess, bInheritHandle, dwOptions); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetHandleInformation)(HANDLE hObject,  LPDWORD lpdwFlags) = GetHandleInformation;
static BOOL WINAPI hooked_GetHandleInformation(HANDLE hObject,  LPDWORD lpdwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetHandleInformation(hObject, lpdwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetHandleInformation)(HANDLE hObject,  DWORD dwMask,  DWORD dwFlags) = SetHandleInformation;
static BOOL WINAPI hooked_SetHandleInformation(HANDLE hObject,  DWORD dwMask,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetHandleInformation(hObject, dwMask, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CancelIo)(HANDLE hFile) = CancelIo;
static BOOL WINAPI hooked_CancelIo(HANDLE hFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CancelIo(hFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CancelIoEx)(HANDLE hFile,  LPOVERLAPPED lpOverlapped) = CancelIoEx;
static BOOL WINAPI hooked_CancelIoEx(HANDLE hFile,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CancelIoEx(hFile, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CancelSynchronousIo)(HANDLE hThread) = CancelSynchronousIo;
static BOOL WINAPI hooked_CancelSynchronousIo(HANDLE hThread) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CancelSynchronousIo(hThread); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateIoCompletionPort)(HANDLE FileHandle,  HANDLE ExistingCompletionPort,  ULONG_PTR CompletionKey,  DWORD NumberOfConcurrentThreads) = CreateIoCompletionPort;
static HANDLE WINAPI hooked_CreateIoCompletionPort(HANDLE FileHandle,  HANDLE ExistingCompletionPort,  ULONG_PTR CompletionKey,  DWORD NumberOfConcurrentThreads) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateIoCompletionPort(FileHandle, ExistingCompletionPort, CompletionKey, NumberOfConcurrentThreads); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetOverlappedResult)(HANDLE hFile,  LPOVERLAPPED lpOverlapped,  LPDWORD lpNumberOfBytesTransferred,  BOOL bWait) = GetOverlappedResult;
static BOOL WINAPI hooked_GetOverlappedResult(HANDLE hFile,  LPOVERLAPPED lpOverlapped,  LPDWORD lpNumberOfBytesTransferred,  BOOL bWait) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetOverlappedResult(hFile, lpOverlapped, lpNumberOfBytesTransferred, bWait); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeviceIoControl)(HANDLE hDevice,  DWORD dwIoControlCode,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped) = DeviceIoControl;
static BOOL WINAPI hooked_DeviceIoControl(HANDLE hDevice,  DWORD dwIoControlCode,  LPVOID lpInBuffer,  DWORD nInBufferSize,  LPVOID lpOutBuffer,  DWORD nOutBufferSize,  LPDWORD lpBytesReturned,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeviceIoControl(hDevice, dwIoControlCode, lpInBuffer, nInBufferSize, lpOutBuffer, nOutBufferSize, lpBytesReturned, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetQueuedCompletionStatus)(HANDLE CompletionPort, LPDWORD lpNumberOfBytesTransferred,  PULONG_PTR lpCompletionKey,  LPOVERLAPPED *lpOverlapped,  DWORD dwMilliseconds) = GetQueuedCompletionStatus;
static BOOL WINAPI hooked_GetQueuedCompletionStatus(HANDLE CompletionPort, LPDWORD lpNumberOfBytesTransferred,  PULONG_PTR lpCompletionKey,  LPOVERLAPPED *lpOverlapped,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetQueuedCompletionStatus(CompletionPort, lpNumberOfBytesTransferred, lpCompletionKey, lpOverlapped, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_PostQueuedCompletionStatus)(HANDLE CompletionPort,  DWORD dwNumberOfBytesTransferred,  ULONG_PTR dwCompletionKey,  LPOVERLAPPED lpOverlapped) = PostQueuedCompletionStatus;
static BOOL WINAPI hooked_PostQueuedCompletionStatus(HANDLE CompletionPort,  DWORD dwNumberOfBytesTransferred,  ULONG_PTR dwCompletionKey,  LPOVERLAPPED lpOverlapped) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_PostQueuedCompletionStatus(CompletionPort, dwNumberOfBytesTransferred, dwCompletionKey, lpOverlapped); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetOverlappedResultEx)(HANDLE hFile,  LPOVERLAPPED lpOverlapped,  LPDWORD lpNumberOfBytesTransferred,  DWORD dwMilliseconds,  BOOL bAlertable) = GetOverlappedResultEx;
static BOOL WINAPI hooked_GetOverlappedResultEx(HANDLE hFile,  LPOVERLAPPED lpOverlapped,  LPDWORD lpNumberOfBytesTransferred,  DWORD dwMilliseconds,  BOOL bAlertable) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetOverlappedResultEx(hFile, lpOverlapped, lpNumberOfBytesTransferred, dwMilliseconds, bAlertable); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetQueuedCompletionStatusEx)(HANDLE CompletionPort,  LPOVERLAPPED_ENTRY lpCompletionPortEntries,  ULONG ulCount,  PULONG ulNumEntriesRemoved,  DWORD dwMilliseconds,  BOOL fAlertable) = GetQueuedCompletionStatusEx;
static BOOL WINAPI hooked_GetQueuedCompletionStatusEx(HANDLE CompletionPort,  LPOVERLAPPED_ENTRY lpCompletionPortEntries,  ULONG ulCount,  PULONG ulNumEntriesRemoved,  DWORD dwMilliseconds,  BOOL fAlertable) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetQueuedCompletionStatusEx(CompletionPort, lpCompletionPortEntries, ulCount, ulNumEntriesRemoved, dwMilliseconds, fAlertable); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_IsProcessInJob)(HANDLE ProcessHandle,  HANDLE JobHandle,  PBOOL Result) = IsProcessInJob;
static BOOL WINAPI hooked_IsProcessInJob(HANDLE ProcessHandle,  HANDLE JobHandle,  PBOOL Result) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_IsProcessInJob(ProcessHandle, JobHandle, Result); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AssignProcessToJobObject)(HANDLE hJob,  HANDLE hProcess) = AssignProcessToJobObject;
static BOOL WINAPI hooked_AssignProcessToJobObject(HANDLE hJob,  HANDLE hProcess) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AssignProcessToJobObject(hJob, hProcess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateJobObjectW)(LPSECURITY_ATTRIBUTES lpJobAttributes,  LPCWSTR lpName) = CreateJobObjectW;
static HANDLE WINAPI hooked_CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateJobObjectW(lpJobAttributes, lpName); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_FreeMemoryJobObject)(_Frees_ptr_ VOID *Buffer) = FreeMemoryJobObject;
static VOID WINAPI hooked_FreeMemoryJobObject(_Frees_ptr_ VOID *Buffer) {

	SEND_BEFORE_CALL

	
	TIME({ og_FreeMemoryJobObject(Buffer); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_QueryInformationJobObject)(HANDLE hJob,  JOBOBJECTINFOCLASS JobObjectInformationClass,  LPVOID lpJobObjectInformation,  DWORD cbJobObjectInformationLength,  LPDWORD lpReturnLength) = QueryInformationJobObject;
static BOOL WINAPI hooked_QueryInformationJobObject(HANDLE hJob,  JOBOBJECTINFOCLASS JobObjectInformationClass,  LPVOID lpJobObjectInformation,  DWORD cbJobObjectInformationLength,  LPDWORD lpReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryInformationJobObject(hJob, JobObjectInformationClass, lpJobObjectInformation, cbJobObjectInformationLength, lpReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenJobObjectW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) = OpenJobObjectW;
static HANDLE WINAPI hooked_OpenJobObjectW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenJobObjectW(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_QueryIoRateControlInformationJobObject)(HANDLE hJob,  PCWSTR VolumeName,  JOBOBJECT_IO_RATE_CONTROL_INFORMATION **InfoBlocks,  ULONG *InfoBlockCount) = QueryIoRateControlInformationJobObject;
static DWORD WINAPI hooked_QueryIoRateControlInformationJobObject(HANDLE hJob,  PCWSTR VolumeName,  JOBOBJECT_IO_RATE_CONTROL_INFORMATION **InfoBlocks,  ULONG *InfoBlockCount) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_QueryIoRateControlInformationJobObject(hJob, VolumeName, InfoBlocks, InfoBlockCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetInformationJobObject)(HANDLE hJob,  JOBOBJECTINFOCLASS JobObjectInformationClass,  LPVOID lpJobObjectInformation,  DWORD cbJobObjectInformationLength) = SetInformationJobObject;
static BOOL WINAPI hooked_SetInformationJobObject(HANDLE hJob,  JOBOBJECTINFOCLASS JobObjectInformationClass,  LPVOID lpJobObjectInformation,  DWORD cbJobObjectInformationLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetInformationJobObject(hJob, JobObjectInformationClass, lpJobObjectInformation, cbJobObjectInformationLength); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetIoRateControlInformationJobObject)(HANDLE hJob,  JOBOBJECT_IO_RATE_CONTROL_INFORMATION *IoRateControlInfo) = SetIoRateControlInformationJobObject;
static DWORD WINAPI hooked_SetIoRateControlInformationJobObject(HANDLE hJob,  JOBOBJECT_IO_RATE_CONTROL_INFORMATION *IoRateControlInfo) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetIoRateControlInformationJobObject(hJob, IoRateControlInfo); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TerminateJobObject)(HANDLE hJob,  UINT uExitCode) = TerminateJobObject;
static BOOL WINAPI hooked_TerminateJobObject(HANDLE hJob,  UINT uExitCode) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TerminateJobObject(hJob, uExitCode); });

	SEND_AFTER_CALL

    return result;
}

static DLL_DIRECTORY_COOKIE (WINAPI *og_AddDllDirectory)(PCWSTR NewDirectory) = AddDllDirectory;
static DLL_DIRECTORY_COOKIE WINAPI hooked_AddDllDirectory(PCWSTR NewDirectory) {

	SEND_BEFORE_CALL

	
    DLL_DIRECTORY_COOKIE result;
    TIME({ result = og_AddDllDirectory(NewDirectory); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DisableThreadLibraryCalls)(HMODULE hLibModule) = DisableThreadLibraryCalls;
static BOOL WINAPI hooked_DisableThreadLibraryCalls(HMODULE hLibModule) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DisableThreadLibraryCalls(hLibModule); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceNamesA)(HMODULE hModule,  LPCSTR lpType,  ENUMRESNAMEPROCA lpEnumFunc,  LONG_PTR lParam) = EnumResourceNamesA;
static BOOL WINAPI hooked_EnumResourceNamesA(HMODULE hModule,  LPCSTR lpType,  ENUMRESNAMEPROCA lpEnumFunc,  LONG_PTR lParam) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceNamesA(hModule, lpType, lpEnumFunc, lParam); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceLanguagesExW)(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  ENUMRESLANGPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceLanguagesExW;
static BOOL WINAPI hooked_EnumResourceLanguagesExW(HMODULE hModule,  LPCWSTR lpType,  LPCWSTR lpName,  ENUMRESLANGPROCW lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceLanguagesExW(hModule, lpType, lpName, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceNamesExA)(HMODULE hModule, LPCSTR lpType,  ENUMRESNAMEPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceNamesExA;
static BOOL WINAPI hooked_EnumResourceNamesExA(HMODULE hModule, LPCSTR lpType,  ENUMRESNAMEPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceNamesExA(hModule, lpType, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_EnumResourceLanguagesExA)(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  ENUMRESLANGPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) = EnumResourceLanguagesExA;
static BOOL WINAPI hooked_EnumResourceLanguagesExA(HMODULE hModule,  LPCSTR lpType,  LPCSTR lpName,  ENUMRESLANGPROCA lpEnumFunc,  LONG_PTR lParam,  DWORD dwFlags,  LANGID LangId) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnumResourceLanguagesExA(hModule, lpType, lpName, lpEnumFunc, lParam, dwFlags, LangId); });

	SEND_AFTER_CALL

    return result;
}

static size_t (WINAPI *og_uaw_wcslen)(PCUWSTR String) = uaw_wcslen;
static size_t WINAPI hooked_uaw_wcslen(PCUWSTR String) {

	SEND_BEFORE_CALL

	
    size_t result;
    TIME({ result = og_uaw_wcslen(String); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_CompareStringEx)(LPCWSTR lpLocaleName,  DWORD dwCmpFlags,  _In_NLS_string_(cchCount1)LPCWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)LPCWCH lpString2,  int cchCount2,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM lParam) = CompareStringEx;
static int WINAPI hooked_CompareStringEx(LPCWSTR lpLocaleName,  DWORD dwCmpFlags,  _In_NLS_string_(cchCount1)LPCWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)LPCWCH lpString2,  int cchCount2,  LPNLSVERSIONINFO lpVersionInformation,  LPVOID lpReserved,  LPARAM lParam) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_CompareStringEx(lpLocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, lpVersionInformation, lpReserved, lParam); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_CompareStringOrdinal)(_In_NLS_string_(cchCount1)LPCWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)LPCWCH lpString2,  int cchCount2,  BOOL bIgnoreCase) = CompareStringOrdinal;
static int WINAPI hooked_CompareStringOrdinal(_In_NLS_string_(cchCount1)LPCWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)LPCWCH lpString2,  int cchCount2,  BOOL bIgnoreCase) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_CompareStringOrdinal(lpString1, cchCount1, lpString2, cchCount2, bIgnoreCase); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_CompareStringW)(LCID Locale,  DWORD dwCmpFlags,  _In_NLS_string_(cchCount1)PCNZWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)PCNZWCH lpString2,  int cchCount2) = CompareStringW;
static int WINAPI hooked_CompareStringW(LCID Locale,  DWORD dwCmpFlags,  _In_NLS_string_(cchCount1)PCNZWCH lpString1,  int cchCount1,  _In_NLS_string_(cchCount2)PCNZWCH lpString2,  int cchCount2) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_CompareStringW(Locale, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_FoldStringW)(DWORD dwMapFlags,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest) = FoldStringW;
static int WINAPI hooked_FoldStringW(DWORD dwMapFlags,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWSTR lpDestStr,  int cchDest) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_FoldStringW(dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetStringTypeExW)(LCID Locale,  DWORD dwInfoType,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWORD lpCharType) = GetStringTypeExW;
static BOOL WINAPI hooked_GetStringTypeExW(LCID Locale,  DWORD dwInfoType,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWORD lpCharType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetStringTypeExW(Locale, dwInfoType, lpSrcStr, cchSrc, lpCharType); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetStringTypeW)(DWORD dwInfoType,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWORD lpCharType) = GetStringTypeW;
static BOOL WINAPI hooked_GetStringTypeW(DWORD dwInfoType,  _In_NLS_string_(cchSrc)LPCWCH lpSrcStr,  int cchSrc,  LPWORD lpCharType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_WideCharToMultiByte)(UINT CodePage,  DWORD dwFlags,  _In_NLS_string_(cchWideChar)LPCWCH lpWideCharStr,  int cchWideChar,  LPSTR lpMultiByteStr,  int cbMultiByte,  LPCCH lpDefaultChar,  LPBOOL lpUsedDefaultChar) = WideCharToMultiByte;
static int WINAPI hooked_WideCharToMultiByte(UINT CodePage,  DWORD dwFlags,  _In_NLS_string_(cchWideChar)LPCWCH lpWideCharStr,  int cchWideChar,  LPSTR lpMultiByteStr,  int cbMultiByte,  LPCCH lpDefaultChar,  LPBOOL lpUsedDefaultChar) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_WideCharToMultiByte(CodePage, dwFlags, lpWideCharStr, cchWideChar, lpMultiByteStr, cbMultiByte, lpDefaultChar, lpUsedDefaultChar); });

	SEND_AFTER_CALL

    return result;
}

static int (WINAPI *og_MultiByteToWideChar)(UINT CodePage,  DWORD dwFlags,  _In_NLS_string_(cbMultiByte)LPCCH lpMultiByteStr,  int cbMultiByte,  LPWSTR lpWideCharStr,  int cchWideChar) = MultiByteToWideChar;
static int WINAPI hooked_MultiByteToWideChar(UINT CodePage,  DWORD dwFlags,  _In_NLS_string_(cbMultiByte)LPCCH lpMultiByteStr,  int cbMultiByte,  LPWSTR lpWideCharStr,  int cchWideChar) {

	SEND_BEFORE_CALL

	
    int result;
    TIME({ result = og_MultiByteToWideChar(CodePage, dwFlags, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_AcquireSRWLockExclusive)(PSRWLOCK SRWLock) = AcquireSRWLockExclusive;
static VOID WINAPI hooked_AcquireSRWLockExclusive(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
	TIME({ og_AcquireSRWLockExclusive(SRWLock); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_AcquireSRWLockShared)(PSRWLOCK SRWLock) = AcquireSRWLockShared;
static VOID WINAPI hooked_AcquireSRWLockShared(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
	TIME({ og_AcquireSRWLockShared(SRWLock); });

	SEND_AFTER_CALL
	
}

static HANDLE (WINAPI *og_CreateEventA)(LPSECURITY_ATTRIBUTES lpEventAttributes,  BOOL bManualReset,  BOOL bInitialState,  LPCSTR lpName) = CreateEventA;
static HANDLE WINAPI hooked_CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,  BOOL bManualReset,  BOOL bInitialState,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateEventA(lpEventAttributes, bManualReset, bInitialState, lpName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CancelWaitableTimer)(HANDLE hTimer) = CancelWaitableTimer;
static BOOL WINAPI hooked_CancelWaitableTimer(HANDLE hTimer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CancelWaitableTimer(hTimer); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateEventExA)(LPSECURITY_ATTRIBUTES lpEventAttributes,  LPCSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) = CreateEventExA;
static HANDLE WINAPI hooked_CreateEventExA(LPSECURITY_ATTRIBUTES lpEventAttributes,  LPCSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateEventExA(lpEventAttributes, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateEventExW)(LPSECURITY_ATTRIBUTES lpEventAttributes,  LPCWSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) = CreateEventExW;
static HANDLE WINAPI hooked_CreateEventExW(LPSECURITY_ATTRIBUTES lpEventAttributes,  LPCWSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateEventExW(lpEventAttributes, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateEventW)(LPSECURITY_ATTRIBUTES lpEventAttributes,  BOOL bManualReset,  BOOL bInitialState,  LPCWSTR lpName) = CreateEventW;
static HANDLE WINAPI hooked_CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,  BOOL bManualReset,  BOOL bInitialState,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateEventW(lpEventAttributes, bManualReset, bInitialState, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMutexA)(LPSECURITY_ATTRIBUTES lpMutexAttributes,  BOOL bInitialOwner,  LPCSTR lpName) = CreateMutexA;
static HANDLE WINAPI hooked_CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,  BOOL bInitialOwner,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMutexA(lpMutexAttributes, bInitialOwner, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMutexExA)(LPSECURITY_ATTRIBUTES lpMutexAttributes,  LPCSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) = CreateMutexExA;
static HANDLE WINAPI hooked_CreateMutexExA(LPSECURITY_ATTRIBUTES lpMutexAttributes,  LPCSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMutexExA(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMutexExW)(LPSECURITY_ATTRIBUTES lpMutexAttributes,  LPCWSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) = CreateMutexExW;
static HANDLE WINAPI hooked_CreateMutexExW(LPSECURITY_ATTRIBUTES lpMutexAttributes,  LPCWSTR lpName,  DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMutexExW(lpMutexAttributes, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateMutexW)(LPSECURITY_ATTRIBUTES lpMutexAttributes,  BOOL bInitialOwner,  LPCWSTR lpName) = CreateMutexW;
static HANDLE WINAPI hooked_CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,  BOOL bInitialOwner,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateMutexW(lpMutexAttributes, bInitialOwner, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateSemaphoreExW)(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCWSTR lpName, DWORD dwFlags,  DWORD dwDesiredAccess) = CreateSemaphoreExW;
static HANDLE WINAPI hooked_CreateSemaphoreExW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCWSTR lpName, DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateSemaphoreExW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateSemaphoreW)(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCWSTR lpName) = CreateSemaphoreW;
static HANDLE WINAPI hooked_CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,  LONG lInitialCount,  LONG lMaximumCount,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateSemaphoreW(lpSemaphoreAttributes, lInitialCount, lMaximumCount, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateWaitableTimerExW)(LPSECURITY_ATTRIBUTES lpTimerAttributes,  LPCWSTR lpTimerName,  DWORD dwFlags,  DWORD dwDesiredAccess) = CreateWaitableTimerExW;
static HANDLE WINAPI hooked_CreateWaitableTimerExW(LPSECURITY_ATTRIBUTES lpTimerAttributes,  LPCWSTR lpTimerName,  DWORD dwFlags,  DWORD dwDesiredAccess) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateWaitableTimerExW(lpTimerAttributes, lpTimerName, dwFlags, dwDesiredAccess); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateWaitableTimerW)(LPSECURITY_ATTRIBUTES lpTimerAttributes,  BOOL bManualReset,  LPCWSTR lpTimerName) = CreateWaitableTimerW;
static HANDLE WINAPI hooked_CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,  BOOL bManualReset,  LPCWSTR lpTimerName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateWaitableTimerW(lpTimerAttributes, bManualReset, lpTimerName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteSynchronizationBarrier)(LPSYNCHRONIZATION_BARRIER lpBarrier) = DeleteSynchronizationBarrier;
static BOOL WINAPI hooked_DeleteSynchronizationBarrier(LPSYNCHRONIZATION_BARRIER lpBarrier) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteSynchronizationBarrier(lpBarrier); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_EnterCriticalSection)(LPCRITICAL_SECTION lpCriticalSection) = EnterCriticalSection;
static VOID WINAPI hooked_EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {

	SEND_BEFORE_CALL

	
	TIME({ og_EnterCriticalSection(lpCriticalSection); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_DeleteCriticalSection)(LPCRITICAL_SECTION lpCriticalSection) = DeleteCriticalSection;
static VOID WINAPI hooked_DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {

	SEND_BEFORE_CALL

	
	TIME({ og_DeleteCriticalSection(lpCriticalSection); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_EnterSynchronizationBarrier)(LPSYNCHRONIZATION_BARRIER lpBarrier,  DWORD dwFlags) = EnterSynchronizationBarrier;
static BOOL WINAPI hooked_EnterSynchronizationBarrier(LPSYNCHRONIZATION_BARRIER lpBarrier,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_EnterSynchronizationBarrier(lpBarrier, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_InitializeConditionVariable)(PCONDITION_VARIABLE ConditionVariable) = InitializeConditionVariable;
static VOID WINAPI hooked_InitializeConditionVariable(PCONDITION_VARIABLE ConditionVariable) {

	SEND_BEFORE_CALL

	
	TIME({ og_InitializeConditionVariable(ConditionVariable); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_InitializeCriticalSection)(LPCRITICAL_SECTION lpCriticalSection) = InitializeCriticalSection;
static VOID WINAPI hooked_InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {

	SEND_BEFORE_CALL

	
	TIME({ og_InitializeCriticalSection(lpCriticalSection); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount) = InitializeCriticalSectionAndSpinCount;
static BOOL WINAPI hooked_InitializeCriticalSectionAndSpinCount(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_InitializeSListHead)(PSLIST_HEADER ListHead) = InitializeSListHead;
static VOID WINAPI hooked_InitializeSListHead(PSLIST_HEADER ListHead) {

	SEND_BEFORE_CALL

	
	TIME({ og_InitializeSListHead(ListHead); });

	SEND_AFTER_CALL
	
}

static PSLIST_ENTRY (WINAPI *og_InterlockedPopEntrySList)(PSLIST_HEADER ListHead) = InterlockedPopEntrySList;
static PSLIST_ENTRY WINAPI hooked_InterlockedPopEntrySList(PSLIST_HEADER ListHead) {

	SEND_BEFORE_CALL

	
    PSLIST_ENTRY result;
    TIME({ result = og_InterlockedPopEntrySList(ListHead); });

	SEND_AFTER_CALL

    return result;
}

static PSLIST_ENTRY (WINAPI *og_InterlockedFlushSList)(PSLIST_HEADER ListHead) = InterlockedFlushSList;
static PSLIST_ENTRY WINAPI hooked_InterlockedFlushSList(PSLIST_HEADER ListHead) {

	SEND_BEFORE_CALL

	
    PSLIST_ENTRY result;
    TIME({ result = og_InterlockedFlushSList(ListHead); });

	SEND_AFTER_CALL

    return result;
}

static PSLIST_ENTRY (WINAPI *og_InterlockedPushEntrySList)(PSLIST_HEADER ListHead,  __drv_aliasesMem PSLIST_ENTRY ListEntry) = InterlockedPushEntrySList;
static PSLIST_ENTRY WINAPI hooked_InterlockedPushEntrySList(PSLIST_HEADER ListHead,  __drv_aliasesMem PSLIST_ENTRY ListEntry) {

	SEND_BEFORE_CALL

	
    PSLIST_ENTRY result;
    TIME({ result = og_InterlockedPushEntrySList(ListHead, ListEntry); });

	SEND_AFTER_CALL

    return result;
}

static PSLIST_ENTRY (WINAPI *og_InterlockedPushListSListEx)(PSLIST_HEADER ListHead,  PSLIST_ENTRY List,  PSLIST_ENTRY ListEnd,  ULONG Count) = InterlockedPushListSListEx;
static PSLIST_ENTRY WINAPI hooked_InterlockedPushListSListEx(PSLIST_HEADER ListHead,  PSLIST_ENTRY List,  PSLIST_ENTRY ListEnd,  ULONG Count) {

	SEND_BEFORE_CALL

	
    PSLIST_ENTRY result;
    TIME({ result = og_InterlockedPushListSListEx(ListHead, List, ListEnd, Count); });

	SEND_AFTER_CALL

    return result;
}

static USHORT (WINAPI *og_QueryDepthSList)(PSLIST_HEADER ListHead) = QueryDepthSList;
static USHORT WINAPI hooked_QueryDepthSList(PSLIST_HEADER ListHead) {

	SEND_BEFORE_CALL

	
    USHORT result;
    TIME({ result = og_QueryDepthSList(ListHead); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetAppContainerNamedObjectPath)(HANDLE Token,  PSID AppContainerSid,  ULONG ObjectPathLength,  LPWSTR ObjectPath,  PULONG ReturnLength) = GetAppContainerNamedObjectPath;
static BOOL WINAPI hooked_GetAppContainerNamedObjectPath(HANDLE Token,  PSID AppContainerSid,  ULONG ObjectPathLength,  LPWSTR ObjectPath,  PULONG ReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetAppContainerNamedObjectPath(Token, AppContainerSid, ObjectPathLength, ObjectPath, ReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AddResourceAttributeAce)(PACL pAcl,  DWORD dwAceRevision,  DWORD AceFlags,  DWORD AccessMask,  PSID pSid,  PCLAIM_SECURITY_ATTRIBUTES_INFORMATION pAttributeInfo,  PDWORD pReturnLength) = AddResourceAttributeAce;
static BOOL WINAPI hooked_AddResourceAttributeAce(PACL pAcl,  DWORD dwAceRevision,  DWORD AceFlags,  DWORD AccessMask,  PSID pSid,  PCLAIM_SECURITY_ATTRIBUTES_INFORMATION pAttributeInfo,  PDWORD pReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AddResourceAttributeAce(pAcl, dwAceRevision, AceFlags, AccessMask, pSid, pAttributeInfo, pReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_AddScopedPolicyIDAce)(PACL pAcl,  DWORD dwAceRevision,  DWORD AceFlags,  DWORD AccessMask,  PSID pSid) = AddScopedPolicyIDAce;
static BOOL WINAPI hooked_AddScopedPolicyIDAce(PACL pAcl,  DWORD dwAceRevision,  DWORD AceFlags,  DWORD AccessMask,  PSID pSid) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_AddScopedPolicyIDAce(pAcl, dwAceRevision, AceFlags, AccessMask, pSid); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CheckTokenCapability)(HANDLE TokenHandle,  PSID CapabilitySidToCheck,  PBOOL HasCapability) = CheckTokenCapability;
static BOOL WINAPI hooked_CheckTokenCapability(HANDLE TokenHandle,  PSID CapabilitySidToCheck,  PBOOL HasCapability) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CheckTokenCapability(TokenHandle, CapabilitySidToCheck, HasCapability); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CheckTokenMembershipEx)(HANDLE TokenHandle,  PSID SidToCheck,  DWORD Flags,  PBOOL IsMember) = CheckTokenMembershipEx;
static BOOL WINAPI hooked_CheckTokenMembershipEx(HANDLE TokenHandle,  PSID SidToCheck,  DWORD Flags,  PBOOL IsMember) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CheckTokenMembershipEx(TokenHandle, SidToCheck, Flags, IsMember); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeriveCapabilitySidsFromName)(LPCWSTR CapName,  PSID **CapabilityGroupSids,  DWORD *CapabilityGroupSidCount,  PSID **CapabilitySids,  DWORD *CapabilitySidCount) = DeriveCapabilitySidsFromName;
static BOOL WINAPI hooked_DeriveCapabilitySidsFromName(LPCWSTR CapName,  PSID **CapabilityGroupSids,  DWORD *CapabilityGroupSidCount,  PSID **CapabilitySids,  DWORD *CapabilitySidCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeriveCapabilitySidsFromName(CapName, CapabilityGroupSids, CapabilityGroupSidCount, CapabilitySids, CapabilitySidCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetCachedSigningLevel)(HANDLE File,  PULONG Flags,  PULONG SigningLevel,  PUCHAR Thumbprint,  PULONG ThumbprintSize,  PULONG ThumbprintAlgorithm) = GetCachedSigningLevel;
static BOOL WINAPI hooked_GetCachedSigningLevel(HANDLE File,  PULONG Flags,  PULONG SigningLevel,  PUCHAR Thumbprint,  PULONG ThumbprintSize,  PULONG ThumbprintAlgorithm) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetCachedSigningLevel(File, Flags, SigningLevel, Thumbprint, ThumbprintSize, ThumbprintAlgorithm); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetCachedSigningLevel)(PHANDLE SourceFiles,  ULONG SourceFileCount,  ULONG Flags,  HANDLE TargetFile) = SetCachedSigningLevel;
static BOOL WINAPI hooked_SetCachedSigningLevel(PHANDLE SourceFiles,  ULONG SourceFileCount,  ULONG Flags,  HANDLE TargetFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetCachedSigningLevel(SourceFiles, SourceFileCount, Flags, TargetFile); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_InitializeSRWLock)(PSRWLOCK SRWLock) = InitializeSRWLock;
static VOID WINAPI hooked_InitializeSRWLock(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
	TIME({ og_InitializeSRWLock(SRWLock); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_InitializeCriticalSectionEx)(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount,  DWORD Flags) = InitializeCriticalSectionEx;
static BOOL WINAPI hooked_InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount,  DWORD Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitializeSynchronizationBarrier)(LPSYNCHRONIZATION_BARRIER lpBarrier,  LONG lTotalThreads,  LONG lSpinCount) = InitializeSynchronizationBarrier;
static BOOL WINAPI hooked_InitializeSynchronizationBarrier(LPSYNCHRONIZATION_BARRIER lpBarrier,  LONG lTotalThreads,  LONG lSpinCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitializeSynchronizationBarrier(lpBarrier, lTotalThreads, lSpinCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitOnceBeginInitialize)(LPINIT_ONCE lpInitOnce,  DWORD dwFlags,  PBOOL fPending,  LPVOID *lpContext) = InitOnceBeginInitialize;
static BOOL WINAPI hooked_InitOnceBeginInitialize(LPINIT_ONCE lpInitOnce,  DWORD dwFlags,  PBOOL fPending,  LPVOID *lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitOnceBeginInitialize(lpInitOnce, dwFlags, fPending, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitOnceComplete)(LPINIT_ONCE lpInitOnce,  DWORD dwFlags,  LPVOID lpContext) = InitOnceComplete;
static BOOL WINAPI hooked_InitOnceComplete(LPINIT_ONCE lpInitOnce,  DWORD dwFlags,  LPVOID lpContext) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitOnceComplete(lpInitOnce, dwFlags, lpContext); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InitOnceExecuteOnce)(PINIT_ONCE InitOnce,  PINIT_ONCE_FN InitFn,  PVOID Parameter,  LPVOID *Context) = InitOnceExecuteOnce;
static BOOL WINAPI hooked_InitOnceExecuteOnce(PINIT_ONCE InitOnce,  PINIT_ONCE_FN InitFn,  PVOID Parameter,  LPVOID *Context) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InitOnceExecuteOnce(InitOnce, InitFn, Parameter, Context); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_InitOnceInitialize)(PINIT_ONCE InitOnce) = InitOnceInitialize;
static VOID WINAPI hooked_InitOnceInitialize(PINIT_ONCE InitOnce) {

	SEND_BEFORE_CALL

	
	TIME({ og_InitOnceInitialize(InitOnce); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_LeaveCriticalSection)(LPCRITICAL_SECTION lpCriticalSection) = LeaveCriticalSection;
static VOID WINAPI hooked_LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {

	SEND_BEFORE_CALL

	
	TIME({ og_LeaveCriticalSection(lpCriticalSection); });

	SEND_AFTER_CALL
	
}

static HANDLE (WINAPI *og_OpenEventA)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) = OpenEventA;
static HANDLE WINAPI hooked_OpenEventA(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenEventA(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenMutexW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) = OpenMutexW;
static HANDLE WINAPI hooked_OpenMutexW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenMutexW(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenEventW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) = OpenEventW;
static HANDLE WINAPI hooked_OpenEventW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenEventW(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenSemaphoreW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) = OpenSemaphoreW;
static HANDLE WINAPI hooked_OpenSemaphoreW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenSemaphoreW(dwDesiredAccess, bInheritHandle, lpName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReleaseMutex)(HANDLE hMutex) = ReleaseMutex;
static BOOL WINAPI hooked_ReleaseMutex(HANDLE hMutex) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReleaseMutex(hMutex); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_OpenWaitableTimerW)(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpTimerName) = OpenWaitableTimerW;
static HANDLE WINAPI hooked_OpenWaitableTimerW(DWORD dwDesiredAccess,  BOOL bInheritHandle,  LPCWSTR lpTimerName) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_OpenWaitableTimerW(dwDesiredAccess, bInheritHandle, lpTimerName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_ReleaseSemaphore)(HANDLE hSemaphore,  LONG lReleaseCount,  LPLONG lpPreviousCount) = ReleaseSemaphore;
static BOOL WINAPI hooked_ReleaseSemaphore(HANDLE hSemaphore,  LONG lReleaseCount,  LPLONG lpPreviousCount) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ReleaseSemaphore(hSemaphore, lReleaseCount, lpPreviousCount); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_ReleaseSRWLockExclusive)(PSRWLOCK SRWLock) = ReleaseSRWLockExclusive;
static VOID WINAPI hooked_ReleaseSRWLockExclusive(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
	TIME({ og_ReleaseSRWLockExclusive(SRWLock); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_ReleaseSRWLockShared)(PSRWLOCK SRWLock) = ReleaseSRWLockShared;
static VOID WINAPI hooked_ReleaseSRWLockShared(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
	TIME({ og_ReleaseSRWLockShared(SRWLock); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_ResetEvent)(HANDLE hEvent) = ResetEvent;
static BOOL WINAPI hooked_ResetEvent(HANDLE hEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ResetEvent(hEvent); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SetCriticalSectionSpinCount)(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount) = SetCriticalSectionSpinCount;
static DWORD WINAPI hooked_SetCriticalSectionSpinCount(LPCRITICAL_SECTION lpCriticalSection,  DWORD dwSpinCount) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SetCriticalSectionSpinCount(lpCriticalSection, dwSpinCount); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetEvent)(HANDLE hEvent) = SetEvent;
static BOOL WINAPI hooked_SetEvent(HANDLE hEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetEvent(hEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetWaitableTimerEx)(HANDLE hTimer,  const LARGE_INTEGER *lpDueTime,  LONG lPeriod,  PTIMERAPCROUTINE pfnCompletionRoutine,  LPVOID lpArgToCompletionRoutine,  PREASON_CONTEXT WakeContext,  ULONG TolerableDelay) = SetWaitableTimerEx;
static BOOL WINAPI hooked_SetWaitableTimerEx(HANDLE hTimer,  const LARGE_INTEGER *lpDueTime,  LONG lPeriod,  PTIMERAPCROUTINE pfnCompletionRoutine,  LPVOID lpArgToCompletionRoutine,  PREASON_CONTEXT WakeContext,  ULONG TolerableDelay) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetWaitableTimerEx(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, WakeContext, TolerableDelay); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetWaitableTimer)(HANDLE hTimer,  const LARGE_INTEGER *lpDueTime,  LONG lPeriod,  PTIMERAPCROUTINE pfnCompletionRoutine,  LPVOID lpArgToCompletionRoutine,  BOOL fResume) = SetWaitableTimer;
static BOOL WINAPI hooked_SetWaitableTimer(HANDLE hTimer,  const LARGE_INTEGER *lpDueTime,  LONG lPeriod,  PTIMERAPCROUTINE pfnCompletionRoutine,  LPVOID lpArgToCompletionRoutine,  BOOL fResume) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetWaitableTimer(hTimer, lpDueTime, lPeriod, pfnCompletionRoutine, lpArgToCompletionRoutine, fResume); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_SignalObjectAndWait)(HANDLE hObjectToSignal,  HANDLE hObjectToWaitOn,  DWORD dwMilliseconds,  BOOL bAlertable) = SignalObjectAndWait;
static DWORD WINAPI hooked_SignalObjectAndWait(HANDLE hObjectToSignal,  HANDLE hObjectToWaitOn,  DWORD dwMilliseconds,  BOOL bAlertable) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SignalObjectAndWait(hObjectToSignal, hObjectToWaitOn, dwMilliseconds, bAlertable); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_Sleep)(DWORD dwMilliseconds) = Sleep;
static VOID WINAPI hooked_Sleep(DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
	TIME({ og_Sleep(dwMilliseconds); });

	SEND_AFTER_CALL
	
}

static DWORD (WINAPI *og_SleepEx)(DWORD dwMilliseconds,  BOOL bAlertable) = SleepEx;
static DWORD WINAPI hooked_SleepEx(DWORD dwMilliseconds,  BOOL bAlertable) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_SleepEx(dwMilliseconds, bAlertable); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_TryAcquireSRWLockExclusive)(PSRWLOCK SRWLock) = TryAcquireSRWLockExclusive;
static BOOLEAN WINAPI hooked_TryAcquireSRWLockExclusive(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_TryAcquireSRWLockExclusive(SRWLock); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SleepConditionVariableSRW)(PCONDITION_VARIABLE ConditionVariable,  PSRWLOCK SRWLock,  DWORD dwMilliseconds,  ULONG Flags) = SleepConditionVariableSRW;
static BOOL WINAPI hooked_SleepConditionVariableSRW(PCONDITION_VARIABLE ConditionVariable,  PSRWLOCK SRWLock,  DWORD dwMilliseconds,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SleepConditionVariableSRW(ConditionVariable, SRWLock, dwMilliseconds, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SleepConditionVariableCS)(PCONDITION_VARIABLE ConditionVariable,  PCRITICAL_SECTION CriticalSection,  DWORD dwMilliseconds) = SleepConditionVariableCS;
static BOOL WINAPI hooked_SleepConditionVariableCS(PCONDITION_VARIABLE ConditionVariable,  PCRITICAL_SECTION CriticalSection,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SleepConditionVariableCS(ConditionVariable, CriticalSection, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static BOOLEAN (WINAPI *og_TryAcquireSRWLockShared)(PSRWLOCK SRWLock) = TryAcquireSRWLockShared;
static BOOLEAN WINAPI hooked_TryAcquireSRWLockShared(PSRWLOCK SRWLock) {

	SEND_BEFORE_CALL

	
    BOOLEAN result;
    TIME({ result = og_TryAcquireSRWLockShared(SRWLock); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TryEnterCriticalSection)(LPCRITICAL_SECTION lpCriticalSection) = TryEnterCriticalSection;
static BOOL WINAPI hooked_TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TryEnterCriticalSection(lpCriticalSection); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WaitForMultipleObjects)(DWORD nCount,  const HANDLE *lpHandles,  BOOL bWaitAll,  DWORD dwMilliseconds) = WaitForMultipleObjects;
static DWORD WINAPI hooked_WaitForMultipleObjects(DWORD nCount,  const HANDLE *lpHandles,  BOOL bWaitAll,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WaitForMultipleObjects(nCount, lpHandles, bWaitAll, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WaitForMultipleObjectsEx)(DWORD nCount,  const HANDLE *lpHandles,  BOOL bWaitAll,  DWORD dwMilliseconds,  BOOL bAlertable) = WaitForMultipleObjectsEx;
static DWORD WINAPI hooked_WaitForMultipleObjectsEx(DWORD nCount,  const HANDLE *lpHandles,  BOOL bWaitAll,  DWORD dwMilliseconds,  BOOL bAlertable) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WaitForMultipleObjectsEx(nCount, lpHandles, bWaitAll, dwMilliseconds, bAlertable); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WaitForSingleObject)(HANDLE hHandle,  DWORD dwMilliseconds) = WaitForSingleObject;
static DWORD WINAPI hooked_WaitForSingleObject(HANDLE hHandle,  DWORD dwMilliseconds) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WaitForSingleObject(hHandle, dwMilliseconds); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_WaitForSingleObjectEx)(HANDLE hHandle,  DWORD dwMilliseconds,  BOOL bAlertable) = WaitForSingleObjectEx;
static DWORD WINAPI hooked_WaitForSingleObjectEx(HANDLE hHandle,  DWORD dwMilliseconds,  BOOL bAlertable) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_WaitForSingleObjectEx(hHandle, dwMilliseconds, bAlertable); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_WakeAllConditionVariable)(PCONDITION_VARIABLE ConditionVariable) = WakeAllConditionVariable;
static VOID WINAPI hooked_WakeAllConditionVariable(PCONDITION_VARIABLE ConditionVariable) {

	SEND_BEFORE_CALL

	
	TIME({ og_WakeAllConditionVariable(ConditionVariable); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_WakeConditionVariable)(PCONDITION_VARIABLE ConditionVariable) = WakeConditionVariable;
static VOID WINAPI hooked_WakeConditionVariable(PCONDITION_VARIABLE ConditionVariable) {

	SEND_BEFORE_CALL

	
	TIME({ og_WakeConditionVariable(ConditionVariable); });

	SEND_AFTER_CALL
	
}

static UINT (WINAPI *og_EnumSystemFirmwareTables)(DWORD FirmwareTableProviderSignature,  PVOID pFirmwareTableEnumBuffer,  DWORD BufferSize) = EnumSystemFirmwareTables;
static UINT WINAPI hooked_EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature,  PVOID pFirmwareTableEnumBuffer,  DWORD BufferSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_EnumSystemFirmwareTables(FirmwareTableProviderSignature, pFirmwareTableEnumBuffer, BufferSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetComputerNameExA)(COMPUTER_NAME_FORMAT NameType,  LPSTR lpBuffer,  LPDWORD nSize) = GetComputerNameExA;
static BOOL WINAPI hooked_GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,  LPSTR lpBuffer,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetComputerNameExA(NameType, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetComputerNameExW)(COMPUTER_NAME_FORMAT NameType,  LPWSTR lpBuffer,  LPDWORD nSize) = GetComputerNameExW;
static BOOL WINAPI hooked_GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,  LPWSTR lpBuffer,  LPDWORD nSize) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetComputerNameExW(NameType, lpBuffer, nSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetLogicalProcessorInformation)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,  PDWORD ReturnedLength) = GetLogicalProcessorInformation;
static BOOL WINAPI hooked_GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,  PDWORD ReturnedLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetLogicalProcessorInformation(Buffer, ReturnedLength); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetLocalTime)(LPSYSTEMTIME lpSystemTime) = GetLocalTime;
static VOID WINAPI hooked_GetLocalTime(LPSYSTEMTIME lpSystemTime) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetLocalTime(lpSystemTime); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_GetLogicalProcessorInformationEx)(LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType,  PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer,  PDWORD ReturnedLength) = GetLogicalProcessorInformationEx;
static BOOL WINAPI hooked_GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP RelationshipType,  PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX Buffer,  PDWORD ReturnedLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetLogicalProcessorInformationEx(RelationshipType, Buffer, ReturnedLength); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetNativeSystemInfo)(LPSYSTEM_INFO lpSystemInfo) = GetNativeSystemInfo;
static VOID WINAPI hooked_GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetNativeSystemInfo(lpSystemInfo); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_GetProcessorSystemCycleTime)(USHORT Group,  PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer,  PDWORD ReturnedLength) = GetProcessorSystemCycleTime;
static BOOL WINAPI hooked_GetProcessorSystemCycleTime(USHORT Group,  PSYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION Buffer,  PDWORD ReturnedLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProcessorSystemCycleTime(Group, Buffer, ReturnedLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetPhysicallyInstalledSystemMemory)(PULONGLONG TotalMemoryInKilobytes) = GetPhysicallyInstalledSystemMemory;
static BOOL WINAPI hooked_GetPhysicallyInstalledSystemMemory(PULONGLONG TotalMemoryInKilobytes) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetPhysicallyInstalledSystemMemory(TotalMemoryInKilobytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetProductInfo)(DWORD dwOSMajorVersion,  DWORD dwOSMinorVersion,  DWORD dwSpMajorVersion,  DWORD dwSpMinorVersion,  PDWORD pdwReturnedProductType) = GetProductInfo;
static BOOL WINAPI hooked_GetProductInfo(DWORD dwOSMajorVersion,  DWORD dwOSMinorVersion,  DWORD dwSpMajorVersion,  DWORD dwSpMinorVersion,  PDWORD pdwReturnedProductType) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetSystemDirectoryA)(LPSTR lpBuffer,  UINT uSize) = GetSystemDirectoryA;
static UINT WINAPI hooked_GetSystemDirectoryA(LPSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemDirectoryA(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}


static UINT (WINAPI *og_GetSystemDirectoryW)(LPWSTR lpBuffer,  UINT uSize) = GetSystemDirectoryW;
static UINT WINAPI hooked_GetSystemDirectoryW(LPWSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemDirectoryW(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetSystemFirmwareTable)(DWORD FirmwareTableProviderSignature,  DWORD FirmwareTableID,  PVOID pFirmwareTableBuffer,  DWORD BufferSize) = GetSystemFirmwareTable;
static UINT WINAPI hooked_GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature,  DWORD FirmwareTableID,  PVOID pFirmwareTableBuffer,  DWORD BufferSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemFirmwareTable(FirmwareTableProviderSignature, FirmwareTableID, pFirmwareTableBuffer, BufferSize); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetSystemInfo)(LPSYSTEM_INFO lpSystemInfo) = GetSystemInfo;
static VOID WINAPI hooked_GetSystemInfo(LPSYSTEM_INFO lpSystemInfo) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetSystemInfo(lpSystemInfo); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_GetSystemTime)(LPSYSTEMTIME lpSystemTime) = GetSystemTime;
static VOID WINAPI hooked_GetSystemTime(LPSYSTEMTIME lpSystemTime) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetSystemTime(lpSystemTime); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_GetSystemTimeAdjustment)(PDWORD lpTimeAdjustment,  PDWORD lpTimeIncrement,  PBOOL lpTimeAdjustmentDisabled) = GetSystemTimeAdjustment;
static BOOL WINAPI hooked_GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,  PDWORD lpTimeIncrement,  PBOOL lpTimeAdjustmentDisabled) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetSystemTimeAsFileTime)(LPFILETIME lpSystemTimeAsFileTime) = GetSystemTimeAsFileTime;
static VOID WINAPI hooked_GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetSystemTimeAsFileTime(lpSystemTimeAsFileTime); });

	SEND_AFTER_CALL
	
}

static UINT (WINAPI *og_GetSystemWindowsDirectoryA)(LPSTR lpBuffer,  UINT uSize) = GetSystemWindowsDirectoryA;
static UINT WINAPI hooked_GetSystemWindowsDirectoryA(LPSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemWindowsDirectoryA(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetSystemWindowsDirectoryW)(LPWSTR lpBuffer,  UINT uSize) = GetSystemWindowsDirectoryW;
static UINT WINAPI hooked_GetSystemWindowsDirectoryW(LPWSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetSystemWindowsDirectoryW(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTickCount)() = GetTickCount;
static DWORD WINAPI hooked_GetTickCount() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTickCount(); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_GetSystemTimePreciseAsFileTime)(LPFILETIME lpSystemTimeAsFileTime) = GetSystemTimePreciseAsFileTime;
static VOID WINAPI hooked_GetSystemTimePreciseAsFileTime(LPFILETIME lpSystemTimeAsFileTime) {

	SEND_BEFORE_CALL

	
	TIME({ og_GetSystemTimePreciseAsFileTime(lpSystemTimeAsFileTime); });

	SEND_AFTER_CALL
	
}

static ULONGLONG (WINAPI *og_GetTickCount64)() = GetTickCount64;
static ULONGLONG WINAPI hooked_GetTickCount64() {

	SEND_BEFORE_CALL

	
    ULONGLONG result;
    TIME({ result = og_GetTickCount64(); });

	SEND_AFTER_CALL

    return result;
}

static NOT_BUILD_WINDOWS_DEPRECATE DWORD (WINAPI *og_GetVersion)() = GetVersion;
static NOT_BUILD_WINDOWS_DEPRECATE DWORD WINAPI hooked_GetVersion() {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetVersion(); });

	SEND_AFTER_CALL

    return result;
}

static NOT_BUILD_WINDOWS_DEPRECATE BOOL (WINAPI *og_GetVersionExA)(LPOSVERSIONINFOA lpVersionInformation) = GetVersionExA;
static NOT_BUILD_WINDOWS_DEPRECATE BOOL WINAPI hooked_GetVersionExA(LPOSVERSIONINFOA lpVersionInformation) {

	SEND_BEFORE_CALL

	
   BOOL result;
    TIME({ result = og_GetVersionExA(lpVersionInformation); });

	SEND_AFTER_CALL

    return result;
}

static NOT_BUILD_WINDOWS_DEPRECATE BOOL (WINAPI *og_GetVersionExW)(LPOSVERSIONINFOW lpVersionInformation) = GetVersionExW;
static NOT_BUILD_WINDOWS_DEPRECATE BOOL WINAPI hooked_GetVersionExW(LPOSVERSIONINFOW lpVersionInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetVersionExW(lpVersionInformation); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetWindowsDirectoryA)(LPSTR lpBuffer,  UINT uSize) = GetWindowsDirectoryA;
static UINT WINAPI hooked_GetWindowsDirectoryA(LPSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetWindowsDirectoryA(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static UINT (WINAPI *og_GetWindowsDirectoryW)(LPWSTR lpBuffer,  UINT uSize) = GetWindowsDirectoryW;
static UINT WINAPI hooked_GetWindowsDirectoryW(LPWSTR lpBuffer,  UINT uSize) {

	SEND_BEFORE_CALL

	
    UINT result;
    TIME({ result = og_GetWindowsDirectoryW(lpBuffer, uSize); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GlobalMemoryStatusEx)(LPMEMORYSTATUSEX lpBuffer) = GlobalMemoryStatusEx;
static BOOL WINAPI hooked_GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GlobalMemoryStatusEx(lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_InstallELAMCertificateInfo)(HANDLE ELAMFile) = InstallELAMCertificateInfo;
static BOOL WINAPI hooked_InstallELAMCertificateInfo(HANDLE ELAMFile) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_InstallELAMCertificateInfo(ELAMFile); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetComputerNameA)(LPCSTR lpComputerName) = SetComputerNameA;
static BOOL WINAPI hooked_SetComputerNameA(LPCSTR lpComputerName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetComputerNameA(lpComputerName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetComputerNameExA)(COMPUTER_NAME_FORMAT NameType,  LPCSTR lpBuffer) = SetComputerNameExA;
static BOOL WINAPI hooked_SetComputerNameExA(COMPUTER_NAME_FORMAT NameType,  LPCSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetComputerNameExA(NameType, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetComputerNameExW)(COMPUTER_NAME_FORMAT NameType,  LPCWSTR lpBuffer) = SetComputerNameExW;
static BOOL WINAPI hooked_SetComputerNameExW(COMPUTER_NAME_FORMAT NameType,  LPCWSTR lpBuffer) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetComputerNameExW(NameType, lpBuffer); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetComputerNameW)(LPCWSTR lpComputerName) = SetComputerNameW;
static BOOL WINAPI hooked_SetComputerNameW(LPCWSTR lpComputerName) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetComputerNameW(lpComputerName); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetLocalTime)(const SYSTEMTIME *lpSystemTime) = SetLocalTime;
static BOOL WINAPI hooked_SetLocalTime(const SYSTEMTIME *lpSystemTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetLocalTime(lpSystemTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetSystemTime)(const SYSTEMTIME *lpSystemTime) = SetSystemTime;
static BOOL WINAPI hooked_SetSystemTime(const SYSTEMTIME *lpSystemTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetSystemTime(lpSystemTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetSystemTimeAdjustment)(DWORD dwTimeAdjustment,  BOOL bTimeAdjustmentDisabled) = SetSystemTimeAdjustment;
static BOOL WINAPI hooked_SetSystemTimeAdjustment(DWORD dwTimeAdjustment,  BOOL bTimeAdjustmentDisabled) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaHighestNodeNumber)(PULONG HighestNodeNumber) = GetNumaHighestNodeNumber;
static BOOL WINAPI hooked_GetNumaHighestNodeNumber(PULONG HighestNodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaHighestNodeNumber(HighestNodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaNodeProcessorMaskEx)(USHORT Node,  PGROUP_AFFINITY ProcessorMask) = GetNumaNodeProcessorMaskEx;
static BOOL WINAPI hooked_GetNumaNodeProcessorMaskEx(USHORT Node,  PGROUP_AFFINITY ProcessorMask) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaNodeProcessorMaskEx(Node, ProcessorMask); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetNumaProximityNodeEx)(ULONG ProximityId,  PUSHORT NodeNumber) = GetNumaProximityNodeEx;
static BOOL WINAPI hooked_GetNumaProximityNodeEx(ULONG ProximityId,  PUSHORT NodeNumber) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetNumaProximityNodeEx(ProximityId, NodeNumber); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapDestroy)(HANDLE hHeap) = HeapDestroy;
static BOOL WINAPI hooked_HeapDestroy(HANDLE hHeap) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapDestroy(hHeap); });

	SEND_AFTER_CALL

    return result;
}

static  LPVOID (WINAPI *og_HeapAlloc)(HANDLE hHeap,  DWORD dwFlags,  SIZE_T dwBytes) = HeapAlloc;
static  LPVOID WINAPI hooked_HeapAlloc(HANDLE hHeap,  DWORD dwFlags,  SIZE_T dwBytes) {

	SEND_BEFORE_CALL

	
     LPVOID result;
    TIME({ result = og_HeapAlloc(hHeap, dwFlags, dwBytes); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_GetProcessHeap)() = GetProcessHeap;
static HANDLE WINAPI hooked_GetProcessHeap() {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_GetProcessHeap(); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_HeapCompact)(HANDLE hHeap,  DWORD dwFlags) = HeapCompact;
static SIZE_T WINAPI hooked_HeapCompact(HANDLE hHeap,  DWORD dwFlags) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_HeapCompact(hHeap, dwFlags); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_HeapCreate)(DWORD flOptions,  SIZE_T dwInitialSize,  SIZE_T dwMaximumSize) = HeapCreate;
static HANDLE WINAPI hooked_HeapCreate(DWORD flOptions,  SIZE_T dwInitialSize,  SIZE_T dwMaximumSize) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_HeapCreate(flOptions, dwInitialSize, dwMaximumSize); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetProcessHeaps)(DWORD NumberOfHeaps,  PHANDLE ProcessHeaps) = GetProcessHeaps;
static DWORD WINAPI hooked_GetProcessHeaps(DWORD NumberOfHeaps,  PHANDLE ProcessHeaps) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetProcessHeaps(NumberOfHeaps, ProcessHeaps); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapFree)(HANDLE hHeap,  DWORD dwFlags,  _Frees_ptr_opt_ LPVOID lpMem) = HeapFree;
static BOOL WINAPI hooked_HeapFree(HANDLE hHeap,  DWORD dwFlags,  _Frees_ptr_opt_ LPVOID lpMem) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapFree(hHeap, dwFlags, lpMem); });

	SEND_AFTER_CALL

    return result;
}

static  LPVOID (WINAPI *og_HeapReAlloc)(HANDLE hHeap,  DWORD dwFlags,  _Frees_ptr_opt_ LPVOID lpMem,  SIZE_T dwBytes) = HeapReAlloc;
static  LPVOID WINAPI hooked_HeapReAlloc(HANDLE hHeap,  DWORD dwFlags,  _Frees_ptr_opt_ LPVOID lpMem,  SIZE_T dwBytes) {

	SEND_BEFORE_CALL

	
     LPVOID result;
    TIME({ result = og_HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapLock)(HANDLE hHeap) = HeapLock;
static BOOL WINAPI hooked_HeapLock(HANDLE hHeap) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapLock(hHeap); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapSetInformation)(HANDLE HeapHandle,  HEAP_INFORMATION_CLASS HeapInformationClass,  PVOID HeapInformation,  SIZE_T HeapInformationLength) = HeapSetInformation;
static BOOL WINAPI hooked_HeapSetInformation(HANDLE HeapHandle,  HEAP_INFORMATION_CLASS HeapInformationClass,  PVOID HeapInformation,  SIZE_T HeapInformationLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapSetInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength); });

	SEND_AFTER_CALL

    return result;
}

static SIZE_T (WINAPI *og_HeapSize)(HANDLE hHeap,  DWORD dwFlags,  LPCVOID lpMem) = HeapSize;
static SIZE_T WINAPI hooked_HeapSize(HANDLE hHeap,  DWORD dwFlags,  LPCVOID lpMem) {

	SEND_BEFORE_CALL

	
    SIZE_T result;
    TIME({ result = og_HeapSize(hHeap, dwFlags, lpMem); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapQueryInformation)(HANDLE HeapHandle,  HEAP_INFORMATION_CLASS HeapInformationClass,  PVOID HeapInformation,  SIZE_T HeapInformationLength,  PSIZE_T ReturnLength) = HeapQueryInformation;
static BOOL WINAPI hooked_HeapQueryInformation(HANDLE HeapHandle,  HEAP_INFORMATION_CLASS HeapInformationClass,  PVOID HeapInformation,  SIZE_T HeapInformationLength,  PSIZE_T ReturnLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapQueryInformation(HeapHandle, HeapInformationClass, HeapInformation, HeapInformationLength, ReturnLength); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapUnlock)(HANDLE hHeap) = HeapUnlock;
static BOOL WINAPI hooked_HeapUnlock(HANDLE hHeap) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapUnlock(hHeap); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapSummary)(HANDLE hHeap,  DWORD dwFlags,  LPHEAP_SUMMARY lpSummary) = HeapSummary;
static BOOL WINAPI hooked_HeapSummary(HANDLE hHeap,  DWORD dwFlags,  LPHEAP_SUMMARY lpSummary) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapSummary(hHeap, dwFlags, lpSummary); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapValidate)(HANDLE hHeap,  DWORD dwFlags,  LPCVOID lpMem) = HeapValidate;
static BOOL WINAPI hooked_HeapValidate(HANDLE hHeap,  DWORD dwFlags,  LPCVOID lpMem) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapValidate(hHeap, dwFlags, lpMem); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_HeapWalk)(HANDLE hHeap,  LPPROCESS_HEAP_ENTRY lpEntry) = HeapWalk;
static BOOL WINAPI hooked_HeapWalk(HANDLE hHeap,  LPPROCESS_HEAP_ENTRY lpEntry) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_HeapWalk(hHeap, lpEntry); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_CancelThreadpoolIo)(PTP_IO pio) = CancelThreadpoolIo;
static VOID WINAPI hooked_CancelThreadpoolIo(PTP_IO pio) {

	SEND_BEFORE_CALL

	
	TIME({ og_CancelThreadpoolIo(pio); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_CallbackMayRunLong)(PTP_CALLBACK_INSTANCE pci) = CallbackMayRunLong;
static BOOL WINAPI hooked_CallbackMayRunLong(PTP_CALLBACK_INSTANCE pci) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CallbackMayRunLong(pci); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_CloseThreadpool)(PTP_POOL ptpp) = CloseThreadpool;
static VOID WINAPI hooked_CloseThreadpool(PTP_POOL ptpp) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpool(ptpp); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolCleanupGroup)(PTP_CLEANUP_GROUP ptpcg) = CloseThreadpoolCleanupGroup;
static VOID WINAPI hooked_CloseThreadpoolCleanupGroup(PTP_CLEANUP_GROUP ptpcg) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolCleanupGroup(ptpcg); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolCleanupGroupMembers)(PTP_CLEANUP_GROUP ptpcg,  BOOL fCancelPendingCallbacks,  PVOID pvCleanupContext) = CloseThreadpoolCleanupGroupMembers;
static VOID WINAPI hooked_CloseThreadpoolCleanupGroupMembers(PTP_CLEANUP_GROUP ptpcg,  BOOL fCancelPendingCallbacks,  PVOID pvCleanupContext) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolCleanupGroupMembers(ptpcg, fCancelPendingCallbacks, pvCleanupContext); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolIo)(PTP_IO pio) = CloseThreadpoolIo;
static VOID WINAPI hooked_CloseThreadpoolIo(PTP_IO pio) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolIo(pio); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolWait)(PTP_WAIT pwa) = CloseThreadpoolWait;
static VOID WINAPI hooked_CloseThreadpoolWait(PTP_WAIT pwa) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolWait(pwa); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolTimer)(PTP_TIMER pti) = CloseThreadpoolTimer;
static VOID WINAPI hooked_CloseThreadpoolTimer(PTP_TIMER pti) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolTimer(pti); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_CloseThreadpoolWork)(PTP_WORK pwk) = CloseThreadpoolWork;
static VOID WINAPI hooked_CloseThreadpoolWork(PTP_WORK pwk) {

	SEND_BEFORE_CALL

	
	TIME({ og_CloseThreadpoolWork(pwk); });

	SEND_AFTER_CALL
	
}

static PTP_POOL (WINAPI *og_CreateThreadpool)(PVOID reserved) = CreateThreadpool;
static PTP_POOL WINAPI hooked_CreateThreadpool(PVOID reserved) {

	SEND_BEFORE_CALL

	
    PTP_POOL result;
    TIME({ result = og_CreateThreadpool(reserved); });

	SEND_AFTER_CALL

    return result;
}

static PTP_CLEANUP_GROUP (WINAPI *og_CreateThreadpoolCleanupGroup)() = CreateThreadpoolCleanupGroup;
static PTP_CLEANUP_GROUP WINAPI hooked_CreateThreadpoolCleanupGroup() {

	SEND_BEFORE_CALL

	
    PTP_CLEANUP_GROUP result;
    TIME({ result = og_CreateThreadpoolCleanupGroup(); });

	SEND_AFTER_CALL

    return result;
}

static PTP_IO (WINAPI *og_CreateThreadpoolIo)(HANDLE fl,  PTP_WIN32_IO_CALLBACK pfnio,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) = CreateThreadpoolIo;
static PTP_IO WINAPI hooked_CreateThreadpoolIo(HANDLE fl,  PTP_WIN32_IO_CALLBACK pfnio,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) {

	SEND_BEFORE_CALL

	
    PTP_IO result;
    TIME({ result = og_CreateThreadpoolIo(fl, pfnio, pv, pcbe); });

	SEND_AFTER_CALL

    return result;
}

static PTP_WORK (WINAPI *og_CreateThreadpoolWork)(PTP_WORK_CALLBACK pfnwk,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) = CreateThreadpoolWork;
static PTP_WORK WINAPI hooked_CreateThreadpoolWork(PTP_WORK_CALLBACK pfnwk,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) {

	SEND_BEFORE_CALL

	
    PTP_WORK result;
    TIME({ result = og_CreateThreadpoolWork(pfnwk, pv, pcbe); });

	SEND_AFTER_CALL

    return result;
}

static PTP_TIMER (WINAPI *og_CreateThreadpoolTimer)(PTP_TIMER_CALLBACK pfnti,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) = CreateThreadpoolTimer;
static PTP_TIMER WINAPI hooked_CreateThreadpoolTimer(PTP_TIMER_CALLBACK pfnti,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) {

	SEND_BEFORE_CALL

	
    PTP_TIMER result;
    TIME({ result = og_CreateThreadpoolTimer(pfnti, pv, pcbe); });

	SEND_AFTER_CALL

    return result;
}

static PTP_WAIT (WINAPI *og_CreateThreadpoolWait)(PTP_WAIT_CALLBACK pfnwa,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) = CreateThreadpoolWait;
static PTP_WAIT WINAPI hooked_CreateThreadpoolWait(PTP_WAIT_CALLBACK pfnwa,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) {

	SEND_BEFORE_CALL

	
    PTP_WAIT result;
    TIME({ result = og_CreateThreadpoolWait(pfnwa, pv, pcbe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueryThreadpoolStackInformation)(PTP_POOL ptpp,  PTP_POOL_STACK_INFORMATION ptpsi) = QueryThreadpoolStackInformation;
static BOOL WINAPI hooked_QueryThreadpoolStackInformation(PTP_POOL ptpp,  PTP_POOL_STACK_INFORMATION ptpsi) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueryThreadpoolStackInformation(ptpp, ptpsi); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_ReleaseMutexWhenCallbackReturns)(PTP_CALLBACK_INSTANCE pci,  HANDLE mut) = ReleaseMutexWhenCallbackReturns;
static VOID WINAPI hooked_ReleaseMutexWhenCallbackReturns(PTP_CALLBACK_INSTANCE pci,  HANDLE mut) {

	SEND_BEFORE_CALL

	
	TIME({ og_ReleaseMutexWhenCallbackReturns(pci, mut); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_ReleaseSemaphoreWhenCallbackReturns)(PTP_CALLBACK_INSTANCE pci,  HANDLE sem,  DWORD crel) = ReleaseSemaphoreWhenCallbackReturns;
static VOID WINAPI hooked_ReleaseSemaphoreWhenCallbackReturns(PTP_CALLBACK_INSTANCE pci,  HANDLE sem,  DWORD crel) {

	SEND_BEFORE_CALL

	
	TIME({ og_ReleaseSemaphoreWhenCallbackReturns(pci, sem, crel); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_SetThreadpoolThreadMaximum)(PTP_POOL ptpp,  DWORD cthrdMost) = SetThreadpoolThreadMaximum;
static VOID WINAPI hooked_SetThreadpoolThreadMaximum(PTP_POOL ptpp,  DWORD cthrdMost) {

	SEND_BEFORE_CALL

	
	TIME({ og_SetThreadpoolThreadMaximum(ptpp, cthrdMost); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_SetEventWhenCallbackReturns)(PTP_CALLBACK_INSTANCE pci,  HANDLE evt) = SetEventWhenCallbackReturns;
static VOID WINAPI hooked_SetEventWhenCallbackReturns(PTP_CALLBACK_INSTANCE pci,  HANDLE evt) {

	SEND_BEFORE_CALL

	
	TIME({ og_SetEventWhenCallbackReturns(pci, evt); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetThreadpoolStackInformation)(PTP_POOL ptpp,  PTP_POOL_STACK_INFORMATION ptpsi) = SetThreadpoolStackInformation;
static BOOL WINAPI hooked_SetThreadpoolStackInformation(PTP_POOL ptpp,  PTP_POOL_STACK_INFORMATION ptpsi) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadpoolStackInformation(ptpp, ptpsi); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetThreadpoolThreadMinimum)(PTP_POOL ptpp,  DWORD cthrdMic) = SetThreadpoolThreadMinimum;
static BOOL WINAPI hooked_SetThreadpoolThreadMinimum(PTP_POOL ptpp,  DWORD cthrdMic) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadpoolThreadMinimum(ptpp, cthrdMic); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SetThreadpoolTimer)(PTP_TIMER pti,  PFILETIME pftDueTime,  DWORD msPeriod,  DWORD msWindowLength) = SetThreadpoolTimer;
static VOID WINAPI hooked_SetThreadpoolTimer(PTP_TIMER pti,  PFILETIME pftDueTime,  DWORD msPeriod,  DWORD msWindowLength) {

	SEND_BEFORE_CALL

	
	TIME({ og_SetThreadpoolTimer(pti, pftDueTime, msPeriod, msWindowLength); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetThreadpoolTimerEx)(PTP_TIMER pti,  PFILETIME pftDueTime,  DWORD msPeriod,  DWORD msWindowLength) = SetThreadpoolTimerEx;
static BOOL WINAPI hooked_SetThreadpoolTimerEx(PTP_TIMER pti,  PFILETIME pftDueTime,  DWORD msPeriod,  DWORD msWindowLength) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadpoolTimerEx(pti, pftDueTime, msPeriod, msWindowLength); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SetThreadpoolWait)(PTP_WAIT pwa,  HANDLE h,  PFILETIME pftTimeout) = SetThreadpoolWait;
static VOID WINAPI hooked_SetThreadpoolWait(PTP_WAIT pwa,  HANDLE h,  PFILETIME pftTimeout) {

	SEND_BEFORE_CALL

	
	TIME({ og_SetThreadpoolWait(pwa, h, pftTimeout); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_StartThreadpoolIo)(PTP_IO pio) = StartThreadpoolIo;
static VOID WINAPI hooked_StartThreadpoolIo(PTP_IO pio) {

	SEND_BEFORE_CALL

	
	TIME({ og_StartThreadpoolIo(pio); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_SetThreadpoolWaitEx)(PTP_WAIT pwa,  HANDLE h,  PFILETIME pftTimeout, PVOID Reserved) = SetThreadpoolWaitEx;
static BOOL WINAPI hooked_SetThreadpoolWaitEx(PTP_WAIT pwa,  HANDLE h,  PFILETIME pftTimeout, PVOID Reserved) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetThreadpoolWaitEx(pwa, h, pftTimeout, Reserved); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_SubmitThreadpoolWork)(PTP_WORK pwk) = SubmitThreadpoolWork;
static VOID WINAPI hooked_SubmitThreadpoolWork(PTP_WORK pwk) {

	SEND_BEFORE_CALL

	
	TIME({ og_SubmitThreadpoolWork(pwk); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_TrySubmitThreadpoolCallback)(PTP_SIMPLE_CALLBACK pfns,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) = TrySubmitThreadpoolCallback;
static BOOL WINAPI hooked_TrySubmitThreadpoolCallback(PTP_SIMPLE_CALLBACK pfns,  PVOID pv,  PTP_CALLBACK_ENVIRON pcbe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TrySubmitThreadpoolCallback(pfns, pv, pcbe); });

	SEND_AFTER_CALL

    return result;
}

static VOID (WINAPI *og_WaitForThreadpoolIoCallbacks)(PTP_IO pio,  BOOL fCancelPendingCallbacks) = WaitForThreadpoolIoCallbacks;
static VOID WINAPI hooked_WaitForThreadpoolIoCallbacks(PTP_IO pio,  BOOL fCancelPendingCallbacks) {

	SEND_BEFORE_CALL

	
	TIME({ og_WaitForThreadpoolIoCallbacks(pio, fCancelPendingCallbacks); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_WaitForThreadpoolTimerCallbacks)(PTP_TIMER pti,  BOOL fCancelPendingCallbacks) = WaitForThreadpoolTimerCallbacks;
static VOID WINAPI hooked_WaitForThreadpoolTimerCallbacks(PTP_TIMER pti,  BOOL fCancelPendingCallbacks) {

	SEND_BEFORE_CALL

	
	TIME({ og_WaitForThreadpoolTimerCallbacks(pti, fCancelPendingCallbacks); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_WaitForThreadpoolWorkCallbacks)(PTP_WORK pwk,  BOOL fCancelPendingCallbacks) = WaitForThreadpoolWorkCallbacks;
static VOID WINAPI hooked_WaitForThreadpoolWorkCallbacks(PTP_WORK pwk,  BOOL fCancelPendingCallbacks) {

	SEND_BEFORE_CALL

	
	TIME({ og_WaitForThreadpoolWorkCallbacks(pwk, fCancelPendingCallbacks); });

	SEND_AFTER_CALL
	
}

static VOID (WINAPI *og_WaitForThreadpoolWaitCallbacks)(PTP_WAIT pwa,  BOOL fCancelPendingCallbacks) = WaitForThreadpoolWaitCallbacks;
static VOID WINAPI hooked_WaitForThreadpoolWaitCallbacks(PTP_WAIT pwa,  BOOL fCancelPendingCallbacks) {

	SEND_BEFORE_CALL

	
	TIME({ og_WaitForThreadpoolWaitCallbacks(pwa, fCancelPendingCallbacks); });

	SEND_AFTER_CALL
	
}

static BOOL (WINAPI *og_ChangeTimerQueueTimer)(HANDLE TimerQueue,  HANDLE Timer,  ULONG DueTime,  ULONG Period) = ChangeTimerQueueTimer;
static BOOL WINAPI hooked_ChangeTimerQueueTimer(HANDLE TimerQueue,  HANDLE Timer,  ULONG DueTime,  ULONG Period) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_ChangeTimerQueueTimer(TimerQueue, Timer, DueTime, Period); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateTimerQueue)() = CreateTimerQueue;
static HANDLE WINAPI hooked_CreateTimerQueue() {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateTimerQueue(); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_CreateTimerQueueTimer)(PHANDLE phNewTimer,  HANDLE TimerQueue,  WAITORTIMERCALLBACK Callback,  PVOID Parameter,  DWORD DueTime,  DWORD Period,  ULONG Flags) = CreateTimerQueueTimer;
static BOOL WINAPI hooked_CreateTimerQueueTimer(PHANDLE phNewTimer,  HANDLE TimerQueue,  WAITORTIMERCALLBACK Callback,  PVOID Parameter,  DWORD DueTime,  DWORD Period,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_CreateTimerQueueTimer(phNewTimer, TimerQueue, Callback, Parameter, DueTime, Period, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteTimerQueueTimer)(HANDLE TimerQueue,  HANDLE Timer,  HANDLE CompletionEvent) = DeleteTimerQueueTimer;
static BOOL WINAPI hooked_DeleteTimerQueueTimer(HANDLE TimerQueue,  HANDLE Timer,  HANDLE CompletionEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteTimerQueueTimer(TimerQueue, Timer, CompletionEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_DeleteTimerQueueEx)(HANDLE TimerQueue,  HANDLE CompletionEvent) = DeleteTimerQueueEx;
static BOOL WINAPI hooked_DeleteTimerQueueEx(HANDLE TimerQueue,  HANDLE CompletionEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_DeleteTimerQueueEx(TimerQueue, CompletionEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_QueueUserWorkItem)(LPTHREAD_START_ROUTINE Function,  PVOID Context,  ULONG Flags) = QueueUserWorkItem;
static BOOL WINAPI hooked_QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,  PVOID Context,  ULONG Flags) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_QueueUserWorkItem(Function, Context, Flags); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_UnregisterWaitEx)(HANDLE WaitHandle,  HANDLE CompletionEvent) = UnregisterWaitEx;
static BOOL WINAPI hooked_UnregisterWaitEx(HANDLE WaitHandle,  HANDLE CompletionEvent) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_UnregisterWaitEx(WaitHandle, CompletionEvent); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_FileTimeToSystemTime)(const FILETIME *lpFileTime,  LPSYSTEMTIME lpSystemTime) = FileTimeToSystemTime;
static BOOL WINAPI hooked_FileTimeToSystemTime(const FILETIME *lpFileTime,  LPSYSTEMTIME lpSystemTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_FileTimeToSystemTime(lpFileTime, lpSystemTime); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetDynamicTimeZoneInformation)(PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation) = GetDynamicTimeZoneInformation;
static DWORD WINAPI hooked_GetDynamicTimeZoneInformation(PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetDynamicTimeZoneInformation(pTimeZoneInformation); });

	SEND_AFTER_CALL

    return result;
}

static DWORD (WINAPI *og_GetTimeZoneInformation)(LPTIME_ZONE_INFORMATION lpTimeZoneInformation) = GetTimeZoneInformation;
static DWORD WINAPI hooked_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation) {

	SEND_BEFORE_CALL

	
    DWORD result;
    TIME({ result = og_GetTimeZoneInformation(lpTimeZoneInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_GetTimeZoneInformationForYear)(USHORT wYear,  PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,  LPTIME_ZONE_INFORMATION ptzi) = GetTimeZoneInformationForYear;
static BOOL WINAPI hooked_GetTimeZoneInformationForYear(USHORT wYear,  PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,  LPTIME_ZONE_INFORMATION ptzi) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_GetTimeZoneInformationForYear(wYear, pdtzi, ptzi); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetDynamicTimeZoneInformation)(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation) = SetDynamicTimeZoneInformation;
static BOOL WINAPI hooked_SetDynamicTimeZoneInformation(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetDynamicTimeZoneInformation(lpTimeZoneInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SystemTimeToTzSpecificLocalTime)(const TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpUniversalTime,  LPSYSTEMTIME lpLocalTime) = SystemTimeToTzSpecificLocalTime;
static BOOL WINAPI hooked_SystemTimeToTzSpecificLocalTime(const TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpUniversalTime,  LPSYSTEMTIME lpLocalTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SystemTimeToFileTime)(const SYSTEMTIME *lpSystemTime,  LPFILETIME lpFileTime) = SystemTimeToFileTime;
static BOOL WINAPI hooked_SystemTimeToFileTime(const SYSTEMTIME *lpSystemTime,  LPFILETIME lpFileTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SystemTimeToFileTime(lpSystemTime, lpFileTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SetTimeZoneInformation)(const TIME_ZONE_INFORMATION *lpTimeZoneInformation) = SetTimeZoneInformation;
static BOOL WINAPI hooked_SetTimeZoneInformation(const TIME_ZONE_INFORMATION *lpTimeZoneInformation) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SetTimeZoneInformation(lpTimeZoneInformation); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_SystemTimeToTzSpecificLocalTimeEx)(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpUniversalTime,  LPSYSTEMTIME lpLocalTime) = SystemTimeToTzSpecificLocalTimeEx;
static BOOL WINAPI hooked_SystemTimeToTzSpecificLocalTimeEx(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpUniversalTime,  LPSYSTEMTIME lpLocalTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_SystemTimeToTzSpecificLocalTimeEx(lpTimeZoneInformation, lpUniversalTime, lpLocalTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TzSpecificLocalTimeToSystemTimeEx)(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpLocalTime,  LPSYSTEMTIME lpUniversalTime) = TzSpecificLocalTimeToSystemTimeEx;
static BOOL WINAPI hooked_TzSpecificLocalTimeToSystemTimeEx(const DYNAMIC_TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpLocalTime,  LPSYSTEMTIME lpUniversalTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TzSpecificLocalTimeToSystemTimeEx(lpTimeZoneInformation, lpLocalTime, lpUniversalTime); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_TzSpecificLocalTimeToSystemTime)(const TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpLocalTime,  LPSYSTEMTIME lpUniversalTime) = TzSpecificLocalTimeToSystemTime;
static BOOL WINAPI hooked_TzSpecificLocalTimeToSystemTime(const TIME_ZONE_INFORMATION *lpTimeZoneInformation,  const SYSTEMTIME *lpLocalTime,  LPSYSTEMTIME lpUniversalTime) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_TzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime); });

	SEND_AFTER_CALL

    return result;
}

static HANDLE (WINAPI *og_CreateToolhelp32Snapshot)(DWORD dwFlags,  DWORD th32ProcessID) = CreateToolhelp32Snapshot;
static HANDLE WINAPI hooked_CreateToolhelp32Snapshot(DWORD dwFlags,  DWORD th32ProcessID) {

	SEND_BEFORE_CALL

	
    HANDLE result;
    TIME({ result = og_CreateToolhelp32Snapshot(dwFlags, th32ProcessID); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Heap32ListFirst)(HANDLE hSnapshot,  LPHEAPLIST32 lphl) = Heap32ListFirst;
static BOOL WINAPI hooked_Heap32ListFirst(HANDLE hSnapshot,  LPHEAPLIST32 lphl) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Heap32ListFirst(hSnapshot, lphl); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Heap32First)(LPHEAPENTRY32 lphe,  DWORD th32ProcessID,  ULONG_PTR th32HeapID) = Heap32First;
static BOOL WINAPI hooked_Heap32First(LPHEAPENTRY32 lphe,  DWORD th32ProcessID,  ULONG_PTR th32HeapID) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Heap32First(lphe, th32ProcessID, th32HeapID); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Heap32ListNext)(HANDLE hSnapshot,  LPHEAPLIST32 lphl) = Heap32ListNext;
static BOOL WINAPI hooked_Heap32ListNext(HANDLE hSnapshot,  LPHEAPLIST32 lphl) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Heap32ListNext(hSnapshot, lphl); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Module32First)(HANDLE hSnapshot,  LPMODULEENTRY32 lpme) = Module32First;
static BOOL WINAPI hooked_Module32First(HANDLE hSnapshot,  LPMODULEENTRY32 lpme) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Module32First(hSnapshot, lpme); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Heap32Next)(LPHEAPENTRY32 lphe) = Heap32Next;
static BOOL WINAPI hooked_Heap32Next(LPHEAPENTRY32 lphe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Heap32Next(lphe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Module32FirstW)(HANDLE hSnapshot,  LPMODULEENTRY32W lpme) = Module32FirstW;
static BOOL WINAPI hooked_Module32FirstW(HANDLE hSnapshot,  LPMODULEENTRY32W lpme) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Module32FirstW(hSnapshot, lpme); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Module32Next)(HANDLE hSnapshot,  LPMODULEENTRY32 lpme) = Module32Next;
static BOOL WINAPI hooked_Module32Next(HANDLE hSnapshot,  LPMODULEENTRY32 lpme) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Module32Next(hSnapshot, lpme); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Process32First)(HANDLE hSnapshot,  LPPROCESSENTRY32 lppe) = Process32First;
static BOOL WINAPI hooked_Process32First(HANDLE hSnapshot,  LPPROCESSENTRY32 lppe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Process32First(hSnapshot, lppe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Module32NextW)(HANDLE hSnapshot,  LPMODULEENTRY32W lpme) = Module32NextW;
static BOOL WINAPI hooked_Module32NextW(HANDLE hSnapshot,  LPMODULEENTRY32W lpme) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Module32NextW(hSnapshot, lpme); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Process32FirstW)(HANDLE hSnapshot,  LPPROCESSENTRY32W lppe) = Process32FirstW;
static BOOL WINAPI hooked_Process32FirstW(HANDLE hSnapshot,  LPPROCESSENTRY32W lppe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Process32FirstW(hSnapshot, lppe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Process32Next)(HANDLE hSnapshot,  LPPROCESSENTRY32 lppe) = Process32Next;
static BOOL WINAPI hooked_Process32Next(HANDLE hSnapshot,  LPPROCESSENTRY32 lppe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Process32Next(hSnapshot, lppe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Thread32First)(HANDLE hSnapshot,  LPTHREADENTRY32 lpte) = Thread32First;
static BOOL WINAPI hooked_Thread32First(HANDLE hSnapshot,  LPTHREADENTRY32 lpte) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Thread32First(hSnapshot, lpte); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Process32NextW)(HANDLE hSnapshot,  LPPROCESSENTRY32W lppe) = Process32NextW;
static BOOL WINAPI hooked_Process32NextW(HANDLE hSnapshot,  LPPROCESSENTRY32W lppe) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Process32NextW(hSnapshot, lppe); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Thread32Next)(HANDLE hSnapshot,  LPTHREADENTRY32 lpte) = Thread32Next;
static BOOL WINAPI hooked_Thread32Next(HANDLE hSnapshot,  LPTHREADENTRY32 lpte) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Thread32Next(hSnapshot, lpte); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Toolhelp32ReadProcessMemory)(DWORD th32ProcessID,  LPCVOID lpBaseAddress,  LPVOID lpBuffer,  SIZE_T cbRead,  SIZE_T *lpNumberOfBytesRead) = Toolhelp32ReadProcessMemory;
static BOOL WINAPI hooked_Toolhelp32ReadProcessMemory(DWORD th32ProcessID,  LPCVOID lpBaseAddress,  LPVOID lpBuffer,  SIZE_T cbRead,  SIZE_T *lpNumberOfBytesRead) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Toolhelp32ReadProcessMemory(th32ProcessID, lpBaseAddress, lpBuffer, cbRead, lpNumberOfBytesRead); });

	SEND_AFTER_CALL

    return result;
}

static BOOL (WINAPI *og_Beep)(DWORD dwFreq,  DWORD dwDuration) = Beep;
static BOOL WINAPI hooked_Beep(DWORD dwFreq,  DWORD dwDuration) {

	SEND_BEFORE_CALL

	
    BOOL result;
    TIME({ result = og_Beep(dwFreq, dwDuration); });

	SEND_AFTER_CALL

    return result;
}

static  BOOLEAN (WINAPI *og_RtlAddFunctionTable)(PRUNTIME_FUNCTION FunctionTable,  DWORD EntryCount,  DWORD64 BaseAddress) = RtlAddFunctionTable;
static  BOOLEAN WINAPI hooked_RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,  DWORD EntryCount,  DWORD64 BaseAddress) {

	SEND_BEFORE_CALL

	
     BOOLEAN result;
    TIME({ result = og_RtlAddFunctionTable(FunctionTable, EntryCount, BaseAddress); });

	SEND_AFTER_CALL

    return result;
}

static  VOID (WINAPI *og_RtlCaptureContext)(PCONTEXT ContextRecord) = RtlCaptureContext;
static  VOID WINAPI hooked_RtlCaptureContext(PCONTEXT ContextRecord) {

	SEND_BEFORE_CALL

	
    TIME({ og_RtlCaptureContext(ContextRecord); });

	SEND_AFTER_CALL

}

static  BOOLEAN (WINAPI *og_RtlDeleteFunctionTable)(PRUNTIME_FUNCTION FunctionTable) = RtlDeleteFunctionTable;
static  BOOLEAN WINAPI hooked_RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable) {

	SEND_BEFORE_CALL

	
     BOOLEAN result;
    TIME({ result = og_RtlDeleteFunctionTable(FunctionTable); });

	SEND_AFTER_CALL

    return result;
}

static  BOOLEAN (WINAPI *og_RtlInstallFunctionTableCallback)(DWORD64 TableIdentifier,  DWORD64 BaseAddress,  DWORD Length,  PGET_RUNTIME_FUNCTION_CALLBACK Callback,  PVOID Context,  PCWSTR OutOfProcessCallbackDll) = RtlInstallFunctionTableCallback;
static  BOOLEAN WINAPI hooked_RtlInstallFunctionTableCallback(DWORD64 TableIdentifier,  DWORD64 BaseAddress,  DWORD Length,  PGET_RUNTIME_FUNCTION_CALLBACK Callback,  PVOID Context,  PCWSTR OutOfProcessCallbackDll) {

	SEND_BEFORE_CALL

	
     BOOLEAN result;
    TIME({ result = og_RtlInstallFunctionTableCallback(TableIdentifier, BaseAddress, Length, Callback, Context, OutOfProcessCallbackDll); });

	SEND_AFTER_CALL

    return result;
}

static  PRUNTIME_FUNCTION (WINAPI *og_RtlLookupFunctionEntry)(DWORD64 ControlPc,  PDWORD64 ImageBase,  PUNWIND_HISTORY_TABLE HistoryTable) = RtlLookupFunctionEntry;
static  PRUNTIME_FUNCTION WINAPI hooked_RtlLookupFunctionEntry(DWORD64 ControlPc,  PDWORD64 ImageBase,  PUNWIND_HISTORY_TABLE HistoryTable) {

	SEND_BEFORE_CALL

	
     PRUNTIME_FUNCTION result;
    TIME({ result = og_RtlLookupFunctionEntry(ControlPc, ImageBase, HistoryTable); });

	SEND_AFTER_CALL

    return result;
}

static  PVOID (WINAPI *og_RtlPcToFileHeader)(PVOID PcValue,  PVOID *BaseOfImage) = RtlPcToFileHeader;
static  PVOID WINAPI hooked_RtlPcToFileHeader(PVOID PcValue,  PVOID *BaseOfImage) {

	SEND_BEFORE_CALL

	
     PVOID result;
    TIME({ result = og_RtlPcToFileHeader(PcValue, BaseOfImage); });

	SEND_AFTER_CALL

    return result;
}
static  VOID (WINAPI *og_RtlRestoreContext)(PCONTEXT ContextRecord, _EXCEPTION_RECORD *ExceptionRecord) = RtlRestoreContext;
static  VOID WINAPI hooked_RtlRestoreContext(PCONTEXT ContextRecord, _EXCEPTION_RECORD *ExceptionRecord) {

	SEND_BEFORE_CALL

	
    TIME({ og_RtlRestoreContext(ContextRecord, ExceptionRecord); });

	SEND_AFTER_CALL

}


static  VOID (WINAPI *og_RtlUnwind)(PVOID TargetFrame,  PVOID TargetIp,  PEXCEPTION_RECORD ExceptionRecord,  PVOID ReturnValue) = RtlUnwind;
static  VOID WINAPI hooked_RtlUnwind(PVOID TargetFrame,  PVOID TargetIp,  PEXCEPTION_RECORD ExceptionRecord,  PVOID ReturnValue) {

	SEND_BEFORE_CALL

	
    TIME({ og_RtlUnwind(TargetFrame, TargetIp, ExceptionRecord, ReturnValue); });

	SEND_AFTER_CALL

}

static  VOID (WINAPI *og_RtlUnwindEx)(PVOID TargetFrame,  PVOID TargetIp,  PEXCEPTION_RECORD ExceptionRecord,  PVOID ReturnValue,  PCONTEXT ContextRecord,  PUNWIND_HISTORY_TABLE HistoryTable) = RtlUnwindEx;
static  VOID WINAPI hooked_RtlUnwindEx(PVOID TargetFrame,  PVOID TargetIp,  PEXCEPTION_RECORD ExceptionRecord,  PVOID ReturnValue,  PCONTEXT ContextRecord,  PUNWIND_HISTORY_TABLE HistoryTable) {

	SEND_BEFORE_CALL

	
    TIME({ og_RtlUnwindEx(TargetFrame, TargetIp, ExceptionRecord, ReturnValue, ContextRecord, HistoryTable); });

	SEND_AFTER_CALL

}

static  PEXCEPTION_ROUTINE (WINAPI *og_RtlVirtualUnwind)(DWORD HandlerType,  DWORD64 ImageBase,  DWORD64 ControlPc,  PRUNTIME_FUNCTION FunctionEntry,  PCONTEXT ContextRecord,  PVOID *HandlerData,  PDWORD64 EstablisherFrame,  PKNONVOLATILE_CONTEXT_POINTERS ContextPointers) = RtlVirtualUnwind;
static  PEXCEPTION_ROUTINE WINAPI hooked_RtlVirtualUnwind(DWORD HandlerType,  DWORD64 ImageBase,  DWORD64 ControlPc,  PRUNTIME_FUNCTION FunctionEntry,  PCONTEXT ContextRecord,  PVOID *HandlerData,  PDWORD64 EstablisherFrame,  PKNONVOLATILE_CONTEXT_POINTERS ContextPointers) {

	SEND_BEFORE_CALL

	
     PEXCEPTION_ROUTINE result;
    TIME({ result = og_RtlVirtualUnwind(HandlerType, ImageBase, ControlPc, FunctionEntry, ContextRecord, HandlerData, EstablisherFrame, ContextPointers); });

	SEND_AFTER_CALL

    return result;
}

static  ULONGLONG (WINAPI *og_VerSetConditionMask)(ULONGLONG ConditionMask,  DWORD TypeMask,  BYTE Condition) = VerSetConditionMask;
static  ULONGLONG WINAPI hooked_VerSetConditionMask(ULONGLONG ConditionMask,  DWORD TypeMask,  BYTE Condition) {

	SEND_BEFORE_CALL

	
     ULONGLONG result;
    TIME({ result = og_VerSetConditionMask(ConditionMask, TypeMask, Condition); });

	SEND_AFTER_CALL

    return result;
}



static Hook GLBL_hooks[] = {
    {&(void *&)og_MessageBoxA, (void *)hooked_MessageBoxA},
	{&(void *&)og_DisassociateCurrentThreadFromCallback, (void *)hooked_DisassociateCurrentThreadFromCallback},
	{&(void *&)og_FreeLibraryWhenCallbackReturns, (void *)hooked_FreeLibraryWhenCallbackReturns},
	{&(void *&)og_IsThreadpoolTimerSet, (void *)hooked_IsThreadpoolTimerSet},
	{&(void *&)og_LeaveCriticalSectionWhenCallbackReturns, (void *)hooked_LeaveCriticalSectionWhenCallbackReturns},
	{&(void *&)og_GetDateFormatA, (void *)hooked_GetDateFormatA},
	{&(void *&)og_GetDateFormatEx, (void *)hooked_GetDateFormatEx},
	{&(void *&)og_GetDateFormatW, (void *)hooked_GetDateFormatW},
	{&(void *&)og_GetTimeFormatA, (void *)hooked_GetTimeFormatA},
	{&(void *&)og_GetTimeFormatW, (void *)hooked_GetTimeFormatW},
	{&(void *&)og_GetTimeFormatEx, (void *)hooked_GetTimeFormatEx},
	{&(void *&)og_GetSystemWow64DirectoryA, (void *)hooked_GetSystemWow64DirectoryA},
	{&(void *&)og_GetSystemWow64DirectoryW, (void *)hooked_GetSystemWow64DirectoryW},
	{&(void *&)og_IsWow64Process, (void *)hooked_IsWow64Process},
	{&(void *&)og_IsWow64Process2, (void *)hooked_IsWow64Process2},
	{&(void *&)og_Wow64DisableWow64FsRedirection, (void *)hooked_Wow64DisableWow64FsRedirection},
	{&(void *&)og_Wow64GetThreadContext, (void *)hooked_Wow64GetThreadContext},
	{&(void *&)og_Wow64EnableWow64FsRedirection, (void *)hooked_Wow64EnableWow64FsRedirection},
	{&(void *&)og_Wow64SetThreadContext, (void *)hooked_Wow64SetThreadContext},
	{&(void *&)og_Wow64RevertWow64FsRedirection, (void *)hooked_Wow64RevertWow64FsRedirection},
	{&(void *&)og_Wow64SuspendThread, (void *)hooked_Wow64SuspendThread},
	{&(void *&)og_CheckRemoteDebuggerPresent, (void *)hooked_CheckRemoteDebuggerPresent},
	{&(void *&)og_ContinueDebugEvent, (void *)hooked_ContinueDebugEvent},
	{&(void *&)og_DebugActiveProcess, (void *)hooked_DebugActiveProcess},
	{&(void *&)og_DebugActiveProcessStop, (void *)hooked_DebugActiveProcessStop},
	{&(void *&)og_DebugBreak, (void *)hooked_DebugBreak},
	{&(void *&)og_IsDebuggerPresent, (void *)hooked_IsDebuggerPresent},
	{&(void *&)og_OutputDebugStringA, (void *)hooked_OutputDebugStringA},
	{&(void *&)og_WaitForDebugEvent, (void *)hooked_WaitForDebugEvent},
	{&(void *&)og_OutputDebugStringW, (void *)hooked_OutputDebugStringW},
	{&(void *&)og_WaitForDebugEventEx, (void *)hooked_WaitForDebugEventEx},
	{&(void *&)og_CallNamedPipeW, (void *)hooked_CallNamedPipeW},
	{&(void *&)og_ConnectNamedPipe, (void *)hooked_ConnectNamedPipe},
	{&(void *&)og_CreatePipe, (void *)hooked_CreatePipe},
	{&(void *&)og_CreateNamedPipeW, (void *)hooked_CreateNamedPipeW},
	{&(void *&)og_DisconnectNamedPipe, (void *)hooked_DisconnectNamedPipe},
	{&(void *&)og_GetNamedPipeClientComputerNameW, (void *)hooked_GetNamedPipeClientComputerNameW},
	{&(void *&)og_GetNamedPipeHandleStateW, (void *)hooked_GetNamedPipeHandleStateW},
	{&(void *&)og_GetNamedPipeInfo, (void *)hooked_GetNamedPipeInfo},
	{&(void *&)og_SetNamedPipeHandleState, (void *)hooked_SetNamedPipeHandleState},
	{&(void *&)og_TransactNamedPipe, (void *)hooked_TransactNamedPipe},
	{&(void *&)og_PeekNamedPipe, (void *)hooked_PeekNamedPipe},
	{&(void *&)og_WaitNamedPipeW, (void *)hooked_WaitNamedPipeW},
	{&(void *&)og_AddSIDToBoundaryDescriptor, (void *)hooked_AddSIDToBoundaryDescriptor},
	{&(void *&)og_ClosePrivateNamespace, (void *)hooked_ClosePrivateNamespace},
	{&(void *&)og_CreateBoundaryDescriptorW, (void *)hooked_CreateBoundaryDescriptorW},
	{&(void *&)og_DeleteBoundaryDescriptor, (void *)hooked_DeleteBoundaryDescriptor},
	{&(void *&)og_CreatePrivateNamespaceW, (void *)hooked_CreatePrivateNamespaceW},
	{&(void *&)og_OpenPrivateNamespaceW, (void *)hooked_OpenPrivateNamespaceW},
	{&(void *&)og_RegisterWaitUntilOOBECompleted, (void *)hooked_RegisterWaitUntilOOBECompleted},
	{&(void *&)og_OOBEComplete, (void *)hooked_OOBEComplete},
	{&(void *&)og_UnregisterWaitUntilOOBECompleted, (void *)hooked_UnregisterWaitUntilOOBECompleted},
	{&(void *&)og_ExpandEnvironmentStringsA, (void *)hooked_ExpandEnvironmentStringsA},
	{&(void *&)og_ExpandEnvironmentStringsW, (void *)hooked_ExpandEnvironmentStringsW},
	{&(void *&)og_FreeEnvironmentStringsA, (void *)hooked_FreeEnvironmentStringsA},
	{&(void *&)og_FreeEnvironmentStringsW, (void *)hooked_FreeEnvironmentStringsW},
	{&(void *&)og_GetCommandLineA, (void *)hooked_GetCommandLineA},
	{&(void *&)og_GetEnvironmentStringsW, (void *)hooked_GetEnvironmentStringsW},
	{&(void *&)og_GetEnvironmentStrings, (void *)hooked_GetEnvironmentStrings},
	{&(void *&)og_GetCommandLineW, (void *)hooked_GetCommandLineW},
	{&(void *&)og_GetEnvironmentVariableA, (void *)hooked_GetEnvironmentVariableA},
	{&(void *&)og_GetEnvironmentVariableW, (void *)hooked_GetEnvironmentVariableW},
	{&(void *&)og_NeedCurrentDirectoryForExePathA, (void *)hooked_NeedCurrentDirectoryForExePathA},
	{&(void *&)og_NeedCurrentDirectoryForExePathW, (void *)hooked_NeedCurrentDirectoryForExePathW},
	{&(void *&)og_SearchPathA, (void *)hooked_SearchPathA},
	{&(void *&)og_SearchPathW, (void *)hooked_SearchPathW},
	{&(void *&)og_SetEnvironmentStringsW, (void *)hooked_SetEnvironmentStringsW},
	{&(void *&)og_SetEnvironmentVariableA, (void *)hooked_SetEnvironmentVariableA},
	{&(void *&)og_SetEnvironmentVariableW, (void *)hooked_SetEnvironmentVariableW},
	{&(void *&)og_PssCaptureSnapshot, (void *)hooked_PssCaptureSnapshot},
	{&(void *&)og_PssDuplicateSnapshot, (void *)hooked_PssDuplicateSnapshot},
	{&(void *&)og_PssQuerySnapshot, (void *)hooked_PssQuerySnapshot},
	{&(void *&)og_PssFreeSnapshot, (void *)hooked_PssFreeSnapshot},
	{&(void *&)og_PssWalkMarkerCreate, (void *)hooked_PssWalkMarkerCreate},
	{&(void *&)og_PssWalkMarkerSeekToBeginning, (void *)hooked_PssWalkMarkerSeekToBeginning},
	{&(void *&)og_PssWalkMarkerGetPosition, (void *)hooked_PssWalkMarkerGetPosition},
	{&(void *&)og_PssWalkMarkerSetPosition, (void *)hooked_PssWalkMarkerSetPosition},
	{&(void *&)og_PssWalkMarkerFree, (void *)hooked_PssWalkMarkerFree},
	{&(void *&)og_PssWalkSnapshot, (void *)hooked_PssWalkSnapshot},
	{&(void *&)og_CreateProcessW, (void *)hooked_CreateProcessW},
	{&(void *&)og_CreateProcessA, (void *)hooked_CreateProcessA},
	{&(void *&)og_CreateRemoteThread, (void *)hooked_CreateRemoteThread},
	{&(void *&)og_CreateRemoteThreadEx, (void *)hooked_CreateRemoteThreadEx},
	{&(void *&)og_CreateThread, (void *)hooked_CreateThread},
	{&(void *&)og_DeleteProcThreadAttributeList, (void *)hooked_DeleteProcThreadAttributeList},
	{&(void *&)og_ExitProcess, (void *)hooked_ExitProcess},
	{&(void *&)og_FlushInstructionCache, (void *)hooked_FlushInstructionCache},
	{&(void *&)og_ExitThread, (void *)hooked_ExitThread},
	{&(void *&)og_FlushProcessWriteBuffers, (void *)hooked_FlushProcessWriteBuffers},
	{&(void *&)og_GetCurrentProcess, (void *)hooked_GetCurrentProcess},
	{&(void *&)og_GetCurrentProcessId, (void *)hooked_GetCurrentProcessId},
	{&(void *&)og_GetCurrentProcessorNumber, (void *)hooked_GetCurrentProcessorNumber},
	{&(void *&)og_GetCurrentProcessorNumberEx, (void *)hooked_GetCurrentProcessorNumberEx},
	{&(void *&)og_GetCurrentThread, (void *)hooked_GetCurrentThread},
	{&(void *&)og_GetCurrentThreadId, (void *)hooked_GetCurrentThreadId},
	{&(void *&)og_GetCurrentThreadStackLimits, (void *)hooked_GetCurrentThreadStackLimits},
	{&(void *&)og_GetExitCodeProcess, (void *)hooked_GetExitCodeProcess},
	{&(void *&)og_GetExitCodeThread, (void *)hooked_GetExitCodeThread},
	{&(void *&)og_GetMachineTypeAttributes, (void *)hooked_GetMachineTypeAttributes},
	{&(void *&)og_GetPriorityClass, (void *)hooked_GetPriorityClass},
	{&(void *&)og_GetProcessDefaultCpuSetMasks, (void *)hooked_GetProcessDefaultCpuSetMasks},
	{&(void *&)og_GetProcessDefaultCpuSets, (void *)hooked_GetProcessDefaultCpuSets},
	{&(void *&)og_GetProcessHandleCount, (void *)hooked_GetProcessHandleCount},
	{&(void *&)og_GetProcessId, (void *)hooked_GetProcessId},
	{&(void *&)og_GetProcessIdOfThread, (void *)hooked_GetProcessIdOfThread},
	{&(void *&)og_GetProcessInformation, (void *)hooked_GetProcessInformation},
	{&(void *&)og_GetProcessMitigationPolicy, (void *)hooked_GetProcessMitigationPolicy},
	{&(void *&)og_GetProcessPriorityBoost, (void *)hooked_GetProcessPriorityBoost},
	{&(void *&)og_GetProcessShutdownParameters, (void *)hooked_GetProcessShutdownParameters},
	{&(void *&)og_GetProcessTimes, (void *)hooked_GetProcessTimes},
	{&(void *&)og_GetProcessVersion, (void *)hooked_GetProcessVersion},
	{&(void *&)og_GetStartupInfoW, (void *)hooked_GetStartupInfoW},
	{&(void *&)og_GetSystemTimes, (void *)hooked_GetSystemTimes},
	{&(void *&)og_GetThreadContext, (void *)hooked_GetThreadContext},
	{&(void *&)og_GetThreadDescription, (void *)hooked_GetThreadDescription},
	{&(void *&)og_GetThreadId, (void *)hooked_GetThreadId},
	{&(void *&)og_GetThreadIOPendingFlag, (void *)hooked_GetThreadIOPendingFlag},
	{&(void *&)og_GetThreadIdealProcessorEx, (void *)hooked_GetThreadIdealProcessorEx},
	{&(void *&)og_GetThreadInformation, (void *)hooked_GetThreadInformation},
	{&(void *&)og_GetThreadPriority, (void *)hooked_GetThreadPriority},
	{&(void *&)og_GetThreadPriorityBoost, (void *)hooked_GetThreadPriorityBoost},
	{&(void *&)og_GetThreadSelectedCpuSetMasks, (void *)hooked_GetThreadSelectedCpuSetMasks},
	{&(void *&)og_GetThreadTimes, (void *)hooked_GetThreadTimes},
	{&(void *&)og_InitializeProcThreadAttributeList, (void *)hooked_InitializeProcThreadAttributeList},
	{&(void *&)og_IsProcessCritical, (void *)hooked_IsProcessCritical},
	{&(void *&)og_GetThreadSelectedCpuSets, (void *)hooked_GetThreadSelectedCpuSets},
	{&(void *&)og_IsProcessorFeaturePresent, (void *)hooked_IsProcessorFeaturePresent},
	{&(void *&)og_OpenProcess, (void *)hooked_OpenProcess},
	{&(void *&)og_ProcessIdToSessionId, (void *)hooked_ProcessIdToSessionId},
	{&(void *&)og_OpenThread, (void *)hooked_OpenThread},
	{&(void *&)og_QueryProcessAffinityUpdateMode, (void *)hooked_QueryProcessAffinityUpdateMode},
	{&(void *&)og_QueryProtectedPolicy, (void *)hooked_QueryProtectedPolicy},
	{&(void *&)og_QueueUserAPC, (void *)hooked_QueueUserAPC},
	{&(void *&)og_SetPriorityClass, (void *)hooked_SetPriorityClass},
	{&(void *&)og_ResumeThread, (void *)hooked_ResumeThread},
	{&(void *&)og_QueueUserAPC2, (void *)hooked_QueueUserAPC2},
	{&(void *&)og_SetProcessAffinityUpdateMode, (void *)hooked_SetProcessAffinityUpdateMode},
	{&(void *&)og_SetProcessDefaultCpuSetMasks, (void *)hooked_SetProcessDefaultCpuSetMasks},
	{&(void *&)og_SetProcessDefaultCpuSets, (void *)hooked_SetProcessDefaultCpuSets},
	{&(void *&)og_SetProcessInformation, (void *)hooked_SetProcessInformation},
	{&(void *&)og_SetProcessMitigationPolicy, (void *)hooked_SetProcessMitigationPolicy},
	{&(void *&)og_SetProcessPriorityBoost, (void *)hooked_SetProcessPriorityBoost},
	{&(void *&)og_SetThreadContext, (void *)hooked_SetThreadContext},
	{&(void *&)og_SetProcessShutdownParameters, (void *)hooked_SetProcessShutdownParameters},
	{&(void *&)og_SetThreadDescription, (void *)hooked_SetThreadDescription},
	{&(void *&)og_SetProtectedPolicy, (void *)hooked_SetProtectedPolicy},
	{&(void *&)og_SetThreadIdealProcessor, (void *)hooked_SetThreadIdealProcessor},
	{&(void *&)og_SetThreadIdealProcessorEx, (void *)hooked_SetThreadIdealProcessorEx},
	{&(void *&)og_SetThreadInformation, (void *)hooked_SetThreadInformation},
	{&(void *&)og_SetThreadPriority, (void *)hooked_SetThreadPriority},
	{&(void *&)og_SetThreadSelectedCpuSetMasks, (void *)hooked_SetThreadSelectedCpuSetMasks},
	{&(void *&)og_SetThreadPriorityBoost, (void *)hooked_SetThreadPriorityBoost},
	{&(void *&)og_SetThreadSelectedCpuSets, (void *)hooked_SetThreadSelectedCpuSets},
	{&(void *&)og_SetThreadStackGuarantee, (void *)hooked_SetThreadStackGuarantee},
	{&(void *&)og_SuspendThread, (void *)hooked_SuspendThread},
	{&(void *&)og_SwitchToThread, (void *)hooked_SwitchToThread},
	{&(void *&)og_TerminateProcess, (void *)hooked_TerminateProcess},
	{&(void *&)og_TlsAlloc, (void *)hooked_TlsAlloc},
	{&(void *&)og_TerminateThread, (void *)hooked_TerminateThread},
	{&(void *&)og_TlsFree, (void *)hooked_TlsFree},
	{&(void *&)og_TlsGetValue, (void *)hooked_TlsGetValue},
	{&(void *&)og_TlsGetValue2, (void *)hooked_TlsGetValue2},
	{&(void *&)og_TlsSetValue, (void *)hooked_TlsSetValue},
	{&(void *&)og_GetProcessGroupAffinity, (void *)hooked_GetProcessGroupAffinity},
	{&(void *&)og_GetThreadGroupAffinity, (void *)hooked_GetThreadGroupAffinity},
	{&(void *&)og_SetThreadGroupAffinity, (void *)hooked_SetThreadGroupAffinity},
	{&(void *&)og_QueryPerformanceCounter, (void *)hooked_QueryPerformanceCounter},
	{&(void *&)og_QueryPerformanceFrequency, (void *)hooked_QueryPerformanceFrequency},
	{&(void *&)og_EmptyWorkingSet, (void *)hooked_EmptyWorkingSet},
	{&(void *&)og_EnumDeviceDrivers, (void *)hooked_EnumDeviceDrivers},
	{&(void *&)og_EnumPageFilesA, (void *)hooked_EnumPageFilesA},
	{&(void *&)og_EnumPageFilesW, (void *)hooked_EnumPageFilesW},
	{&(void *&)og_EnumProcesses, (void *)hooked_EnumProcesses},
	{&(void *&)og_EnumProcessModulesEx, (void *)hooked_EnumProcessModulesEx},
	{&(void *&)og_EnumProcessModules, (void *)hooked_EnumProcessModules},
	{&(void *&)og_GetDeviceDriverBaseNameA, (void *)hooked_GetDeviceDriverBaseNameA},
	{&(void *&)og_GetDeviceDriverBaseNameW, (void *)hooked_GetDeviceDriverBaseNameW},
	{&(void *&)og_GetDeviceDriverFileNameA, (void *)hooked_GetDeviceDriverFileNameA},
	{&(void *&)og_GetDeviceDriverFileNameW, (void *)hooked_GetDeviceDriverFileNameW},
	{&(void *&)og_GetModuleBaseNameA, (void *)hooked_GetModuleBaseNameA},
	{&(void *&)og_GetMappedFileNameA, (void *)hooked_GetMappedFileNameA},
	{&(void *&)og_GetMappedFileNameW, (void *)hooked_GetMappedFileNameW},
	{&(void *&)og_GetModuleBaseNameW, (void *)hooked_GetModuleBaseNameW},
	{&(void *&)og_GetModuleFileNameExA, (void *)hooked_GetModuleFileNameExA},
	{&(void *&)og_GetModuleFileNameExW, (void *)hooked_GetModuleFileNameExW},
	{&(void *&)og_GetModuleInformation, (void *)hooked_GetModuleInformation},
	{&(void *&)og_GetProcessImageFileNameA, (void *)hooked_GetProcessImageFileNameA},
	{&(void *&)og_GetPerformanceInfo, (void *)hooked_GetPerformanceInfo},
	{&(void *&)og_GetProcessImageFileNameW, (void *)hooked_GetProcessImageFileNameW},
	{&(void *&)og_GetProcessMemoryInfo, (void *)hooked_GetProcessMemoryInfo},
	{&(void *&)og_GetWsChanges, (void *)hooked_GetWsChanges},
	{&(void *&)og_GetWsChangesEx, (void *)hooked_GetWsChangesEx},
	{&(void *&)og_InitializeProcessForWsWatch, (void *)hooked_InitializeProcessForWsWatch},
	{&(void *&)og_QueryWorkingSet, (void *)hooked_QueryWorkingSet},
	{&(void *&)og_QueryWorkingSetEx, (void *)hooked_QueryWorkingSetEx},
	{&(void *&)og_SetFileBandwidthReservation, (void *)hooked_SetFileBandwidthReservation},
	{&(void *&)og_SetFileCompletionNotificationModes, (void *)hooked_SetFileCompletionNotificationModes},
	{&(void *&)og_SetFileAttributesTransactedA, (void *)hooked_SetFileAttributesTransactedA},
	{&(void *&)og_SetEnvironmentVariable, (void *)hooked_SetEnvironmentVariable},
	{&(void *&)og_SetFileAttributesTransactedW, (void *)hooked_SetFileAttributesTransactedW},
	{&(void *&)og_SetFirmwareEnvironmentVariableExW, (void *)hooked_SetFirmwareEnvironmentVariableExW},
	{&(void *&)og_SetFirmwareEnvironmentVariableExA, (void *)hooked_SetFirmwareEnvironmentVariableExA},
	{&(void *&)og_SetFileShortNameA, (void *)hooked_SetFileShortNameA},
	{&(void *&)og_SetFirmwareEnvironmentVariableW, (void *)hooked_SetFirmwareEnvironmentVariableW},
	{&(void *&)og_SetFileShortNameW, (void *)hooked_SetFileShortNameW},
	{&(void *&)og_SetFirmwareEnvironmentVariableA, (void *)hooked_SetFirmwareEnvironmentVariableA},
	{&(void *&)og_SetHandleCount, (void *)hooked_SetHandleCount},
	{&(void *&)og_SetProcessDEPPolicy, (void *)hooked_SetProcessDEPPolicy},
	{&(void *&)og_SetMailslotInfo, (void *)hooked_SetMailslotInfo},
	{&(void *&)og_SetSearchPathMode, (void *)hooked_SetSearchPathMode},
	{&(void *&)og_SetProcessAffinityMask, (void *)hooked_SetProcessAffinityMask},
	{&(void *&)og_SetSystemPowerState, (void *)hooked_SetSystemPowerState},
	{&(void *&)og_SetTapeParameters, (void *)hooked_SetTapeParameters},
	{&(void *&)og_SetTapePosition, (void *)hooked_SetTapePosition},
	{&(void *&)og_SetThreadAffinityMask, (void *)hooked_SetThreadAffinityMask},
	{&(void *&)og_SetThreadExecutionState, (void *)hooked_SetThreadExecutionState},
	{&(void *&)og_SetUmsThreadInformation, (void *)hooked_SetUmsThreadInformation},
	{&(void *&)og_SetupComm, (void *)hooked_SetupComm},
	{&(void *&)og_SetVolumeLabelA, (void *)hooked_SetVolumeLabelA},
	{&(void *&)og_SetVolumeLabelW, (void *)hooked_SetVolumeLabelW},
	{&(void *&)og_SetVolumeMountPointA, (void *)hooked_SetVolumeMountPointA},
	{&(void *&)og_SetVolumeMountPointW, (void *)hooked_SetVolumeMountPointW},
	{&(void *&)og_SetXStateFeaturesMask, (void *)hooked_SetXStateFeaturesMask},
	{&(void *&)og_TransmitCommChar, (void *)hooked_TransmitCommChar},
	{&(void *&)og_SwitchToFiber, (void *)hooked_SwitchToFiber},
	{&(void *&)og_UmsThreadYield, (void *)hooked_UmsThreadYield},
	{&(void *&)og_UnregisterApplicationRestart, (void *)hooked_UnregisterApplicationRestart},
	{&(void *&)og_UnregisterApplicationRecoveryCallback, (void *)hooked_UnregisterApplicationRecoveryCallback},
	{&(void *&)og_UnregisterWait, (void *)hooked_UnregisterWait},
	{&(void *&)og_UpdateResourceA, (void *)hooked_UpdateResourceA},
	{&(void *&)og_UpdateResourceW, (void *)hooked_UpdateResourceW},
	{&(void *&)og_VerifyVersionInfoW, (void *)hooked_VerifyVersionInfoW},
	{&(void *&)og_VerifyVersionInfoA, (void *)hooked_VerifyVersionInfoA},
	{&(void *&)og_WaitCommEvent, (void *)hooked_WaitCommEvent},
	{&(void *&)og_WaitNamedPipeA, (void *)hooked_WaitNamedPipeA},
	{&(void *&)og_Wow64GetThreadSelectorEntry, (void *)hooked_Wow64GetThreadSelectorEntry},
	{&(void *&)og_WinExec, (void *)hooked_WinExec},
	{&(void *&)og_WritePrivateProfileSectionA, (void *)hooked_WritePrivateProfileSectionA},
	{&(void *&)og_WritePrivateProfileStringA, (void *)hooked_WritePrivateProfileStringA},
	{&(void *&)og_WritePrivateProfileSectionW, (void *)hooked_WritePrivateProfileSectionW},
	{&(void *&)og_WritePrivateProfileStructA, (void *)hooked_WritePrivateProfileStructA},
	{&(void *&)og_WritePrivateProfileStringW, (void *)hooked_WritePrivateProfileStringW},
	{&(void *&)og_WriteProfileSectionA, (void *)hooked_WriteProfileSectionA},
	{&(void *&)og_WritePrivateProfileStructW, (void *)hooked_WritePrivateProfileStructW},
	{&(void *&)og_WriteProfileSectionW, (void *)hooked_WriteProfileSectionW},
	{&(void *&)og_WTSGetActiveConsoleSessionId, (void *)hooked_WTSGetActiveConsoleSessionId},
	{&(void *&)og_WriteProfileStringA, (void *)hooked_WriteProfileStringA},
	{&(void *&)og_WriteProfileStringW, (void *)hooked_WriteProfileStringW},
	{&(void *&)og_WriteTapemark, (void *)hooked_WriteTapemark},
	{&(void *&)og_ZombifyActCtx, (void *)hooked_ZombifyActCtx},
	{&(void *&)og_ConvertAuxiliaryCounterToPerformanceCounter, (void *)hooked_ConvertAuxiliaryCounterToPerformanceCounter},
	{&(void *&)og_ConvertPerformanceCounterToAuxiliaryCounter, (void *)hooked_ConvertPerformanceCounterToAuxiliaryCounter},
	{&(void *&)og_QueryAuxiliaryCounterFrequency, (void *)hooked_QueryAuxiliaryCounterFrequency},
	{&(void *&)og_QueryIdleProcessorCycleTimeEx, (void *)hooked_QueryIdleProcessorCycleTimeEx},
	{&(void *&)og_QueryInterruptTimePrecise, (void *)hooked_QueryInterruptTimePrecise},
	{&(void *&)og_QueryIdleProcessorCycleTime, (void *)hooked_QueryIdleProcessorCycleTime},
	{&(void *&)og_QueryInterruptTime, (void *)hooked_QueryInterruptTime},
	{&(void *&)og_QueryProcessCycleTime, (void *)hooked_QueryProcessCycleTime},
	{&(void *&)og_QueryThreadCycleTime, (void *)hooked_QueryThreadCycleTime},
	{&(void *&)og_QueryUnbiasedInterruptTimePrecise, (void *)hooked_QueryUnbiasedInterruptTimePrecise},
	{&(void *&)og_QueryUnbiasedInterruptTime, (void *)hooked_QueryUnbiasedInterruptTime},
	{&(void *&)og_EnumResourceNamesExW, (void *)hooked_EnumResourceNamesExW},
	{&(void *&)og_EnumResourceNamesW, (void *)hooked_EnumResourceNamesW},
	{&(void *&)og_EnumResourceTypesExA, (void *)hooked_EnumResourceTypesExA},
	{&(void *&)og_FindResourceExW, (void *)hooked_FindResourceExW},
	{&(void *&)og_EnumResourceTypesExW, (void *)hooked_EnumResourceTypesExW},
	{&(void *&)og_FindResourceW, (void *)hooked_FindResourceW},
	{&(void *&)og_FreeLibrary, (void *)hooked_FreeLibrary},
	{&(void *&)og_FindStringOrdinal, (void *)hooked_FindStringOrdinal},
	{&(void *&)og_FreeResource, (void *)hooked_FreeResource},
	{&(void *&)og_FreeLibraryAndExitThread, (void *)hooked_FreeLibraryAndExitThread},
	{&(void *&)og_GetModuleFileNameW, (void *)hooked_GetModuleFileNameW},
	{&(void *&)og_GetModuleFileNameA, (void *)hooked_GetModuleFileNameA},
	{&(void *&)og_GetModuleHandleA, (void *)hooked_GetModuleHandleA},
	{&(void *&)og_GetModuleHandleExA, (void *)hooked_GetModuleHandleExA},
	{&(void *&)og_GetModuleHandleExW, (void *)hooked_GetModuleHandleExW},
	{&(void *&)og_GetModuleHandleW, (void *)hooked_GetModuleHandleW},
	{&(void *&)og_GetProcAddress, (void *)hooked_GetProcAddress},
	{&(void *&)og_LoadLibraryA, (void *)hooked_LoadLibraryA},
	{&(void *&)og_LoadLibraryExA, (void *)hooked_LoadLibraryExA},
	{&(void *&)og_LoadLibraryExW, (void *)hooked_LoadLibraryExW},
	{&(void *&)og_LoadLibraryW, (void *)hooked_LoadLibraryW},
	{&(void *&)og_LockResource, (void *)hooked_LockResource},
	{&(void *&)og_LoadResource, (void *)hooked_LoadResource},
	{&(void *&)og_RemoveDllDirectory, (void *)hooked_RemoveDllDirectory},
	{&(void *&)og_SetDefaultDllDirectories, (void *)hooked_SetDefaultDllDirectories},
	{&(void *&)og_SizeofResource, (void *)hooked_SizeofResource},
	{&(void *&)og_AllocateUserPhysicalPages, (void *)hooked_AllocateUserPhysicalPages},
	{&(void *&)og_AllocateUserPhysicalPagesNuma, (void *)hooked_AllocateUserPhysicalPagesNuma},
	{&(void *&)og_CreateFileMapping2, (void *)hooked_CreateFileMapping2},
	{&(void *&)og_CreateFileMappingFromApp, (void *)hooked_CreateFileMappingFromApp},
	{&(void *&)og_CreateFileMappingW, (void *)hooked_CreateFileMappingW},
	{&(void *&)og_CreateFileMappingNumaW, (void *)hooked_CreateFileMappingNumaW},
	{&(void *&)og_CreateMemoryResourceNotification, (void *)hooked_CreateMemoryResourceNotification},
	{&(void *&)og_DiscardVirtualMemory, (void *)hooked_DiscardVirtualMemory},
	{&(void *&)og_FlushViewOfFile, (void *)hooked_FlushViewOfFile},
	{&(void *&)og_GetLargePageMinimum, (void *)hooked_GetLargePageMinimum},
	{&(void *&)og_GetMemoryErrorHandlingCapabilities, (void *)hooked_GetMemoryErrorHandlingCapabilities},
	{&(void *&)og_FreeUserPhysicalPages, (void *)hooked_FreeUserPhysicalPages},
	{&(void *&)og_GetProcessWorkingSetSize, (void *)hooked_GetProcessWorkingSetSize},
	{&(void *&)og_GetProcessWorkingSetSizeEx, (void *)hooked_GetProcessWorkingSetSizeEx},
	{&(void *&)og_GetSystemFileCacheSize, (void *)hooked_GetSystemFileCacheSize},
	{&(void *&)og_MapUserPhysicalPages, (void *)hooked_MapUserPhysicalPages},
	{&(void *&)og_MapViewOfFile, (void *)hooked_MapViewOfFile},
	{&(void *&)og_GetWriteWatch, (void *)hooked_GetWriteWatch},
	{&(void *&)og_MapViewOfFile2, (void *)hooked_MapViewOfFile2},
	{&(void *&)og_MapViewOfFile3, (void *)hooked_MapViewOfFile3},
	{&(void *&)og_MapViewOfFile3FromApp, (void *)hooked_MapViewOfFile3FromApp},
	{&(void *&)og_MapViewOfFileFromApp, (void *)hooked_MapViewOfFileFromApp},
	{&(void *&)og_MapViewOfFileEx, (void *)hooked_MapViewOfFileEx},
	{&(void *&)og_OfferVirtualMemory, (void *)hooked_OfferVirtualMemory},
	{&(void *&)og_OpenFileMappingFromApp, (void *)hooked_OpenFileMappingFromApp},
	{&(void *&)og_OpenFileMappingW, (void *)hooked_OpenFileMappingW},
	{&(void *&)og_QueryMemoryResourceNotification, (void *)hooked_QueryMemoryResourceNotification},
	{&(void *&)og_PrefetchVirtualMemory, (void *)hooked_PrefetchVirtualMemory},
	{&(void *&)og_ReadProcessMemory, (void *)hooked_ReadProcessMemory},
	{&(void *&)og_RegisterBadMemoryNotification, (void *)hooked_RegisterBadMemoryNotification},
	{&(void *&)og_ReclaimVirtualMemory, (void *)hooked_ReclaimVirtualMemory},
	{&(void *&)og_ResetWriteWatch, (void *)hooked_ResetWriteWatch},
	{&(void *&)og_SetProcessWorkingSetSize, (void *)hooked_SetProcessWorkingSetSize},
	{&(void *&)og_SetProcessWorkingSetSizeEx, (void *)hooked_SetProcessWorkingSetSizeEx},
	{&(void *&)og_UnmapViewOfFile, (void *)hooked_UnmapViewOfFile},
	{&(void *&)og_SetSystemFileCacheSize, (void *)hooked_SetSystemFileCacheSize},
	{&(void *&)og_UnregisterBadMemoryNotification, (void *)hooked_UnregisterBadMemoryNotification},
	{&(void *&)og_UnmapViewOfFileEx, (void *)hooked_UnmapViewOfFileEx},
	{&(void *&)og_VirtualAlloc, (void *)hooked_VirtualAlloc},
	{&(void *&)og_VirtualAlloc2, (void *)hooked_VirtualAlloc2},
	{&(void *&)og_VirtualAllocEx, (void *)hooked_VirtualAllocEx},
	{&(void *&)og_VirtualAlloc2FromApp, (void *)hooked_VirtualAlloc2FromApp},
	{&(void *&)og_VirtualAllocExNuma, (void *)hooked_VirtualAllocExNuma},
	{&(void *&)og_VirtualAllocFromApp, (void *)hooked_VirtualAllocFromApp},
	{&(void *&)og_VirtualFree, (void *)hooked_VirtualFree},
	{&(void *&)og_VirtualFreeEx, (void *)hooked_VirtualFreeEx},
	{&(void *&)og_VirtualLock, (void *)hooked_VirtualLock},
	{&(void *&)og_VirtualProtect, (void *)hooked_VirtualProtect},
	{&(void *&)og_VirtualProtectEx, (void *)hooked_VirtualProtectEx},
	{&(void *&)og_VirtualProtectFromApp, (void *)hooked_VirtualProtectFromApp},
	{&(void *&)og_VirtualUnlock, (void *)hooked_VirtualUnlock},
	{&(void *&)og_VirtualQueryEx, (void *)hooked_VirtualQueryEx},
	{&(void *&)og_VirtualQuery, (void *)hooked_VirtualQuery},
	{&(void *&)og_WriteProcessMemory, (void *)hooked_WriteProcessMemory},
	{&(void *&)og_EraseTape, (void *)hooked_EraseTape},
	{&(void *&)og_EnumResourceTypesW, (void *)hooked_EnumResourceTypesW},
	{&(void *&)og_EnumResourceLanguagesW, (void *)hooked_EnumResourceLanguagesW},
	{&(void *&)og_EscapeCommFunction, (void *)hooked_EscapeCommFunction},
	{&(void *&)og_EnumResourceTypesA, (void *)hooked_EnumResourceTypesA},
	{&(void *&)og_ExecuteUmsThread, (void *)hooked_ExecuteUmsThread},
	{&(void *&)og_FatalExit, (void *)hooked_FatalExit},
	{&(void *&)og_FileTimeToDosDateTime, (void *)hooked_FileTimeToDosDateTime},
	{&(void *&)og_FindActCtxSectionStringA, (void *)hooked_FindActCtxSectionStringA},
	{&(void *&)og_FindActCtxSectionGuid, (void *)hooked_FindActCtxSectionGuid},
	{&(void *&)og_FindActCtxSectionStringW, (void *)hooked_FindActCtxSectionStringW},
	{&(void *&)og_FindAtomA, (void *)hooked_FindAtomA},
	{&(void *&)og_FindAtomW, (void *)hooked_FindAtomW},
	{&(void *&)og_FindFirstFileTransactedA, (void *)hooked_FindFirstFileTransactedA},
	{&(void *&)og_FindFirstFileNameTransactedW, (void *)hooked_FindFirstFileNameTransactedW},
	{&(void *&)og_FindFirstFileTransactedW, (void *)hooked_FindFirstFileTransactedW},
	{&(void *&)og_FindFirstStreamTransactedW, (void *)hooked_FindFirstStreamTransactedW},
	{&(void *&)og_FindFirstVolumeA, (void *)hooked_FindFirstVolumeA},
	{&(void *&)og_FindFirstVolumeMountPointA, (void *)hooked_FindFirstVolumeMountPointA},
	{&(void *&)og_FindNextVolumeA, (void *)hooked_FindNextVolumeA},
	{&(void *&)og_FindNextVolumeMountPointA, (void *)hooked_FindNextVolumeMountPointA},
	{&(void *&)og_FindFirstVolumeMountPointW, (void *)hooked_FindFirstVolumeMountPointW},
	{&(void *&)og_FindNextVolumeMountPointW, (void *)hooked_FindNextVolumeMountPointW},
	{&(void *&)og_FormatMessage, (void *)hooked_FormatMessage},
	{&(void *&)og_FindResourceA, (void *)hooked_FindResourceA},
	{&(void *&)og_FindVolumeMountPointClose, (void *)hooked_FindVolumeMountPointClose},
	{&(void *&)og_FindResourceExA, (void *)hooked_FindResourceExA},
	{&(void *&)og_FormatMessageA, (void *)hooked_FormatMessageA},
	{&(void *&)og_FormatMessageW, (void *)hooked_FormatMessageW},
	{&(void *&)og_GetActiveProcessorCount, (void *)hooked_GetActiveProcessorCount},
	{&(void *&)og_GetActiveProcessorGroupCount, (void *)hooked_GetActiveProcessorGroupCount},
	{&(void *&)og_GetApplicationRecoveryCallback, (void *)hooked_GetApplicationRecoveryCallback},
	{&(void *&)og_GetApplicationRestartSettings, (void *)hooked_GetApplicationRestartSettings},
	{&(void *&)og_GetAtomNameA, (void *)hooked_GetAtomNameA},
	{&(void *&)og_GetAtomNameW, (void *)hooked_GetAtomNameW},
	{&(void *&)og_GetBinaryTypeA, (void *)hooked_GetBinaryTypeA},
	{&(void *&)og_GetCommConfig, (void *)hooked_GetCommConfig},
	{&(void *&)og_GetBinaryTypeW, (void *)hooked_GetBinaryTypeW},
	{&(void *&)og_GetCommMask, (void *)hooked_GetCommMask},
	{&(void *&)og_GetCommModemStatus, (void *)hooked_GetCommModemStatus},
	{&(void *&)og_GetCommProperties, (void *)hooked_GetCommProperties},
	{&(void *&)og_GetCommState, (void *)hooked_GetCommState},
	{&(void *&)og_GetCommTimeouts, (void *)hooked_GetCommTimeouts},
	{&(void *&)og_GetCompressedFileSizeTransactedA, (void *)hooked_GetCompressedFileSizeTransactedA},
	{&(void *&)og_GetCompressedFileSizeTransactedW, (void *)hooked_GetCompressedFileSizeTransactedW},
	{&(void *&)og_GetComputerNameA, (void *)hooked_GetComputerNameA},
	{&(void *&)og_GetComputerNameW, (void *)hooked_GetComputerNameW},
	{&(void *&)og_GetCurrentActCtx, (void *)hooked_GetCurrentActCtx},
	{&(void *&)og_GetCurrentDirectory, (void *)hooked_GetCurrentDirectory},
	{&(void *&)og_GetDefaultCommConfigA, (void *)hooked_GetDefaultCommConfigA},
	{&(void *&)og_GetCurrentUmsThread, (void *)hooked_GetCurrentUmsThread},
	{&(void *&)og_GetDefaultCommConfigW, (void *)hooked_GetDefaultCommConfigW},
	{&(void *&)og_GetDevicePowerState, (void *)hooked_GetDevicePowerState},
	{&(void *&)og_GetDllDirectoryA, (void *)hooked_GetDllDirectoryA},
	{&(void *&)og_GetDllDirectoryW, (void *)hooked_GetDllDirectoryW},
	{&(void *&)og_GetEnabledXStateFeatures, (void *)hooked_GetEnabledXStateFeatures},
	{&(void *&)og_GetEnvironmentVariable, (void *)hooked_GetEnvironmentVariable},
	{&(void *&)og_GetFileAttributesTransactedA, (void *)hooked_GetFileAttributesTransactedA},
	{&(void *&)og_GetFileAttributesTransactedW, (void *)hooked_GetFileAttributesTransactedW},
	{&(void *&)og_GetFileBandwidthReservation, (void *)hooked_GetFileBandwidthReservation},
	{&(void *&)og_GetFileInformationByHandleEx, (void *)hooked_GetFileInformationByHandleEx},
	{&(void *&)og_GetFileInformationByName, (void *)hooked_GetFileInformationByName},
	{&(void *&)og_GetFirmwareEnvironmentVariableA, (void *)hooked_GetFirmwareEnvironmentVariableA},
	{&(void *&)og_GetFirmwareEnvironmentVariableExA, (void *)hooked_GetFirmwareEnvironmentVariableExA},
	{&(void *&)og_GetFirmwareEnvironmentVariableExW, (void *)hooked_GetFirmwareEnvironmentVariableExW},
	{&(void *&)og_GetFirmwareEnvironmentVariableW, (void *)hooked_GetFirmwareEnvironmentVariableW},
	{&(void *&)og_GetFirmwareType, (void *)hooked_GetFirmwareType},
	{&(void *&)og_GetFullPathNameTransactedA, (void *)hooked_GetFullPathNameTransactedA},
	{&(void *&)og_GetFullPathNameTransactedW, (void *)hooked_GetFullPathNameTransactedW},
	{&(void *&)og_GetLogicalDriveStringsA, (void *)hooked_GetLogicalDriveStringsA},
	{&(void *&)og_GetLongPathNameTransactedA, (void *)hooked_GetLongPathNameTransactedA},
	{&(void *&)og_GetLongPathNameTransactedW, (void *)hooked_GetLongPathNameTransactedW},
	{&(void *&)og_GetMailslotInfo, (void *)hooked_GetMailslotInfo},
	{&(void *&)og_GetMaximumProcessorCount, (void *)hooked_GetMaximumProcessorCount},
	{&(void *&)og_GetMaximumProcessorGroupCount, (void *)hooked_GetMaximumProcessorGroupCount},
	{&(void *&)og_GetNamedPipeClientComputerNameA, (void *)hooked_GetNamedPipeClientComputerNameA},
	{&(void *&)og_GetNamedPipeClientProcessId, (void *)hooked_GetNamedPipeClientProcessId},
	{&(void *&)og_GetNamedPipeClientSessionId, (void *)hooked_GetNamedPipeClientSessionId},
	{&(void *&)og_GetNamedPipeHandleStateA, (void *)hooked_GetNamedPipeHandleStateA},
	{&(void *&)og_GetNextUmsListItem, (void *)hooked_GetNextUmsListItem},
	{&(void *&)og_GetNamedPipeServerSessionId, (void *)hooked_GetNamedPipeServerSessionId},
	{&(void *&)og_GetNamedPipeServerProcessId, (void *)hooked_GetNamedPipeServerProcessId},
	{&(void *&)og_GetNumaAvailableMemoryNode, (void *)hooked_GetNumaAvailableMemoryNode},
	{&(void *&)og_GetNumaAvailableMemoryNodeEx, (void *)hooked_GetNumaAvailableMemoryNodeEx},
	{&(void *&)og_GetNumaNodeNumberFromHandle, (void *)hooked_GetNumaNodeNumberFromHandle},
	{&(void *&)og_GetNumaProcessorNode, (void *)hooked_GetNumaProcessorNode},
	{&(void *&)og_GetNumaNodeProcessorMask, (void *)hooked_GetNumaNodeProcessorMask},
	{&(void *&)og_GetNumaProcessorNodeEx, (void *)hooked_GetNumaProcessorNodeEx},
	{&(void *&)og_GetNumaProximityNode, (void *)hooked_GetNumaProximityNode},
	{&(void *&)og_GetPrivateProfileInt, (void *)hooked_GetPrivateProfileInt},
	{&(void *&)og_GetPrivateProfileIntA, (void *)hooked_GetPrivateProfileIntA},
	{&(void *&)og_GetPrivateProfileIntW, (void *)hooked_GetPrivateProfileIntW},
	{&(void *&)og_GetPrivateProfileSection, (void *)hooked_GetPrivateProfileSection},
	{&(void *&)og_GetPrivateProfileSectionNames, (void *)hooked_GetPrivateProfileSectionNames},
	{&(void *&)og_GetPrivateProfileSectionA, (void *)hooked_GetPrivateProfileSectionA},
	{&(void *&)og_GetPrivateProfileSectionNamesA, (void *)hooked_GetPrivateProfileSectionNamesA},
	{&(void *&)og_GetPrivateProfileSectionNamesW, (void *)hooked_GetPrivateProfileSectionNamesW},
	{&(void *&)og_GetPrivateProfileSectionW, (void *)hooked_GetPrivateProfileSectionW},
	{&(void *&)og_GetPrivateProfileString, (void *)hooked_GetPrivateProfileString},
	{&(void *&)og_GetPrivateProfileStringA, (void *)hooked_GetPrivateProfileStringA},
	{&(void *&)og_GetPrivateProfileStringW, (void *)hooked_GetPrivateProfileStringW},
	{&(void *&)og_GetPrivateProfileStruct, (void *)hooked_GetPrivateProfileStruct},
	{&(void *&)og_GetPrivateProfileStructA, (void *)hooked_GetPrivateProfileStructA},
	{&(void *&)og_GetPrivateProfileStructW, (void *)hooked_GetPrivateProfileStructW},
	{&(void *&)og_GetProcessAffinityMask, (void *)hooked_GetProcessAffinityMask},
	{&(void *&)og_GetProcessDEPPolicy, (void *)hooked_GetProcessDEPPolicy},
	{&(void *&)og_GetProcessIoCounters, (void *)hooked_GetProcessIoCounters},
	{&(void *&)og_GetProfileIntA, (void *)hooked_GetProfileIntA},
	{&(void *&)og_GetProfileIntW, (void *)hooked_GetProfileIntW},
	{&(void *&)og_GetProfileSectionA, (void *)hooked_GetProfileSectionA},
	{&(void *&)og_GetProfileSectionW, (void *)hooked_GetProfileSectionW},
	{&(void *&)og_GetProfileStringA, (void *)hooked_GetProfileStringA},
	{&(void *&)og_GetShortPathNameA, (void *)hooked_GetShortPathNameA},
	{&(void *&)og_GetProfileStringW, (void *)hooked_GetProfileStringW},
	{&(void *&)og_GetSystemPowerStatus, (void *)hooked_GetSystemPowerStatus},
	{&(void *&)og_GetSystemDEPPolicy, (void *)hooked_GetSystemDEPPolicy},
	{&(void *&)og_GetSystemRegistryQuota, (void *)hooked_GetSystemRegistryQuota},
	{&(void *&)og_GetTapeParameters, (void *)hooked_GetTapeParameters},
	{&(void *&)og_GetTapePosition, (void *)hooked_GetTapePosition},
	{&(void *&)og_GetTapeStatus, (void *)hooked_GetTapeStatus},
	{&(void *&)og_GetTempFileName, (void *)hooked_GetTempFileName},
	{&(void *&)og_GetThreadSelectorEntry, (void *)hooked_GetThreadSelectorEntry},
	{&(void *&)og_GetUmsSystemThreadInformation, (void *)hooked_GetUmsSystemThreadInformation},
	{&(void *&)og_GetUmsCompletionListEvent, (void *)hooked_GetUmsCompletionListEvent},
	{&(void *&)og_GetVolumeNameForVolumeMountPointA, (void *)hooked_GetVolumeNameForVolumeMountPointA},
	{&(void *&)og_GetXStateFeaturesMask, (void *)hooked_GetXStateFeaturesMask},
	{&(void *&)og_GetVolumePathNamesForVolumeNameA, (void *)hooked_GetVolumePathNamesForVolumeNameA},
	{&(void *&)og_GlobalAddAtomA, (void *)hooked_GlobalAddAtomA},
	{&(void *&)og_GlobalAddAtomExA, (void *)hooked_GlobalAddAtomExA},
	{&(void *&)og_GlobalAddAtomExW, (void *)hooked_GlobalAddAtomExW},
	{&(void *&)og_GlobalAddAtomW, (void *)hooked_GlobalAddAtomW},
	{&(void *&)og_GlobalFindAtomA, (void *)hooked_GlobalFindAtomA},
	{&(void *&)og_GlobalAlloc, (void *)hooked_GlobalAlloc},
	{&(void *&)og_GlobalDeleteAtom, (void *)hooked_GlobalDeleteAtom},
	{&(void *&)og_GlobalFindAtomW, (void *)hooked_GlobalFindAtomW},
	{&(void *&)og_GlobalFree, (void *)hooked_GlobalFree},
	{&(void *&)og_GlobalFlags, (void *)hooked_GlobalFlags},
	{&(void *&)og_GlobalGetAtomNameW, (void *)hooked_GlobalGetAtomNameW},
	{&(void *&)og_GlobalGetAtomNameA, (void *)hooked_GlobalGetAtomNameA},
	{&(void *&)og_GlobalLock, (void *)hooked_GlobalLock},
	{&(void *&)og_GlobalHandle, (void *)hooked_GlobalHandle},
	{&(void *&)og_GlobalMemoryStatus, (void *)hooked_GlobalMemoryStatus},
	{&(void *&)og_GlobalReAlloc, (void *)hooked_GlobalReAlloc},
	{&(void *&)og_GlobalSize, (void *)hooked_GlobalSize},
	{&(void *&)og_InitAtomTable, (void *)hooked_InitAtomTable},
	{&(void *&)og_InitializeContext, (void *)hooked_InitializeContext},
	{&(void *&)og_GlobalUnlock, (void *)hooked_GlobalUnlock},
	{&(void *&)og_IsBadCodePtr, (void *)hooked_IsBadCodePtr},
	{&(void *&)og_IsBadReadPtr, (void *)hooked_IsBadReadPtr},
	{&(void *&)og_IsBadStringPtrA, (void *)hooked_IsBadStringPtrA},
	{&(void *&)og_IsBadStringPtrW, (void *)hooked_IsBadStringPtrW},
	{&(void *&)og_IsNativeVhdBoot, (void *)hooked_IsNativeVhdBoot},
	{&(void *&)og_IsBadWritePtr, (void *)hooked_IsBadWritePtr},
	{&(void *&)og_LoadModule, (void *)hooked_LoadModule},
	{&(void *&)og_IsSystemResumeAutomatic, (void *)hooked_IsSystemResumeAutomatic},
	{&(void *&)og_LoadPackagedLibrary, (void *)hooked_LoadPackagedLibrary},
	{&(void *&)og_LocalAlloc, (void *)hooked_LocalAlloc},
	{&(void *&)og_LocalFlags, (void *)hooked_LocalFlags},
	{&(void *&)og_LocalFree, (void *)hooked_LocalFree},
	{&(void *&)og_LocalHandle, (void *)hooked_LocalHandle},
	{&(void *&)og_LocalLock, (void *)hooked_LocalLock},
	{&(void *&)og_LocalReAlloc, (void *)hooked_LocalReAlloc},
	{&(void *&)og_LocalSize, (void *)hooked_LocalSize},
	{&(void *&)og_LocalUnlock, (void *)hooked_LocalUnlock},
	{&(void *&)og_LocateXStateFeature, (void *)hooked_LocateXStateFeature},
	{&(void *&)og_lstrcatA, (void *)hooked_lstrcatA},
	{&(void *&)og_lstrcatW, (void *)hooked_lstrcatW},
	{&(void *&)og_lstrcmpiA, (void *)hooked_lstrcmpiA},
	{&(void *&)og_lstrcmpA, (void *)hooked_lstrcmpA},
	{&(void *&)og_lstrcmpiW, (void *)hooked_lstrcmpiW},
	{&(void *&)og_lstrcmpW, (void *)hooked_lstrcmpW},
	{&(void *&)og_lstrcpynA, (void *)hooked_lstrcpynA},
	{&(void *&)og_lstrcpyA, (void *)hooked_lstrcpyA},
	{&(void *&)og_lstrcpyW, (void *)hooked_lstrcpyW},
	{&(void *&)og_lstrcpynW, (void *)hooked_lstrcpynW},
	{&(void *&)og_lstrlenA, (void *)hooked_lstrlenA},
	{&(void *&)og_lstrlenW, (void *)hooked_lstrlenW},
	{&(void *&)og_MapUserPhysicalPagesScatter, (void *)hooked_MapUserPhysicalPagesScatter},
	{&(void *&)og_MapViewOfFileExNuma, (void *)hooked_MapViewOfFileExNuma},
	{&(void *&)og_MoveFile, (void *)hooked_MoveFile},
	{&(void *&)og_MoveFileA, (void *)hooked_MoveFileA},
	{&(void *&)og_MoveFileExA, (void *)hooked_MoveFileExA},
	{&(void *&)og_MoveFileExW, (void *)hooked_MoveFileExW},
	{&(void *&)og_MoveFileTransactedA, (void *)hooked_MoveFileTransactedA},
	{&(void *&)og_MoveFileTransactedW, (void *)hooked_MoveFileTransactedW},
	{&(void *&)og_MoveFileW, (void *)hooked_MoveFileW},
	{&(void *&)og_MoveFileWithProgressA, (void *)hooked_MoveFileWithProgressA},
	{&(void *&)og_MoveFileWithProgressW, (void *)hooked_MoveFileWithProgressW},
	{&(void *&)og_MulDiv, (void *)hooked_MulDiv},
	{&(void *&)og_OpenFileById, (void *)hooked_OpenFileById},
	{&(void *&)og_OpenFile, (void *)hooked_OpenFile},
	{&(void *&)og_OpenFileMappingA, (void *)hooked_OpenFileMappingA},
	{&(void *&)og_OpenJobObjectA, (void *)hooked_OpenJobObjectA},
	{&(void *&)og_OpenPrivateNamespaceA, (void *)hooked_OpenPrivateNamespaceA},
	{&(void *&)og_PowerClearRequest, (void *)hooked_PowerClearRequest},
	{&(void *&)og_PowerCreateRequest, (void *)hooked_PowerCreateRequest},
	{&(void *&)og_PowerSetRequest, (void *)hooked_PowerSetRequest},
	{&(void *&)og_PrepareTape, (void *)hooked_PrepareTape},
	{&(void *&)og_PulseEvent, (void *)hooked_PulseEvent},
	{&(void *&)og_PurgeComm, (void *)hooked_PurgeComm},
	{&(void *&)og_QueryActCtxSettingsW, (void *)hooked_QueryActCtxSettingsW},
	{&(void *&)og_QueryActCtxW, (void *)hooked_QueryActCtxW},
	{&(void *&)og_QueryDosDeviceA, (void *)hooked_QueryDosDeviceA},
	{&(void *&)og_QueryFullProcessImageNameW, (void *)hooked_QueryFullProcessImageNameW},
	{&(void *&)og_QueryFullProcessImageNameA, (void *)hooked_QueryFullProcessImageNameA},
	{&(void *&)og_QueryThreadProfiling, (void *)hooked_QueryThreadProfiling},
	{&(void *&)og_ReadDirectoryChangesExW, (void *)hooked_ReadDirectoryChangesExW},
	{&(void *&)og_QueryUmsThreadInformation, (void *)hooked_QueryUmsThreadInformation},
	{&(void *&)og_ReadDirectoryChangesW, (void *)hooked_ReadDirectoryChangesW},
	{&(void *&)og_RegisterApplicationRecoveryCallback, (void *)hooked_RegisterApplicationRecoveryCallback},
	{&(void *&)og_ReadThreadProfilingData, (void *)hooked_ReadThreadProfilingData},
	{&(void *&)og_RegisterApplicationRestart, (void *)hooked_RegisterApplicationRestart},
	{&(void *&)og_RegisterWaitForSingleObject, (void *)hooked_RegisterWaitForSingleObject},
	{&(void *&)og_ReleaseActCtx, (void *)hooked_ReleaseActCtx},
	{&(void *&)og_RemoveDirectoryTransactedW, (void *)hooked_RemoveDirectoryTransactedW},
	{&(void *&)og_RemoveDirectoryTransactedA, (void *)hooked_RemoveDirectoryTransactedA},
	{&(void *&)og_RemoveSecureMemoryCacheCallback, (void *)hooked_RemoveSecureMemoryCacheCallback},
	{&(void *&)og_ReOpenFile, (void *)hooked_ReOpenFile},
	{&(void *&)og_ReplaceFileA, (void *)hooked_ReplaceFileA},
	{&(void *&)og_ReplaceFileW, (void *)hooked_ReplaceFileW},
	{&(void *&)og_RequestWakeupLatency, (void *)hooked_RequestWakeupLatency},
	{&(void *&)og_SetCommBreak, (void *)hooked_SetCommBreak},
	{&(void *&)og_SetCommConfig, (void *)hooked_SetCommConfig},
	{&(void *&)og_SetCommMask, (void *)hooked_SetCommMask},
	{&(void *&)og_SetCurrentDirectory, (void *)hooked_SetCurrentDirectory},
	{&(void *&)og_SetCommState, (void *)hooked_SetCommState},
	{&(void *&)og_SetCommTimeouts, (void *)hooked_SetCommTimeouts},
	{&(void *&)og_SetDefaultCommConfigA, (void *)hooked_SetDefaultCommConfigA},
	{&(void *&)og_SetDefaultCommConfigW, (void *)hooked_SetDefaultCommConfigW},
	{&(void *&)og_SetDllDirectoryA, (void *)hooked_SetDllDirectoryA},
	{&(void *&)og_SetDllDirectoryW, (void *)hooked_SetDllDirectoryW},
	{&(void *&)og_CeipIsOptedIn, (void *)hooked_CeipIsOptedIn},
	{&(void *&)og_CompareString, (void *)hooked_CompareString},
	{&(void *&)og_CompareStringA, (void *)hooked_CompareStringA},
	{&(void *&)og_ConvertDefaultLocale, (void *)hooked_ConvertDefaultLocale},
	{&(void *&)og_EnumCalendarInfoA, (void *)hooked_EnumCalendarInfoA},
	{&(void *&)og_EnumCalendarInfoExA, (void *)hooked_EnumCalendarInfoExA},
	{&(void *&)og_EnumCalendarInfoExEx, (void *)hooked_EnumCalendarInfoExEx},
	{&(void *&)og_EnumCalendarInfoExW, (void *)hooked_EnumCalendarInfoExW},
	{&(void *&)og_EnumCalendarInfoW, (void *)hooked_EnumCalendarInfoW},
	{&(void *&)og_EnumDateFormatsA, (void *)hooked_EnumDateFormatsA},
	{&(void *&)og_EnumDateFormatsExA, (void *)hooked_EnumDateFormatsExA},
	{&(void *&)og_EnumDateFormatsW, (void *)hooked_EnumDateFormatsW},
	{&(void *&)og_EnumDateFormatsExW, (void *)hooked_EnumDateFormatsExW},
	{&(void *&)og_EnumDateFormatsExEx, (void *)hooked_EnumDateFormatsExEx},
	{&(void *&)og_EnumLanguageGroupLocalesA, (void *)hooked_EnumLanguageGroupLocalesA},
	{&(void *&)og_EnumLanguageGroupLocalesW, (void *)hooked_EnumLanguageGroupLocalesW},
	{&(void *&)og_EnumSystemCodePagesA, (void *)hooked_EnumSystemCodePagesA},
	{&(void *&)og_EnumSystemCodePagesW, (void *)hooked_EnumSystemCodePagesW},
	{&(void *&)og_EnumSystemGeoID, (void *)hooked_EnumSystemGeoID},
	{&(void *&)og_EnumSystemGeoNames, (void *)hooked_EnumSystemGeoNames},
	{&(void *&)og_EnumSystemLanguageGroupsA, (void *)hooked_EnumSystemLanguageGroupsA},
	{&(void *&)og_EnumSystemLanguageGroupsW, (void *)hooked_EnumSystemLanguageGroupsW},
	{&(void *&)og_EnumSystemLocalesA, (void *)hooked_EnumSystemLocalesA},
	{&(void *&)og_EnumSystemLocalesEx, (void *)hooked_EnumSystemLocalesEx},
	{&(void *&)og_EnumSystemLocalesW, (void *)hooked_EnumSystemLocalesW},
	{&(void *&)og_EnumTimeFormatsA, (void *)hooked_EnumTimeFormatsA},
	{&(void *&)og_EnumTimeFormatsEx, (void *)hooked_EnumTimeFormatsEx},
	{&(void *&)og_EnumUILanguagesA, (void *)hooked_EnumUILanguagesA},
	{&(void *&)og_EnumTimeFormatsW, (void *)hooked_EnumTimeFormatsW},
	{&(void *&)og_EnumUILanguagesW, (void *)hooked_EnumUILanguagesW},
	{&(void *&)og_FindNLSString, (void *)hooked_FindNLSString},
	{&(void *&)og_FindNLSStringEx, (void *)hooked_FindNLSStringEx},
	{&(void *&)og_FoldStringA, (void *)hooked_FoldStringA},
	{&(void *&)og_GetACP, (void *)hooked_GetACP},
	{&(void *&)og_GetCalendarInfoA, (void *)hooked_GetCalendarInfoA},
	{&(void *&)og_GetCalendarInfoEx, (void *)hooked_GetCalendarInfoEx},
	{&(void *&)og_GetCPInfo, (void *)hooked_GetCPInfo},
	{&(void *&)og_GetCalendarInfoW, (void *)hooked_GetCalendarInfoW},
	{&(void *&)og_GetCPInfoExA, (void *)hooked_GetCPInfoExA},
	{&(void *&)og_GetCPInfoExW, (void *)hooked_GetCPInfoExW},
	{&(void *&)og_GetCurrencyFormatA, (void *)hooked_GetCurrencyFormatA},
	{&(void *&)og_GetCurrencyFormatEx, (void *)hooked_GetCurrencyFormatEx},
	{&(void *&)og_GetCurrencyFormatW, (void *)hooked_GetCurrencyFormatW},
	{&(void *&)og_GetDurationFormat, (void *)hooked_GetDurationFormat},
	{&(void *&)og_GetFileMUIInfo, (void *)hooked_GetFileMUIInfo},
	{&(void *&)og_GetDurationFormatEx, (void *)hooked_GetDurationFormatEx},
	{&(void *&)og_GetFileMUIPath, (void *)hooked_GetFileMUIPath},
	{&(void *&)og_GetGeoInfoA, (void *)hooked_GetGeoInfoA},
	{&(void *&)og_GetGeoInfoEx, (void *)hooked_GetGeoInfoEx},
	{&(void *&)og_GetGeoInfoW, (void *)hooked_GetGeoInfoW},
	{&(void *&)og_GetLocaleInfoA, (void *)hooked_GetLocaleInfoA},
	{&(void *&)og_GetLocaleInfoEx, (void *)hooked_GetLocaleInfoEx},
	{&(void *&)og_GetNLSVersionEx, (void *)hooked_GetNLSVersionEx},
	{&(void *&)og_GetNLSVersion, (void *)hooked_GetNLSVersion},
	{&(void *&)og_GetLocaleInfoW, (void *)hooked_GetLocaleInfoW},
	{&(void *&)og_GetNumberFormatA, (void *)hooked_GetNumberFormatA},
	{&(void *&)og_GetNumberFormatEx, (void *)hooked_GetNumberFormatEx},
	{&(void *&)og_GetOEMCP, (void *)hooked_GetOEMCP},
	{&(void *&)og_GetNumberFormatW, (void *)hooked_GetNumberFormatW},
	{&(void *&)og_GetProcessPreferredUILanguages, (void *)hooked_GetProcessPreferredUILanguages},
	{&(void *&)og_GetStringScripts, (void *)hooked_GetStringScripts},
	{&(void *&)og_GetStringTypeA, (void *)hooked_GetStringTypeA},
	{&(void *&)og_GetSystemDefaultLangID, (void *)hooked_GetSystemDefaultLangID},
	{&(void *&)og_GetSystemDefaultLCID, (void *)hooked_GetSystemDefaultLCID},
	{&(void *&)og_GetSystemDefaultLocaleName, (void *)hooked_GetSystemDefaultLocaleName},
	{&(void *&)og_GetSystemDefaultUILanguage, (void *)hooked_GetSystemDefaultUILanguage},
	{&(void *&)og_GetThreadLocale, (void *)hooked_GetThreadLocale},
	{&(void *&)og_GetSystemPreferredUILanguages, (void *)hooked_GetSystemPreferredUILanguages},
	{&(void *&)og_GetThreadPreferredUILanguages, (void *)hooked_GetThreadPreferredUILanguages},
	{&(void *&)og_GetThreadUILanguage, (void *)hooked_GetThreadUILanguage},
	{&(void *&)og_GetUserDefaultGeoName, (void *)hooked_GetUserDefaultGeoName},
	{&(void *&)og_GetUILanguageInfo, (void *)hooked_GetUILanguageInfo},
	{&(void *&)og_GetUserDefaultLCID, (void *)hooked_GetUserDefaultLCID},
	{&(void *&)og_GetUserDefaultLocaleName, (void *)hooked_GetUserDefaultLocaleName},
	{&(void *&)og_GetUserDefaultLangID, (void *)hooked_GetUserDefaultLangID},
	{&(void *&)og_GetUserDefaultUILanguage, (void *)hooked_GetUserDefaultUILanguage},
	{&(void *&)og_GetUserGeoID, (void *)hooked_GetUserGeoID},
	{&(void *&)og_GetUserPreferredUILanguages, (void *)hooked_GetUserPreferredUILanguages},
	{&(void *&)og_IsDBCSLeadByte, (void *)hooked_IsDBCSLeadByte},
	{&(void *&)og_IsDBCSLeadByteEx, (void *)hooked_IsDBCSLeadByteEx},
	{&(void *&)og_IsNLSDefinedString, (void *)hooked_IsNLSDefinedString},
	{&(void *&)og_IsValidCodePage, (void *)hooked_IsValidCodePage},
	{&(void *&)og_IsValidLanguageGroup, (void *)hooked_IsValidLanguageGroup},
	{&(void *&)og_IsValidLocale, (void *)hooked_IsValidLocale},
	{&(void *&)og_IsValidLocaleName, (void *)hooked_IsValidLocaleName},
	{&(void *&)og_IsValidNLSVersion, (void *)hooked_IsValidNLSVersion},
	{&(void *&)og_LCMapStringA, (void *)hooked_LCMapStringA},
	{&(void *&)og_LCIDToLocaleName, (void *)hooked_LCIDToLocaleName},
	{&(void *&)og_IsActiveSessionCountLimited, (void *)hooked_IsActiveSessionCountLimited},
	{&(void *&)og_IsWindows10OrGreater, (void *)hooked_IsWindows10OrGreater},
	{&(void *&)og_IsWindows7OrGreater, (void *)hooked_IsWindows7OrGreater},
	{&(void *&)og_IsWindows7SP1OrGreater, (void *)hooked_IsWindows7SP1OrGreater},
	{&(void *&)og_IsWindows8OrGreater, (void *)hooked_IsWindows8OrGreater},
	{&(void *&)og_IsWindows8Point1OrGreater, (void *)hooked_IsWindows8Point1OrGreater},
	{&(void *&)og_IsWindowsServer, (void *)hooked_IsWindowsServer},
	{&(void *&)og_IsWindowsVistaOrGreater, (void *)hooked_IsWindowsVistaOrGreater},
	{&(void *&)og_IsWindowsVistaSP1OrGreater, (void *)hooked_IsWindowsVistaSP1OrGreater},
	{&(void *&)og_IsWindowsVistaSP2OrGreater, (void *)hooked_IsWindowsVistaSP2OrGreater},
	{&(void *&)og_IsWindowsXPSP2OrGreater, (void *)hooked_IsWindowsXPSP2OrGreater},
	{&(void *&)og_IsWindowsXPOrGreater, (void *)hooked_IsWindowsXPOrGreater},
	{&(void *&)og_IsWindowsXPSP1OrGreater, (void *)hooked_IsWindowsXPSP1OrGreater},
	{&(void *&)og_IsWindowsXPSP3OrGreater, (void *)hooked_IsWindowsXPSP3OrGreater},
	{&(void *&)og_WerRegisterAdditionalProcess, (void *)hooked_WerRegisterAdditionalProcess},
	{&(void *&)og_WerGetFlags, (void *)hooked_WerGetFlags},
	{&(void *&)og_WerRegisterCustomMetadata, (void *)hooked_WerRegisterCustomMetadata},
	{&(void *&)og_WerRegisterExcludedMemoryBlock, (void *)hooked_WerRegisterExcludedMemoryBlock},
	{&(void *&)og_WerRegisterFile, (void *)hooked_WerRegisterFile},
	{&(void *&)og_WerRegisterMemoryBlock, (void *)hooked_WerRegisterMemoryBlock},
	{&(void *&)og_WerRegisterRuntimeExceptionModule, (void *)hooked_WerRegisterRuntimeExceptionModule},
	{&(void *&)og_WerSetFlags, (void *)hooked_WerSetFlags},
	{&(void *&)og_WerUnregisterAdditionalProcess, (void *)hooked_WerUnregisterAdditionalProcess},
	{&(void *&)og_WerUnregisterCustomMetadata, (void *)hooked_WerUnregisterCustomMetadata},
	{&(void *&)og_WerUnregisterExcludedMemoryBlock, (void *)hooked_WerUnregisterExcludedMemoryBlock},
	{&(void *&)og_WerUnregisterFile, (void *)hooked_WerUnregisterFile},
	{&(void *&)og_WerUnregisterMemoryBlock, (void *)hooked_WerUnregisterMemoryBlock},
	{&(void *&)og_WerUnregisterRuntimeExceptionModule, (void *)hooked_WerUnregisterRuntimeExceptionModule},
	{&(void *&)og__lclose, (void *)hooked__lclose},
	{&(void *&)og__lcreat, (void *)hooked__lcreat},
	{&(void *&)og__llseek, (void *)hooked__llseek},
	{&(void *&)og__lopen, (void *)hooked__lopen},
	{&(void *&)og__lread, (void *)hooked__lread},
	{&(void *&)og__lwrite, (void *)hooked__lwrite},
	{&(void *&)og_ActivateActCtx, (void *)hooked_ActivateActCtx},
	{&(void *&)og_AddAtomA, (void *)hooked_AddAtomA},
	{&(void *&)og_AddAtomW, (void *)hooked_AddAtomW},
	{&(void *&)og_AddIntegrityLabelToBoundaryDescriptor, (void *)hooked_AddIntegrityLabelToBoundaryDescriptor},
	{&(void *&)og_AddRefActCtx, (void *)hooked_AddRefActCtx},
	{&(void *&)og_AddSecureMemoryCacheCallback, (void *)hooked_AddSecureMemoryCacheCallback},
	{&(void *&)og_ApplicationRecoveryFinished, (void *)hooked_ApplicationRecoveryFinished},
	{&(void *&)og_ApplicationRecoveryInProgress, (void *)hooked_ApplicationRecoveryInProgress},
	{&(void *&)og_BackupRead, (void *)hooked_BackupRead},
	{&(void *&)og_BackupSeek, (void *)hooked_BackupSeek},
	{&(void *&)og_BackupWrite, (void *)hooked_BackupWrite},
	{&(void *&)og_BeginUpdateResourceA, (void *)hooked_BeginUpdateResourceA},
	{&(void *&)og_BeginUpdateResourceW, (void *)hooked_BeginUpdateResourceW},
	{&(void *&)og_BindIoCompletionCallback, (void *)hooked_BindIoCompletionCallback},
	{&(void *&)og_BuildCommDCBA, (void *)hooked_BuildCommDCBA},
	{&(void *&)og_BuildCommDCBAndTimeoutsA, (void *)hooked_BuildCommDCBAndTimeoutsA},
	{&(void *&)og_BuildCommDCBAndTimeoutsW, (void *)hooked_BuildCommDCBAndTimeoutsW},
	{&(void *&)og_CallNamedPipeA, (void *)hooked_CallNamedPipeA},
	{&(void *&)og_BuildCommDCBW, (void *)hooked_BuildCommDCBW},
	{&(void *&)og_CheckNameLegalDOS8Dot3A, (void *)hooked_CheckNameLegalDOS8Dot3A},
	{&(void *&)og_CheckNameLegalDOS8Dot3W, (void *)hooked_CheckNameLegalDOS8Dot3W},
	{&(void *&)og_ClearCommBreak, (void *)hooked_ClearCommBreak},
	{&(void *&)og_ClearCommError, (void *)hooked_ClearCommError},
	{&(void *&)og_CommConfigDialogA, (void *)hooked_CommConfigDialogA},
	{&(void *&)og_CommConfigDialogW, (void *)hooked_CommConfigDialogW},
	{&(void *&)og_ConvertFiberToThread, (void *)hooked_ConvertFiberToThread},
	{&(void *&)og_ConvertThreadToFiber, (void *)hooked_ConvertThreadToFiber},
	{&(void *&)og_ConvertThreadToFiberEx, (void *)hooked_ConvertThreadToFiberEx},
	{&(void *&)og_CopyContext, (void *)hooked_CopyContext},
	{&(void *&)og_CopyFile, (void *)hooked_CopyFile},
	{&(void *&)og_CopyFile2, (void *)hooked_CopyFile2},
	{&(void *&)og_CopyFileA, (void *)hooked_CopyFileA},
	{&(void *&)og_CopyFileExA, (void *)hooked_CopyFileExA},
	{&(void *&)og_CopyFileExW, (void *)hooked_CopyFileExW},
	{&(void *&)og_CopyFileTransactedA, (void *)hooked_CopyFileTransactedA},
	{&(void *&)og_CopyFileTransactedW, (void *)hooked_CopyFileTransactedW},
	{&(void *&)og_CreateActCtxA, (void *)hooked_CreateActCtxA},
	{&(void *&)og_CopyFileW, (void *)hooked_CopyFileW},
	{&(void *&)og_CreateActCtxW, (void *)hooked_CreateActCtxW},
	{&(void *&)og_CreateBoundaryDescriptorA, (void *)hooked_CreateBoundaryDescriptorA},
	{&(void *&)og_CreateDirectory, (void *)hooked_CreateDirectory},
	{&(void *&)og_CreateDirectoryExA, (void *)hooked_CreateDirectoryExA},
	{&(void *&)og_CreateDirectoryExW, (void *)hooked_CreateDirectoryExW},
	{&(void *&)og_CreateDirectoryTransactedA, (void *)hooked_CreateDirectoryTransactedA},
	{&(void *&)og_CreateFiber, (void *)hooked_CreateFiber},
	{&(void *&)og_CreateDirectoryTransactedW, (void *)hooked_CreateDirectoryTransactedW},
	{&(void *&)og_CreateFiberEx, (void *)hooked_CreateFiberEx},
	{&(void *&)og_CreateFileMappingA, (void *)hooked_CreateFileMappingA},
	{&(void *&)og_CreateFileMappingNumaA, (void *)hooked_CreateFileMappingNumaA},
	{&(void *&)og_CreateFileTransactedA, (void *)hooked_CreateFileTransactedA},
	{&(void *&)og_CreateFileTransactedW, (void *)hooked_CreateFileTransactedW},
	{&(void *&)og_CreateHardLinkA, (void *)hooked_CreateHardLinkA},
	{&(void *&)og_CreateHardLinkTransactedA, (void *)hooked_CreateHardLinkTransactedA},
	{&(void *&)og_CreateHardLinkTransactedW, (void *)hooked_CreateHardLinkTransactedW},
	{&(void *&)og_CreateJobObjectA, (void *)hooked_CreateJobObjectA},
	{&(void *&)og_CreateHardLinkW, (void *)hooked_CreateHardLinkW},
	{&(void *&)og_CreateMailslotA, (void *)hooked_CreateMailslotA},
	{&(void *&)og_CreateMailslotW, (void *)hooked_CreateMailslotW},
	{&(void *&)og_CreateNamedPipeA, (void *)hooked_CreateNamedPipeA},
	{&(void *&)og_CreatePrivateNamespaceA, (void *)hooked_CreatePrivateNamespaceA},
	{&(void *&)og_CreateSemaphoreA, (void *)hooked_CreateSemaphoreA},
	{&(void *&)og_CreateSemaphoreExA, (void *)hooked_CreateSemaphoreExA},
	{&(void *&)og_CreateSymbolicLinkA, (void *)hooked_CreateSymbolicLinkA},
	{&(void *&)og_CreateSymbolicLinkTransactedA, (void *)hooked_CreateSymbolicLinkTransactedA},
	{&(void *&)og_CreateSymbolicLinkTransactedW, (void *)hooked_CreateSymbolicLinkTransactedW},
	{&(void *&)og_CreateTapePartition, (void *)hooked_CreateTapePartition},
	{&(void *&)og_CreateSymbolicLinkW, (void *)hooked_CreateSymbolicLinkW},
	{&(void *&)og_DeactivateActCtx, (void *)hooked_DeactivateActCtx},
	{&(void *&)og_CreateUmsCompletionList, (void *)hooked_CreateUmsCompletionList},
	{&(void *&)og_CreateUmsThreadContext, (void *)hooked_CreateUmsThreadContext},
	{&(void *&)og_DebugBreakProcess, (void *)hooked_DebugBreakProcess},
	{&(void *&)og_DebugSetProcessKillOnExit, (void *)hooked_DebugSetProcessKillOnExit},
	{&(void *&)og_DefineDosDeviceA, (void *)hooked_DefineDosDeviceA},
	{&(void *&)og_DeleteFiber, (void *)hooked_DeleteFiber},
	{&(void *&)og_DeleteAtom, (void *)hooked_DeleteAtom},
	{&(void *&)og_DeleteFile, (void *)hooked_DeleteFile},
	{&(void *&)og_DeleteFileTransactedA, (void *)hooked_DeleteFileTransactedA},
	{&(void *&)og_DeleteFileTransactedW, (void *)hooked_DeleteFileTransactedW},
	{&(void *&)og_DeleteUmsCompletionList, (void *)hooked_DeleteUmsCompletionList},
	{&(void *&)og_DeleteUmsThreadContext, (void *)hooked_DeleteUmsThreadContext},
	{&(void *&)og_DeleteVolumeMountPointA, (void *)hooked_DeleteVolumeMountPointA},
	{&(void *&)og_DequeueUmsCompletionListItems, (void *)hooked_DequeueUmsCompletionListItems},
	{&(void *&)og_DisableThreadProfiling, (void *)hooked_DisableThreadProfiling},
	{&(void *&)og_DnsHostnameToComputerNameA, (void *)hooked_DnsHostnameToComputerNameA},
	{&(void *&)og_DnsHostnameToComputerNameW, (void *)hooked_DnsHostnameToComputerNameW},
	{&(void *&)og_DosDateTimeToFileTime, (void *)hooked_DosDateTimeToFileTime},
	{&(void *&)og_EnableThreadProfiling, (void *)hooked_EnableThreadProfiling},
	{&(void *&)og_EndUpdateResourceA, (void *)hooked_EndUpdateResourceA},
	{&(void *&)og_EndUpdateResourceW, (void *)hooked_EndUpdateResourceW},
	{&(void *&)og_EnterUmsSchedulingMode, (void *)hooked_EnterUmsSchedulingMode},
	{&(void *&)og_EnumResourceLanguagesA, (void *)hooked_EnumResourceLanguagesA},
	{&(void *&)og_LCMapStringEx, (void *)hooked_LCMapStringEx},
	{&(void *&)og_LCMapStringW, (void *)hooked_LCMapStringW},
	{&(void *&)og_LocaleNameToLCID, (void *)hooked_LocaleNameToLCID},
	{&(void *&)og_NotifyUILanguageChange, (void *)hooked_NotifyUILanguageChange},
	{&(void *&)og_ResolveLocaleName, (void *)hooked_ResolveLocaleName},
	{&(void *&)og_SetCalendarInfoA, (void *)hooked_SetCalendarInfoA},
	{&(void *&)og_SetLocaleInfoA, (void *)hooked_SetLocaleInfoA},
	{&(void *&)og_SetCalendarInfoW, (void *)hooked_SetCalendarInfoW},
	{&(void *&)og_SetProcessPreferredUILanguages, (void *)hooked_SetProcessPreferredUILanguages},
	{&(void *&)og_SetLocaleInfoW, (void *)hooked_SetLocaleInfoW},
	{&(void *&)og_SetThreadLocale, (void *)hooked_SetThreadLocale},
	{&(void *&)og_SetThreadPreferredUILanguages, (void *)hooked_SetThreadPreferredUILanguages},
	{&(void *&)og_SetThreadUILanguage, (void *)hooked_SetThreadUILanguage},
	{&(void *&)og_SetUserGeoID, (void *)hooked_SetUserGeoID},
	{&(void *&)og_SetUserGeoName, (void *)hooked_SetUserGeoName},
	{&(void *&)og_VerifyScripts, (void *)hooked_VerifyScripts},
	{&(void *&)og_ClosePackageInfo, (void *)hooked_ClosePackageInfo},
	{&(void *&)og_FindPackagesByPackageFamily, (void *)hooked_FindPackagesByPackageFamily},
	{&(void *&)og_FormatApplicationUserModelId, (void *)hooked_FormatApplicationUserModelId},
	{&(void *&)og_GetApplicationUserModelId, (void *)hooked_GetApplicationUserModelId},
	{&(void *&)og_GetCurrentPackageFamilyName, (void *)hooked_GetCurrentPackageFamilyName},
	{&(void *&)og_GetCurrentApplicationUserModelId, (void *)hooked_GetCurrentApplicationUserModelId},
	{&(void *&)og_GetCurrentPackageFullName, (void *)hooked_GetCurrentPackageFullName},
	{&(void *&)og_GetCurrentPackageId, (void *)hooked_GetCurrentPackageId},
	{&(void *&)og_GetCurrentPackageInfo, (void *)hooked_GetCurrentPackageInfo},
	{&(void *&)og_GetCurrentPackagePath, (void *)hooked_GetCurrentPackagePath},
	{&(void *&)og_GetPackageFamilyName, (void *)hooked_GetPackageFamilyName},
	{&(void *&)og_GetPackageApplicationIds, (void *)hooked_GetPackageApplicationIds},
	{&(void *&)og_GetPackageFullName, (void *)hooked_GetPackageFullName},
	{&(void *&)og_GetPackageId, (void *)hooked_GetPackageId},
	{&(void *&)og_GetPackageInfo, (void *)hooked_GetPackageInfo},
	{&(void *&)og_GetPackagePath, (void *)hooked_GetPackagePath},
	{&(void *&)og_GetPackagePathByFullName, (void *)hooked_GetPackagePathByFullName},
	{&(void *&)og_GetPackagesByPackageFamily, (void *)hooked_GetPackagesByPackageFamily},
	{&(void *&)og_GetStagedPackagePathByFullName, (void *)hooked_GetStagedPackagePathByFullName},
	{&(void *&)og_OpenPackageInfoByFullName, (void *)hooked_OpenPackageInfoByFullName},
	{&(void *&)og_PackageFamilyNameFromFullName, (void *)hooked_PackageFamilyNameFromFullName},
	{&(void *&)og_PackageFamilyNameFromId, (void *)hooked_PackageFamilyNameFromId},
	{&(void *&)og_PackageNameAndPublisherIdFromFamilyName, (void *)hooked_PackageNameAndPublisherIdFromFamilyName},
	{&(void *&)og_PackageFullNameFromId, (void *)hooked_PackageFullNameFromId},
	{&(void *&)og_PackageIdFromFullName, (void *)hooked_PackageIdFromFullName},
	{&(void *&)og_ParseApplicationUserModelId, (void *)hooked_ParseApplicationUserModelId},
	{&(void *&)og_CallEnclave, (void *)hooked_CallEnclave},
	{&(void *&)og_DeleteEnclave, (void *)hooked_DeleteEnclave},
	{&(void *&)og_CreateEnclave, (void *)hooked_CreateEnclave},
	{&(void *&)og_IsEnclaveTypeSupported, (void *)hooked_IsEnclaveTypeSupported},
	{&(void *&)og_InitializeEnclave, (void *)hooked_InitializeEnclave},
	{&(void *&)og_LoadEnclaveData, (void *)hooked_LoadEnclaveData},
	{&(void *&)og_LoadEnclaveImageA, (void *)hooked_LoadEnclaveImageA},
	{&(void *&)og_TerminateEnclave, (void *)hooked_TerminateEnclave},
	{&(void *&)og_LoadEnclaveImageW, (void *)hooked_LoadEnclaveImageW},
	{&(void *&)og_AddVectoredContinueHandler, (void *)hooked_AddVectoredContinueHandler},
	{&(void *&)og_AddVectoredExceptionHandler, (void *)hooked_AddVectoredExceptionHandler},
	{&(void *&)og_FatalAppExitA, (void *)hooked_FatalAppExitA},
	{&(void *&)og_FatalAppExitW, (void *)hooked_FatalAppExitW},
	{&(void *&)og_GetErrorMode, (void *)hooked_GetErrorMode},
	{&(void *&)og_GetLastError, (void *)hooked_GetLastError},
	{&(void *&)og_GetThreadErrorMode, (void *)hooked_GetThreadErrorMode},
	{&(void *&)og_RaiseException, (void *)hooked_RaiseException},
	{&(void *&)og_RaiseFailFastException, (void *)hooked_RaiseFailFastException},
	{&(void *&)og_RemoveVectoredContinueHandler, (void *)hooked_RemoveVectoredContinueHandler},
	{&(void *&)og_RemoveVectoredExceptionHandler, (void *)hooked_RemoveVectoredExceptionHandler},
	{&(void *&)og_SetErrorMode, (void *)hooked_SetErrorMode},
	{&(void *&)og_SetLastError, (void *)hooked_SetLastError},
	{&(void *&)og_SetThreadErrorMode, (void *)hooked_SetThreadErrorMode},
	{&(void *&)og_SetUnhandledExceptionFilter, (void *)hooked_SetUnhandledExceptionFilter},
	{&(void *&)og_UnhandledExceptionFilter, (void *)hooked_UnhandledExceptionFilter},
	{&(void *&)og_FlsAlloc, (void *)hooked_FlsAlloc},
	{&(void *&)og_FlsFree, (void *)hooked_FlsFree},
	{&(void *&)og_FlsGetValue, (void *)hooked_FlsGetValue},
	{&(void *&)og_FlsSetValue, (void *)hooked_FlsSetValue},
	{&(void *&)og_IsThreadAFiber, (void *)hooked_IsThreadAFiber},
	{&(void *&)og_AreFileApisANSI, (void *)hooked_AreFileApisANSI},
	{&(void *&)og_CompareFileTime, (void *)hooked_CompareFileTime},
	{&(void *&)og_CreateDirectory2A, (void *)hooked_CreateDirectory2A},
	{&(void *&)og_CreateDirectory2W, (void *)hooked_CreateDirectory2W},
	{&(void *&)og_CreateDirectoryA, (void *)hooked_CreateDirectoryA},
	{&(void *&)og_CreateDirectoryW, (void *)hooked_CreateDirectoryW},
	{&(void *&)og_CreateFile2, (void *)hooked_CreateFile2},
	{&(void *&)og_CreateFile3, (void *)hooked_CreateFile3},
	{&(void *&)og_CreateFileW, (void *)hooked_CreateFileW},
	{&(void *&)og_CreateFileA, (void *)hooked_CreateFileA},
	{&(void *&)og_DefineDosDeviceW, (void *)hooked_DefineDosDeviceW},
	{&(void *&)og_DeleteFile2A, (void *)hooked_DeleteFile2A},
	{&(void *&)og_DeleteFileA, (void *)hooked_DeleteFileA},
	{&(void *&)og_DeleteFile2W, (void *)hooked_DeleteFile2W},
	{&(void *&)og_DeleteFileW, (void *)hooked_DeleteFileW},
	{&(void *&)og_DeleteVolumeMountPointW, (void *)hooked_DeleteVolumeMountPointW},
	{&(void *&)og_FileTimeToLocalFileTime, (void *)hooked_FileTimeToLocalFileTime},
	{&(void *&)og_FindClose, (void *)hooked_FindClose},
	{&(void *&)og_FindCloseChangeNotification, (void *)hooked_FindCloseChangeNotification},
	{&(void *&)og_FindFirstChangeNotificationA, (void *)hooked_FindFirstChangeNotificationA},
	{&(void *&)og_FindFirstFileA, (void *)hooked_FindFirstFileA},
	{&(void *&)og_FindFirstChangeNotificationW, (void *)hooked_FindFirstChangeNotificationW},
	{&(void *&)og_FindFirstFileExA, (void *)hooked_FindFirstFileExA},
	{&(void *&)og_FindFirstFileExW, (void *)hooked_FindFirstFileExW},
	{&(void *&)og_FindFirstFileNameW, (void *)hooked_FindFirstFileNameW},
	{&(void *&)og_FindFirstFileW, (void *)hooked_FindFirstFileW},
	{&(void *&)og_FindFirstStreamW, (void *)hooked_FindFirstStreamW},
	{&(void *&)og_FindFirstVolumeW, (void *)hooked_FindFirstVolumeW},
	{&(void *&)og_FindNextChangeNotification, (void *)hooked_FindNextChangeNotification},
	{&(void *&)og_FindNextFileA, (void *)hooked_FindNextFileA},
	{&(void *&)og_FindNextFileNameW, (void *)hooked_FindNextFileNameW},
	{&(void *&)og_FindNextStreamW, (void *)hooked_FindNextStreamW},
	{&(void *&)og_FindNextFileW, (void *)hooked_FindNextFileW},
	{&(void *&)og_FindNextVolumeW, (void *)hooked_FindNextVolumeW},
	{&(void *&)og_FindVolumeClose, (void *)hooked_FindVolumeClose},
	{&(void *&)og_FlushFileBuffers, (void *)hooked_FlushFileBuffers},
	{&(void *&)og_GetCompressedFileSizeA, (void *)hooked_GetCompressedFileSizeA},
	{&(void *&)og_GetDiskFreeSpaceA, (void *)hooked_GetDiskFreeSpaceA},
	{&(void *&)og_GetCompressedFileSizeW, (void *)hooked_GetCompressedFileSizeW},
	{&(void *&)og_GetDiskFreeSpaceExA, (void *)hooked_GetDiskFreeSpaceExA},
	{&(void *&)og_GetDiskFreeSpaceExW, (void *)hooked_GetDiskFreeSpaceExW},
	{&(void *&)og_GetDiskFreeSpaceW, (void *)hooked_GetDiskFreeSpaceW},
	{&(void *&)og_GetDiskSpaceInformationA, (void *)hooked_GetDiskSpaceInformationA},
	{&(void *&)og_GetDiskSpaceInformationW, (void *)hooked_GetDiskSpaceInformationW},
	{&(void *&)og_GetDriveTypeW, (void *)hooked_GetDriveTypeW},
	{&(void *&)og_GetDriveTypeA, (void *)hooked_GetDriveTypeA},
	{&(void *&)og_GetFileAttributesA, (void *)hooked_GetFileAttributesA},
	{&(void *&)og_GetFileAttributesExA, (void *)hooked_GetFileAttributesExA},
	{&(void *&)og_GetFileAttributesExW, (void *)hooked_GetFileAttributesExW},
	{&(void *&)og_GetFileAttributesW, (void *)hooked_GetFileAttributesW},
	{&(void *&)og_GetFileInformationByHandle, (void *)hooked_GetFileInformationByHandle},
	{&(void *&)og_GetFileSizeEx, (void *)hooked_GetFileSizeEx},
	{&(void *&)og_GetFileSize, (void *)hooked_GetFileSize},
	{&(void *&)og_GetFileType, (void *)hooked_GetFileType},
	{&(void *&)og_GetFileTime, (void *)hooked_GetFileTime},
	{&(void *&)og_GetFinalPathNameByHandleA, (void *)hooked_GetFinalPathNameByHandleA},
	{&(void *&)og_GetFinalPathNameByHandleW, (void *)hooked_GetFinalPathNameByHandleW},
	{&(void *&)og_GetFullPathNameA, (void *)hooked_GetFullPathNameA},
	{&(void *&)og_GetLogicalDriveStringsW, (void *)hooked_GetLogicalDriveStringsW},
	{&(void *&)og_GetLogicalDrives, (void *)hooked_GetLogicalDrives},
	{&(void *&)og_GetFullPathNameW, (void *)hooked_GetFullPathNameW},
	{&(void *&)og_GetLongPathNameA, (void *)hooked_GetLongPathNameA},
	{&(void *&)og_GetLongPathNameW, (void *)hooked_GetLongPathNameW},
	{&(void *&)og_GetShortPathNameW, (void *)hooked_GetShortPathNameW},
	{&(void *&)og_GetTempFileNameA, (void *)hooked_GetTempFileNameA},
	{&(void *&)og_GetTempFileNameW, (void *)hooked_GetTempFileNameW},
	{&(void *&)og_GetTempPath2A, (void *)hooked_GetTempPath2A},
	{&(void *&)og_GetTempPath2W, (void *)hooked_GetTempPath2W},
	{&(void *&)og_GetTempPathA, (void *)hooked_GetTempPathA},
	{&(void *&)og_GetTempPathW, (void *)hooked_GetTempPathW},
	{&(void *&)og_GetVolumeInformationA, (void *)hooked_GetVolumeInformationA},
	{&(void *&)og_GetVolumeInformationByHandleW, (void *)hooked_GetVolumeInformationByHandleW},
	{&(void *&)og_GetVolumeInformationW, (void *)hooked_GetVolumeInformationW},
	{&(void *&)og_GetVolumeNameForVolumeMountPointW, (void *)hooked_GetVolumeNameForVolumeMountPointW},
	{&(void *&)og_GetVolumePathNamesForVolumeNameW, (void *)hooked_GetVolumePathNamesForVolumeNameW},
	{&(void *&)og_GetVolumePathNameW, (void *)hooked_GetVolumePathNameW},
	{&(void *&)og_LockFile, (void *)hooked_LockFile},
	{&(void *&)og_LockFileEx, (void *)hooked_LockFileEx},
	{&(void *&)og_LocalFileTimeToFileTime, (void *)hooked_LocalFileTimeToFileTime},
	{&(void *&)og_QueryDosDeviceW, (void *)hooked_QueryDosDeviceW},
	{&(void *&)og_ReadFile, (void *)hooked_ReadFile},
	{&(void *&)og_RemoveDirectory2A, (void *)hooked_RemoveDirectory2A},
	{&(void *&)og_ReadFileEx, (void *)hooked_ReadFileEx},
	{&(void *&)og_ReadFileScatter, (void *)hooked_ReadFileScatter},
	{&(void *&)og_RemoveDirectoryA, (void *)hooked_RemoveDirectoryA},
	{&(void *&)og_RemoveDirectory2W, (void *)hooked_RemoveDirectory2W},
	{&(void *&)og_RemoveDirectoryW, (void *)hooked_RemoveDirectoryW},
	{&(void *&)og_SetFileApisToANSI, (void *)hooked_SetFileApisToANSI},
	{&(void *&)og_SetEndOfFile, (void *)hooked_SetEndOfFile},
	{&(void *&)og_SetFileApisToOEM, (void *)hooked_SetFileApisToOEM},
	{&(void *&)og_SetFileAttributesA, (void *)hooked_SetFileAttributesA},
	{&(void *&)og_SetFileAttributesW, (void *)hooked_SetFileAttributesW},
	{&(void *&)og_SetFileInformationByHandle, (void *)hooked_SetFileInformationByHandle},
	{&(void *&)og_SetFileIoOverlappedRange, (void *)hooked_SetFileIoOverlappedRange},
	{&(void *&)og_SetFilePointer, (void *)hooked_SetFilePointer},
	{&(void *&)og_SetFilePointerEx, (void *)hooked_SetFilePointerEx},
	{&(void *&)og_UnlockFile, (void *)hooked_UnlockFile},
	{&(void *&)og_SetFileTime, (void *)hooked_SetFileTime},
	{&(void *&)og_SetFileValidData, (void *)hooked_SetFileValidData},
	{&(void *&)og_WriteFile, (void *)hooked_WriteFile},
	{&(void *&)og_UnlockFileEx, (void *)hooked_UnlockFileEx},
	{&(void *&)og_WriteFileEx, (void *)hooked_WriteFileEx},
	{&(void *&)og_WriteFileGather, (void *)hooked_WriteFileGather},
	{&(void *&)og_CloseHandle, (void *)hooked_CloseHandle},
	{&(void *&)og_DuplicateHandle, (void *)hooked_DuplicateHandle},
	{&(void *&)og_GetHandleInformation, (void *)hooked_GetHandleInformation},
	{&(void *&)og_SetHandleInformation, (void *)hooked_SetHandleInformation},
	{&(void *&)og_CancelIo, (void *)hooked_CancelIo},
	{&(void *&)og_CancelIoEx, (void *)hooked_CancelIoEx},
	{&(void *&)og_CancelSynchronousIo, (void *)hooked_CancelSynchronousIo},
	{&(void *&)og_CreateIoCompletionPort, (void *)hooked_CreateIoCompletionPort},
	{&(void *&)og_GetOverlappedResult, (void *)hooked_GetOverlappedResult},
	{&(void *&)og_DeviceIoControl, (void *)hooked_DeviceIoControl},
	{&(void *&)og_GetQueuedCompletionStatus, (void *)hooked_GetQueuedCompletionStatus},
	{&(void *&)og_PostQueuedCompletionStatus, (void *)hooked_PostQueuedCompletionStatus},
	{&(void *&)og_GetOverlappedResultEx, (void *)hooked_GetOverlappedResultEx},
	{&(void *&)og_GetQueuedCompletionStatusEx, (void *)hooked_GetQueuedCompletionStatusEx},
	{&(void *&)og_IsProcessInJob, (void *)hooked_IsProcessInJob},
	{&(void *&)og_AssignProcessToJobObject, (void *)hooked_AssignProcessToJobObject},
	{&(void *&)og_CreateJobObjectW, (void *)hooked_CreateJobObjectW},
	{&(void *&)og_FreeMemoryJobObject, (void *)hooked_FreeMemoryJobObject},
	{&(void *&)og_QueryInformationJobObject, (void *)hooked_QueryInformationJobObject},
	{&(void *&)og_OpenJobObjectW, (void *)hooked_OpenJobObjectW},
	{&(void *&)og_QueryIoRateControlInformationJobObject, (void *)hooked_QueryIoRateControlInformationJobObject},
	{&(void *&)og_SetInformationJobObject, (void *)hooked_SetInformationJobObject},
	{&(void *&)og_SetIoRateControlInformationJobObject, (void *)hooked_SetIoRateControlInformationJobObject},
	{&(void *&)og_TerminateJobObject, (void *)hooked_TerminateJobObject},
	{&(void *&)og_AddDllDirectory, (void *)hooked_AddDllDirectory},
	{&(void *&)og_DisableThreadLibraryCalls, (void *)hooked_DisableThreadLibraryCalls},
	{&(void *&)og_EnumResourceNamesA, (void *)hooked_EnumResourceNamesA},
	{&(void *&)og_EnumResourceLanguagesExW, (void *)hooked_EnumResourceLanguagesExW},
	{&(void *&)og_EnumResourceNamesExA, (void *)hooked_EnumResourceNamesExA},
	{&(void *&)og_EnumResourceLanguagesExA, (void *)hooked_EnumResourceLanguagesExA},
	{&(void *&)og_uaw_wcslen, (void *)hooked_uaw_wcslen},
	{&(void *&)og_CompareStringEx, (void *)hooked_CompareStringEx},
	{&(void *&)og_CompareStringOrdinal, (void *)hooked_CompareStringOrdinal},
	{&(void *&)og_CompareStringW, (void *)hooked_CompareStringW},
	{&(void *&)og_FoldStringW, (void *)hooked_FoldStringW},
	{&(void *&)og_GetStringTypeExW, (void *)hooked_GetStringTypeExW},
	{&(void *&)og_GetStringTypeW, (void *)hooked_GetStringTypeW},
	{&(void *&)og_WideCharToMultiByte, (void *)hooked_WideCharToMultiByte},
	{&(void *&)og_MultiByteToWideChar, (void *)hooked_MultiByteToWideChar},
	{&(void *&)og_AcquireSRWLockExclusive, (void *)hooked_AcquireSRWLockExclusive},
	{&(void *&)og_AcquireSRWLockShared, (void *)hooked_AcquireSRWLockShared},
	{&(void *&)og_CreateEventA, (void *)hooked_CreateEventA},
	{&(void *&)og_CancelWaitableTimer, (void *)hooked_CancelWaitableTimer},
	{&(void *&)og_CreateEventExA, (void *)hooked_CreateEventExA},
	{&(void *&)og_CreateEventExW, (void *)hooked_CreateEventExW},
	{&(void *&)og_CreateEventW, (void *)hooked_CreateEventW},
	{&(void *&)og_CreateMutexA, (void *)hooked_CreateMutexA},
	{&(void *&)og_CreateMutexExA, (void *)hooked_CreateMutexExA},
	{&(void *&)og_CreateMutexExW, (void *)hooked_CreateMutexExW},
	{&(void *&)og_CreateMutexW, (void *)hooked_CreateMutexW},
	{&(void *&)og_CreateSemaphoreExW, (void *)hooked_CreateSemaphoreExW},
	{&(void *&)og_CreateSemaphoreW, (void *)hooked_CreateSemaphoreW},
	{&(void *&)og_CreateWaitableTimerExW, (void *)hooked_CreateWaitableTimerExW},
	{&(void *&)og_CreateWaitableTimerW, (void *)hooked_CreateWaitableTimerW},
	{&(void *&)og_DeleteSynchronizationBarrier, (void *)hooked_DeleteSynchronizationBarrier},
	{&(void *&)og_EnterCriticalSection, (void *)hooked_EnterCriticalSection},
	{&(void *&)og_DeleteCriticalSection, (void *)hooked_DeleteCriticalSection},
	{&(void *&)og_EnterSynchronizationBarrier, (void *)hooked_EnterSynchronizationBarrier},
	{&(void *&)og_InitializeConditionVariable, (void *)hooked_InitializeConditionVariable},
	{&(void *&)og_InitializeCriticalSection, (void *)hooked_InitializeCriticalSection},
	{&(void *&)og_InitializeCriticalSectionAndSpinCount, (void *)hooked_InitializeCriticalSectionAndSpinCount},
	{&(void *&)og_InitializeSListHead, (void *)hooked_InitializeSListHead},
	{&(void *&)og_InterlockedPopEntrySList, (void *)hooked_InterlockedPopEntrySList},
	{&(void *&)og_InterlockedFlushSList, (void *)hooked_InterlockedFlushSList},
	{&(void *&)og_InterlockedPushEntrySList, (void *)hooked_InterlockedPushEntrySList},
	{&(void *&)og_InterlockedPushListSListEx, (void *)hooked_InterlockedPushListSListEx},
	{&(void *&)og_QueryDepthSList, (void *)hooked_QueryDepthSList},
	{&(void *&)og_GetAppContainerNamedObjectPath, (void *)hooked_GetAppContainerNamedObjectPath},
	{&(void *&)og_AddResourceAttributeAce, (void *)hooked_AddResourceAttributeAce},
	{&(void *&)og_AddScopedPolicyIDAce, (void *)hooked_AddScopedPolicyIDAce},
	{&(void *&)og_CheckTokenCapability, (void *)hooked_CheckTokenCapability},
	{&(void *&)og_CheckTokenMembershipEx, (void *)hooked_CheckTokenMembershipEx},
	{&(void *&)og_DeriveCapabilitySidsFromName, (void *)hooked_DeriveCapabilitySidsFromName},
	{&(void *&)og_GetCachedSigningLevel, (void *)hooked_GetCachedSigningLevel},
	{&(void *&)og_SetCachedSigningLevel, (void *)hooked_SetCachedSigningLevel},
	{&(void *&)og_InitializeSRWLock, (void *)hooked_InitializeSRWLock},
	{&(void *&)og_InitializeCriticalSectionEx, (void *)hooked_InitializeCriticalSectionEx},
	{&(void *&)og_InitializeSynchronizationBarrier, (void *)hooked_InitializeSynchronizationBarrier},
	{&(void *&)og_InitOnceBeginInitialize, (void *)hooked_InitOnceBeginInitialize},
	{&(void *&)og_InitOnceComplete, (void *)hooked_InitOnceComplete},
	{&(void *&)og_InitOnceExecuteOnce, (void *)hooked_InitOnceExecuteOnce},
	{&(void *&)og_InitOnceInitialize, (void *)hooked_InitOnceInitialize},
	{&(void *&)og_LeaveCriticalSection, (void *)hooked_LeaveCriticalSection},
	{&(void *&)og_OpenEventA, (void *)hooked_OpenEventA},
	{&(void *&)og_OpenMutexW, (void *)hooked_OpenMutexW},
	{&(void *&)og_OpenEventW, (void *)hooked_OpenEventW},
	{&(void *&)og_OpenSemaphoreW, (void *)hooked_OpenSemaphoreW},
	{&(void *&)og_ReleaseMutex, (void *)hooked_ReleaseMutex},
	{&(void *&)og_OpenWaitableTimerW, (void *)hooked_OpenWaitableTimerW},
	{&(void *&)og_ReleaseSemaphore, (void *)hooked_ReleaseSemaphore},
	{&(void *&)og_ReleaseSRWLockExclusive, (void *)hooked_ReleaseSRWLockExclusive},
	{&(void *&)og_ReleaseSRWLockShared, (void *)hooked_ReleaseSRWLockShared},
	{&(void *&)og_ResetEvent, (void *)hooked_ResetEvent},
	{&(void *&)og_SetCriticalSectionSpinCount, (void *)hooked_SetCriticalSectionSpinCount},
	{&(void *&)og_SetEvent, (void *)hooked_SetEvent},
	{&(void *&)og_SetWaitableTimerEx, (void *)hooked_SetWaitableTimerEx},
	{&(void *&)og_SetWaitableTimer, (void *)hooked_SetWaitableTimer},
	{&(void *&)og_SignalObjectAndWait, (void *)hooked_SignalObjectAndWait},
	{&(void *&)og_Sleep, (void *)hooked_Sleep},
	{&(void *&)og_SleepEx, (void *)hooked_SleepEx},
	{&(void *&)og_TryAcquireSRWLockExclusive, (void *)hooked_TryAcquireSRWLockExclusive},
	{&(void *&)og_SleepConditionVariableSRW, (void *)hooked_SleepConditionVariableSRW},
	{&(void *&)og_SleepConditionVariableCS, (void *)hooked_SleepConditionVariableCS},
	{&(void *&)og_TryAcquireSRWLockShared, (void *)hooked_TryAcquireSRWLockShared},
	{&(void *&)og_TryEnterCriticalSection, (void *)hooked_TryEnterCriticalSection},
	{&(void *&)og_WaitForMultipleObjects, (void *)hooked_WaitForMultipleObjects},
	{&(void *&)og_WaitForMultipleObjectsEx, (void *)hooked_WaitForMultipleObjectsEx},
	{&(void *&)og_WaitForSingleObject, (void *)hooked_WaitForSingleObject},
	{&(void *&)og_WaitForSingleObjectEx, (void *)hooked_WaitForSingleObjectEx},
	{&(void *&)og_WakeAllConditionVariable, (void *)hooked_WakeAllConditionVariable},
	{&(void *&)og_WakeConditionVariable, (void *)hooked_WakeConditionVariable},
	{&(void *&)og_EnumSystemFirmwareTables, (void *)hooked_EnumSystemFirmwareTables},
	{&(void *&)og_GetComputerNameExA, (void *)hooked_GetComputerNameExA},
	{&(void *&)og_GetComputerNameExW, (void *)hooked_GetComputerNameExW},
	{&(void *&)og_GetLogicalProcessorInformation, (void *)hooked_GetLogicalProcessorInformation},
	{&(void *&)og_GetLocalTime, (void *)hooked_GetLocalTime},
	{&(void *&)og_GetLogicalProcessorInformationEx, (void *)hooked_GetLogicalProcessorInformationEx},
	{&(void *&)og_GetNativeSystemInfo, (void *)hooked_GetNativeSystemInfo},
	{&(void *&)og_GetProcessorSystemCycleTime, (void *)hooked_GetProcessorSystemCycleTime},
	{&(void *&)og_GetPhysicallyInstalledSystemMemory, (void *)hooked_GetPhysicallyInstalledSystemMemory},
	{&(void *&)og_GetProductInfo, (void *)hooked_GetProductInfo},
	{&(void *&)og_GetSystemDirectoryA, (void *)hooked_GetSystemDirectoryA},
	{&(void *&)og_GetSystemDirectoryW, (void *)hooked_GetSystemDirectoryW},
	{&(void *&)og_GetSystemFirmwareTable, (void *)hooked_GetSystemFirmwareTable},
	{&(void *&)og_GetSystemInfo, (void *)hooked_GetSystemInfo},
	{&(void *&)og_GetSystemTime, (void *)hooked_GetSystemTime},
	{&(void *&)og_GetSystemTimeAdjustment, (void *)hooked_GetSystemTimeAdjustment},
	{&(void *&)og_GetSystemTimeAsFileTime, (void *)hooked_GetSystemTimeAsFileTime},
	{&(void *&)og_GetSystemWindowsDirectoryA, (void *)hooked_GetSystemWindowsDirectoryA},
	{&(void *&)og_GetSystemWindowsDirectoryW, (void *)hooked_GetSystemWindowsDirectoryW},
	{&(void *&)og_GetTickCount, (void *)hooked_GetTickCount},
	{&(void *&)og_GetSystemTimePreciseAsFileTime, (void *)hooked_GetSystemTimePreciseAsFileTime},
	{&(void *&)og_GetTickCount64, (void *)hooked_GetTickCount64},
	{&(void *&)og_GetVersion, (void *)hooked_GetVersion},
	{&(void *&)og_GetVersionExA, (void *)hooked_GetVersionExA},
	{&(void *&)og_GetVersionExW, (void *)hooked_GetVersionExW},
	{&(void *&)og_GetWindowsDirectoryA, (void *)hooked_GetWindowsDirectoryA},
	{&(void *&)og_GetWindowsDirectoryW, (void *)hooked_GetWindowsDirectoryW},
	{&(void *&)og_GlobalMemoryStatusEx, (void *)hooked_GlobalMemoryStatusEx},
	{&(void *&)og_InstallELAMCertificateInfo, (void *)hooked_InstallELAMCertificateInfo},
	{&(void *&)og_SetComputerNameA, (void *)hooked_SetComputerNameA},
	{&(void *&)og_SetComputerNameExA, (void *)hooked_SetComputerNameExA},
	{&(void *&)og_SetComputerNameExW, (void *)hooked_SetComputerNameExW},
	{&(void *&)og_SetComputerNameW, (void *)hooked_SetComputerNameW},
	{&(void *&)og_SetLocalTime, (void *)hooked_SetLocalTime},
	{&(void *&)og_SetSystemTime, (void *)hooked_SetSystemTime},
	{&(void *&)og_SetSystemTimeAdjustment, (void *)hooked_SetSystemTimeAdjustment},
	{&(void *&)og_GetNumaHighestNodeNumber, (void *)hooked_GetNumaHighestNodeNumber},
	{&(void *&)og_GetNumaNodeProcessorMaskEx, (void *)hooked_GetNumaNodeProcessorMaskEx},
	{&(void *&)og_GetNumaProximityNodeEx, (void *)hooked_GetNumaProximityNodeEx},
	{&(void *&)og_HeapDestroy, (void *)hooked_HeapDestroy},
	{&(void *&)og_HeapAlloc, (void *)hooked_HeapAlloc},
	{&(void *&)og_GetProcessHeap, (void *)hooked_GetProcessHeap},
	{&(void *&)og_HeapCompact, (void *)hooked_HeapCompact},
	{&(void *&)og_HeapCreate, (void *)hooked_HeapCreate},
	{&(void *&)og_GetProcessHeaps, (void *)hooked_GetProcessHeaps},
	{&(void *&)og_HeapFree, (void *)hooked_HeapFree},
	{&(void *&)og_HeapReAlloc, (void *)hooked_HeapReAlloc},
	{&(void *&)og_HeapLock, (void *)hooked_HeapLock},
	{&(void *&)og_HeapSetInformation, (void *)hooked_HeapSetInformation},
	{&(void *&)og_HeapSize, (void *)hooked_HeapSize},
	{&(void *&)og_HeapQueryInformation, (void *)hooked_HeapQueryInformation},
	{&(void *&)og_HeapUnlock, (void *)hooked_HeapUnlock},
	{&(void *&)og_HeapSummary, (void *)hooked_HeapSummary},
	{&(void *&)og_HeapValidate, (void *)hooked_HeapValidate},
	{&(void *&)og_HeapWalk, (void *)hooked_HeapWalk},
	{&(void *&)og_CancelThreadpoolIo, (void *)hooked_CancelThreadpoolIo},
	{&(void *&)og_CallbackMayRunLong, (void *)hooked_CallbackMayRunLong},
	{&(void *&)og_CloseThreadpool, (void *)hooked_CloseThreadpool},
	{&(void *&)og_CloseThreadpoolCleanupGroup, (void *)hooked_CloseThreadpoolCleanupGroup},
	{&(void *&)og_CloseThreadpoolCleanupGroupMembers, (void *)hooked_CloseThreadpoolCleanupGroupMembers},
	{&(void *&)og_CloseThreadpoolIo, (void *)hooked_CloseThreadpoolIo},
	{&(void *&)og_CloseThreadpoolWait, (void *)hooked_CloseThreadpoolWait},
	{&(void *&)og_CloseThreadpoolTimer, (void *)hooked_CloseThreadpoolTimer},
	{&(void *&)og_CloseThreadpoolWork, (void *)hooked_CloseThreadpoolWork},
	{&(void *&)og_CreateThreadpool, (void *)hooked_CreateThreadpool},
	{&(void *&)og_CreateThreadpoolCleanupGroup, (void *)hooked_CreateThreadpoolCleanupGroup},
	{&(void *&)og_CreateThreadpoolIo, (void *)hooked_CreateThreadpoolIo},
	{&(void *&)og_CreateThreadpoolWork, (void *)hooked_CreateThreadpoolWork},
	{&(void *&)og_CreateThreadpoolTimer, (void *)hooked_CreateThreadpoolTimer},
	{&(void *&)og_CreateThreadpoolWait, (void *)hooked_CreateThreadpoolWait},
	{&(void *&)og_QueryThreadpoolStackInformation, (void *)hooked_QueryThreadpoolStackInformation},
	{&(void *&)og_ReleaseMutexWhenCallbackReturns, (void *)hooked_ReleaseMutexWhenCallbackReturns},
	{&(void *&)og_ReleaseSemaphoreWhenCallbackReturns, (void *)hooked_ReleaseSemaphoreWhenCallbackReturns},
	{&(void *&)og_SetThreadpoolThreadMaximum, (void *)hooked_SetThreadpoolThreadMaximum},
	{&(void *&)og_SetEventWhenCallbackReturns, (void *)hooked_SetEventWhenCallbackReturns},
	{&(void *&)og_SetThreadpoolStackInformation, (void *)hooked_SetThreadpoolStackInformation},
	{&(void *&)og_SetThreadpoolThreadMinimum, (void *)hooked_SetThreadpoolThreadMinimum},
	{&(void *&)og_SetThreadpoolTimer, (void *)hooked_SetThreadpoolTimer},
	{&(void *&)og_SetThreadpoolTimerEx, (void *)hooked_SetThreadpoolTimerEx},
	{&(void *&)og_SetThreadpoolWait, (void *)hooked_SetThreadpoolWait},
	{&(void *&)og_StartThreadpoolIo, (void *)hooked_StartThreadpoolIo},
	{&(void *&)og_SetThreadpoolWaitEx, (void *)hooked_SetThreadpoolWaitEx},
	{&(void *&)og_SubmitThreadpoolWork, (void *)hooked_SubmitThreadpoolWork},
	{&(void *&)og_TrySubmitThreadpoolCallback, (void *)hooked_TrySubmitThreadpoolCallback},
	{&(void *&)og_WaitForThreadpoolIoCallbacks, (void *)hooked_WaitForThreadpoolIoCallbacks},
	{&(void *&)og_WaitForThreadpoolTimerCallbacks, (void *)hooked_WaitForThreadpoolTimerCallbacks},
	{&(void *&)og_WaitForThreadpoolWorkCallbacks, (void *)hooked_WaitForThreadpoolWorkCallbacks},
	{&(void *&)og_WaitForThreadpoolWaitCallbacks, (void *)hooked_WaitForThreadpoolWaitCallbacks},
	{&(void *&)og_ChangeTimerQueueTimer, (void *)hooked_ChangeTimerQueueTimer},
	{&(void *&)og_CreateTimerQueue, (void *)hooked_CreateTimerQueue},
	{&(void *&)og_CreateTimerQueueTimer, (void *)hooked_CreateTimerQueueTimer},
	{&(void *&)og_DeleteTimerQueueTimer, (void *)hooked_DeleteTimerQueueTimer},
	{&(void *&)og_DeleteTimerQueueEx, (void *)hooked_DeleteTimerQueueEx},
	{&(void *&)og_QueueUserWorkItem, (void *)hooked_QueueUserWorkItem},
	{&(void *&)og_UnregisterWaitEx, (void *)hooked_UnregisterWaitEx},
	{&(void *&)og_FileTimeToSystemTime, (void *)hooked_FileTimeToSystemTime},
	{&(void *&)og_GetDynamicTimeZoneInformation, (void *)hooked_GetDynamicTimeZoneInformation},
	{&(void *&)og_GetTimeZoneInformation, (void *)hooked_GetTimeZoneInformation},
	{&(void *&)og_GetTimeZoneInformationForYear, (void *)hooked_GetTimeZoneInformationForYear},
	{&(void *&)og_SetDynamicTimeZoneInformation, (void *)hooked_SetDynamicTimeZoneInformation},
	{&(void *&)og_SystemTimeToTzSpecificLocalTime, (void *)hooked_SystemTimeToTzSpecificLocalTime},
	{&(void *&)og_SystemTimeToFileTime, (void *)hooked_SystemTimeToFileTime},
	{&(void *&)og_SetTimeZoneInformation, (void *)hooked_SetTimeZoneInformation},
	{&(void *&)og_SystemTimeToTzSpecificLocalTimeEx, (void *)hooked_SystemTimeToTzSpecificLocalTimeEx},
	{&(void *&)og_TzSpecificLocalTimeToSystemTimeEx, (void *)hooked_TzSpecificLocalTimeToSystemTimeEx},
	{&(void *&)og_TzSpecificLocalTimeToSystemTime, (void *)hooked_TzSpecificLocalTimeToSystemTime},
	{&(void *&)og_CreateToolhelp32Snapshot, (void *)hooked_CreateToolhelp32Snapshot},
	{&(void *&)og_Heap32ListFirst, (void *)hooked_Heap32ListFirst},
	{&(void *&)og_Heap32First, (void *)hooked_Heap32First},
	{&(void *&)og_Heap32ListNext, (void *)hooked_Heap32ListNext},
	{&(void *&)og_Module32First, (void *)hooked_Module32First},
	{&(void *&)og_Heap32Next, (void *)hooked_Heap32Next},
	{&(void *&)og_Module32FirstW, (void *)hooked_Module32FirstW},
	{&(void *&)og_Module32Next, (void *)hooked_Module32Next},
	{&(void *&)og_Process32First, (void *)hooked_Process32First},
	{&(void *&)og_Module32NextW, (void *)hooked_Module32NextW},
	{&(void *&)og_Process32FirstW, (void *)hooked_Process32FirstW},
	{&(void *&)og_Process32Next, (void *)hooked_Process32Next},
	{&(void *&)og_Thread32First, (void *)hooked_Thread32First},
	{&(void *&)og_Process32NextW, (void *)hooked_Process32NextW},
	{&(void *&)og_Thread32Next, (void *)hooked_Thread32Next},
	{&(void *&)og_Toolhelp32ReadProcessMemory, (void *)hooked_Toolhelp32ReadProcessMemory},
	{&(void *&)og_Beep, (void *)hooked_Beep},
	{&(void *&)og_RtlAddFunctionTable, (void *)hooked_RtlAddFunctionTable},
	{&(void *&)og_RtlCaptureContext, (void *)hooked_RtlCaptureContext},
	{&(void *&)og_RtlDeleteFunctionTable, (void *)hooked_RtlDeleteFunctionTable},
	{&(void *&)og_RtlInstallFunctionTableCallback, (void *)hooked_RtlInstallFunctionTableCallback},
	{&(void *&)og_RtlLookupFunctionEntry, (void *)hooked_RtlLookupFunctionEntry},
	{&(void *&)og_RtlPcToFileHeader, (void *)hooked_RtlPcToFileHeader},
	{&(void *&)og_RtlRestoreContext, (void *)hooked_RtlRestoreContext},
	{&(void *&)og_RtlUnwind, (void *)hooked_RtlUnwind},
	{&(void *&)og_RtlUnwindEx, (void *)hooked_RtlUnwindEx},
	{&(void *&)og_RtlVirtualUnwind, (void *)hooked_RtlVirtualUnwind},
	{&(void *&)og_VerSetConditionMask, (void *)hooked_VerSetConditionMask},
	
};

