/**
* Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    //返回的数组长度
    *returnSize = 2 * numsSize;

    int* ans = (int*)malloc(2 * numsSize * sizeof(int));

    //遍历原数组，利用一次循环填满新数组的两个位置
    for(int i = 0; i < numsSize; i++){
    ans[i] = nums[i];
    ans[i + numsSize] = nums[i];
    }

    return ans;
}



//
// Created by Madeleine on 2026/6/11.
//
