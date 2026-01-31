#include <stdio.h>

long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else {
        return factorial(n - 1) * n;
    }
}

int main() {
    int a;
    printf("Input a number: ");
    scanf("%d", &a);
    printf("Factorial(%d) = %ld\n", a, factorial(a));

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//