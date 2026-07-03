#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    //第一阶段：原地做标记
    for (int i = 0; i < numsSize; i++) {
        //因为有的数字可能已经被别的数字标记成了负数，所以必须取绝对值找原本的房间号
        int val = abs(nums[i]);
        int idx = val - 1;  //对应的数组索引

        //如果房间里的数还是正数，就把它变成负数
        if (nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }

    //第二阶段：计算一共有几个正数（有多少个消失的数字）
    //这一步是为了精确地分配内存
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            count++;
        }
    }

    //给即将返回的答案数组分配精确的内存空间
    int* result = (int*)malloc(count * sizeof(int));
    //必须通过指针把数组大小传回去，否则LeetCode判题机会报错
    *returnSize = count;

    //第三阶段：把正数对应放入编号装进答案数组
    int resultIndex = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            result[resultIndex] = i + 1;
            resultIndex++;
        }
    }

    return result;
}

//===================================================
//本地测试必备main函数
int main() {
    //1.准备测试数据
    int test_nums[] = {4, 3, 2, 7, 8, 2, 3, 1};

    //在C语言中自动计算数组长度的经典公式
    //用整个数组占用的总字节数，除以单个元素占用的字节数
    int numsSize = sizeof(test_nums) / sizeof(test_nums[0]);

    //准备一个变量，用来接收函数返回的“答案的数组的长度”
    int returned_size = 0;

    //2.调用函数
    //注意：我们将returned_size的内存地址（&）传进去，这样函数内部修改它时，外面的变量也会跟着变
    printf("开始执行寻找消失的数字的算法...");
    int* ans = findDisappearedNumbers(test_nums, numsSize, &returned_size);

    //3.打印结果
    printf("消失的数字有%d个，分别是：[ ", returned_size);
    for (int i = 0; i < returned_size; i++) {
        printf("%d ", ans[i]);
    }
    printf("]\n");

    //4.手动释放内存
    free(ans);
    printf("内存已清理，程序完美退出。\n");

    return 0;
}

//
// Created by Madeleine on 2026/7/3.
//
