#include <stdio.h>
int main() {
    float score, appearance;

    printf("请输入赛马的成绩（0-100）：");
    scanf("%f", &score);

    printf("请输入赛马的美貌（0-100）：");
    scanf("%f", &appearance);

    if (score >= 90) {
        if (appearance >= 85) {
            printf("恭喜！您的爱马获得了一等奖金！\n");
        }else {
            printf("很遗憾，虽然您的爱马成绩达标，但美貌不足。您获得了二等奖金！\n");
        }
    }else {
        if (appearance >= 95) {
            printf("虽然您的爱马成绩未达到一等奖金标准，但由于出色的美貌，您获得了三等奖金！\n");
        }else {
            printf("很抱歉，您的爱马没有获得奖金。欢迎下次参赛！\n");
        }
    }

    return 0;
}




//嵌套if else语句:一般建议嵌套不要超过三层。可以考虑使用 switch 语句。正确缩进
//if(条件1){
    //当条件1成立时执行这里的代码
    //if(条件2){
        //当条件2成立时执行这里的代码
    //}else{
        //当条件2不成立时执行这里的代码
    //}
//}else{
    //当条件1不成立时执行这里的代码
    //if (条件3){
        //当条件3成立时执行这里的代码
    //}else{
        //当条件3不成立时执行这里的代码
    //}
//}

// Created by Madeleine on 2026/1/28.
//