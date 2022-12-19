#include <windows.h>

__declspec(dllimport) int RunDll();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	RunDll();
	return 0;
}
