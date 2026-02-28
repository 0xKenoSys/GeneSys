#include <stdio.h>
#include <ctype.h>

int main() {
    char ch = 0;

    printf("请输入一个英文字母：");
    scanf("%c", &ch);
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        printf("%c 是元音字母\n", ch);
    }else {
        printf("%c 不是元音字母\n", ch);
    }

    return 0;
}


//
// Created by Madeleine on 2026/1/28.
//