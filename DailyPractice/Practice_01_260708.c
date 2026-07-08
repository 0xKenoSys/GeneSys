#include <stdio.h>

int main() {
     //声明一个字符指针，指向一个字符串常量
     char *str = "Happy Hacking";

     printf("准备执行越界写操作…");

     //企图修改字符串的第一个字符
     //这行代码执行的瞬间会被操作系统干掉
     str[0] =  'h';

     //这一行永远没机会被打印
     printf("修改成功：%s \n", str);

     return 0;
}



//
// Created by Madeleine on 2026/7/8.
//
