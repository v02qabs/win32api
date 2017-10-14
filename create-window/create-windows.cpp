#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANC hInstance,
									HINSTANC hPrevInstance,
									PWSTR rCmdLine,
									int nCmdShow)
{

	const wchar_t CL_NAME[] = "Hello1";

	WNDCLASS wc = {};

	wc.lpfnWndProc = WndProc;
	wc.hInstanc = hInstance;
	wc.lpSzClassName = CL_NAME;

	Register(CL_NAME,&wc);

	HWND hwnd = CreateWindow(0,CL_NAME, WS_OVERLAPPEDWINDOW, 0, 0, 500, 500, NULL,NULL, hInstance, NULL);
	if(hwnd == NULL)
		return 0;

	ShowWindow(hwnd, nCmdShow);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umsg, WPARAM wParam, LPARAM lParam)
{

	switch(msg)
	{
		case WN_DESTROY:
				PostQuiteMessage(0);
				return 0;
	}
}

						

