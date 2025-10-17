#ifndef HOOK_UTILS_H
#define HOOK_UTILS_H
// --------------------------------------------------------------------------------------------- //

#include <cstdint>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <atomic>


static thread_local unsigned long GlobalCallDepth = 0;
static thread_local unsigned long GlobalMaxCallDepth = 0;
static thread_local std::ostringstream logs;
static thread_local bool IsLoggingOn = false;
static thread_local int64_t PerfCounterFrequency = 0;
static thread_local double TimeElapsed = 0;

// static std::atomic<bool> Running{false};
static std::atomic<bool> StopBeforeCall{true};
static std::atomic<bool> StopAfterCall{true};
static std::atomic<bool> Break{false};

static HANDLE HookPipeHandle = INVALID_HANDLE_VALUE;
static HANDLE ControlPipeHandle = INVALID_HANDLE_VALUE;

static HANDLE ThreadHandle = 0;
static HANDLE ThreadStopEvent = 0;

const LPCSTR HookPipeName = TEXT("\\\\.\\pipe\\P7_HOOKS");
const LPCSTR ControlPipeName = TEXT("\\\\.\\pipe\\P7_CONTROLS");

// Sending to the UI ---------------------------------------------------------------------------- //
static void
SendHookBuffer(uint8_t* buffer, size_t len){
        if (HookPipeHandle == INVALID_HANDLE_VALUE) {
        HookPipeHandle = CreateFileA(HookPipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (HookPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(HookPipeHandle, buffer, (DWORD)len , &bytesWritten, NULL);
}

static void
SendToServer(const char *text) {
    if (HookPipeHandle == INVALID_HANDLE_VALUE) {
        HookPipeHandle = CreateFileA(HookPipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (HookPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(HookPipeHandle, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
}



// Thread to listen to control signals from the UI ---------------------------------------------- //

#define START_SIG  0x21
#define STOP_SIG   0x22
#define RESUME_SIG 0x23
#define ABORT_SIG  0x24
#define STEC_SIG   0x25
#define STSC_SIG   0x26

// TODO: Just needs checking if we need overlapped io or not
DWORD WINAPI
ControlListener(LPVOID lpParam) {
    bool IsThreadRunning = true;

    while (IsThreadRunning) {

        // Thread Handling ---------------------------------------------------------------------- //

        // This is the part that stops cpu melting btw, no extra sleep
        // and THIS IS A BUSY WORKING THREAD
        DWORD wait = WaitForSingleObject(ThreadStopEvent, 50);
        switch (wait) {
            case (WAIT_ABANDONED):
            case (WAIT_OBJECT_0): {
                IsThreadRunning = false;
            } break;

            case (WAIT_FAILED): {
                IsThreadRunning = false;
            } break;

            case (WAIT_TIMEOUT):
            default: {
            } break;
        }

        if (!IsThreadRunning) {
            break;
        }
        // -------------------------------------------------------------------------------------- //

        // Reading the signal from the ControlPipe ---------------------------------------------- //

        /* TODO: Dont know if we need overlapped io for this */
        // OVERLAPPED OverLapEvent = {};
        // OverLapEvent.hEvent = CreateEventA(0, TRUE, FALSE, 0);
        BYTE SignalByte = 0;
        DWORD SignalBytesRead = 0;

        // BOOL ok = ReadFile(ControlPipeHandle, &SignalByte, sizeof(SignalByte), 0, &OverLapEvent);
        BOOL ok = ReadFile(ControlPipeHandle, &SignalByte, sizeof(SignalByte), 0, 0);

        switch (GetLastError()) {
            case (ERROR_IO_PENDING): {
                std::cerr << "IO PENDING OR SOMETHING";
            } break;

            default: {
            } break;
        }

        switch (SignalByte) {
            case (START_SIG): {
                SendToServer("Start signal\n");
            } break;

            case (STOP_SIG): {
                StopBeforeCall.store(true);
                StopAfterCall.store(true);

                SendToServer("Stop signal\n");
            } break;

            case (RESUME_SIG): {
                StopBeforeCall.store(false);
                StopAfterCall.store(false);

                SendToServer("Resume signal\n");
            } break;

            case (ABORT_SIG): {
                SendToServer("Abort signal\n");
                std::cerr << "Aborting on p7's control signal\n";

                ExitProcess('p' + 7); // Easter Egg
            } break;

            case (STEC_SIG): {
                StopBeforeCall.store(false);
                StopAfterCall.store(true);

                Break.store(true);

                SendToServer("Step to end of call signal\n");
            } break;

            case (STSC_SIG): {
                StopBeforeCall.store(true);
                StopAfterCall.store(false);

                Break.store(true);

                SendToServer("Step to start of call signal\n");
            } break;

            case (0): {
            } break;

            default: {
                std::cerr << "######### UNREACHABLE CODE REACHED ##########";
            } break;
        }

        // CloseHandle(OverLapEvent.hEvent);

        // -------------------------------------------------------------------------------------- //
    }
    return 0;
}

// Stepping Utilities --------------------------------------------------------- //

static void
ControlBefore() {

    // THIS WILL BE A BUSY WAIT AS WELL
    // I AM SORRY FOR MY CRIMES
    while (StopBeforeCall.load()) {
        if (Break.load()) {
            break;
        }
        Sleep(50);
    }
	Break.store(false);
}

static void
ControlAfter() {

    // THIS WILL BE A BUSY WAIT AS WELL
    // I AM SORRY FOR MY CRIMES
    while (StopAfterCall.load()) {

        if (Break.load()) {
            break;
        }
        Sleep(50);
    }
	Break.store(false);
}


// Logging Utilities --------------------------------------------------------- //

static void
start_json_before(const std::string &hookName) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"ARGS\": {\n";
}

static void
start_json_after(const std::string &hookName) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"time\": \"" << TimeElapsed << "us" << "\",\n";
    logs << "  \"RETURNS\": {\n";
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
        SendHookBuffer(bytebuffer, bufferhead);                                                    \                                                                                                                                                     
        ControlBefore();                                                                           \
        IsLoggingOn = true;                                                                        \
    }                                                                                              \
    GlobalCallDepth += 1;

#define SEND_AFTER_CALL(CODE)                                                                      \
    GlobalCallDepth -= 1;                                                                          \
    if (GlobalCallDepth <= GlobalMaxCallDepth && IsLoggingOn) {                                    \
        IsLoggingOn = false;                                                                       \
        CODE;                                                                                      \
        SendHookBuffer(bytebuffer, bufferhead);                                                    \                                                                      
        ControlAfter();                                                                            \
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
