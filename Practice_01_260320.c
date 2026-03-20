//int (* get_math_func(char op))(int, int);

#include <stdio.h>

int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}

//定义一种类型，叫做MathOperation
//它代表了“返回int，接收两个int的函数指针”
typedef int(*MathOperation)(int, int);

//函数定义就像普通变量一样清爽
//这是一个函数，名字叫get_math_func。返回类型是MathOperation（函数指针）
MathOperation get_math_func(char op) {
    if (op == '+') {
        return add; //返回加法函数的地址
    }else if (op == '-') {
        return sub;
    }
    return NULL;
}
int main() {
    //向系统请求一个做加法的“厨师”（获取函数指针）
    MathOperation my_func = get_math_func('+');

    //使用这个厨师来执行函数
    int result = my_func(10, 5);
    printf("10 + 5 = %d\n", result);

    return 0;
}

//
// Created by Madeleine on 2026/3/20.
//