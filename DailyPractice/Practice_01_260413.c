//Two sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//You can return the answer in any order.

//Example 1:

//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]
//Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//two for-loops
//提问：咋映射过去呢？indices的中括号里的内容，和指针的偏移量如何建立映射？
//Created by Madeleine on 2026/3/24.

#include<stdio.h>
#include <stdlib.h>

    int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
        for (int i = 0; i < numsSize; i++) {
            for (int j = i + 1; j < numsSize; j++) {
                if (nums[j] == target - nums[i]) {
                    int* result = malloc(sizeof(int) * 2);
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;
                }
            }
        }

        //Return an empty array if no solution is found
        *returnSize = 0;
        return malloc(sizeof(int) * 0);
    }
int main() {
        int nums[] = {2, 7, 11, 15};
        int target = 9;
        int returnSize;

        int* result = twoSum(nums, 4, target, &returnSize);

        if (returnSize == 2) {
            printf("Indices: %d, %d\n", result[0], result[1]);
        }else {
            printf("No solution found.\n");
        }

        free(result);
        return 0;
    }














//
// Created by Madeleine on 2026/4/13.
//
