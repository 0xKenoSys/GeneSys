#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int a;
    srand((unsigned)time(NULL));
    a = rand();
    printf("%d\n", a);
    return 0;
}

//我去，无限熵增啊！
// Created by Madeleine on 2026/2/3.
//