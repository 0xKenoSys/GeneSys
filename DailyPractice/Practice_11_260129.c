#include <stdio.h>

int main() {
    int i = 10;

    while (i < 5) {
        printf("This will never be printed\n");
        i++;
    }

    printf("Loop finished. i = %d\n", i);

    return 0;
}

//
// Created by Madeleine on 2026/1/29.
//