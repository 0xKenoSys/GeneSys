#include <stdio.h>
int main () {
    char grade;//想输入ABCD，那变量是个char
    printf("Input the grade:");
    scanf(" %c", &grade);//%c前面加个空格，预防缓冲区里的回车符

    switch (grade) {
        case 'A':
        case 'B':
        case 'C':
            printf("牛逼！\n");
            break;
        case 'D':
        case 'E':
            printf("也牛逼！\n");
            break;
        default:
            printf("show me new bee!\n");
    }

    return 0;
}


//贯穿现象：让多个 case 执行相同的代码。没遇到break就一直往下滚
// Created by Madeleine on 2026/1/29.
//