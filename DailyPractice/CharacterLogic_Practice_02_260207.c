#include <stdio.h>
int main() {
    char n;
    printf("输入一个字符：");
    scanf("%c", & n);   //提问：%c就是'X'吗？

    if (('A' <= n) && (n <= 'Z')) {     //不能写成'n' <= 'Z'，这就是n这个字母本体对应的死数字
        printf("1");
    }else {
        printf("0");
    }
    return 0;
}


//为什么条件'A' <= 'n'是无效的

//第二关：ASCII 密码锁 (Character Logic)
//题目： 编写一个程序，输入一个字符 ch。
//* 判断这个字符是不是 “大写字母”。
//* 提示： 利用 ASCII 码的顺序。如果 ch 在 'A' 和 'Z' 之间（包含边界），就是大写。
//* 输出： 是则输出 1，否则输出 0。

// Created by Madeleine on 2026/2/7.
//