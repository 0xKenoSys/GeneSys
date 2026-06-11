#include <stdio.h>
int main() {
    char str1[30] = {0};
    char str2[30] = {0};
    char str3[30] = {0};

    //gets()用法
    printf("Input a string: ");
    gets(str1); //warning: this program uses gets(), which is unsafe.

    //scanf()用法
    printf("Input a string: ");
    scanf("%s",str2);
    scanf("%s",str3);

    printf("\nstr1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//