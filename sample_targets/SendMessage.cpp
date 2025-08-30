#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>

int
main() {
    // Example hard-coded HWND value (just for illustration)
    HWND hwnd = (HWND)0x00123456;

    if (hwnd == NULL) {
        std::cout << "Invalid window handle." << std::endl;
        return 1;
    }

    LRESULT result = SendMessageA(hwnd, WM_CLOSE, 0, 0);
    std::cout << "Sent WM_CLOSE message with result: " << result << std::endl;

    return 0;
}
