#include <stdio.h>
int main() {
    int i,j;
    int sum = 0;
    int average;
    int v[3];
    int a[5][3] = {{80,75,92},{61,65,71},{59,63,70},{85,87,90},{76,77,85}};

    for (i=0; i<3; i++) {
        for (j=0; j<5; j++) {
            sum += a[j][i];
        }
        v[i] = sum / 5;
        sum = 0;
    }

    average = (v[0] + v[1] + v[2]) / 3;
    printf("Math: %d\nC Language: %d\nEnglish: %d\n", v[0], v[1], v[2]);
    printf("Total: %d\n",average);

    return 0;
 }


////二维数组初始化，未赋值，取零值
//int a[3][3] = {{1},{2},{3}};
//赋值后各元素的值为：
//1 0 0
//2 0 0
//3 0 0

//再如：
//int a[3][3] = {{0,1},{0,0,2},{3}};
//赋值后各元素的值为：
//0 1 0
//0 0 2
//3 0 0

//如果对全部元素赋值，那么第一维的长度可以不给出：
//int a[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//可以写为：
//int a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// Created by Madeleine on 2026/1/29.
//