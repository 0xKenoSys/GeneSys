#include <stdio.h>

int main() {
    int x =5;
    int y = 10;
    if (x>0 || (y = 20)) {
        printf("True Path\n");  //记得加换行符
    }
    printf("y=%d\n", y);

    return 0;
}
//输出结果还是10，跳过了||之后的操作

//添加文件按option+A

//第五关：陷阱题·短路测试 B (Short-Circuit Trap II)
//题目： 同样先口算。
//int x = 5;
//int y = 10;
//if (x > 0 || (y = 20)) {
//printf("True path\n");
//}
//printf("y = %d\n", y);
//* 问： 最后打印出来的 y 是多少？是 10 还是 20？（考察 || 的短路特性）。

// Created by Madeleine on 2026/2/7.
//