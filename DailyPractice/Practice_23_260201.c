#include <stdio.h>

int main() {
    int a[6] = {0, 1, 2, 3, 4, 5};
    int *p = a;
    int len_a = sizeof(a) / sizeof(int);
    int len_p = sizeof(p) / sizeof(int);
    printf("len_a = %d, len_p = %d\n", len_a, len_p);
    return 0;
}


// Created by Madeleine on 2026/2/1.
//教程的结果是len_p = 1。差别在哪？