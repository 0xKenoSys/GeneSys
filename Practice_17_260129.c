#include <stdio.h>
int main() {
    int n, factorial = 1;
    int temp;

    printf("请输入一个正整数：");
    scanf("%d", &n);

    for (temp = n; temp > 0; temp--) {
        factorial *= temp;
    }

    printf("%d 的阶乘是%d\n", n, factorial);

    return 0;
}

//1.修改“从1加到100的和”的代码，省略初始化表达式(分号;必须要保留。)：
//int i =1, sum = 0;
//for( ; i<=100; i++){
    //sum+=i;
//}

//2.死循环：
//for(i=1; ;i++) sum=sum+i;
//相当于：
//i=1;
//while(1){
    //sum=sum+1;
    //i++;
//}

//3.省略了更新表达式，就不会修改条件表达式中的变量，这时可在循环体中加入修改变量的语句
//for( i=1; i<=100; ){
    //sum=sum+i;
    //i++;
//}

//4.省略初始化表达式和更新表达式
//for( ; i<=100 ; ){
    //sum=sum+i;
    //i++;
// }
//相当于：
// while(i<=100){
    //sum=sum+i;
    //i++;
//}

//5.3个表达式可以同时省略。
//for(;;)语句
//相当于：
//while(1)语句

//6.初始化表达式和更新表达式可以是一个简单表达式，也可以是逗号表达式。
//for( sum=0,i=1; i<=100; i++ ) sum=sum+i;
//或者：
//for( i=0,j=100; i<=100; i++,j--)  k=i+j;

//7.条件表达式一般是关系表达式或者逻辑表达式，但也可是数值、字符、函数调用等，只要其值为真（非零），就执行循环体。
//for( i=0;(c=getchar())!='\n'; i+=c );
//又如：
//for( ; (c=getchar())!='\n' ; )    printf("%c",c);




// Created by Madeleine on 2026/1/29.
//