#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a, i;
    for (i = 0; i < 10; i++) {
        srand((unsigned)time(NULL));
        a = rand();
        printf("%d ", a);
    }

    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//