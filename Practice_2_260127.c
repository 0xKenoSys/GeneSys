#include<stdio.h>
int main() {
    int number;

    printf("请输入一个整数：");
    scanf("%d", &number);

    if (number % 2==0) {
        //这是第一个代码块
        printf("%d 是偶数。\n", number);
    }else {
        //这是第二个代码块
        printf("%d 是奇数。\n", number);
    }

    return 0;
}



//
// Created by Madeleine on 2026/1/27.
//