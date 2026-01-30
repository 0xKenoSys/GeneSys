#include <stdio.h>

int strcmp_alias(char *s1, char *s2) {
    int i, result;
    for (i=0; (result = s1[i] - s2[i]) == 0; i++) {
        if (s1[i] == '\0' || s2[i] == '\0') {
            break;
        }
    }

    return result;
}

int main() {
    char str1[] = "https://KenoSys.net";
    char str2[] = "https://0xKenoSys.net";
    char str3[] = "https://Tata.net";

    int result_1_2 = strcmp_alias(str1, str2);
    int result_1_3 = strcmp_alias(str1, str3);
    printf("str1 - str2 = %d\n", result_1_2);
    printf("str1 - str3 = %d\n", result_1_3);

    return 0;
}

//
// Created by Madeleine on 2026/1/30.
//