#include <windows.h>
LRESULT CALLBACK WndProc(HWND,UINT, WPARAM, LPARAM);
ATOM InitApp(HINSTANCE);
BOOL InitInstance(HINSTANCE ,int);
TCHAR szClassName[] = TEXT("MENU0");

int WINAPI WinMain(HINSTANCE hInstance,
			HINSTANCE hPrevInst,
			LPSTR lpCmdLine,
			int nCmdShow)
{
	MSG msg;
	BOOLD re;	
	if(!InitApp(hCurInst))
	{
		return FALSE;
	}
		if(!InitInstance(hCurInst, nCmdShow))
			return FALSE;
	
	while((re =GetMessage(&msg, NUL, 0,0)) != 0)
	{
		if(re == -1)
		{
			break;
		}
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wPram;

}

