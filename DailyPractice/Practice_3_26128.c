//
// Created by Madeleine on 2026/1/28.
//if（条件）{
    //代码块1
    //如果条件为真，执行这里的代码
//}else{
    //代码块2
    //如果条件为假，执行这里的代码
//}

//所谓代码块，就是由{ }包围的一条或者多条语句的集合。

#include <stdio.h>

int main() {
    int age;

    printf("请输入你的年龄：");
    scanf("%d", &age);

    if (age >= 18) {
        printf("你已经成年了。\n");
    }else {
        printf("你还未成年。\n");
    }

    //if (age >= 18)
        //printf("你已经成年了。\n");      //f 和 else 后面的代码块中，如果只有一条语句，那么可以省略{ }
    //else                              //从可读性和规范性上讲，还是强烈建议加上{ }，这也是很多公司的编码规范所要求的。
        //printf("你还未成年。\n");

    return 0;
}