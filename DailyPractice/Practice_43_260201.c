#include <stdio.h>

union data {
    int n;
    char ch;
    short m;
};

int main() {
    union data a;
    printf("%d, %d\n", sizeof(a), sizeof(union data) );
    a.n = 0x40;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);

    a.ch = '9';
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);

    a.m = 0x2059;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);

    a.n = 0x3E25AD54;
    printf("%X, %c, %hX\n", a.n, a.ch, a.m);

    return 0;

}










//union data {
    //int n;
    //char ch;
    //double f;
//};
//union data a, b, c;

//union data {
    //int n;
    //char ch;
    //double f;
//}a, b, c;

//union {
    //int n;
    //char ch;
    //double f;
//}a, b, c;

//
// Created by Madeleine on 2026/2/1.
//