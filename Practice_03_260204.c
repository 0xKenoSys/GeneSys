#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 1; i <= 100; i++) {  //for 循环初始化变量 i 为 1,直到 i 大于 100 时停止,每次循环 i 增加 1
        //这是重复执行的代码块
        sum += i; //循环体内将每次的 i 值加到 sum 中
    }

    printf("1 到 100 的和是： %d\n", sum);

    return 0;
}


//
// Created by Madeleine on 2026/2/4.
//
//遍历数组、计算累加的和、分析每一条日志,等需要重复执行的任务，适合用循环结构处理。它允许程序重复地执行某个代码块，直到满足特定的条件才会终止。
// for 循环、while 循环和 do while 循环，是c语言提供的三种主要循环结构