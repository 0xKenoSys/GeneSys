#include <stdio.h>
int s1 = 0, s2 = 0, s3 = 0;

int vs(int length, int width, int height) {
    int v;
    v = length * width * height;
    s1 = length * width;
    s2 = width * height;
    s3 = length * height;
    return v;
}

int main() {
    int v = 0;
    v = vs(15, 20, 30);
    printf("v=%d, s1=%d, s2=%d, s3=%d\n", v, s1, s2, s3);
    v = vs(5, 17,8);
    printf("v=%d, s1=%d, s2=%d, s3=%d\n", v, s1, s2, s3);

    return 0;

}



//
// Created by Madeleine on 2026/1/31.
//