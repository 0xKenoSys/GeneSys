#include <stdio.h>

int main() {
    int a = 15, b = 99, c = 222;
    int *p = &a;
    *p = b;
    c = *p;
    printf("%d, %d, %d, %d\n", a, b, c, *p);
    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//

//int *p = &a;
//*p = 100;

// int *p;
//p = &a;
//*p = 100;

//int x, y, *px = &x, *py = &y;
//y = *px + 5;
//y = ++*px;
//y = *px++;
//py = px;





