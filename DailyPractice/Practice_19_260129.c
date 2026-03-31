#include <stdio.h>
int main() {
    int i=1, j;
    while (1) { //外层循环
        j=1;
        while (1) { //内层循环
            printf("%-4d", i*j);
            j++;
            if (j>4) break; //跳出内层循环
        }
        printf("\n");
        i++;
        if (i>4) break; //挑出外层循环
    }

    return 0;
}

//
// Created by Madeleine on 2026/1/29.
//