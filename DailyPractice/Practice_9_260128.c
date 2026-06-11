#include <stdio.h>
int main() {
    int a = 0, b = 10, c = 16;
    int result_1 = a&&b, result_2 = c ||0;
    printf("%d, %d\n", result_1, !c);
    printf("%d, %d\n", 9&&0, result_2);
    printf("%d, %d\n", b||100, 0&&0);
    return 0;
}



//优先级从低到高：|| < && < !
// Created by Madeleine on 2026/1/28.
//逻辑运算符和其它运算符优先级从低到高依次为：
//赋值运算符= < 逻辑运算符|| < 逻辑运算符&& < 关系运算符 < 算术运算符 < 逻辑运算符!