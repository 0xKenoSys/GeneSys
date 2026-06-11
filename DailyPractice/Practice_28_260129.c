#include <stdio.h>
int main() {
    int nums[10];
    int i;

    //从控制台读取用户输入
    for (i=0; i<10; i++) {
        scanf("%d", &nums[i]);  //注意取地址符&不要遗忘
    }

    //依次输出数组元素
    for (i=0; i<10; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}


//数组的初始化

//int nums[5] = {20, 345, 700, 22, -94};

//int a[10]={12, 19, 22, 993, 344};

//int nums[10] = {0};
//char str[10] = {0};
//float scores[10] = {0.0};

//int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

//int a[10] = 1;

//int a[] = {1, 2, 3, 4, 5};

//int a[5] = {1, 2, 3, 4, 5};


// Created by Madeleine on 2026/1/29.
//