#include <stdio.h>
int main() {
    int score;
    printf("请输入赛马的成绩（0-100）：");
    scanf("%d", &score);

    if (score >= 90 && score <= 100) {
        printf("优秀\n");
    }else if (score >= 80 && score < 90) {
        printf("良好\n");
    }else if (score >= 70 && score < 80) {
        printf("中等\n");
    }else if (score >= 60 && score < 70 ) {
        printf("及格\n");
    }else if (score >= 0  && score < 60) {
        printf("不及格\n");
    }else {
        printf("输入的成绩无效\n");
    }

    return 0;
}

//多重if else语句：更具体或更严格的条件应该放在前面(由于C语言会按顺序检查条件)
//if(条件1){
    //如果条件1成立，执行这里的代码
//}else if(条件2){
    //如果条件2成立，执行这里的代码
//}else if(条件3){
    //如果条件3成立，执行这里的代码
//}else{
    //如果以上所有条件都为假，执行这里的代码
//}

// Created by Madeleine on 2026/1/28.
//