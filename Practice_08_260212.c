#include <stdio.h>
int main() {
    int i, j;
    for (i=1; i<=4; i++) {  //外层for循环
        for (j=1; j<=4; j++) {  //内层for循环
            printf("%-4d", i*j);
        }
        printf("\n");
    }
    return 0;
}

//
// Created by 14423 on 2026/2/12.
//