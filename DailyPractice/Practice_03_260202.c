#include <stdio.h>

int getNum() {
    return 100;
}

int main(){
    int n = 90;
    const int MaxNum1 = getNum();
    const int MaxNum2 = n;
    const int MaxNum3 = 80;
    printf("%d, %d, %d\n", MaxNum1, MaxNum2, MaxNum3);

    return 0;
}

//
// Created by Madeleine on 2026/2/2.
//

//const int MaxNum = 100;

//MaxNum = 90;

//const type name = value;

//type const name = value;



//const int *p1;
//int const *p2;
//int * const p3;


//const int * const p4;
//int const * const p5;


