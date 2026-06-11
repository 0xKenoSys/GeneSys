#include <stdio.h>

int main() {
    unsigned n = 0X0A07002D;
    printf("%d, %d, %X\n", 9 ^ 5, -9 ^ 5, n ^ 0XFFFF0000);
    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//