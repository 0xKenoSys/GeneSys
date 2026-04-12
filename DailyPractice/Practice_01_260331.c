#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    //任务要求：编写一个动态字符串处理程序
    char *line_buffer = NULL;   //这个星号是啥意思
    int length;
    //char string;/*不初始化吗？*/
    //输入阶段： 你的程序需要首先在终端提示用户：“请输入你打算存储的字符串的最大长度（例如 50）：”。读取用户输入的这个整数。
    printf("请输入你打算储存的字符串的最大长度（例如50）：");
    //scanf("%d",&length);
    //if (length <= 0) {  //习惯：检查输入是否有效。我认为这也是一种边界条件意识
    if (scanf("%d", &length) != 1){ //检查scanf的返回值，确保用户输入了正确的整数 //scanf("%d", &length)读入几个变量，就变成数字几。比如读入a，就是0
    printf("长度无效\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF){ }
    //动态分配： 根据用户输入的长度，使用 malloc 在堆区动态分配一块足够大的字符（char）数组。
    line_buffer = (char *)malloc((length+1) * sizeof(char));    //+1:加一个结束符

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
//}
    if (line_buffer == NULL) {
        printf("内存不足，分配失败\n");
        return 1;
    }
    //数据写入： 如果分配成功，提示用户：“请输入字符串：”。将用户输入的字符串读入到你刚才动态分配的堆内存中。
    printf("请输入字符串：");
    if (fgets(line_buffer, length + 1, stdin) != NULL) {    //fgets会读入\n，要把它踢掉 //地址，容量，坐标  //如果读入信息，返回line_buffer，当然不等于NULL；若读到一场空，就不必剔除\n。原子感的执行和判断一体化：去做这件事，如果没有预期回馈，立即停止。
        line_buffer[strcspn(line_buffer, "\n")] = '\0'; //strcspn: string span complement 把\n替换为\0  //方括号（数组下标运算符）：物理寻址，本质是偏移量计算器，格式为：起点地址[偏移步数]。这一行是嵌套用法，方括号内调用了函数，返回了偏移步数。最后用\0覆盖定位到的内存。
    }
    //scanf("%s", line_buffer);   //line_buffer是一个地址，直接写入
//if (p->s.size >= nunits) {  /*如何表示分配成功？我的理解是指针指到的一块size足够大。我不知道整个分配过程如何引入指针，如何用*/
//}
    //sprintf(line_buffer, "%s", &string);
    //数据处理： 遍历这个动态分配的字符数组，把里面的所有小写字母全部转换成大写字母（证明你确实掌握了对这块堆内存的读写控制权）。
/*遍历需要指针吧，还要循环*/
    int i = 0;
    while (line_buffer[i] != '\0') {    //单引号：翻译为ASCII码整数值
        if (line_buffer[i] >= 'a' && line_buffer[i] <= 'z') {
            line_buffer[i] = line_buffer[i] -32;
        }
        i++;    //C语言里没有字符串（以\0结尾的字符数组），只有字符数组
    }
    //for (line_buffer[i]; i++; )
    //for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        //char n = n + 32; /*大小写转换即编码加一个特定值*/

    //输出结果： 打印出转换后的大写字符串。
    printf("转换后的字符串为：%s\n", line_buffer);
//printf("%s",&string);    /*指针解引用*/   /*如何输出这么多个字母组成的字符串*/
    //清理现场： 使用 free 释放这块堆内存。
    free(line_buffer);  //光围绕line_buffer，就这个指针指向了一块分配的内存
    line_buffer = NULL;
//free((void*)(p+1));
    //安全收尾： 将指向该内存的指针置为 NULL，彻底切断联系。
    //return int NULL;

    }
//
// Created by Madeleine on 2026/3/31.
//