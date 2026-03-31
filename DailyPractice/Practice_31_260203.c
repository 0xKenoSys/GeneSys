#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include "debuginfo.h"
int main() {
    int num;
    printf_s("请输入数值：\n");
    scanf_s("%d", &num);
    DebugInfo(TEXT("用户输入的数是 %d\n"), num);
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//