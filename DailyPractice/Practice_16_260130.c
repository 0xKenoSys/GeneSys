#include <stdio.h>

int sum(int m, int n) {
    int i;
    for (i = m + 1; i <= n; ++i) {
        m += i;
    }
    return m;
}

int main() {
    int m, n, total;
    printf("Input two numbers: ");
    scanf("%d %d", &m, &n);
    total = sum(m, n);
    printf("m=%d, n=%d\n", m, n);
    printf("total=%d\n", total);

    return 0;
}

//
// Created by Madeleine on 2026/1/30.
//