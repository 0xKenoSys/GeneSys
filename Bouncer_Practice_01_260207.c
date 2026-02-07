#include <stdio.h>

int main() {
    int age;

    printf("请输入年龄：");
    scanf("%d", &age);

    if (age>=18 && age<=60) {
        printf("劳动力");
    }else {
        printf("其他");
    }
    return 0;
}

//第一关：基础安检 (The Bouncer)
//题目： 编写一个程序，要求用户输入一个整数代表“年龄”。
//* 如果年龄 大于等于 18 且 小于等于 60，打印 "Worker"（劳动力）。
//* 否则，打印 "Other"。
//* 考点： 这种连续区间判断，千万别写成 18 <= age <= 60（这是数学写法，C 语言里是错的），要用 &&。

// Created by Madeleine on 2026/2/7.
//