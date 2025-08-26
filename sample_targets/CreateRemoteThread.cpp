#include <windows.h>
#include <iostream>

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    MessageBoxA(NULL, "CreateRemoteThread executed", "Info", MB_OK);
    return 0;
}

int main() {
    HANDLE hThread = CreateRemoteThread(GetCurrentProcess(), NULL, 0, ThreadFunc, NULL, 0, NULL);
    if (hThread) {
        std::cout << "CreateRemoteThread success\n";
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    } else {
        std::cout << "CreateRemoteThread failed\n";
    }
    return 0;
}
