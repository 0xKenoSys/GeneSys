#include <stdio.h>
int main() {
    int a = 5;
    int b = 10;
    if (a > 10 && (b = 20)) {
        printf("Entered\n");
    }
    printf("b = %d\n", b);

    return 0;
}

//b就是b，输出为10
//题目里的条件相当于是if(0 && 0)  //不对，应该是if(0 && 20[被屏蔽的操作])

//第四关：陷阱题·短路测试 A (Short-Circuit Trap I)
//题目： 不要上机运行，先口算（或者手写）出结果，然后再去 CLion 验证。
//int a = 5;
//int b = 10;
//if (a > 10 && (b = 20)) {
//printf("Entered\n");
//}
//printf("b = %d\n", b);
//* 问： 最后打印出来的 b 是多少？是 10 还是 20？为什么？

// Created by Madeleine on 2026/2/7.
//