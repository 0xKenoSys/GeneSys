#include <stdio.h>
int main() {
    char a = 't';
    char b = 'a';
    char c = 't';
    char d = 'a';

    char m = a+1;
    char n = b+1;
    char o = c+1;
    char p = d+1;


    printf("m: %c, %d\n", m, m);
    printf("n: %c, %d\n", n, n);
    printf("o: %c, %d\n", o, o);
    printf("p: %c, %d\n", p, p);

    printf("Original: %c\t, Secret: %c\t, Diff: %d", a, m, m-a);

    return 0;



}


//
// Created by Madeleine on 2026/1/17.
//把你自己的名字 "tata" 加密。
//1. 定义四个 char 变量，分别存 't', 'a', 't', 'a'。
//2. 把这四个变量分别加 1。
//3. 输出加密后的结果。

