#include <stdio.h>
int main() {
    int i = 1, sum = 0;
    do {
        sum += i;
        i++;
    }while (i<=100);
    printf("1加到100的和为：%d\n", sum);

    return 0;
}

//do {
    //循环体
    //要重复执行的代码
//}while (条件);


//注意，最后的分号;必须要写，不能省略。
//do while 循环至少要执行一次循环体。
//do while 循环和 while 循环的不同在于：它会先执行一次循环体，然后再检测条件是否为真，如果为真则继续循环；如果为假，则终止循环。
// Created by 14423 on 2026/2/11.
//