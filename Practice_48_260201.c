#include <stdio.h>

int main() {
    struct bs {
        unsigned m: 12;
        unsigned char ch: 4;
        unsigned p: 4;
    };
    printf("%d\n", sizeof(struct bs));

    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//

//struct bs {
    //unsigned m: 12;
    //unsigned ch;
    //unsigned p: 4;
//};

//struct bs {
    //int m: 12;
    //int     : 20;
    //int n: 4;
//};









