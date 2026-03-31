#include <stdio.h>
int main() {
    int n = 22;
    {
        int n = 40;
        printf("block n: %d\n", n);
    }
    printf("main n: %d\n", n);

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//