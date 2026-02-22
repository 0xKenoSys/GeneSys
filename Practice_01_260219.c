#include <stdio.h>
int main() {
    int    a = 10, *pa = &a, *paa = &a;
    double b = 99.9, *pb = &b;
    char c = '@', *pc = &c;
    //最初的值
    printf("&a=%p, &b=%p, &c=%p\n", &a, &b, &c);
    printf("pa=%p, pb=%p, pc=%p\n", pa, pb, pc);
    //加法运算
    pa++; pb++; pc++;
    printf("pa=%p, pb=%p, pc=%p\n", pa, pb, pc);
    //减法运算
    pa -= 2; pb -= 2; pc -= 2;
    printf("pa=%p, pb=%p, pc=%p\n", pa, pb, pc);
    //比较运算
    if (pa == paa) {
        printf("%d\n", *paa);
    }else {
        printf("%d\n", *pa);
    }
    return 0;
}

//标准的指针打印符%p
//或者类型转换uintptr_t或者unsigned long
// Created by Madeleine on 2026/2/19.
//