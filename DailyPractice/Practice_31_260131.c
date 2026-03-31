#include <stdio.h>

#define CONCAT1(a, b) a ## b
#define CONCAT2(a, b) a ## e ## b

int main() {
    int xy = 10;
    printf("%d\n", CONCAT1(x,y));

    printf("%.2f\n", CONCAT2(8.5, 2));

    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//