#include <stdio.h>

int s1, s2, s3;

int vs(int a, int b, int c) {
    int v;
    v = a * b * c;
    s1 = a * b;
    s2 = b * c;
    s3 = a * c;
    return v;
}

int main() {
    int v, length, width, height;
    printf("Input length, width and height: ");
    scanf("%d %d %d", &length, &width, &height);
    v = vs(length, width, height);
    printf("v=%d, s1=%d, s2=%d, s3=%D\n", v, s1, s2, s3);

    return 0;
}



// Created by Madeleine on 2026/1/31.
//