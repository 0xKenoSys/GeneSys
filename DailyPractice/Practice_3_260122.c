#include<stdio.h>
#include<unistd.h>
int main() {
    setbuf(stdout,NULL);

    printf("Tata");
    sleep(1);
    printf(" is");
    sleep(1);
    printf(" so");
    sleep(1);
    printf(" TASTY!");
    sleep(1);


    return 0;
}


//
// Created by Madeleine on 2026/1/22.
//