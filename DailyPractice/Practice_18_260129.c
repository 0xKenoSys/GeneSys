#include <stdio.h>
int main() {
    int i=1, sum=0;
    while (1) {
        sum+=i;
        i++;
        if (i>100) break;
    }

    printf("%d\n", sum);
    return 0;
}



//
// Created by Madeleine on 2026/1/29.
//