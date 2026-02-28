#include <stdio.h>

int main() {
    int arr[] = { 99, 15, 100, 888, 252 };
    int len = sizeof(arr) / sizeof(int);
    int i;
    for (i=0; i<len; i++) {
        printf("%d ", *(arr+i) );
    }
    printf("\n");
    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//

//int arr[] = { 99, 15, 100, 888, 252 };
//int *p = arr;