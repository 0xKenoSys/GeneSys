#include <stdio.h>
int main() {    //提问一：为什么说内层循环共执行了 4 次，外层循环共执行了 1 次？
    int i=1, j;
    while (1) { //外层循环
        j=1;    //提问二：为什么给j赋值在这个位置？
        while (1) { //内层循环
            printf("%-4d", i*j);
            j++;
            if (j>4) break; //跳出内层循环
        }
        printf("\n");
        i++;
        if (i>4) break; //跳出外层循环
    }
    return 0;
}

//
// Created by 14423 on 2026/2/12.
//一个 break 只能跳出一个 while/for 循环。这意味着在多层循环中，一个 break 语句只向外跳出一层；如果需要跳出多层循环，那么每层循环都需要一个 break 语句。