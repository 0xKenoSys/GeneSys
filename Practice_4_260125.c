#include<stdio.h>
int main() {
    char str[31];//读取一行不能包含十进制数字的字符串，并且长度不能超过 "30" 实际能读的比定义少一位，因为结束用的\0
    scanf("%30[^0-9\n]",str);//不读数字：^0-9
    printf("str:%s",str);

    return 0;
}


//
// Created by Madeleine on 2026/1/25.
//