#include <Windows.h>
#include <iostream>

DWORD WINAPI
ThreadFunc(LPVOID lpParam) {
    MessageBoxA(NULL, "Hello from remote thread!", "Thread MessageBox", MB_OK | MB_ICONINFORMATION);
    return 0;
}

void
SafeCreateProcess(const char *cmdLine) {
    STARTUPINFOA si = {sizeof(si)};
    PROCESS_INFORMATION pi = {0};

    // Create the process and check if it succeeded
    if (!CreateProcessA(NULL,           // Application name (NULL means use cmdLine)
                        (LPSTR)cmdLine, // Command line
                        NULL,           // Process handle not inheritable
                        NULL,           // Thread handle not inheritable
                        FALSE,          // Inherit handles: false
                        0,              // Creation flags
                        NULL,           // Use parent's environment block
                        NULL,           // Use parent's starting directory
                        &si,            // STARTUPINFO structure
                        &pi))           // PROCESS_INFORMATION structure
    {
        std::cerr << "CreateProcess failed. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Process created successfully with PID: " << pi.dwProcessId << std::endl;

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void
SafeCreateRemoteThread() {
    HANDLE hThread = CreateRemoteThread(GetCurrentProcess(), NULL, 0, ThreadFunc, NULL, 0, NULL);

    if (hThread == NULL) {
        std::cerr << "CreateRemoteThread failed. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Remote thread created successfully." << std::endl;

    WaitForSingleObject(hThread, INFINITE);

    CloseHandle(hThread);
}

void
SafeMessageBox() {
    // Displaying a MessageBox
    int msgBoxResult = MessageBoxA(NULL,                      // Parent window
                                   "Hello from Windows!",     // Message text
                                   "My MessageBox",           // Title text
                                   MB_OK | MB_ICONINFORMATION // Style
    );

    if (msgBoxResult == 0) {
        std::cerr << "MessageBoxA failed. Error: " << GetLastError() << std::endl;
    }
}

void
SafeLoadLibrary() {
    HMODULE hModule = LoadLibraryA("User32.dll");
    if (hModule == NULL) {
        std::cerr << "LoadLibraryA failed. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Library loaded successfully." << std::endl;
    FreeLibrary(hModule);
}

void
SafeSendMessage(HWND hwnd) {
    if (SendMessageA(hwnd, WM_CLOSE, 0, 0) == 0) {
        std::cerr << "SendMessageA failed. Error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Message sent successfully to window." << std::endl;
    }
}

void
SafeMemoryOperations() {
    SIZE_T memSize = 1024;
    LPVOID buffer = VirtualAlloc(NULL, memSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (buffer == NULL) {
        std::cerr << "VirtualAlloc failed. Error: " << GetLastError() << std::endl;
        return;
    }

    std::cout << "Memory allocated at: " << buffer << std::endl;

    DWORD oldProtect;
    if (VirtualProtect(buffer, memSize, PAGE_READONLY, &oldProtect) == 0) {
        std::cerr << "VirtualProtect failed. Error: " << GetLastError() << std::endl;
        VirtualFree(buffer, 0, MEM_RELEASE);
        return;
    }

    std::cout << "Memory protection changed to PAGE_READONLY." << std::endl;

    if (VirtualProtect(buffer, memSize, oldProtect, &oldProtect) == 0) {
        std::cerr << "Restoring original memory protection failed. Error: " << GetLastError()
                  << std::endl;
    } else {
        std::cout << "Memory protection restored to original state." << std::endl;
    }

    if (VirtualFree(buffer, 0, MEM_RELEASE) == 0) {
        std::cerr << "VirtualFree failed. Error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Memory freed successfully." << std::endl;
    }
}


void
SafeWriteProcessMemory() {
    const char *data = "World";
    SIZE_T bytesWritten;

    // Write memory in the current process
    if (!WriteProcessMemory(GetCurrentProcess(), (LPVOID)0x12345678, (LPCVOID)data, 6,
                            &bytesWritten)) {
        std::cerr << "WriteProcessMemory failed. Error: " << GetLastError() << std::endl;
    } else {
        std::cout << "Memory written successfully. Bytes written: " << bytesWritten << std::endl;
    }
}

int
main() {
    const char *cmdLine = "notepad.exe";

    // Demonstrate the API calls safely
    SafeCreateProcess(cmdLine);
    SafeCreateRemoteThread();
    SafeMessageBox();
    SafeLoadLibrary();

    HWND hwnd = GetConsoleWindow();
    SafeSendMessage(hwnd);

    SafeMemoryOperations();
    SafeWriteProcessMemory();

    Sleep(2000);

    return 0;
}
