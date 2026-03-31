#include <stdio.h>

long factorial(int n) {
    int i;
    long result=1;
    for (i=1; i<=n; i++) {
        result *= i;
    }
    return result;
}

long sum(long n) {
    int i;
    long result = 0;
    for (i=1; i<=n; i++) {
        result += factorial(i);
    }
    return result;
}

int main() {
    printf("1!+2!+...+9!+10! = %ld\n", sum(10));

    return 0;
}

//函数的调用
//函数作为表达式中的一项出现在表达式中
//z = max(x, y);
//m = n + max(x, y);
//函数作为一个单独的语句
//printf("%d", a);
//scanf("%d", &b);
//函数返回值作为另一个函数时的实参
//printf( "%d", max(x, y));
//total( max(x, y), min(m, n));

//
// Created by Madeleine on 2026/1/30.
//