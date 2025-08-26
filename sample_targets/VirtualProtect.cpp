#include <windows.h>
#include <iostream>

int
main() {
    char buffer[128] = {0};
    DWORD oldProtect;

    // Correct cast to LPVOID (void*)
    if (VirtualProtect((LPVOID)buffer, sizeof(buffer), PAGE_READONLY, &oldProtect)) {
        std::cout << "VirtualProtect success\n";
    } else {
        std::cout << "VirtualProtect failed\n";
    }

    // Restore previous protection
    VirtualProtect((LPVOID)buffer, sizeof(buffer), oldProtect, &oldProtect);

    return 0;
}
