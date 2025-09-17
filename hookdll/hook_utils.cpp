#ifndef HOOK_UTILS_H
#define HOOK_UTILS_H
// --------------------------------------------------------------------------------------------- //

#include <cstdint>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <atomic>

static HANDLE GlobalPipeHandle = INVALID_HANDLE_VALUE;
static thread_local unsigned long GlobalCallDepth = 0;
static thread_local unsigned long GlobalMaxCallDepth = 0;
static thread_local std::ostringstream logs;
static thread_local bool IsLoggingOn = false;
static thread_local int64_t PerfCounterFrequency;
static thread_local double TimeElapsed;

static std::atomic<bool> Running{false};
static std::atomic<bool> SteppingOn{false};
static std::atomic<bool> Abort{false};
static std::atomic<bool> StopBeforeCall{false};
static std::atomic<bool> StopAfterCall{false};
static std::atomic<bool> Break{false};

static HANDLE ThreadHandle = nullptr;
static HANDLE ControlPipeHandle = INVALID_HANDLE_VALUE;
static HANDLE ThreadStopEvent = nullptr;

const LPCSTR HookPipeName = TEXT("\\\\.\\pipe\\P7_HOOKS");
const LPCSTR ControlPipeName = TEXT("\\\\.\\pipe\\P7_CONTROLS");

// Sending to the UI ---------------------------------------------------------------------------- //

static void
SendToServer(const char *text) {
    if (GlobalPipeHandle == INVALID_HANDLE_VALUE) {
        GlobalPipeHandle =
            CreateFileA(HookPipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (GlobalPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(GlobalPipeHandle, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
}



// Thread to listen to control signals from the UI ---------------------------------------------- //

#define START_SIG  0x21
#define STOP_SIG   0x22
#define RESUME_SIG 0x23
#define ABORT_SIG  0x24
#define STEC_SIG   0x25
#define STSC_SIG   0x26
#define STENC_SIG  0x27
#define STSNC_SIG  0x28

// TODO: this needs to be polished this totaly does not work
// for some reason this needs spanking for not funking my ui
DWORD WINAPI
ControlListener(LPVOID lpParam) {
    OVERLAPPED ov = {};
    ov.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);

    BYTE msg = 0;
    DWORD bytes_read = 0;
    HANDLE wait_handles[2] = {ThreadStopEvent, ov.hEvent};

    while (true) {
        ResetEvent(ov.hEvent);

        std::cout << "Control Listener Ping\n";
        std::cout << "Control Listener send pipe handle: " << GlobalPipeHandle << '\n';
        BOOL ok = ReadFile(ControlPipeHandle, &msg, sizeof(msg), nullptr, &ov);
        // BOOL ok = ReadFile(ControlPipeHandle, &msg, sizeof(msg), nullptr, nullptr);
        if (!ok && GetLastError() != ERROR_IO_PENDING) {
            std::cerr << "Should this ever run??";
            break;
        }

        DWORD wait = WaitForMultipleObjects(2, wait_handles, FALSE, INFINITE);

        if (wait == WAIT_OBJECT_0) {
            CancelIo(ControlPipeHandle);
            break;
        } else if (wait == WAIT_OBJECT_0 + 1) {
            if (GetOverlappedResult(ControlPipeHandle, &ov, &bytes_read, FALSE) &&
                bytes_read == 1) {

                switch (msg) {

                    case (START_SIG): {
                        std::cout << "======START SIG========\n";
                        SendToServer("Start signal\n");
                    } break;

                    case (STOP_SIG): {
                        SendToServer("Stop signal\n");
                    } break;

                    case (RESUME_SIG): {
                        SendToServer("Resume signal\n");
                    } break;

                    case (ABORT_SIG): {
                        SendToServer("Abort signal\n");
                    } break;

                    case (STEC_SIG): {
                        SendToServer("Step to end of call signal\n");
                    } break;

                    case (STSC_SIG): {
                        SendToServer("Step to start of call signal\n");
                    } break;

                    case (STENC_SIG): {
                        SendToServer("Step to end of next call signal\n");
                    } break;

                    case (STSNC_SIG): {
                        SendToServer("Step to start of next call signal\n");
                    } break;

                    default: {
                        SendToServer("######## UNREACHABLE CODE REACHED ########\n");
                    } break;
                }
            }
        }
    }

    CloseHandle(ov.hEvent);
    return 0;
}

// Logging Utilities
// ---------------------------------------------------------------------------- //

static void
start_json_before(const std::string &hookName) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"args\": {\n";
}

static void
start_json_after(const std::string &hookName) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"time\": \"" << TimeElapsed << "us" << "\",\n";
    logs << "  \"returns\": {\n";
}

static void
log_fields(const std::string &key, std::string val, bool last = false) {
    logs << "    \"" << key << "\": \"" << std::hex << val << std::dec << "\"";

    if (!last)
        logs << ",";

    logs << "\n";
}

static void
end_json() {
    logs << "  }\n";
    logs << "}\n";
}
// ----------------------------------------------------------------------------------------------
// //

// ----------------------------------------------------------------------------------------------
// // THIS STUFF IS VERY IMPORTANT
// ----------------------------------------------------------------- //
// ----------------------------------------------------------------------------------------------
// // The reason for keeping logs global is that we do not want to reallocate it again and
// again. -- // It will then not reallocate memmory for the log all the time, we just clear
// it. -------------- //
// ----------------------------------------------------------------------------------------------
// //

#define SEND_BEFORE_CALL(CODE)                                                                     \
    if (GlobalCallDepth <= GlobalMaxCallDepth && IsLoggingOn) {                                    \
        IsLoggingOn = false;                                                                       \
        CODE;                                                                                      \
        end_json();                                                                                \
        SendToServer(logs.str().c_str());                                                          \
        logs.str("");                                                                              \
        logs.clear();                                                                              \
        IsLoggingOn = true;                                                                        \
    }                                                                                              \
    GlobalCallDepth += 1;

#define SEND_AFTER_CALL(CODE)                                                                      \
    GlobalCallDepth -= 1;                                                                          \
    if (GlobalCallDepth <= GlobalMaxCallDepth && IsLoggingOn) {                                    \
        IsLoggingOn = false;                                                                       \
        CODE;                                                                                      \
        end_json();                                                                                \
        SendToServer(logs.str().c_str());                                                          \
        logs.str("");                                                                              \
        logs.clear();                                                                              \
        IsLoggingOn = true;                                                                        \
    }                                                                                              \
    TimeElapsed = 0.0f;



#define TIME(CALL)                                                                                 \
    LARGE_INTEGER BeginCounter;                                                                    \
    QueryPerformanceCounter(&BeginCounter);                                                        \
    CALL;                                                                                          \
    LARGE_INTEGER EndCounter;                                                                      \
    QueryPerformanceCounter(&EndCounter);                                                          \
    int64_t CounterElapsed = EndCounter.QuadPart - BeginCounter.QuadPart;                          \
    TimeElapsed = 1000.0f * 1000.0f * (double)CounterElapsed / (double)PerfCounterFrequency;

// ---------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //


// --------------------------------------------------------------------------------------------- //
#endif
