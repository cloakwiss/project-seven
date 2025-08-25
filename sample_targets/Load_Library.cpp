#include <windows.h>
#include <iostream>

int main() {
    HMODULE hMod = LoadLibraryA("User32.dll");
    if (hMod) {
        std::cout << "User32.dll loaded successfully at address: " << hMod << std::endl;
        FreeLibrary(hMod);
    } else {
        std::cout << "Failed to load User32.dll." << std::endl;
    }
    return 0;
}
