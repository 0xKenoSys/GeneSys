#include <stdio.h>
int main() {
    int i, sum=0;
    i = 1;
    while (i<=100/*条件表达式*/) {
        sum+=i;
        i++;//更新表达式
    }
    printf("%d\n",sum);
    return 0;
}


//for循环的用法：
//for(初始化表达式；条件表达式；更新表达式){
    //循环体
    //也就是要重复执行的代码
//}
// Created by Madeleine on 2026/1/29.
//