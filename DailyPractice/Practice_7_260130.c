#include <stdio.h>
int main() {
    int n;
    printf("Input string length: ");
    scanf("%d", &n);
    scanf("%*[^\n]"); scanf("%*c"); //清空输入缓冲区

    char str[n];
    printf("Input a string: ");
    gets(str);
    puts(str);

    return 0;
}

//int a[10];
//int b[3*5];
//int c[4+8];

//int m = 10, n;
//scanf("%d", &n);
//int a[m], b[n];
// Created by Madeleine on 2026/1/30.
//

//不对的写法：
//int n;
//int arr[n];
//scanf("%d", &n);

//正确的写法：
//int n;
//scanf("%d", &n);
//int arr[n];