#include <stdio.h>

int main() {
    int a = 100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
    printf("&p2 = %p, p3 = %p\n", &p2, p3);
    printf("&p1 = %p, p2 = %p, *p3 = %p\n", &p1, p2, *p3);
    printf(" &a = %p, p1 = %p, *p2 = %p, **p3 = %p", &a, p1, *p2, **p3);
    return 0;
}

//
// Created by Madeleine on 2026/2/25.
//