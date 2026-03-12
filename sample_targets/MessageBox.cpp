#pragma comment(lib, "user32.lib")

#include <windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    OutputDebugStringA("Inside the target\n");
	return MessageBoxA(NULL, "Hello from Windows!", "My MessageBox", MB_OK | MB_ICONINFORMATION);
}
