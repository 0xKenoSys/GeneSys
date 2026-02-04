#include <stdio.h>

int main() {
    int number;

    printf("请输入一个整数：");
    scanf("%d", &number);

    if (number % 2 == 0) {  //f 语句检查条件number % 2 == 0，如果它的结果为真，则执行第一个代码块，否则执行 else 后的代码块。
        //这是第一个代码块。代码块，也即{ }中的代码
        printf("%d 是偶数。\n", number);
    } else {
        //这是第二个代码块
        printf("%d 是奇数。\n", number);
    }

    return 0;
}

//
// Created by Madeleine on 2026/2/4.
// if else 语句、switch case 语句、三目运算符? :。实现分支结构