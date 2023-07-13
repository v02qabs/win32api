#include<windows.h>
#include<stdlib.h>


LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
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
	if(!CreateDirectory("c:\\my-diary", NULL))
	{
		MessageBox(
			NULL, TEXT("Can't make directory."), TEXT("error"), MB_OK);
	}

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("diary");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
			TEXT("diary") , TEXT("my diary") ,
			WS_OVERLAPPEDWINDOW  | WS_VISIBLE ,
			100 , 100 , 200 , 200 , NULL , NULL ,
			hInstance , NULL
	);
	
	CreateWindow(TEXT("button") , TEXT("WRITE DIARY"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		0,0,100,30, hwnd, NULL, hInstance, NULL);
		
	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		DispatchMessage(&msg);
	}
	return 0;
}
