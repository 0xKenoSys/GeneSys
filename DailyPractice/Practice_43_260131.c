#include <stdio.h>

#define DEBUG 1
#define VERBOSE_DEBUG 1

int main(){
#if DEBUG
    printf("Debug mode enabled.\n");
     #if VERBOSE_DEBUG
        printf("Verbose debug information will be displayed. \n");
    #endif
#else
    printf("Running in release mode.\n");
#endif
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//