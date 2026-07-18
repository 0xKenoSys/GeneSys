#include "tlpi_hdr.h"

extern char **environ;

int main(int argc, char *argv[]) {
    char **ep;

    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);

    exit(EXIT_SUCCESS);

}


//
// Created by Yingmei Zhang on 19/7/2026.
//
