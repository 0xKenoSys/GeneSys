#include <stdio.h>

int*func() {
    int n = 100;
    return &n;
}

int main() {
    int *p = func(), n;
    printf("KenoSys.net\n");
    n = *p;
    printf("value = %d\n",n);
    return 0;
}


//
// Created by Madeleine on 2026/2/1.
//

//int a = 100;
//int *p1 = &a;
//int **p2 = &p1;

//int ***p3 = &p2;

//int ****p4 = &p3;