#include <stdio.h>

#define PLATFORM_LINUX

int main() {
#ifdef PLATFOR_WINDOWS
    printf("Running on Windows\n");
#elif defined(PLATFORM_LINUX)
    printf("Running on Linux\n");
#elif defined(PLATFORM_MACOS)
    printf("Running on macOS\n");
#else
    printf(""Unknown platform\n);
#endif

    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//
//#ifdef WIN32
//#error This Programme cannot compile at Windows Platform
//#endif

//#ifndef __cplusplus
//#error
//#endif