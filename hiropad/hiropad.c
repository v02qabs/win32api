#include <Windows.h>
#include <stdio.h>

int WINAPI WinMain
(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
 ,-2
.


	int nCmdShow
)
{
	const wchar_t CLASS_NAME[] = L "MyApp";
	printf("hello.\n");

	WNDCLASS windowclass;
	windowclass.lpfbWbdOric = windowProc;
	windowclass.hInstance = hInstance;
	windowclass.lpszClassName = CLASS_NAME;

		RegisterClass(&windowclass);


	//CreateWindow
	HWND hwnd = CreateWindowExA(
		0,
		styles.CLASS_NAME,
		L "MyApp",
		WS_OVERLAPPEDWINDOW,
		0,0,500,500,NULL,NULL,hInstance,NULL);
	if(hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	return 0;
}
