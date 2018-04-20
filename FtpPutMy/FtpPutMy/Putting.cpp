#include <stdio.h>
#include <windows.h>
#include <wininet.h>
#include <conio.h>

#pragma comment (lib, "wininet.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HINTERNET hOpen, hConnect;
	hOpen = InternetOpen(TEXT("ftptest"), INTERNET_OPEN_TYPE_DIRECT, NULL,NULL,0);
	if(hOpen!=NULL)
	{
		printf("hOpen..\n");
		
	}
	else
	{
		printf("error.\n");
	}
	
	
	return 0;
}
