#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    //如果文件不存在，给出提示并退出
    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "rt")) == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }

    //每次读取一个字节，直到读取完毕
    while ( (ch=fgetc(fp)) != EOF ) {
        putchar(ch);
    }
    putchar('\n');

    if (ferror(fp)) {
        puts("读取出错");
    }else {
        puts("读取成功");
    }

    fclose(fp);
    return 0;


}


//
// Created by Madeleine on 2026/2/3.
//