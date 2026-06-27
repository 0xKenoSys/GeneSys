#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
     int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        return NULL;
    }


    int count[101] = {0};

    for (int i = 0; i < numsSize; i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        count[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            result[i] = 0;
        }else {
            result[i] = count[nums[i] - 1];
        }
    }

    return result;
}




//
// Created by Madeleine on 2026/6/26.
//
