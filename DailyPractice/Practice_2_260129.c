#include <stdio.h>
int main() {
    int a;
    printf("Input an integer number:");
    scanf("%d",&a);

    switch (a) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("null\n");
    }

    return 0;
}

//必须加break，不然会一起输出
// Created by Madeleine on 2026/1/29.
//

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