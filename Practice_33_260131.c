#include <stdio.h>

#define DEBUG_PRINT(level, fmt, ...) printf("DEBUG[" #level "]: " fmt "\n", ##__VA_ARGS__)

    int main() {
    int x = 10;
    double y = 20.5;
    DEBUG_PRINT(INFO, "x = %d", x);
    DEBUG_PRINT(WARNINGS, "y = %.2f", y);
    DEBUG_PRINT(ERROR, "Something went wrong!");
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//

//#define LONG_MACRO(x, y) \
    //do { \
        //int temp = (x) + (y); \
        //printf("Sum: %d\n", temp); \
    //}while(0)