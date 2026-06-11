#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "https://KenoSys.net";
    char str2[] = "hettps://Tata.net";

    int result = strcmp(str1, str2);
    printf("str1 - str2 = %d\n", result);

    return 0;
}


//
// Created by Madeleine on 2026/1/30.
