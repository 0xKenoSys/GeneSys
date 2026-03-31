#include<stdio.h>
int main() {
    int a,b,c;

    scanf("%d %d",&a,&b);
    printf("a+b=%d\n",a+b);

    scanf("%d   %d",&a,&b);
    printf("a+b=%d\n",a+b);

    scanf("%d, %d, %d", &a,&b,&c);
    printf("a+b+c=%d\n", a+b+c);

    scanf("%d is bigger than %d",&a, &b); //必须输入一模一样的字符串，否则读不进去b的值，输出结果里的b还保留上一次赋的值。scanf不可靠，少打字符就崩，而且用旧数据糊弄。
    printf("a-b=%d\n", a-b);

    return 0;

}

//
// Created by Madeleine on 2026/1/23.
//