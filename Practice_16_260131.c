#include <stdio.h>

long sum(int n) {
    int arr[250];

    if (n <= 1) {
        return n;
    }else {
        return n + sum(n-1);
    }
}

int main() {
    printf("从1 加到1000的值为%ld\n", sum(1000));
    return 0;
}
//
// Created by Madeleine on 2026/1/31.
//