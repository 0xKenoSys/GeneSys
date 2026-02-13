#include <stdio.h>
int main() {
    int i, j;
    for (i=1; i<=9; i++) {
        for (j=1; j<=i; j++) {
            printf("%d*%d=%-2d  ", i, j, i*j );
        }
        printf("\n");
    }
    return 0;
}

//
// Created by 14423 on 2026/2/12.
//