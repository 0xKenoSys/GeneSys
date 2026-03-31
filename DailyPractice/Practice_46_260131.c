#include <stdio.h>

#define NUM1
#define NUM2 10

int main() {
    #if defined(NUM1) && defined(NUM2)
        printf("正确：NUM1 和 NUM2 都被定义了");
    #endif

    #if !defined(NUM1) || !defined(NUM2)
        printf("错误：缺少宏定义");
    #endif

    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//