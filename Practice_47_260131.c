#include <stdio.h>

int main() {
#ifdef _DEBUG
    printf("正在使用 Debug 模式编译程序...\n");
#else
    printf("正在使用 Release 模式编译程序...\n");
#endif

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//