#include <stdio.h>
int main() {
    char str[30];
    char c;
    int i;
    for (c=65, i=0; c<=90; c++, i++) {
        str[i] = c;
    }
    str[i] = 0; //此处为添加的代码，也可以写作 str[i] = '\0';

    printf("%s\n",str);

    return 0;
}
//
// Created by Madeleine on 2026/1/29.
//