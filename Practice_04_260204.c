#include <stdio.h>
int main() {
    int i, j;

    for ( i = 1; i < 5; i++) {
        for (j = 1; j < 5; j++) {
            if (i == 2 && j == 2) {
                goto end_loop;
            }
            printf("i = %d, j = %d\n", i, j);
        }
    }

    end_loop:
    printf("跳出循环");

    return 0;
}

//在这个例子中，当 i 和 j 都等于 2 时，会执行 goto 语句，直接跳到 end_loop 标签处，然后执行它后面的代码。这意味着，整个循环被跳过了，不再执行了。
// Created by Madeleine on 2026/2/4.
//