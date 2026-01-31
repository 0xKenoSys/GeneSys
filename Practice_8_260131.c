#include <stdio.h>

int gcd(int a, int b);

    int main() {
        printf("The greatest common divisor is %d\n", gcd(100, 60));
        return 0;
    }

    int gcd(int a, int b) {

        if (a < b) {
            int temp1 = a;
            a = b;
            b = temp1;
        }

        //while (b!=0) {
            //int temp1 = a;
            //a = b;
            //b = temp1;
        //}
        //这一段我照着教程打，结果是死循环

        while (b!=0) {
            int temp2 = b;
            b = a % b;
            a = temp2;
        }

        return a;

}

//
// Created by Madeleine on 2026/1/31.
