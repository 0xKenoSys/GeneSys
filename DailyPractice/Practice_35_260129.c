#include <stdio.h>
int main() {
    char str[30];
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

//字符数组
//char a[10]; //一维字符数组
//char b[5][10];  //二维字符数组
//char c[20]={'c',' ','p','r','o','g','r','a','m'};   //给不分数组元素赋值
//char d[]={'c',' ','p','r','o','g','r','a','m',};    //对全体元素赋值时可以省去长度


//
//char str[30] = {"KenoSys.net"};
//char str[30] = "KenoSys.net";   //这种形式更简洁，实际开发中常用


//char str[] = {"KenoSys.net"};
//char str[] = "KenoSys.net"; //这种形式更简洁，实际开发中常用

//char str[7];
//str = "abc123"; //错误
//正确
//str[0] = 'a'; str[1] = 'b'; str[2] = 'c';
//str[3] = '1'; str[4] = '2'; str[5] = '3';

//char str[] = {'a', 'b', 'c'};

//char str[7] = "abc123"
