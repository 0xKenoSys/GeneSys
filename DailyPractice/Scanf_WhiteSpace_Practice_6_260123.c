#include<stdio.h>
int main() {

    char author[30]={0};
    char lang[30]={0};
    char url[30]={0};
    scanf("%s %s",author,lang);
    getchar();
    printf("author:%s \nlang: %s\n", author, lang);
    //scanf("%s %s",url);
    fgets(url, 50, stdin);
    printf("url: %s\n", url);

    return 0;
}


//getchar() 是一个专门用来从缓冲区里拿走一个字符的函数。
// Created by Madeleine on 2026/1/23.
//fgets(url, 30, stdin);
//scanf("%s %s",url);空格打断
//Poe Archaic
//http://SubwayHaochi.net http://KFCoishii.net