#include <stdio.h>

int main() {
    float grade, attendance;

    printf("请输入学生的成绩（0-100）：");
    scanf("%f", &grade);

    printf("请输入学生的出勤率（0-100）：");
    scanf("%f", &attendance);

    if (grade >= 85) {
        if (attendance >= 90) {
            printf("恭喜！你获得了一等奖学金！\n");
        }else {
            printf("很遗憾，虽然你的成绩达标，但出勤率不足。你获得了二等奖学金。\n");
        }
    }else {
        if (attendance >= 95) {
            printf("虽然你的成绩未达到一等奖学金标准，但由于出色的出勤率，你获得了三等奖学金。\n");
        }else {
            printf("很抱歉，你没有获得奖学金的资格。请继续努力！\n");
        }
    }

    return 0;
}

//嵌套不要超过三层。
//以考虑使用 switch 语句或者将逻辑拆分为单独的函数
//正确缩进提高可读性



//嵌套if语句
//if（条件1）{
    //条件1成立时执行这里的代码
    //if（条件2）{
        //当条件2成立时执行这里的代码
    //}else{
        //当条件2不成立时执行这里的代码
    //}
//}else{
    //当条件1不成立时执行这里的代码
    //if（条件3）{
        //当条件3成立时执行这里的代码
    //}else{
        //当条件3不成立时执行这里的代码
    //}
//}


//
// Created by Madeleine on 2026/2/6.
//