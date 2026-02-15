#include <stdlib.h>
#include <stdio.h>
int main(){
    while(1){  //死循环
        malloc(1024);  //分配1024个字节的内存
    }
    return 0;
}

//进程已结束，退出代码为 143 (interrupted by signal 15:SIGTERM)

// Created by Madeleine on 2026/2/14.
//