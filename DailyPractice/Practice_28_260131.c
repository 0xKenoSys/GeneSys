#include <stdio.h>

int square(int n) {
    return n * n;
}

int main() {
    int i=1;
    while (i <= 5) {
        printf("%d^2 = %d\n", (i-1), square(++i));
    }

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//