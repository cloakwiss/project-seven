#pragma comment(lib, "./detours/detours.lib")

#include <iostream>
#include <windows.h>
#include <winnt.h>

#include "../builds/debug/detours/detours.h"

int
main(int argc, char *argv[]) {

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <target.exe> <hook.dll>\n";
        return 1;
    }

    HANDLE Pipe = CreateNamedPipeA("\\\\.\\pipe\\DataPipe", // Pipe Name
                                   PIPE_ACCESS_INBOUND,     // Access Type
                                   PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, // Config
                                   1, 256, 256, // InstanceCount, OutBuffSize, InBuffSize
                                   0, NULL);    // Timeout, SecurityAttributes

    if (Pipe == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create pipe\n";
        return 1;
    }

    STARTUPINFOA StartupInfo = {};
    PROCESS_INFORMATION ProcessInfo = {};
    StartupInfo.cb = sizeof(StartupInfo);

    if (!DetourCreateProcessWithDllA(argv[1],                    //
                                     NULL, NULL, NULL, FALSE,    //
                                     CREATE_DEFAULT_ERROR_MODE,  //
                                     NULL, NULL,                 //
                                     &StartupInfo, &ProcessInfo, //
                                     argv[2], NULL)) {

        std::cerr << "Failed to launch process with DLL. Error: " << GetLastError() << "\n";
        return 1;
    }

    std::cout << "Waiting for Hook DLL...\n";
    if (ConnectNamedPipe(Pipe, NULL)) {

        char buffer[256];
        DWORD bytesRead;

        while (ReadFile(Pipe, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
            std::cout << "[Program B] Received hook text: " << buffer << "\n";
        }

        CloseHandle(Pipe);
    } else {

        std::cout << "The pipe didn't connect for some reason\n";
    }

    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    CloseHandle(ProcessInfo.hThread);
    CloseHandle(ProcessInfo.hProcess);
    return 0;
}
