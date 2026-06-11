#include <stdlib.h>
#include <stdio.h>
int main() {
    while (1) { //死循环
        malloc(1024);   //分配1024个字节的内存
    }

    return 0;
}


//是不是Windows才能跑
// Created by Madeleine on 2026/1/29.
//