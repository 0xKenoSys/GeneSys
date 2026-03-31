#include<stdio.h>
int main() {
    int a = 1, b = 2;
    char c;//getchar()这个函数的返回值类型应该是int，如果遇到无符号字符的环境，会无法正确匹配EOF（-1）而导致死循环

    scanf("a=%d", &a);
    while ((c = getchar()) != '\n' && c != EOF);
    scanf("b=%d", &b);
    printf("a=%d, b=%d\n", a, b);

    return 0;
}

//0 vs O
//看看getchar来清空缓存
//getchar() 是带有缓冲区的，每次从缓冲区中读取一个字符，包括空格、制表符、换行符等空白符，
//只要我们让 getchar() 不停地读取，直到读完缓冲区中的所有字符，就能达到清空缓冲区的效果。请看下面的代码：
// int c;
//while((c = getchar()) != 'n' && c != EOF);
//该代码不停地使用 getchar() 获取缓冲区中的字符，直到遇见换行符\n或者到达文件结尾才停止。
// Created by Madeleine on 2026/1/26.
//只有一种很蹩脚的方案能适用于所有平台，那就是将输入缓冲区中的数据都读取出来，但是却不使用。