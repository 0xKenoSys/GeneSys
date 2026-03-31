#include <stdio.h>

int main() {
    int score;
    printf("请输入学生的成绩（0-100）：");
    scanf("%d", &score);

    if (score >= 90 && score <= 100) {
        printf("优秀\n");
    }else if (score >= 80 && score < 90){
        printf("良好\n");
    }else if (score >= 70 && score < 80) {
        printf("中等\n");
    }else if (score >= 60 && score < 70) {
        printf("及格\n");
    }else if (score >= 0 && score < 60) {
        printf("不及格\n");    //换行符要输在引号里面
    }else {
        printf("输入的成绩无效\n");
    }
    return 0;
}

//多重 if else 语句
//更具体或更严格的条件应该放在前面
// Created by Madeleine on 2026/2/6.
//