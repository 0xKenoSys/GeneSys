#include <stdio.h>'

#define PI 3.14159

int main() {
    float radius = 0, area = 0;
    printf("Enter radius:");
    scanf("%f", &radius);
    area = PI * radius * radius;
    printf("圆的半径是%.2f，面积是%.4f。\n", radius, area);

    return 0;
}

//
// Created by Madeleine on 2026/1/31.
//