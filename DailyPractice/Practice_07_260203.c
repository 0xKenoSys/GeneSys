#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char ch;

    //判断文件是否成功打开
    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "wt+")) == NULL ) {
        puts("Fail to open file!");
        exit(0);
    }

    printf("Input a string:\n");
    //每次从键盘读取一个字符并写入文件
    while ( (ch=getchar()) != '\n' ) {
        fputc(ch,fp);
    }
    fclose(fp);
    return 0;
}


//
// Created by Madeleine on 2026/2/3.
//

//int fputc ( int ch, FILE *fp );

//fputc('a', fp);

//char ch = 'a';
//fputc(ch, fp);
