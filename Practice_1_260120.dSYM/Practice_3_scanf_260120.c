#include<stdio.h>
int main() {
    int n;
    float f;
    char str[23];

    scanf("%2d", &n);
    //scanf("%*[^\n]"); scanf("%*c");
    scanf("%5f", &f);
    //scanf("%*[^\n]"); scanf("%*c");
    scanf("%22s", str);
    printf("n=%d, f=%g, str=%s\n", n, f,str);

    return 0;
}


// Created by Madeleine on 2026/1/20.
