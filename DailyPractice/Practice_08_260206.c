#include <stdio.h>
int main() {
    char c='k';
    int i=1, j=2, k=3;
    float x=3e+5, y=0.85;
    printf("%d, %d\n", !x*!y, !!!x );
    printf("%d, %d\n", x||i&&j-3, i<j&&x<y );
    printf("%d, %d\n", i==5&&c&&(j=8), x+y||i+j+k );
    return 0;
}

//优先级从低到高依次是:|| < && < !
//赋值运算符= < 逻辑运算符|| < 逻辑运算符&& < 关系运算符 < 算术运算符 < 逻辑运算符!

//
// Created by Madeleine on 2026/2/6.
