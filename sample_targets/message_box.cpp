#pragma comment(lib, "user32.lib")

#include <windows.h>
#include <iostream>

// int WINAPI
// WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine, int nCmdShow) {
int
main() {
	std::cout << "Inside the target";

    MessageBoxA(NULL, "Hello from Windows!", "My MessageBox", MB_OK | MB_ICONINFORMATION);

    return 0;
}
