#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 0;

    printf("请输入一个英文字母：");
    scanf("%c", &ch);
    ch = tolower(ch);   //转换为小写字母

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        printf("%c是元音字母\n", ch);
    }else {
        printf("%c不是元音字母\n", ch);
    }

    return 0;
}

//
// Created by Madeleine on 2026/2/6.
//