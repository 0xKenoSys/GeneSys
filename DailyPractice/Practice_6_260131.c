#include <stdio.h>

void func_a() {
    int n = 100;
    printf("func_a: n = %d\n", n);
    n = 86;
    printf("func_a: n = %d\n", n);
}

void func_b() {
    int n = 29;
    printf("func_b: n = %d\n", n);
    func_a();
    printf("func_b: n = %d\n", n);
}

int main() {
    func_b();
    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//