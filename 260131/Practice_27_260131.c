#include <stdio.h>

#define SQ(y)(y)*(y) //整个宏体两侧都要加括号

int main() {
    int a,sq;
    printf("input a number:");
    scanf("%d", &a);
    sq = 200 / SQ(a+1);
    printf("sq=%d\n", sq);
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//