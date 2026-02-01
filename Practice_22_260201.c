#include <stdio.h>

int main() {
    char *str = (char *)malloc(sizeof(char) *30);
    gets(str);
    printf("%s\n", str);
    return 0;
}

//为什么malloc报错，系统不兼容吗？
// Created by Madeleine on 2026/2/1.
//