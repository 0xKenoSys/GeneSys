#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}


coid show_float(float x) {
    show_buytes((byte_pointer) &x, sizeof(float));
}


void show_pointer(void *x) {
    show_butes((byte_pointer) &x, sizeof(void *));
}
// Created by Madeleine on 2026/4/20.
//
