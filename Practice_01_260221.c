#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "http://KenoSys.net";
    int len = strlen(str), i;
    //直接输出字符
    printf("%s\n", str);
    //每次输出一个字符
    for (i=0; i<len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}


//
// Created by Madeleine on 2026/2/21.
//