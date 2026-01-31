#include <stdio.h>

int main() {
#ifdef __STDC__
    printf("This compiler conforms to the ISO C standard. \n");
#else
    printf("This compiler may not conferm to the ISO C standard. \n");
#endif
    return 0;
}



//
// Created by Madeleine on 2026/1/31.
//