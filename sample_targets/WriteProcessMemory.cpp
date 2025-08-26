#include <windows.h>
#include <iostream>

int
main() {
    char data[] = "Hello";
    SIZE_T bytesWritten;
    BOOL ok = WriteProcessMemory(GetCurrentProcess(), data, "World", 6, &bytesWritten);
    if (ok) {
        std::cout << "WriteProcessMemory: " << data << " (" << bytesWritten << " bytes)\n";
    } else {
        std::cout << "WriteProcessMemory failed\n";
    }
    return 0;
}
