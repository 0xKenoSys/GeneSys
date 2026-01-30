#include <stdio.h>
int main()
{
    short a = 0b1010;  //二进制数字
    int b = 012;  //八进制数字
    long c = 0XA;  //十六进制数字
    long long d = 10;
    printf("a=%#ho, b=%#o, c=%#lo, d=%#llo\n", a, b, c, d);  //以八进制形似输出
    printf("a=%hd, b=%d, c=%ld, d=%lld\n", a, b, c, d);  //以十进制形式输出
    printf("a=%#hx, b=%#x, c=%#lx, d=%#llx\n", a, b, c, d);  //以十六进制形式输出（字母小写）
    printf("a=%#hX, b=%#X, c=%#lX, d=%#llX\n", a, b, c, d);  //以十六进制形式输出（字母大写）
    return 0;
}

//
// Created by Madeleine on 2026/1/15.
//