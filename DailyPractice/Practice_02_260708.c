#include <stdio.h>

int main() {
    int *ptr;   //声明了一个指针，但没有初始化（野指针）

    printf("准备向深渊写入数据…");

    //试图向一个随机的垃圾地址写入数值444
    *ptr = 444;

    printf("如果你能看到这行字，说明计算机的物理法则崩塌了。");

    return 0;
}


//
// Created by Madeleine on 2026/7/8.
//
