#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmdLine,
                   int nCmdShow) {

    MessageBoxA(NULL, "Hello from Windows!", "My MessageBox",
                MB_OK | MB_ICONINFORMATION);

    return 0;
}
