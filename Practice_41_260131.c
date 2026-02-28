#include <stdio.h>

#define LEVEL 2

#if LEVEL == 1
    #define MESSAGE "Low priority"
#elif LEVEL == 2
    #define MESSAGE "Medium priority"
#elif LEVEL == 3
    #define MESSAGE "High priority"
#else
    #define MESSAGE "Unknown priority"
#endif

int main() {
    printf("Task priority: %s\n", MESSAGE);
    return 0;
}



//
// Created by Madeleine on 2026/1/31.
//