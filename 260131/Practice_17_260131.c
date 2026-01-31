#include <stdio.h>
#include <time.h>

long fib(int n) {
    if (n <= 2) {
        return 1;
    }
    else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int a;
    clock_t time_start, time_end;

    printf("Input a number: ");
    scanf("%d", &a);
    time_start = clock();
    printf("Fib(%d) = %ld\n", a, fib(a));
    time_end = clock();
    printf("run time: %lfs\n",(double)(time_end - time_start)/CLOCKS_PER_SEC );
}
//
// Created by Madeleine on 2026/1/31.
//