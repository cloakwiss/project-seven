#include <windows.h>
#include <iostream>

int main() {
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char value[256];
        DWORD valueSize = sizeof(value);
        DWORD type = 0;
        // Correct usage: passing buffer as LPBYTE, which is equivalent to unsigned char*
        if (RegQueryValueExA(hKey, "Shell Folders", NULL, &type, reinterpret_cast<LPBYTE>(value), &valueSize) == ERROR_SUCCESS) {
            std::cout << "RegQueryValueEx success: " << value << "\n";
        } else {
            std::cout << "RegQueryValueEx failed\n";
        }
        RegCloseKey(hKey);
    } else {
        std::cout << "RegOpenKeyEx failed\n";
    }
    return 0;
}
