#include<stdio.h>
    int main() {
        int n;
        int a=5;
        int b=9;
        double average;
        average = (double)a/b;
        char str[23];

        scanf("%d", &n);
        float m=average*(n-32);

        scanf("%*[^\n]"); scanf("%*c");
        scanf("%s",str);

        printf("Fahrenheit=[%8d] \n",n);
        printf("Celsius=[%0+8.2f] \n",m);
        printf("Collin=%s \n",str);
        printf("[塔塔是天才少女程序员]""[嘿嘿！]");

        return 0;

    }



//%0+8.2f
// Created by Madeleine on 2026/1/20.
//