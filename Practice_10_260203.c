#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {
    //从键盘输入的数据放入a，从文件读取的数据放入b
    int a[N], b[N];
    int i, size = sizeof(int);
    FILE *fp;

    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "rb+")) == NULL ) {
       //以二进制方式打开
        puts("Fail to open file!");
        exit(0);
    }

    //从键盘输入数据 并保存到数组a
    for (i=0; i<N; i++) {
        scanf("%d", &a[i]);
    }
    //将数组a的内容写入到文件
    fwrite(a, size, N, fp);
    //将文件中的位置指针重新定位到文件开头
    rewind(fp);
    //从文件读取内容并保存到数组b
    fread(b, size, N,fp);
    //在屏幕上显示数组b的内容
    for (i=0; i<N; i++) {
        printf("%d", b[i]);
    }
    printf("\n");

    fclose(fp);
    return 0;
}

//可是格式好像输入、输出对不上，比如空格就没打出来。何解？














//size_t fread ( void *ptr, size_t size, size_t count, FILE *fp );

//size_t fwrite ( void * ptr, size_t size, size_t count, FILE *fp );

//
// Created by Madeleine on 2026/2/3.
//