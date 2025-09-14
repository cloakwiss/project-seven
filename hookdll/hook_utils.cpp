#ifndef HOOK_UTILS_H
#define HOOK_UTILS_H
// --------------------------------------------------------------------------------------------- //

#include <windows.h>
#include <iostream>
#include <sstream>

static thread_local HANDLE GlobalPipeHandle = INVALID_HANDLE_VALUE;
static thread_local unsigned long GlobalCallDepth = 0;
static thread_local unsigned long GlobalMaxCallDepth = 0;
static thread_local std::ostringstream logs;
static thread_local bool IsLoggingOn = false;



static void
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

// Logging Utilities ---------------------------------------------------------------------------- //

static void
start_json_before(const std::string &hookName) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"args\": {\n";
}

static void
start_json_after(const std::string &hookName, std::string time) {
    logs << "{\n";
    logs << "  \"hook\": \"" << hookName << "\",\n";
    logs << "  \"call_depth\": \"" << GlobalCallDepth << "\",\n";
    logs << "  \"time\": \"" << time << "\",\n";
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
    logs << "  }\n"; // close returns
    logs << "}\n";
}
// ---------------------------------------------------------------------------------------------- //

// ---------------------------------------------------------------------------------------------- //
// THIS STUFF IS VERY IMPORTANT ----------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //
// The reason for keeping logs global is that we do not want to reallocate it again and again. -- //
// It will then not reallocate memmory for the log all the time, we just clear it. -------------- //
// ---------------------------------------------------------------------------------------------- //

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
    }
// ---------------------------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------------------------- //


// --------------------------------------------------------------------------------------------- //
#endif
