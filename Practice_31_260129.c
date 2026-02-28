#include <stdio.h>
int main() {
    int i, j;   //二维数组下标
    int sum = 0;    //当前科目的总成绩
    int average;    //总平均分
    int v[3];   //各科平均分
    int a[5][3];    //用来保存每个同学各科成绩的二维数组

    printf("Input score:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<5; j++) {
            scanf("%d", &a[j][i]);  //输入每个同学的各科成绩

            sum += a[j][i]; //计算当前科目的总成绩
        }
        v[i]=sum/5; //当前科目的平均分
        sum=0;
    }
    average = (v[0] + v[1] + v[2])/3;
    printf("Math: %d\nC Language: %d\nEnglish: %d\n", v[0], v[1], v[2]);
    printf("Total: %d\n", average);

    return 0;
}



//二维数组定义的一般形式为：
//dataType arrayName[length1][length2];

//int a[3][4];

//a[0][0],a[0][1],a[0][2],a[0][3]
//a[1][0],a[1][1],a[1][2],a[1][3]
//a[2][0],a[2][1],a[2][2],a[2][3]

// Created by Madeleine on 2026/1/29.
//

//二位数据的初始化
//int a[5][3]={{80,75,92},{61,65,71},{59,63,70},{85,87,90},{76,77,85}};
//int a[5][3]={80, 75, 92, 61, 65, 71, 59, 63, 70, 85, 87, 90, 76, 77, 85};