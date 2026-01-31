#include <stdio.h>

#define SQUARE(n)((n)*(n))

int main () {
    int i = 1;
    while (i <= 5) {
        printf("%d^2 = %d\n", i, SQUARE(++i));
    }

    return 0;
}


//为什么和教程的运行结果不一样呢
// Created by Madeleine on 2026/1/31.
//