#include <stdio.h>
int main() {
    int start, space, length, i, thisNum;
    long total = 0;

    printf("请输入等差数列的首项值：");
    scanf("%d", &start);
    printf("请输入等差数列的公差：");
    scanf("%d", &space);
    printf("请输入等差数列的项数：");
    scanf("%d", &length);

    for (i=0; i<length; i++) {
        thisNum = start + space * i;
        if ( length-i > 1 ) {
            printf("%d", thisNum);
        }
        total += thisNum;
    }
    printf(" = %ld\n", total);

    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//输出结果好奇怪啊？