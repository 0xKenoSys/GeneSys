#include <stdio.h>
#include <stdlib.h>
#include <time.h> //time函数所在头文件
int main() {
    int a, b;
    int randNumber;
    srand((unsigned)time(NULL));    //设置随机数种子，以产生不同随机数
    for (int i = 0; i<50; i++) {
        a = rand() % 7; //产生0-6的随机数
        b = rand() % 7; //产生0-6的随机数
        //TDO：在这里插入条件断点： a == b
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//