#include <stdio.h>

int main() {
    struct bs {
        unsigned m: 6;
        unsigned n: 12;
        unsigned p: 4;
    };
    printf("%d\n", sizeof(struct bs));

    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//