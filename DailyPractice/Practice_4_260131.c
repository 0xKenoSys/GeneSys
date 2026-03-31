#include <stdio.h>

int sum(int m, int n) {
    int i, sum=0;

    for (i=m; i<=n; i++) {
        sum+=i;
    }
    return sum;
}

int main() {
    int begin = 5, end = 86;
    int result = sum(begin, end);
    printf("The sum from %d to %d is %d\n", begin, end, result);

    return 0;



}
//
// Created by Madeleine on 2026/1/31.
//