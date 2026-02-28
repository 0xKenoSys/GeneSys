#include <stdio.h>
int main () {
    int i = 1, sum = 0;
    do {
        sum += i;
        i++;
    }while (i <= 100);
    printf("1加到100的和为：%d\n", sum);

    return 0;
}



//
// Created by Madeleine on 2026/1/29.
//