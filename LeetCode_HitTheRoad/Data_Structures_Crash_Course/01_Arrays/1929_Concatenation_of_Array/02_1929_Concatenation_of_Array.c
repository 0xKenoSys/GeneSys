/**
* Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {

    //返回的数组长度
    *returnSize = 2 * numsSize;

    int* ans = (int*)malloc(2 * numsSize * sizeof(int));

    //memcpy(目标地址，源地址，复制的字节数)
    memcpy(ans, nums, numsSize * sizeof(int));
    memcpy(ans + numsSize, nums, numsSize * sizeof(int));


    return ans;
}


//
// Created by Madeleine on 2026/6/11.
//
