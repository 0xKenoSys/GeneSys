#include <stdio.h>

int *func() {
    int n = 100;
    return &n;
}

int main() {
    int *p = func(), n;
    n = *p;
    printf("value = %d\n", n);
    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//