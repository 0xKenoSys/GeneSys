#include<stdio.h>
int main() {
    //int n;
    float f=0.0;
    //定义变量时，给个初始值
   // char str[24];

  //  scanf("%2d",&n);
   // scanf("%*[^\n]");scanf("%*c");
    scanf("5%f",&f);
    //如果写成了5%f，意思是，先在输入里找一个数字5,然后再读一个浮点数
    scanf("%*[^\n]");scanf("%*c");
    //scanf("%23s",str);
    //为什么比char定义的少一个长度？解答：因为要自动跟一个\0空字符，null terminator来结束字符串，否则printf会没完没了地打印
   // printf("n=%d,f=%g,str=%s\n",n,f,str);
    printf("f=%g",f);

 //511.5(回车)
 //f=11.5
    return 0;
}


//
// Created by Madeleine on 2026/1/25.
//