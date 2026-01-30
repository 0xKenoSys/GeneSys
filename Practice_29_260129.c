#include <stdio.h>

int main() {
    int scores[] = { 85, 92, 78, 95, 88, 60, 100, 92, 88 };
    int sum = 0;
    float average;
    int length = sizeof(scores) /
        sizeof(scores[0]);

    for (int i = 0; i < length; i++) {
        sum += scores[i];
    }

    average = (float)sum / length;

    printf("平均分数： %.2f\n", average);

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//