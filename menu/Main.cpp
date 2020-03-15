#include <windows.h>

ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE, int);
TCHAR szClassName[] = TEXT("MENU");


int WINAPI WinMain(HINSTANCE hInstance,
									HINSTANCE hPrevInstance,
									LPSTR lpsCmdLine,
									int nCmdShow)

{
	MSG msg;
	BOOL bret;

	if(!InitApp(hCurInst))
		return FALSE;

		if(!InitInstance(hCurInst, nCmdShow))
			return FAlSE;

	
	while((bret = GetMessage(&msg,NULL,0,0)) != 0)
	{
		if(bret == -1)
		{
			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

ATOM InitApp(HINSTANCE hInst)
{
	WNDCLASSEX wc;
	wc.cbSize							=	sizeof(WINDCLASSEX);
	wc.style							= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc 				= WndProc;
	wc.cbClsExtra					= 0;
	wc.cbWndExtra					= 0;
	wc.hInstance					= hInst;
	wc.hIcon 							= NULL;
	wc.hCursor 						= (HCURSOR)LoadImage(NULL,MAKEINTRESOURCE(IDC_ARROW),
	IMAGE_CURSOR,0,0,LR_DEFAULTSIZE | LR_SHARED);
	wc.hbrBackground			= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszClassName			= szClassName;
	return (RegisterClassEX(&ws));
}

BOOL InitInstance(HINSTANCE hInst, int nCmdShow)
{
	HWND hwnd;
	hwnd = CreateWindow(szClassName, TEXT("HELLO"),
	WS_OVERLAPEDWINDOW, CW_USEDEFAULT, CW_USEEFAULT,
	CW_USEDEFAULT, CW_USEDEFAULT,NULL, NULL, hInst, NULL);
	if(!hwnd)
		return FALSE;
	

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	return FLASE;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	int ld;
	switch(msg)
	{
		case WM_COMMAND:
			switch(LOWORD(wp))
			{
				case 100:
					SendMessage(hwnd, WM_CLOSE, 0,0);
					break;
					default:
						return (DefWindowProc(hwnd, msg,wp,lp));
			}
		case WM_CLOSE:
			id= MessageBox(hwnd, TEXT("FINISH IS OK?"), TEXT("AGREE?"), MB_YESNO | MB_ICONQUESTION);
			IF(ID == IDYES)
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return (DefWindowProc(hwnd,msg,wp,lp));
	}
	return 0;
}

