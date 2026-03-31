#include <stdio.h>
#include <string.h>
int main() {
    char str1[100]="The URL is: ";
    char str2[60];
    printf("Input a URL: ");
    gets(str2); //warning: this program uses gets(), which is unsafe.
    strcat(str1, str2);
    puts(str1);

    return 0;
}

//
// Created by Madeleine on 2026/1/29.
//