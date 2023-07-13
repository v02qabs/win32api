#include<windows.h>
#include<stdlib.h>

LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {

//static HWND OKB;
static HINSTANCE hInstance;
	switch (msg) {
	case WM_DESTROY:
		exit(0);
		return 0;
	}
	return DefWindowProc(hwnd , msg , wp , lp);
}


int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,
		 PSTR lpCmdLine , int nCmdShow ) {
	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("KITTY");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
			TEXT("KITTY") , TEXT("Kitty on your lap") ,
			WS_OVERLAPPEDWINDOW  | WS_VISIBLE ,
			100 , 100 , 200 , 200 , NULL , NULL ,
			hInstance , NULL
	);

	CreateWindow(TEXT("BUTTON"),TEXT("OK"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 0,0,100,30, hwnd,NULL, hInstance, NULL);

	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		DispatchMessage(&msg);
	}
	return 0;
}
