#include <windows.h>
#include <stdio.h>
#include <locale.h>


int WINAPI WinMain(
HINSTANCE hInstance,
HINSTANCE hPrevInstance,
PSTR lpCmdLine,
int nCmdShow)
{
	printf("Hello.\n");
	HANDLE hFile = NULL;
	char szBuff[1000] = {'\0'};
	hFile = CreateFile(TEXT("./item.txt"),GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile == INVALID_HANDLE_VALUE)
	{
		printf("Can't create file.\n");
	}
	BOOL ret;
	DWORD dword;
	ret = ReadFile(
	hFile, szBuff,sizeof(szBuff)/sizeof(szBuff[0]),&dword, NULL);
	if(!ret)
	{
		printf("error.\n");
		CloseHandle(hFile);
		return 1;
	}
	DWORD writer;
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE),
	szBuff, (DWORD)strlen(szBuff),&writer, NULL);
	CloseHandle(hFile);
	return 0;
}
