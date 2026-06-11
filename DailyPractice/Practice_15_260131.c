#include <stdio.h>

long fib(int n) {
    if (n <= 2) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int a;
    printf("Input a number: ");
    scanf("%d", &a);
    printf("Fib(%d) = %ld\n", a, fib(a));

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//