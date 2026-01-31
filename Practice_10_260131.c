#include <stdio.h>
#include <string.h>

int strchar(char *str, char c);

int main() {
    char url[] = "https://KenoSys.net";
    char letter = 'K';
    if (strchar(url, letter) >= 0) {
        printf("The letter is in the string.\n");
    }else {
        printf("The letter is not in the string.\n");
    }
    return 0;
}

int strchar(char *str, char c) {
    for (int i=0, len=strlen(str); i<len; i++) {
        if (str[i] == c) {
            return i;
        }
    }

    return -1;
}

//
// Created by Madeleine on 2026/1/31.
//