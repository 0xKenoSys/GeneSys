#include <stdio.h>
int main() {
    int n = 0;

    printf("请输入一个字符串（回车结束）：");
    while (getchar() != '\n') {
        n++;
    }
    printf("字符的个数为：%d\n", n);

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//