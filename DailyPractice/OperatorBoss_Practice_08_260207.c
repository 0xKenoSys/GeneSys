#include <stdio.h>
int main() {
    int a = 1, b = 2, c = 3, d = 4;

    if ((a + b > c) && (b != c) || !(d > a)) {
        printf("1");
    }else {
        printf("0");
    }
    return 0;

}

//a + b > c的运算结果是0，我觉得打印结果应该是0，为什么打印结果是1？

//第八关：最终 Boss (The Operator Boss)
//题目： 这是一个大杂烩，考察你对优先级的绝对掌控。
//int a = 1, b = 2, c = 3, d = 4;
//int result = (a + b > c) && (b != c) || !(d > a);

//* 问： result 的值最终是 1 (True) 还是 0 (False)？
//* 步骤：
  //* 先算算术 +。
  //* 再算关系 >, !=。
  //* 再算逻辑非 !。
  //* 最后算 && 和 ||。

// Created by Madeleine on 2026/2/7.
//