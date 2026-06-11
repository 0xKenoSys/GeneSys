#include <stdio.h>

typedef char (*PTR_TO_ARR)[30];
typedef int (*PTR_TO_FUNC)(int, int);

int max(int a, int b) {
    return a>b ? a : b;
}

char str[3][30] = {
    "https://KenoSys.net",
    "0xKenoSys",
    "KenoSys"
};

int main() {
    PTR_TO_ARR parr = str;
    PTR_TO_FUNC pfunc = max;
    int i;

    printf("max: %d\n", (*pfunc)(10, 20));
    for (i=0; i<3; i++) {
        printf("str[%d]: %s\n", i, *(parr+i));
    }

    return 0;
}



//
// Created by Madeleine on 2026/2/2.
//
//typedef int INTEGER;
//INTEGER a, b;
//a = 1;
//b = 2;

//typedef char ARRAY20[20];

//ARRAY20, a1, a2, s1, s2;

//char a1[20], a2[20], s1[20], s2[20];


//typedef struct stu{
    //char name[20];
    //int age;
    //char sex;
//} STU;

//STU body1, body2;

//struct stu body1, body2;

//typedef int(*PTR_TO_ARR)[4];

//PTR_TO_ARR p1, p2;

//typedef int (*PTR_TO_FUNC)(int, int);
//PTR_TO_FUNC pfunc;

//#definee INTEGER
//unsigned INTEGER n; //没问题

//typedef int INTEGER;
//unsigned INTEGER n; //错误，不能在INTEGER前面添加unsigned

//#define PTR_INT int*
//PTR_INT p1, p2;

//int *p1, p2;

//typedef int *PTR_INT;
//PTR_INT p1, p2;


















