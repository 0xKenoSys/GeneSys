#include <stdio.h>

int main() {
    int age;
    float balance;

    printf("请输入用户的年龄：");  //如果不在printf里写%d，后面的变量不会被打印也不会被用到，所以不用写变量
    scanf("%d", &age);

    if (age >= 60) {
        printf("大爷/大妈，您身体硬朗啊！免费请您上网！\n");
    }else{
        if (age < 18) {
            printf("未成年人禁止入内，回家写作业去。\n");
        }else{    //不用写“if (age >= 18 && age < 60) {”，浪费算力，直接写逻辑，写else，连条件都不用判断了
        printf("请输入用户的卡内余额：", balance);
        scanf("%f", &balance);
            if (balance >= 100){
                printf("欢迎尊贵的VIP用户，请上二楼包间。\n");
            }else {
                printf("欢迎光临，一楼普通区随便坐。\n");
            }
        }
    }

    return 0;
}


//
// Created by Madeleine on 2026/2/6.
//