#include <stdio.h>
int main () {
    int a = 17;
    const int b = 5;//const:变成常量

    switch (a) {
        case 10: printf("..."); break;
        case 8+9: printf("..."); break;
        case 'A': printf("..."); break;
        case 'A'+19: printf("..."); break;

        //case 9.5: printf("..."); break;
        //case a: printf("..."); break;
        //case a+10: printf("..."); break;

        case b+2: printf("..."); break;

}
    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//