#include <stdio.h>

int main() {
    int age;
    float balance;

    printf("请输入用户的年龄：", age);
    scanf("%d", &age);

    printf("请输入用户的卡内余额：", balance);
    scanf("%f", &balance);

    if (age >= 60) {
        printf("大爷/大妈，您身体硬朗啊！免费请您上网！\n");
    }else{
    if (age >= 18 && age < 60) {
        if (balance >= 100){
            printf("欢迎尊贵的VIP用户，请上二楼包间。\n");
        }else {
            printf("欢迎光临，一楼普通区随便坐。\n");
        }
    }else {
        if (age < 18) {
            printf("未成年人禁止入内，回家写作业去。\n");
            }
        }
    }

    return 0;
}



//
// Created by Madeleine on 2026/2/6.

//CyberCafe GateKeeper
//用户需要输入两个条件：年龄 (age) 和 卡内余额 (balance)。
//系统逻辑（需求文档）：
   //* 基本门槛： 只有成年人（年龄 >= 18）才能进入。如果未成年，直接踢出，输出：“未成年人禁止入内，回家写作业去。”
   //* VIP 通道： 如果是成年人，再检查余额：
   //* 如果余额 >= 100 元，输出：“欢迎尊贵的 VIP 用户，请上二楼包间。”
   //* 如果余额 < 100 元，输出：“欢迎光临，一楼普通区随便坐。”
   //* 隐藏彩蛋（Optional）： 如果用户年龄 > 60 岁，不管余额多少，都输出：“大爷/大妈，您身体硬朗啊！免费请您上网！”
//任务指令：
   //* 新建一个 .c 文件（比如 Practice_04_CyberCafe.c）。
   //* 定义两个变量：int age; 和 float balance;。
   //* 用 scanf 让用户输入这两个值。
   //* 用你刚学的 if-else 嵌套逻辑来实现上述规则。

