#include <stdio.h>
int main() {
    char a = '1';
    char b = '$';
    char c = 'X';
    char d = ' ';
    //使用 putchar 输出
    putchar(a); putchar(d);
    putchar(b); putchar(d);
    putchar(c); putchar('\n');
    //使用 printf 输出
    printf("%c %c %c\n", a, b, c);
    return 0;
}

//
// Created by Madeleine on 2026/1/17.
//