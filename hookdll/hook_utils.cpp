#ifndef HOOK_UTILS_H
#define HOOK_UTILS_H
// --------------------------------------------------------------------------------------------- //

#include <cstdint>
#include <windows.h>
#include <iostream>
#include <sstream>
#include <atomic>


static thread_local uint64_t           GlobalCallDepth      = 0;
static thread_local uint64_t           GlobalMaxCallDepth   = 0;
static thread_local bool               IsHookingOn          = false;
static thread_local int64_t            PerfCounterFrequency = 0;
static thread_local double             TimeElapsed          = 0;
static thread_local uint8_t           *HookBuffer           = NULL;
static thread_local size_t             HookBufferHead       = 0;
static thread_local std::ostringstream Logger;

static std::atomic<bool> StopBeforeCall{true};
static std::atomic<bool> StopAfterCall{true};
static std::atomic<bool> Break{false};

static HANDLE HookPipeHandle    = INVALID_HANDLE_VALUE;
static HANDLE ControlPipeHandle = INVALID_HANDLE_VALUE;
static HANDLE LogPipeHandle     = INVALID_HANDLE_VALUE;

static HANDLE ThreadHandle    = 0;
static HANDLE ThreadStopEvent = 0;

const LPCSTR HookPipeName    = TEXT("\\\\.\\pipe\\P7_HOOKS");
const LPCSTR ControlPipeName = TEXT("\\\\.\\pipe\\P7_CONTROLS");
const LPCSTR LogPipeName     = TEXT("\\\\.\\pipe\\P7_LOGS");

#define BUFFER_SIZE (1024 * 1024 * 2)

#define HOOK_CALL_ID 0x82
#define HOOK_RET_ID  0x28


// ---------------------------------------------------------------------------------------------- //
// Sending to P7 -------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

static void
SendHookBuffer(uint8_t *buffer, size_t len) {
    if (HookPipeHandle == INVALID_HANDLE_VALUE) {
        HookPipeHandle = CreateFileA(HookPipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (HookPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cout << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(HookPipeHandle, buffer, (DWORD)len, &bytesWritten, NULL);
    FlushFileBuffers(HookPipeHandle);
    ZeroMemory(buffer, len);
    HookBufferHead = 0;
}

static void
SendLog(const char *text) {
    if (LogPipeHandle == INVALID_HANDLE_VALUE) {
        LogPipeHandle = CreateFileA(LogPipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

        if (LogPipeHandle == INVALID_HANDLE_VALUE) {
            DWORD LastError = GetLastError();
            std::cerr << "Failed to open pipe. Error code: " << LastError << std::endl;
            return;
        }
    }

    DWORD bytesWritten = 0;
    WriteFile(LogPipeHandle, text, (DWORD)strlen(text) + 1, &bytesWritten, NULL);
    FlushFileBuffers(LogPipeHandle);
}

#define LOG(expr)                                                                                  \
    do {                                                                                           \
        Logger.str("");                                                                            \
        Logger.clear();                                                                            \
        Logger << "[HOOK] " << expr << '\n';                                                       \
        std::cout << "[HOOK] " << expr << '\n';                                                    \
        SendLog(Logger.str().c_str());                                                             \
    } while (0)


// ---------------------------------------------------------------------------------------------- //
// Controls Listener ---------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

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
        BYTE  SignalByte      = 0;
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
                LOG("Start signal\n");
            } break;

            case (STOP_SIG): {
                StopBeforeCall.store(true);
                StopAfterCall.store(true);

                LOG("Stop signal\n");
            } break;

            case (RESUME_SIG): {
                StopBeforeCall.store(false);
                StopAfterCall.store(false);

                LOG("Resume signal\n");
            } break;

            case (ABORT_SIG): {
                LOG("Abort signal\n");
                std::cerr << "Aborting on p7's control signal\n";

                ExitProcess('p' + 7); // Easter Egg
            } break;

            case (STEC_SIG): {
                StopBeforeCall.store(false);
                StopAfterCall.store(true);

                Break.store(true);

                LOG("Step to end of call signal\n");
            } break;

            case (STSC_SIG): {
                StopBeforeCall.store(true);
                StopAfterCall.store(false);

                Break.store(true);

                LOG("Step to start of call signal\n");
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
// ---------------------------------------------------------------------------------------------- //



// ---------------------------------------------------------------------------------------------- //
// Stepping Utilities --------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

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


// ---------------------------------------------------------------------------------------------- //
// Hook Macros ---------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //

#define SEND_BEFORE_CALL(ID, CODE)                                                                 \
    if (GlobalCallDepth <= GlobalMaxCallDepth && IsHookingOn) {                                    \
        IsHookingOn = false;                                                                       \
        InitHookCall((char *)ID);                                                                  \
        CODE;                                                                                      \
        SendHookBuffer(HookBuffer, HookBufferHead);                                                \
        ControlBefore();                                                                           \
        IsHookingOn = true;                                                                        \
    }                                                                                              \
    GlobalCallDepth += 1;

#define SEND_AFTER_CALL(ID, CODE)                                                                  \
    GlobalCallDepth -= 1;                                                                          \
    if (GlobalCallDepth <= GlobalMaxCallDepth && IsHookingOn) {                                    \
        IsHookingOn = false;                                                                       \
        InitHookRet((char *)ID);                                                                   \
        CODE;                                                                                      \
        SendHookBuffer(HookBuffer, HookBufferHead);                                                \
        ControlAfter();                                                                            \
        IsHookingOn = true;                                                                        \
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
