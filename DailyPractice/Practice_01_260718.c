#include "tlpi_hdr.h"

int main(int argc, char *argv[]) {
    int j;
    for (j = 0; j < argc; j++)
        printf("argv[%d] = %s\n", j, argv[j]);
    exit(EXIT_SUCCESS);
}

//
// Created by Yingmei Zhang on 18/7/2026.
//
