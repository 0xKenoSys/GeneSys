#include <stdio.h>

#define M 20
#define N 40

int main() {
#if M+N>100
    printf("The value is too large.\n",);
#elif M+N<=100 && M+N>50
    printf("The value is right.\n");
#else
    printf("The value is too small.\n");
#endif

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//