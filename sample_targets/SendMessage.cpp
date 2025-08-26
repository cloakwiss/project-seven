#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>

int
main() {
    HWND hwnd = FindWindowA(NULL, "Untitled - Notepad"); // Change title as needed
    if (hwnd == NULL) {
        std::cout << "Window not found." << std::endl;
        return 1;
    }

    LRESULT result = SendMessageA(hwnd, WM_CLOSE, 0, 0);
    std::cout << "Sent WM_CLOSE message with result: " << result << std::endl;

    return 0;
}
