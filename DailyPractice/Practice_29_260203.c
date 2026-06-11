#include <stdio.h>
#include <windows.h>
int main() {
    char szBuffer[200];
    int number = 100;
    sprintf_s(szBuffer, "变量 number 的值是 %d \r\n", number);
    OutputdebugString(szBuffer);
    sprintf_s(szBuffer, "变量 number 的地址是%x\r\n", &number);
    OutputDebugString(szBuffer);

    return 0;
}
//
// Created by Madeleine on 2026/2/3.
//