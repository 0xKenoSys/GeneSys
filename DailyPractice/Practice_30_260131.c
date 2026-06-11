#include <stdio.h>

#define PRINT_VAR(x) printf(#x " = %d\n", x)

int main() {
    int age = 25;
    PRINT_VAR(age);
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//

//#define STRINGIFY(x) #x
//printf("%s\n", STRINGIFY(Hello  "World" \n));