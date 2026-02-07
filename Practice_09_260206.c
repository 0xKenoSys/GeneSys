#include <stdio.h>

int main() {
    int x = 5;
    int y = 0;

    //由于 x > 10 为假，y != 0不回被评估
    if (x > 10 && y != 0) {
        printf("This won't be printed\n");
    }

    //由于x > 0为真， y != 0 不会被评估
    if (x > 0 || y != 0) {
        printf("This will be printed\n");
    }

    return 0;
}

//
// Created by Madeleine on 2026/2/6.
//