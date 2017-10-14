#include <iostream>
#include <windows.h>
#include <wininet.h>

#pragma comment (lib, "wininet.lib")

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HINSTANCE hOpen, hConnect;
	hOpen = InternetOpen("ftp.chobi.net", NULL , NULL, "ftp://sg982zc.chobi.net" , 0);
	if(hOpen!=NULL)
	{
		cout << "ok." << endl;
	}
	else
	{
		cout << "ng." << endl;
	}
	
	
	return 0;
}
