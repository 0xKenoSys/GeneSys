#include <stdio.h>
int main() {
    char c = 0;
    while (c!='\n') {   //提问：为什么程序遇到 while 时，变量 c 的值为'\0'？这个\是从哪里来的？
        c=getchar();
        if (c=='4'||c=='5') {
            continue;
        }
        putchar(c); //当读取到 4 或 5 时，if 的条件c=='4'||c=='5'成立，就执行 continue 语句，结束当前循环，直接进入下一次循环，也就是说putchar(c);不会被执行到。
    }
    return 0;
}
//continue 只是结束本次迭代（跳过当前迭代的剩余代码），直接进入下一次迭代；如果循环条件成立，整个循环还会继续执行。
//，一个 break/continue 只能作用于一个 while/for 循环，在内层循环中使用 break/continue 并不会影响外层循环。

//C语言 continue 关键字只能用在 while 和 for 循环中，它的作用是跳过当前迭代，进入下一次迭代。
//位于 continue 后面代码，在当前迭代（当前循环）中不会被执行，但循环并不会因此而终止，而是继续进行下一次迭代。
//continue 关键字常与 if else 语句一起使用，即满足条件时便跳过当前迭代。

// Created by 14423 on 2026/2/12.