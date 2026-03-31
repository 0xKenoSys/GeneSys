#include <stdio.h>
int main() {
    int a;
    printf("Input integer number:");
    scanf("%d", &a);

    switch (a) {
        case 1:     //case后面是：冒号，不是分号
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
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
        case 7:
            printf("Sunday\n");
        default:
            printf("error\n");
    }
    return 0;

}


//switch (表达式) {        //switch case 只能用来匹配整型值（包括 char 类型），不能匹配其它类型的值。虽然表达式的写法很灵活，可以是变量、常量、加减乘除运算、函数调用等，但它必须能够得到一个整型值。
    //case 整形常量1:      //在实际开发中，switch case 常用来替代简单的、拥有多个分支的 if else 语句。
        //代码块1
        //break;          //break 是C语言中的一个关键字，专门用来跳出 switch 语句（也可以跳出 for 循环和 while 循环）。所谓“跳出”，是指一旦遇到 break，就不再执行 switch 中的任何语句，包括当前分支中的语句，以及其它分支中的语句。
    //case 整形常量2:      //为什么要使用 break 呢？因为 switch 有一个坏毛病，就是一旦发现表达式的值和某个整形常量匹配了，就会执行后面的所有代码，包括当前 case 分支的代码，以及它后面的其它 case 分支的代码。这种现象称为贯穿（fall through）。
        //代码块2
        //break;
    //……
    //case 整形常量n:
        //代码块n
        //break;
    //default:
        //默认代码块
//}

//
// Created by Madeleine on 2026/2/8.
//