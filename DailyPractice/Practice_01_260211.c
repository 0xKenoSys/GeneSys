#include <stdio.h>
int main() {
    int i = 1, sum = 0;
    while (i <= 100) {
        sum += i;
        i++;
    }
    printf("1加到100的和为: %d\n", sum);

    return 0;
}


//while 循环用法
//while (条件)
//{
    // 循环体
    // 也即要重复执行的代码
//}
// Created by 14423 on 2026/2/11.
//