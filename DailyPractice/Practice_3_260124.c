#include<stdio.h>
int main() {
    int anxiety_level;
    printf("请输入当前的焦虑值（0-100）\n");
    scanf("%d", &anxiety_level);

    if (anxiety_level > 90) {
        printf("警告：系统过热。启动冷却程序...正在写入代码...\n");
    }else{
        printf("系统正常。继续运行。\n");
    }

    return 0;
}

//
// Created by Madeleine on 2026/1/25.
//