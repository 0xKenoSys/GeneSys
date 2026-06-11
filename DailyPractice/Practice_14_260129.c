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
    printf("%d 的阶乘是 %d\n", n, factorial);

    return 0;
}

//循环条件可以是任何有效地C表达式。
//while(x > 0 && y < 100){
    //循环体
//}
// Created by Madeleine on 2026/1/29.
//