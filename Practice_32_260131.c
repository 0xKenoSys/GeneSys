#include <stdio.h>

#define FUNCTION_NAME(name) my_func_ ## name

void my_func_hello() {
    printf("Hello from my_func_hello!\n");
}

int main() {
    FUNCTION_NAME(hello)();
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//