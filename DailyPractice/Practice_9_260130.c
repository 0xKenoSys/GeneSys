#include <stdio.h>
int main() {
    int nums[10] = {4, 5, 2, 10, 7, 1, 8, 3, 6, 9};
    int i, j, temp, isSorted;

    for (i=0; i<10-1; i++) {
        isSorted = 1;
        for (j=0; j<10-1-i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted) break;
    }
    for (i=0; i<10; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}


//
// Created by Madeleine on 2026/1/30.
//// Created by Madeleine on 2026/1/30.
// 对单个元素赋值
//int a[3];
//a[0] = 3;
//a[1] = 100;
//a[2] = 34;
// 整体赋值（不指明数组长度）
//float b[] = { 23.3, 100.00, 10, 0.34 };
// 整体赋值（指明数组长度）
//int m[10] = { 100, 30, 234 };
// 字符数组赋值
//char str1[] = "https://c.biancheng.net";
// 将数组所有元素都初始化为0
//int arr[10] = {0};
//char str2[20] = {0};
