#include <stdio.h>
#define _DEBUGNOW
int main() {
#ifdef _DEBUGNOW
    orintf("正在为调试做准备...");
#endif
    printf("程序正在运行...");
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//