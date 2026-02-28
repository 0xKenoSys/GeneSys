#include<stdio.h>
#include<unistd.h>
int main() {
    int count;
    printf("Enter countdown start time(e.g., 10):");
    scanf("%d", &count);
    while (count > 0) {
        printf("%d...\n", count);
        count--;
        sleep(1);
    }
    printf("BOOM!Output or Die!\n");

    return 0;
}



//
// Created by Madeleine on 2026/1/26.
//