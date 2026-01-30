#include <stdio.h>

#define SIZE 5

int main() {
    int numbers[SIZE];
    int i, max, min;

    printf("请输入 %d 个整数：", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &numbers[i]);
    }

    max = min = numbers[0];

    for (i = 1; i < SIZE; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("你输入的数组是：");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n最大值：%d\n最小值：%d\n", max, min);

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//