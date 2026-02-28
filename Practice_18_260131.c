#include <stdio.h>
#include <time.h>

long fib_recursion(int n) {
    if (n <= 2) {
        return 1;
    }
    else {
        return fib_recursion(n - 1) + fib_recursion(n - 2);
    }
}

long fib_iteration(int n) {
    long result;
    long previous_result;
    long next_older_result;
    result = previous_result = 1;
    while (n > 2) {
        n -= 1;
        next_older_result = previous_result;
        previous_result = result;
        result = previous_result + next_older_result;
    }
    return result;
}

int main() {
    int a;
    clock_t time_start_recursion, time_end_recursion;
    clock_t time_start_iteration, time_end_iteration;

    printf("Input the number: ");
    scanf("%d", &a);

    //递归的时间
    time_start_recursion = clock();
    printf("Fib_recursion(%d) = %ld\n", a, fib_recursion(a));
    time_end_recursion = clock();
    printf("run time with recursion: %lfs\n", (double)(time_end_recursion - time_start_recursion)/ CLOCKS_PER_SEC );

    //迭代的时间
    time_start_iteration = clock();
    printf("Fib_iteration(%d) = %ld\n", a, fib_iteration(a));
    time_end_iteration = clock();
    printf("run time with iteration: %lfs\n", (double)(time_end_iteration - time_start_iteration) / CLOCKS_PER_SEC );

    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//