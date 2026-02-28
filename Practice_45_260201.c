#include <stdio.h>
int main(){
    union {
        int n;
        char ch;
    }data;

    data.n = 0x00000001; //也可以直接写作0
    if (data.ch == 1) {
        printf("Little-endian\n");
    }else {
        printf("Big-endian\n");
    }
    return 0;

}

//
// Created by Madeleine on 2026/2/1.
//