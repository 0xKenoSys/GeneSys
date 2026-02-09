#include <stdio.h>

void success() {
    puts("Succeed!");
}

void fail() {
    puts("Failed");
}
int main() {
    int isOK = 1;       //1表示真，0表示假
    isOK ? success() : fail();
    return 0;
}
//使用条件表达式来决定调用哪个函数。
// Created by Madeleine on 2026/2/9.
//