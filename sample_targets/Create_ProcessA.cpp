#include <windows.h>
#include <iostream>

int main() {
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;

    std::cout << "Inside Create Process Executable.\n";

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Command to be executed (Notepad in this example)
    const char* cmdLine = "notepad.exe";

    // Create the process
    if (!CreateProcessA(
        NULL,           // Application name
        (LPSTR)cmdLine, // Command line (needs to be modifiable)
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
        &si,            // Pointer to STARTUPINFOA structure
        &pi))           // Pointer to PROCESS_INFORMATION structure
    {
        std::cerr << "CreateProcessA failed (" << GetLastError() << ").\n";
        return 1;
    }

    std::cout << "Notepad launched successfully.\n";

    // Wait for the process to finish (optional)
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Cleanup handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
