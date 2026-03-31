#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char str[102] = {0}; strTemp[100];
    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "at+")) == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }
    printf("Input a string:");
    gets(strTemp);
    stract(str,"\n");
    stract(str, strTemp);
    fputs(str, fp);
    return 0;
}

//int fputs( char *str,FILE *fp );

//cahr *str = "https://KenoSys.net";
//FILE *fp = fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "at+");
//fputs(str, fp);

//
// Created by Madeleine on 2026/2/3.
//