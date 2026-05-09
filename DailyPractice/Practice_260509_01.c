#include <stdio.h>

int main() {
    int *arr[5];
    printf("单个指针的大小： %zu 字节\n ", sizeof(arr[0]));
    printf("整个指针数组的大小：%zu 字节\n", sizeof(arr));
    return 0;
}


//
// Created by Madeleine on 2026/5/9.
//
