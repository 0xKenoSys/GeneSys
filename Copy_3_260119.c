#include <stdio.h>
int main(){
    int n = 123456;
    double f = 882.923672;
    char *str = "abcdefghi";
    printf("n: %.9d  %.4d\n", n, n);
    printf("f: %.2lf  %.4lf  %.10lf\n", f, f, f);
    printf("str: %.5s  %.15s\n", str, str);
    return 0;
}
//.precision用法
// Created by Madeleine on 2026/1/19.
//