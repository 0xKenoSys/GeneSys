#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

long fsize(FILE *fp);

int main() {
    long size = 0;
    FILE *fp = NULL;
    char filename[30] = "/Users/madelin/Desktop/Limbo/Inbox/demo.txt";
    if ( (fp = fopen(filename, "rb")) == NULL ) {   //以二进制方式打开文件
        printf("Failed to open %s...\n", filename);
        getch();
        exit(EXIT_SUCCESS);
    }

    printf("%ld\n", fsize(fp));
    return 0;
}

long fsize(FILE *fp) {
    long n;
    fpos_t fpos;    //当前位置
    fgetpos(fp, &fpos);     //获取当前的位置
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fsetpos(fp, &fpos);     //恢复之前的位置
    return n;
}

//
// Created by Madeleine on 2026/2/3.
//
//FILE *fp;

//typedef struct_iobuf{
    //int cnt;  //剩余的字符，如果是输入缓冲区，那么就表示缓冲区中还有多少个字符未被读取
    //char *ptr;    //下一个要被读取的字符的地址
    //char *base;   //缓冲区基地址
    //int flag;     //读写状态标志位
    //int fd;       //文件描述符
    //
//} FILE;

//long int ftell ( FILE *fp );

//long fsize(FILE *fp){
    //fseek(fp, 0, SEEK_END);
    //return ftell(fp);
//}

//long size = fsize(fp);
//fread(buffer, 1, 1, fp);

//long size(FILE *fp){
    //long n;
    //fpos_t fpos;  //当前位置
    //fgetpos(fp, &fpos);   //获取当前位置
    //fseek(fp, 0, SEEK_END);
    //n = ftell(fp);
    //fsetpos(fp,&fpos);    //恢复之前的位置
    //return 0;
//}
















