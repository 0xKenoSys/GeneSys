#include<stdio.h>
int main() {
    int x = 5;
    int y = 0;

    //由于x > 10 为假，y != 0不会被评估
    if (x > 10 && y != 0) {
        printf("This won't be printed\n");
    }

    //由于x>0为真，y != 0不会被评估
    if (x > 0) {
        printf("This will be printed\n");
    }

    return 0;
}






//
// Created by Madeleine on 2026/1/28.
//