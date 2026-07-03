/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    //int returnSize = int numsSize; //是这样写吗？
    * returnSize = numsSize;

    int* result = (int*)malloc(numsSize * sizeof(int));

    for(int i = 0; i < n; i++){
        // 把前半段的元素 x 放进偶数索引
        result[2 * i] = nums[i];
        // 把后半段的元素 y 放进奇数索引
        result[2 * i + 1] = nums[i + n];
    }

    return result;


}

//
// Created by Madeleine on 2026/6/12.
//
