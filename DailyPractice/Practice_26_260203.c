#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(void) {
    FILE *fpoint;
    fpoint = fopen("存在的文件.txt", "w");
    //以可读写的方式打开一个文件
    //如果文件不存在就自动创建一个同名文件
    assert(fpoint);
    fpoint = fopen("不存在的文件.txt", "r");
    //以只读的方式打开一个文件，如果不存在就打开文件失败
    assert(fpoint);
    //（第二次断言）所以断言失败
    printf("文件打开成功");
    //文件拥有都执行不到这里来
    fclose(fpoint);
    return 0;
}


//#ifdef NDEBUG
//#define assert(_Expression)     ((void)0)
//#else /*NDEBUG*/


//
// Created by Madeleine on 2026/2/3.
//