#include "tlpi_hdr.h"
int main(int argc, char *argv[]) {
    char **p;

    for (p = argv; *p != NULL; p++)
        puts(*p);

    exit(EXIT_SUCCESS);
}

//
// Created by Yingmei Zhang on 18/7/2026.
//
