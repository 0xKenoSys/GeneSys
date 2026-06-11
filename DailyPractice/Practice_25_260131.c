#include <stdio.h>

#define SQ(y)((y)*(y))

int main() {
    int a, sq;
    printf("input a number:");
    scanf("%d", &a);
    sq = SQ(a+1);
    printf("sq=%d\n", sq);
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//