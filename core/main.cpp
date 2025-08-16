#include <iostream>
#include <minwindef.h>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine,
                   int nCmdShow) {

    const char *pipeName = "\\\\.\\pipe\\DataPipe";
    const DWORD pipeType = PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT;

    HANDLE hPipe = CreateNamedPipeA(TEXT(pipeName), PIPE_ACCESS_INBOUND,
                                    pipeType, 1, 256, 256, 0, NULL);

    if (hPipe == INVALID_HANDLE_VALUE) {
        std::cerr << "Failed to create pipe\n";
        return 1;
    }

    std::cout << "Waiting for Hook DLL...\n";
    ConnectNamedPipe(hPipe, NULL);

    char buffer[256];
    DWORD bytesRead;

    while (ReadFile(hPipe, buffer, sizeof(buffer), &bytesRead, NULL) &&
           bytesRead > 0) {
        std::cout << "[Program B] Received hook text: " << buffer << "\n";
    }

    CloseHandle(hPipe);
    return 0;
}
