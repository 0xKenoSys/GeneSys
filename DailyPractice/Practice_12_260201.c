#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[20] = {0};
    int i;

    for (i=0; i<10; i++) {
        *(str+i) = 97+i;
    }

    printf("%s\n", str);
    printf("%s\n", str+2);
    printf("%c\n", str[2]);
    printf("%c\n", (str+2)[2]);

    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//