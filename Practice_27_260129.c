#include <stdio.h>
int main() {
    int nums[10];
    int i;

    //将1~10放入数组中
    for (i=0; i<=10; i++) {
        nums[i] = (i+1);
    }

    //依次输出数组元素
    for (i=0; i<10; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

//为什么nums[i] = (i+1);这一行有问题

//
//dataType arrayName[length];

//int nums[4];

//float temperatures[100];   //定义一个可以存储100个浮点数的数组
//char name[20];    //定义一个可以存储20个字符的数组

//arrayName[index]

//nums[0] = 20;
//nums[1] = 345;
//nums[2] = 700;
//nums[3] = 22;
//nums[4] = -59

//printf("%d", nums[2]);

// Created by Madeleine on 2026/1/29.
//