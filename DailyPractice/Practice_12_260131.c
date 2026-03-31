#include <stdio.h>

int m = 13;
int n = 10;

void func1() {
    int n = 20;
    {
        int n = 822;
        printf("block1 n: %d\n", n);
    }
    printf("func1 n: %d\n", n);
}

void func2(int n) {
    for (int i=0; i<10; i++) {
        if (i % 5 == 0) {
            printf("if m: %d\n", m);
        }else {
            int n = i % 4;
            if (n<2 && n>0) {
                printf("else m: %d\n", m);
            }
        }
    }
    printf("func2 n: %d\n", n);
}

void func3() {
    printf("func3 n: %d\n", n);
}

int main() {
    int n = 30;
    func1();
    func2(n);
    func3();
    printf("main n: %d\n", n);

    return 0;
}
//
// Created by Madeleine on 2026/1/31.
//