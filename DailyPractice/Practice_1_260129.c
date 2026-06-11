#include <stdio.h>
int main() {
    int a;
    printf("Input an integer number:");
    scanf("%d", &a);

    if (a == 1) {
        printf("Monday\n");
    }else if (a == 2) {
        printf("Tuesday\n");
    }else if (a == 3) {
        printf("Wednesday\n");
    }else if (a == 4) {
        printf("Thursday\n");
    }else if (a == 5) {
        printf("Friday\n");
    }else if (a == 6) {
        printf("Saturday\n");
    }else if (a == 7) {
        printf("Sunday\n");
    }else {
        printf("null\n");
    }

    return 0;
}

//
// Created by Madeleine on 2026/1/29.

//switch(表达式){
    //case 整形常量1:
        //代码块1
        //break;
    //case整形常量2:
        //代码块2
        //break;
    //......
    //case 整形常量n:
        //代码块n
        //break;
    //default:
        //默认代码块
//}

