#include <windows.h>
#include <tchar.h>
int main() {
    OutputDebugString(TEXT("你好"));
    OutputDebugString(_T("大家好"));
    system("pause");
    return 0;
}


//#ifdef UNICODE
//#define OutputDebugString OutputDebugStringW
//#else
//#define OutputDebugString OutputDebugStringA
//#endif // !UNICODE


//
// Created by Madeleine on 2026/2/3.
//