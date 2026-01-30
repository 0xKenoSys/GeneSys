#include <stdio.h>
int main() {
    int i, j;

    for (i =1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            if (i == 2 && j == 2) {
                goto end_loop;
            }
            printf("i = %d, j = %d\n", i, j);
        }
    }

end_loop:
    printf("jump out of the loop\n");

    return 0;
}



//
// Created by Madeleine on 2026/1/28.
//