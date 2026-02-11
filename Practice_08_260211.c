#include <stdio.h>
int main() {
    int i, sum=0;
    for (i=1/*初始化表达式*/; i<=100/*条件表达式*/; i++/*更新表达式*/) {
        sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}

//
// Created by 14423 on 2026/2/11.
//