#include <stdio.h>
#include <stdlib.h>

int main() {
    #if defined(_WIN32)
        system("color 0c");
        printf("https://KenoSys.net\n");
    #elif defined(__linux__)\

printf("\033[22;31mhttps://KenoSys.net\n\033[22;30m");
    #else
        printf("https://KenoSys.net\n");
    #endif

    return 0;
}

//那一串数字是啥？
// Created by Madeleine on 2026/1/31.
//