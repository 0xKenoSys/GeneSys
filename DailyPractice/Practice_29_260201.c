#include <stdio.h>
int main() {
    int a[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7},{8, 9, 10, 11}};
    int (*p)[4] = a;
    printf("%d\n", sizeof(*(p+1)));

    return 0;
}

//a+i==p+i
//a[i]==p[i]==*(a+i)==*(p+i)
//a[i][j]==p[i][j]==*(a[i]+j)==*(p[i]+j)==*(*(a+i)+j)==*(*(p+i)+j)


//int a[3][4]={{0, 1, 2, 3}, {4, 5, 6, 7},{8, 9, 10, 11}};

//int(*p)[4]=a;


// Created by Madeleine on 2026/2/1.
//