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
                                                    //&是取地址符
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}


void test_show_bytes(int val) {
    //1.准备三种不同类型的测试数据：
    int ival = val;                 //整
    float fval = (float) ival;      //将整型强制转换为单精度浮点型
    int *pval = &ival;              //指针型：存储ival的内存地址

    printf("--- 开始探索内存底层的字节表示 ---\n\n");

    //2.测试show_int
    printf("1.整数%d在内存中的字节序列：\n", ival);
    show_int(ival);
    printf("\n");

    //3.测试show_float
    printf("2.浮点数%f在内存中的字节序列：\n", fval);
    show_float(fval);
    printf("\n");

    //4.测试show_pointer
    printf("3.存放该整数的指针（内存地址）的字节序列：\n");
    show_pointer(pval);
    printf("\n");
}

int main() {
    //设定一个经典的测试数字，可以随意修改这个数字看看输出的变化
    int test_val = 12345;

    //调用测试集成函数
    test_show_bytes(test_val);

    //返回0代表程序正常、成功地结束
    return 0;
}


//CSAPP page 31
// Created by Madeleine on 2026/6/3.
//
