#pragma comment(lib, "user32.lib")

#include <iostream>
#include <windows.h>

int
main() {
    std::cout << "Inside the target\n";

    MessageBoxA(NULL, "Hello from Windows!", "My MessageBox", MB_OK | MB_ICONINFORMATION);

    return 0;
}
