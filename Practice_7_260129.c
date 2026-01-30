#include <stdio.h>
int main() {
    int a, b;
    printf("输入两个整数：");
    scanf("%d %d", &a, &b);
    printf("较大的数字是：%d\n", a > b ? a : b);

    return 0;
}


//条件运算符：
//max = (a>b) ? a : b;
//max = a>b ? a : b;

//a>b a : c>d ? c : d;
//a>b ? a : ( c>d ? c : d );
//
//
// Created by Madeleine on 2026/1/29.
//