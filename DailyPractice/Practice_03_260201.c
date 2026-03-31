#include <stdio.h>

int main() {
    int arr[] = { 99, 15, 100, 888, 252 };
    int i, *p = arr, len = sizeof(arr) / sizeof(int);

    for (i=0; i<len; i++) {
        printf("%d ", *(p+1) );
    }
    printf("\n");
    return 0;
}


//
// Created by Madeleine on 2026/2/1.
//