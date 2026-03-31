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


//go to语句的用法如下：
//向后跳转
//goto 标签名;
//...
//标签名：语句；

//或者
//向前跳转
//标签名：语句;
//...
//goto 标签名；




// Created by Madeleine on 2026/1/29.
//