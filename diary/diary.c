#include<windows.h>
#include<stdlib.h>

#define BUTTON_ID1 0
#define GetHInstance( ) ((HINSTANCE)GetModuleHandle(0))

<<<<<<< HEAD
LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		exit(0);
		return 0;
	case WM_COMMAND:
		switch(LOWORD(wp))
		{
			case XBUTTON1:
					MessageBox(hwnd, TEXT("BUTTON_ID1"), TEXT("ID_BUTTON_1"), MB_OK);
					ShowWindow(hwnd, SW_HIDE);
					
					break;
			case XBUTTON2:
					MessageBox(hwnd, TEXT("BUTTON_ID2"), TEXT("BUTTON 2"), MB_OK);
					break;
		}
		return 0;
		
	}
	return DefWindowProc(hwnd , msg , wp , lp);
}


int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,
		 PSTR lpCmdLine , int nCmdShow ) {
	HWND hwnd;
=======
int edit_and_writting()
{
	HWND hwnd1;
>>>>>>> 9b7df2b594147598804ff10ae42efd3334fabf7f
	MSG msg;
	WNDCLASS winc;
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = NULL;
	winc.cbClsExtra = winc.cbWndExtra = 0;
	winc.hInstance = GetHInstance();
	winc.hCursor = LoadCursor(NULL , IDC_ARROW);
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT("KITTY");
	if (!RegisterClass(&winc)) return 0;

	hwnd1 = CreateWindow(
			TEXT("diary") , TEXT("my diary") ,
			WS_OVERLAPPEDWINDOW  | WS_VISIBLE ,
			100 , 100 , 200 , 200 , NULL , NULL ,
			GetHInstance() , NULL
	);
<<<<<<< HEAD
	
	CreateWindow(TEXT("button") , TEXT("WRITE DIARY"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		0,0,100,30, hwnd, (HMENU)XBUTTON1, hInstance, NULL);

	CreateWindow(TEXT("button") , TEXT("VIEW DIARY"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		0,35,100,30, hwnd, (HMENU)XBUTTON2, hInstance, NULL);


	if (hwnd == NULL) return 0;
=======
		
	if (hwnd1 == NULL) return 0;
>>>>>>> 9b7df2b594147598804ff10ae42efd3334fabf7f

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		DispatchMessage(&msg);
	}
	return 0;

}



LRESULT CALLBACK WndProc(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	switch (msg) {
	case WM_DESTROY:
		exit(0);
		return 0;
	
	case  WM_COMMAND:
		switch(LOWORD(wp)){
			case BUTTON_ID1:
			MessageBox(hwnd, TEXT("BUTTON"),  TEXT("BUTTON"), MB_OK);
			edit_and_writting();
			break;
		}
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
		0,0,100,30, hwnd, (HMENU)BUTTON_ID1 , hInstance, NULL);
		
	if (hwnd == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		DispatchMessage(&msg);
	}
	return 0;
}
