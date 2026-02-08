#include <stdio.h>
int main() {
    char n;

    printf("Input the grade: ");
    scanf("%c", &n);

    switch (n) {        //这一步是固定的，括号里是表达式，计算出结果后与各个case后面的整形常量进行比较，看是否相等
        case 'A':
        case 'B':
        case 'C':
            printf("及格\n");
            break;
        case 'D':
        case 'F':
            printf("不及格\n");
            break;
        default:
            printf("无效的成绩\n");
    }
    return 0;
}

//没看懂这句话：case 后面除了可以跟整形常量，还可以跟结果是整型的常量表达式，这意味着表达式的值在编译期间就能确定，而不用等到运行时计算得出。
//不懂：另外，虽然普通变量不能用在 case 后面，但是由 const 修饰的常量是可以的，这是因为 const 常量的值不能修改，在编译期间就能确定。
// int a = 60;
//const int b = 5;

//case 10: printf("..."); break;  //正确
//case 8+9: printf("..."); break;  //正确,8+9 的值在编译期间就能算出
//case 'A': printf("..."); break;  //正确，字符和整数可以相互转换
//case 'A'+19: printf("..."); break;  //正确，字符和整数可以相互转换
//case 9.5: printf("..."); break;  //错误，不能为小数
//case a: printf("..."); break;    //错误，不能包含变量
//case a+10: printf("..."); break;  //错误，不能包含变量
//case b+2: printf("..."); break;  //正确，b+2 的值在编译期间就能算出
//
//
//
// Created by Madeleine on 2026/2/8.
//