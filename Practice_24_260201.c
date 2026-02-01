#include <stdio.h>
int main() {
    int a = 16, b = 932, c = 100;
    int *arr[3] = {&a, &b, &c};
    int **parr = arr;
    printf("%d, %d, %d\n", *arr[0], *arr[1], *arr[2]);
    printf("%d, %d, %d\n", **(parr+0), **(parr+1), **(parr+2));

    return 0;

}

//int a = {1, 2, 3, 4, 5}, *p, i = 2;

//void func(int *parr){......}
//void func(int arr[]){......}
//void func(int arr[5]){......}

//dataType*arrayName[length];

//dataType*(arrayName[length]);






//
// Created by Madeleine on 2026/2/1.
//