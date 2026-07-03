int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int max_count = 0;
    int current_count = 0;

    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 1){
            current_count++;
            if (current_count > max_count){
                max_count = current_count;
            }
        }else{
            current_count = 0;
        }
    }

    return max_count;
}

//不需要再开辟空间存储不同的current_count，只需要再比较一次，给max_count赋值。本质上是对时间、空间复杂度认知不足

//
// Created by Madeleine on 2026/6/12.
//
