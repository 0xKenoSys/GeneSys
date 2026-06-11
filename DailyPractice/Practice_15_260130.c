#include <stdio.h>

int sum(int m, int n) {
    int i;
    for (i = m+1; i <= n; ++i) {
        m += i;
    }
    return m;
}

int main() {
    int a, b, total;
    printf("Input two numbers: ");
    scanf("%d %d", &a, &b);
    total = sum(a, b);
    printf("a=%d, b=%d\n", a, b);
    printf("total=%d\n", total);

    return 0;
}

//可以将常量、表达式、函数返回值作为实参
//total = sum(10,98);
//total = sum(a+10, b-3);
//total = sum( pow(2,2), abs(-100));
// Created by Madeleine on 2026/1/30.
//