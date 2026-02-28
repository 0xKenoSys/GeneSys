#include <stdio.h>
int main() {
    int temp;       //不能定义“char Warning, Normal;”
    printf("Input the temperature: ");
    scanf("%d", &temp);
    printf("System Status: %s\n", temp>70 ? "Warning" : "Normal");   //"Warning"和"Normal"是可打印的文本数据，不是变量名，不能裸奔
    return 0;
}
//
// Created by Madeleine on 2026/2/9.
//