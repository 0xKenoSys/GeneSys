#include <stdio.h>  //标准输入输出库提供了printf函数，这是程序与外界交互的窗口，否则只是黑盒
#include <stdlib.h> //标准库引入了内存管理与数据类型转换的底层工具

int main(int argc, char *argv[]) {  //负责计数；负责装满字符指针，是个数组
    //安全校验：期望的参数总数应为3（程序名+数字A+数字B）
    //文件名下拉菜单，编辑配置，程序参数，输入“15 27”
    if (argc != 3) {
        printf("语法错误。正确写法：%s<数字1><数字2>\n", argv[0]);
        return 1;
    }
    //将字符串格式的参数转换为长整型数字
    //在工程实践中，通常使用更安全的strtol函数替代atoi来处理溢出
    char *endptr1, *endptr2;
    long num1 = strtol(argv[1], &endptr1, 10);  //strtol：将文本字符串转换为数值形态，字符在内存中是ASCII码，数字在内存中是二进制。它接收三个指令：要解析的字符串地址、一个用于解析进度的指针的地址、以及表明进制的数字。一旦遇到非数字，就停止
    long num2 = strtol(argv[2], &endptr2, 10);  //endtpr，返回\0，精准识别非数字，并且停止
    //简单的错误处理机制：检查是否包含非数字字符
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        printf("类型错误：参数必须是合法的纯数字。\n");
        return 1;
        }
    long sum = num1 + num2;
    printf("计算结果：%ld + %ld = %ld\n", num1, num2, sum);
    return 0;
    }


//
// Created by Madeleine on 2026/2/27.
//

//函数名后面有()
//argc和argv是什么？、
