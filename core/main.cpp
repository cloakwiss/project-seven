#pragma comment(lib, "./detours/detours.lib")

#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <strsafe.h>

#include "./inject_hook_dll.cpp"

void
PrintUsage() {
    std::cout << "Usage:\n"
              << "     BinStop [options]\n"
              << "Options:\n"
              << "    -d:<hookdll path>    : Add file.dll binary files\n"
              << "    -e:<executable path> : Add executable binary files\n"
              << "    -r                   : Remove extra DLLs from binary files\n"
              << "    -h                   : This help screen.\n";
}

int
ParseArgs(int argc, char *argv[], char **DllPath, char **ExecutablePath, bool *Remove) {
    bool needHelp = false;

    *DllPath = nullptr;
    *ExecutablePath = nullptr;
    *Remove = false;

    if (argc == 1) {
        needHelp = true;
    }

    for (int arg = 1; arg < argc; arg++) {
        if (argv[arg][0] == '-' || argv[arg][0] == '/') {
            char *argn = argv[arg] + 1; // skip '-'
            char *argp = strchr(argn, ':');
            if (argp) {
                *argp++ = '\0'; // split at ':'
            }

            switch (argn[0]) {
                case 'd':
                case 'D': // DLL path
                    if (argp) {
                        *DllPath = argp;
                    } else {
                        needHelp = true;
                    }
                    break;

                case 'e':
                case 'E': // Executable path
                    if (argp) {
                        *ExecutablePath = argp;
                    } else {
                        needHelp = true;
                    }
                    break;

                case 'r':
                case 'R': // Remove DLLs
                    *Remove = true;
                    break;

                case 'h':
                case 'H':
                case '?': // Help
                    needHelp = true;
                    break;

                default:
                    std::cout << "Bad argument: " << argn;
                    if (argp)
                        std::cout << ":" << argp;
                    std::cout << "\n";
                    needHelp = true;
                    break;
            }
        }
    }

    // Must have both DLL and Executable unless help was requested
    if (*DllPath == nullptr || *ExecutablePath == nullptr || needHelp) {
        PrintUsage();
        return 1;
    }

    return 0;
}



int
main(int argc, char *argv[]) {

    // Argument Parsing (I know this is finicky but ok for now) ----------//
    // This will not be done like this anyway, gui will takeover
    char *DllPath = nullptr;
    char *ExecutablePath = nullptr;
    bool Remove = false;

    if (ParseArgs(argc, argv, &DllPath, &ExecutablePath, &Remove)) {
        return 1;
    }
    // -------------------------------------------------------------------//

    // Injecting the Hook DLL in the Executable
    // This was done at runtime before.
    // Injecting directly in the PE resolves
    // the issue of not being able to do
    // blocking tasks in DllMain
    if (InjectHookDll(DllPath, ExecutablePath, Remove)) {
        std::cerr << "Injecting/Dejecting the Hook Failed.\n";
        return 1;
    }



    // Pipe Creation ---------------------------------------------------------- //
    HANDLE Pipe = CreateNamedPipeA("\\\\.\\pipe\\DataPipe", // Pipe Name
                                   PIPE_ACCESS_INBOUND,     // Access Type
                                   PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, // Config
                                   1, 256, 256, // InstanceCount, OutBuffSize, InBuffSize
                                   0, NULL);    // Timeout, SecurityAttributes

    if (Pipe == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create pipe\n";
        return 1;
    }
    // Pipe Creation ---------------------------------------------------------- //

    STARTUPINFOA StartupInfo = {};
    PROCESS_INFORMATION ProcessInfo = {};
    StartupInfo.cb = sizeof(StartupInfo);

    if (!CreateProcessA(ExecutablePath,            // Need to make it more robust
                        0, 0, 0, 0,                // by adding arguments, more options
                        CREATE_DEFAULT_ERROR_MODE, //
                        0, 0,                      //
                        &StartupInfo, &ProcessInfo)) {

        std::cerr << "Failed to launch process. Error: " << GetLastError() << "\n";
        return 1;
    }

    // No need to wait if there is no hook;
    if (!Remove) {
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
    }


    WaitForSingleObject(ProcessInfo.hProcess, INFINITE);
    CloseHandle(ProcessInfo.hThread);
    CloseHandle(ProcessInfo.hProcess);
    return 0;
}
