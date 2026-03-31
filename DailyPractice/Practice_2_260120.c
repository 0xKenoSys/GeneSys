#include<stdio.h>
    int main() {
        printf("输出字符：%c %c \n",'a', 65);
        printf("输出十进制数：%d %ld \n",1980,180000L);
        printf("用空格填充：%10d \n",1980);
        printf("用0填充：%010d \n",1980);
        printf("输出不同进制：%d %x %o %#x %#o \n",100,100,100,100,100);
        printf("输出小数：%4.2f %+.0e %E \n",3.1416,3.1416,3.1416);
        printf("指定宽度：%*d \n", 10,1980);
        printf("输出字符串：%s \n", "Ilsa she wolf of the SS");

        return 0;
    }



//
// Created by Madeleine on 2026/1/20.
//