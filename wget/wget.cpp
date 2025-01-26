#include <Windows.h>
#include <string>

#pragma comment(lib, "urlmon.lib")

int main()
{
    std::wstring dwnld_URL = L"https://hirofumi090.chobi.net/index.html";
    std::wstring savepath = L"index.html";
    URLDownloadToFileW(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);
    return 0;
}
