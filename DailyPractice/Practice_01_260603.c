#include <stdio.h>

typedef unsigned char *byte_pointer;    //用typedef定义一个新的类型别名，叫做byte_pointer

void show_bytes(byte_pointer start, size_t len) {   //start是一个内存地址，告诉程序从哪里的内存开始，它的类型就是刚才定义的单字节精度指针byte_pointer。start是一个指针
    size_t i;                                       //size_t是C语言里专门用来表示大小、长度的标准数据类型，本质上是一个无符号整数。定义循环变量i时类型和len保持一致
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);  //步长为1个字节，从偏移量为0的地方开始读取并打印
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //(byte_pointer)是强制类型转换(Cast)，从跃进4字节变成1字节    //取地址符 & 生成指针。     //指针不仅仅是一个定位器，它还是一个带有自动步长计算功能的游标。也就是说指针（有类型标签的内存地址）不仅包含位置，还包含类型的步长，指针加1，会根据类型的步长跃进（算数运算跨度stride）
                                                    //但编译器是一个极其古板且教条的管家。它在把 1000 这个地址交给你的时候，还会死死地在这个地址上贴一张极其重要的类型标签。
                                                    //这张标签上写着：“这是一个起始地址为 1000 的门牌号，并且请注意，这个门牌号背后住着的客人是一个 int，他一口气占了 4 个房间。”
                                                    //这个带有类型标签的内存地址，才是我们真正意义上所说的指针。
                                                    //所以，&x 的结果，不仅产生了一个数值（1000），还产生了一个数据类型（int *，即指向整型的指针）。取地址的操作，就是把一个物理实体的坐标提取出来，并附加上它跨度的元数据。
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}



//CSAPP page 31
// Created by Madeleine on 2026/6/3.
//
