#include <stdio.h>
int main() {
    char symbol;
    double num1, num2, result;

    printf("输入一个运算符(+, -, *, /):");
    scanf("%c", &symbol);
    printf("输入两个数字：");
    scanf("%lf %lf", &num1, &num2);

    switch (symbol){
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
            }
            else {
                printf("错误！除数不能为零。\n");
            }
            break;
        default:
            printf("错误！无效的运算符。\n");
    }

    return 0;
}

//
// Created by Madeleine on 2026/1/29.
//