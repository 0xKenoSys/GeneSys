#include <stdio.h>
int main(int argc, char *argv[]) {
    int i;
    printf("The program receives %d parameters:\n", argc);
    for (i=0; i<argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}


//int *p1[6];     //指针数组
//int *(p2[6]);   //指针数组，和上面的形式等价
//int (*p3)[6];   //二维数组指针
//int (*p4)(int, int);    //函数指针

//char *(* c[10])(int **p);
//int (*(*(*pfunc)(int *))[5])(int *);

//char*(*c[10])(int**p);

//char*(*c[10])(int **p);

//char*(*c[10])(int **p);

//int(*(*(*pfunc)(int*))[5])(int*);

//int(*(*(pfunc)(int*))[5])(int *);

//int(*(*(*pfunc)(int *))[5])(int *);

//int(*(*(*pfunc)(int *))[5])(int *);

//int(*(*(*pfunc)(int*))[5])(int*);


//int main();
//int main(int argc, char *argv[]);


//
// Created by Madeleine on 2026/2/1.
//