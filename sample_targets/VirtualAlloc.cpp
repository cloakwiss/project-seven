#include <windows.h>
#include <iostream>

int
main() {
    SIZE_T memSize = 1024;
    LPVOID mem = VirtualAlloc(NULL, memSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (mem) {
        std::cout << "VirtualAlloc success\n";
        VirtualFree(mem, 0, MEM_RELEASE);
    } else {
        std::cout << "VirtualAlloc failed\n";
    }
    return 0;
}
