#include <stdio.h>
#include <stdlib.h>

#define N 100

int main() {
    FILE *fp;
    char str[N + 1];

    //判断文件是否打开失败
    if ( (fp = fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt","rt"))==NULL ) {
        puts("Fail to open file!");
        exit(0);
    }

    //循环读取文件的每一行数据
    while ( fgets(str, N,fp) != NULL ) {
        printf("%s", str);
    }

    //操作结束后关闭文件
    fclose(fp);
    return 0;
}

//

//int fclose(FILE *fp);

//fclose(fp);


//FILE *fp;
//if ( (fp=fopen("D:\\demo.txt","rb")) == NULL) {
    //printf("Fail to open file!\n");
    //exit(0);
//}

//
// Created by Madeleine on 2026/2/3.
//

//FILE *fopen(char *filename, char *mode);

//FILE *fp = fopen("demo.txt", "r");

//FILE *fp = fopen("D:\\demo.txt","rb+");

