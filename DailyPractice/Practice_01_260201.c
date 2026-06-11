#include <stdio.h>

int main () {
    int a = 1, b = 2, c = 3;
    int *p = &c;
    int i;
    for (i=0; i<8; i++) {
        printf("%d, ", *(p+i) );
    }
    return 0;
}
//
// Created by Madeleine on 2026/2/1.
//