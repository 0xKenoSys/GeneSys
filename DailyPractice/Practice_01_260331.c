#include <stdio.h>
#include <stdlib.h>
int main() {
    //任务要求：编写一个动态字符串处理程序
    char *line_buffer = NULL;   //这个星号是啥意思
int length, string;/*不初始化吗？*/
    //输入阶段： 你的程序需要首先在终端提示用户：“请输入你打算存储的字符串的最大长度（例如 50）：”。读取用户输入的这个整数。
    printf("请输入你打算储存的字符串的最大长度。");
    scanf("%d",&length);
    //动态分配： 根据用户输入的长度，使用 malloc 在堆区动态分配一块足够大的字符（char）数组。
    line_buffer = (char *)malloc(&length * sizeof(char))
    //void* malloc(unsigned nbytes) {
        /*先打样，再举一反三*/
        /*把leetcode第一题做了再来*/
        /* 赋值给地址*/
//Header *p; /*指针怎么使用啊？*/
    //}
    //(char*)malloc(n * sizeof(char));
    //(陷阱提示：在C语言中，字符串必须以 \0 结尾，所以你在分配内存时，计算大小必须要考虑到这个隐藏的结束符。)
//nunits = (nbytes + sizeof(Header)-1)/sizeof(header)+1
    /*我的想法是加两个位置，分别给\和0*/
    //安全检查： 立即检查 malloc 的返回值。如果分配失败（返回 NULL），通过 printf 打印一条红色的错误提示信息（或者普通的错误信息），然后使用 return 1; 或 exit(1); 安全地结束程序。
//if return != 0{ /*如何检查返回值呢？*/
//printf("error");
    //return 1;
    //
//}
    if (line_buffer == NULL) {
        printf("内存不足，分配失败\n");
        return 1;
    }
    //数据写入： 如果分配成功，提示用户：“请输入字符串：”。将用户输入的字符串读入到你刚才动态分配的堆内存中。
//if (p->s.size >= nunits) {  /*如何表示分配成功？我的理解是指针指到的一块size足够大。我不知道整个分配过程如何引入指针，如何用*/
    printf("请输入字符串：");
    scanf("%s", &string);
//}
    sprintf(line_buffer, "%s", string);
    //数据处理： 遍历这个动态分配的字符数组，把里面的所有小写字母全部转换成大写字母（证明你确实掌握了对这块堆内存的读写控制权）。
/*遍历需要指针吧，还要循环*/
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        char n = n + 32; /*大小写转换即编码加一个特定值*/
    }
    //输出结果： 打印出转换后的大写字符串。
printf("%s",&string);    /*指针解引用*/   /*如何输出这么多个字母组成的字符串*/
    //清理现场： 使用 free 释放这块堆内存。
free((void*)(p+1));
    //安全收尾： 将指向该内存的指针置为 NULL，彻底切断联系。
    return NULL:

    }
//
// Created by Madeleine on 2026/3/31.
//