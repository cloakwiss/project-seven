#include <windows.h>
#include <iostream>

int main() {
    HWND desktop = GetDesktopWindow();
    HWND firstWindow = GetWindow(desktop, GW_CHILD);
    if (firstWindow) {
        std::cout << "First child window handle: " << firstWindow << std::endl;

        HWND nextWindow = GetWindow(firstWindow, GW_HWNDNEXT);
        if (nextWindow) {
            std::cout << "Next window handle: " << nextWindow << std::endl;
        } else {
            std::cout << "No next window found." << std::endl;
        }
    } else {
        std::cout << "No child windows found." << std::endl;
    }
    return 0;
}
