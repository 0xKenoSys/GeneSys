#include <stdio.h>
int main() {
    int i=1, sum=0;
    while (1) {
        sum+=i;
        i++;
        if (i>100) break;   //结束死循环
    }
    printf("%d\n", sum);
    return 0;
}

//
// Created by 14423 on 2026/2/12.
//一次循环称为一次迭代，例如 for(int i=1; i<=10; i++) 会循环 10 次，所以有 10 次迭代。
//我们经常需要提前结束循环（在循环条件成立的情况下强制结束循环），或者跳过某些迭代，此时就可以使用 break 或者 continue 关键字。