#include<windows.h>
#include<stdlib.h>
#include<d3d9.h>


LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		MessageBox(hwnd , TEXT("èIÇÌÇÈÇ…Ç·ÇÒ") ,
			 TEXT("Kitty") , MB_ICONINFORMATION);
		PostQuitMessage(0);
		exit(0);
		return 0;
	}
	return DefWindowProc(hwnd , msg , wp , lp);
}


void Init3D()
{
	LPDIRECT3D9 pD3d;
	if(NULL == (pD3d = Direct3DCreate9(D3D_SDK_VERSION)));
	
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

	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		DispatchMessage(&msg);
	}

	Init3D();

	return 0;
}
