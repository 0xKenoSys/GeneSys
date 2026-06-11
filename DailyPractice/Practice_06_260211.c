#include <stdio.h>

int main() {
    int n, factorial = 1;
    int temp;

    printf("请输入一个正整数：");
    scanf("%d", &n);

    temp = n;
    while (temp > 0) {
        factorial *= temp;
        temp--;
    }
    printf("%d的阶乘是%d\n", n, factorial);

    return 0;
}

//在使用 while 循环时，有几点需要特别注意：

//1) 循环条件的更新：确保在循环体内更新循环条件中的变量，否则可能导致无限循环（死循环）。

//3) 循环条件的复杂性：while 循环的条件可以是任何有效的 C 表达式，比如一个数字、一个变量、一个函数调用、一个算术运算、一个关系运算，甚至，还能使用逻辑运算符拼接多个条件。例如：
//while (x > 0 && y < 100){
    //循环体
// }
//
//4) break 和 continue 语句：在循环体内，可以使用 break 语句立即退出循环，或使用 continue 语句跳过当前迭代的剩余部分，直接进入下一次迭代。
// Created by 14423 on 2026/2/11.
//