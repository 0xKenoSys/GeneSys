#include <stdio.h>

int main() {
#ifdef _WIN32
    printf("This code is compiled for Windows.\n");
#elif defined(__linux__)
    printf("This code is compiled for Linux.\n");
#elif defined(__APPLE__)
    printf("This code is compiled for macOS.\n");
#else
    printf("Unknown platform.\n");
#endif
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//