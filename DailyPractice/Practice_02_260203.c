#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a;
    srand((unsigned)time(NULL));
    a = rand() % 51 + 13;
    printf("%d\n",a);
    return 0;
}


//
// Created by Madeleine on 2026/2/3.
//int a = rand() % 10;

//int a = rand() % 51 + 13;