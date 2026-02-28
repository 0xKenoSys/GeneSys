#include <stdio.h>
int main() {
    int a = 15, b = 99, c = 222;
    int *p = &a;    //定义指针变量
    *p = b; //通过指针变量修改内存上的数据
    c = *p; //通过指针变量获取内存上的数据
    printf("%d, %d, %d, %d\n", a, b, c, *p);
    return 0;
}

//
// Created by Madeleine on 2026/2/18.
//