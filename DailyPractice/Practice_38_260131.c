#include <stdio.h>

int main() {
#ifdef __STDC_VERSION__
    printf("C Standard version: %ld\n", __STDC_VERSION__);
#else
    printf("C Standard version information not available.\n");
#endif
    return 0;
}


//
// Created by Madeleine on 2026/1/31.
//