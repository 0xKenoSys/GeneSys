#include<stdio.h>
#include<unistd.h>
int main () {
    printf("Hello Collin, ");
    fflush(stdout);
    sleep(2);
    printf("this is KenoSys.");

    return 0;
}




//我试试fflush(stdout);这个语句
// Created by Madeleine on 2026/1/26.
//如果不清空缓存，或者加换行符，两个字符串会同时在sleep过后输出