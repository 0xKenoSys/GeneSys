#include <stdio.h>
#include <string.h>

char *reverse(char *str) {
    int len = strlen(str);
    if (len > 1) {
        char ctemp = str[0];
        str[0] = str[len - 1];
        str[len - 1] = '\0';

        reverse(str + 1);
        str[len - 1] = ctemp;
    }

    return str;
}

int main() {
    char str[20] = "123456789";
    printf("%s\n", reverse(str));
    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//