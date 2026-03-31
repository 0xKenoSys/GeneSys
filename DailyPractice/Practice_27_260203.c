#include <stdio.h>
#include <assert.h>
int main(void) {
    int i = 0;
    for ( ; ; ) {
        assert(i++ <= 100);
        printf("我是第%d行\n",i);
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//