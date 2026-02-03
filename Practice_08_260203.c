#include <stdio.h>
#include <stdlib.h>
#define N 100
int main() {
    FILE *fp;
    char str[N+1];
    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt","rt")) ==NULL ) {
        puts("Fail to open file!");
        exit(0);
    }

    while (fgets(str, N, fp) != NULL) {
        printf("%s", str);
    }

    fclose(fp);
    return 0;

}

//char *fgets ( char *str, int n, FILE *fp );

//#define N 101
//char str[N];
//FILE *fp = fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "r");
//fgets(str, N, fp);


//
// Created by Madeleine on 2026/2/3.
//