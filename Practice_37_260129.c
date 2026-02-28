#include <stdio.h>
int main() {
    char str[30] = {0}; //将所有元素都初始化为0,或者说'\0'
    char c;
    int i;
    for (c=65, i=0; c<=90; c++, i++) {
        str[i] = c;
    }
    printf("%s\n", str);

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//