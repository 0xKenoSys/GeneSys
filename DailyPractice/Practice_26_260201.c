#include <stdio.h>
int main() {
    char *str0 = "KenoSys.net";
    char *str1 = "0xKenoSys";
    char *str2 = "KenoSys";
    char *str[3] = {str0, str1, str2};
    printf("%s\n%s\n%s\n", str[0], str[1], str[2]);
    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//