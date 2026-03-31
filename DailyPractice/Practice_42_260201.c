#include <stdio.h>

int main() {
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun }day = Mon;
    printf("%d, %d, %d, %d, %d\n",sizeof(enum week), sizeof(day), sizeof(Mon), sizeof(Wed), sizeof(int) );
    return 0;

}

//
// Created by Madeleine on 2026/2/1.
//