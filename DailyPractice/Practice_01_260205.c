#include <stdio.h>

int main(){
    int age;

    printf("请输入你的年龄：");
    scanf("%d", &age);

    if (age >= 18) {
        printf("你已经成年了。\n");
    }else {
        printf("你还未成年。\n");
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/5.
//