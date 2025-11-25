#pragma comment(lib, "user32.lib")

#include <iostream>
#include <windows.h>

int
main() {
    std::cout << "Inside the target\n";

    for (int i = 0; i < 1; i += 1) {
        std::cout << ("Dragon is white\n");
        Sleep(1000);
    }
    MessageBoxA(NULL, "Hello from Windows!", "My MessageBox", MB_OK | MB_ICONINFORMATION);

    return 0;
}
