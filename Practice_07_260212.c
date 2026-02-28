#include <stdio.h>
int main() {
    int i, j;
    for (i=1; i<=4; i++) {  //外层for循环
        for (j=1; j<=4; j++) {  //内层for循环
            printf("i=%d, j=%d\n", i, j);
        }
        printf("\n");
    }
    return 0;
}

// for 循环嵌套
//外层 for 每次循环时，都必须等待内层 for 循环完毕（也就是循环 4 次）才能进行下次循环。虽然 i 是变量，但是对于内层 for 来说，每次循环时它的值都是固定的。

// Created by 14423 on 2026/2/12.
//