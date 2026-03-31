#include <stdio.h>

void example_function() {
    printf("Current function: %s\n", __FUNCTION__);
}

int main() {
    example_function();
    printf("Current function: %s\n", __FUNCTION__);
    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//