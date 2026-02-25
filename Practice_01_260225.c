#include <stdio.h>

int main() {
    int a = 100;
    int *p1 = &a;
    int **p2 = &p1;
    int ***p3 = &p2;
    printf("%d, %d, %d, %d\n", a, *p1, **p2, ***p3);
    printf("&p2 = %p, p3 = %p\n", &p2, p3);
    printf("&p1 = %p, p2 = %p, *p3 = %p\n", &p1, p2, *p3);
    printf(" &a = %p, p1 = %p, *p2 = %p, **p3 = %p", &a, p1, *p2, **p3);
    return 0;
}

//运行结果：（64位操作系统，但实际只用低48位，所以十六进制字符是12位，高位全是0）（%#会省略高位的0）
//100, 100, 100, 100
//&p2 = 0x7ff7bc1941b8, p3 = 0x7ff7bc1941b8
//&p1 = 0x7ff7bc1941c0, p2 = 0x7ff7bc1941c0, *p3 = 0x7ff7bc1941c0
// &a = 0x7ff7bc1941c8, p1 = 0x7ff7bc1941c8, *p2 = 0x7ff7bc1941c8, **p3 = 0x7ff7bc1941c8
//
// Created by Madeleine on 2026/2/25.
//