#include <stdio.h>
int main() {
    int month = 0;
    printf("输入月份：");
    scanf("%d", &month);

    switch (month) {
        case 12:
        case 1:
        case 2:
            printf("冬季\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("春季\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("夏季\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("秋季\n");
            break;
        default:
            printf("无效的月份\n");
    }

    return 0;
}



//
// Created by Madeleine on 2026/1/29.
//