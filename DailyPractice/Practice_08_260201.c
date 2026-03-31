#include <stdio.h>
#include <string.h>

int main() {
    char *str = "https://KenoSys.net";
    int len = strlen(str), i;

    printf("%s\n", str);

    for (i=0; i<len; i++) {
        printf("%c", *(str+i));
    }
    printf("\n");

    for (i=0; i<len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//