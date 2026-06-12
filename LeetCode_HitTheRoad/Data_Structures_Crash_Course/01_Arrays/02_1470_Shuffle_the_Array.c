/**
* Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){

    * returnSize = numsSize;

    int* result = (int*)malloc(numsSize * sizeof(int));

    int left = 0;
    int right = n;

    int index = 0;

    //或者
    //while(left < n){
    while(index < 2 * n){
        result[index++] = nums[left++];
        result[index++] = nums[right++];
    }

    return result;


}

//
// Created by Madeleine on 2026/6/12.
//
//
// Created by Madeleine on 2026/6/12.
//
