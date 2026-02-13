#include <stdio.h>

int main() {
    int i = 0;

    start:
    printf("%d ", i);
    i++;

    if (i < 5) {
        goto start;
    }

    printf("\nLoop finished.\n");
    return 0;
}

//goto语句的用法如下：
//向后/前跳转：
//标签名：语句；
//...
//goto标签名
// Created by 14423 on 2026/2/13.
//