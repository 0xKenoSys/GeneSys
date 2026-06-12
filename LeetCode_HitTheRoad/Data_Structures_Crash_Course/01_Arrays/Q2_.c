/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    //int returnSize = int numsSize; //是这样写吗？
    * returnSize = numsSize;

    int* ans = (int*)malloc(numsSize * sizeof(int));

    int i;
    for(i = 0; i < n; i++){
        ans[2 * i] = nums[i];
        ans[2 * i + 1] = nums[i + n];
    }

    return ans;


}

//
// Created by Madeleine on 2026/6/12.
//
