#include <stdio.h>

int main() {
    int n, factorial = 1;
    int temp;

    printf("请输入一个正整数：");
    scanf("%d", &n);

    for (temp = n; temp > 0; temp--) {
        factorial *= temp;
    }
    printf("%d的阶乘是%d\n", n, factorial);

    return 0;
}

//
// Created by 14423 on 2026/2/12.
//

