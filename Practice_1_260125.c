#include<stdio.h>
int main () {
    char str[31];
    int i;

    printf("Enter your name:");
    scanf("%30s",str);
    //什么是%30s?我答：30是width
    printf("Enter your age:");
    scanf("%d",&i);
    printf("Hello %s,you are %d years old.\n",str,i);
    printf("Enter a hexadecimal number:");
    scanf("%x",&i);
    printf("You have entered %#x(%d).\n",i,i);
    //我记得#指的是头缀
    return 0;


}


//scanf()的标准用法（原型）为：int scanf(const char*format,argument...);
//argument 为参数列表，或者变量列表，多个参数以,分隔。
//每个参数都是一个指针，用来指明将数据存储在哪里。参数的个数和类型，要与格式说明符一一对应。
// 注意：argument 指向的位置必须已被分配内存，并且允许写入。bb
// Created by Madeleine on 2026/1/25.
//int 表示 scanf() 的返回值类型，也即处理结果的数据类型：
//如果读取成功，scanf() 将返回成功匹配并赋值的个数；
//如果读取失败，或者达到文件末尾，或者遇到输入结束的条件，则返回 EOF。
//EOF 是在 stdio.h 中定义的宏，它的值在不同的平台或者不同的编译器中可能不同，但通常都是 -1。
//* 表示将读取到的字符丢弃，或者忽略，也即不进行存储。因为没有任何字符需要存储，所以它没有对应的参数。
//限制读取数据的长度在实际开发中非常有用，最典型的一个例子就是读取字符串：我们为字符串分配的内存是有限的，用户输入的字符串过长就存放不了了，就会冲刷掉其它的数据，从而导致程序出错甚至崩溃；
//如果被黑客发现了这个漏洞，就可以构造栈溢出攻击，改变程序的执行流程，甚至执行自己的恶意代码，这对服务器来说简直是灭顶之灾。
//为了避免受到缓冲区中遗留数据的影响，每次读取结束我们都使用scanf("%*[^\n]"); scanf("%*c");来清空缓冲区。关于 scanf() 和缓冲区的话