#include <stdio.h>

int main() {
    int a,b,c;

    printf("请输入三角形的三个边：");
    scanf("%d %d %d", &a, &b, &c);

    if ((a+b>c) && (a+c>b) && (b+c>a)) {    //代码是给人读的，一定要加括号增加可读性
        printf("Yes");
    }else {
        printf("No");
    }
    return 0;
}

//if()内每个式子的括号好像是不必要的

//第六关：三角形法则 (Geometry Check)
//题目： 输入三个整数 a, b, c 代表三条边。
//* 判断这三条边能否组成一个三角形。
//* 数学原理： 任意两边之和必须大于第三边。即 (a+b>c) 且 (a+c>b) 且 (b+c>a)。
//* 输出： 能组成输出 "Yes"，不能输出 "No"。
// Created by Madeleine on 2026/2/7.
//