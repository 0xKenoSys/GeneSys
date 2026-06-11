#include <stdio.h>
int main() {
    int str[100];
    printf("Enter a sentence:\n");
    if (fgets(str, sizeof(str), stdin) != NULL) {
        printf("%s\n", str);
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/27.
//