#include <stdio.h>
int main() {
    int n;
    printf("输入一个整数：");
    scanf("%d", &n);

    if ( ((n % 3 == 0) || (n % 5 == 0)) && (n % 15 != 0))  { //不能写成((n % 15 != 0) && (n % 3 == 0) || (n % 5 == 0) )，前面为0，遇到最后一个1，还是为True
        printf("special");      //也不能写成(n % 3 == 0) || (n % 5 == 0) && (n % 15 != 0)，少了前半截的括号
    }else {                     //可以写成((n % 3 == 0)!=(n % 5 ==0))用不等于来模拟逻辑异或(XOR, Exclusive OR)
        printf("Normal");
    }
    return 0;
}

//注意：中文的option+（；：）= ……

//为什么输入15还是输出special(已解决)

//第三关：超级倍数 (The Super Modulo)
//题目： 输入一个整数 n。
//* 判断它是否能 同时被 3 和 5 整除。
//* 进阶： 如果能被 3 整除，或者能被 5 整除，但 不能同时 被两者整除（即逻辑异或），输出 "Special"，否则输出 "Normal"。
//* 考点： &&，||，% 的组合使用。

// Created by Madeleine on 2026/2/7.

//举例：
//if ( (a != 0) && (100 / a > 5) )
//如果不在&&停下，就会导致Divide by Zero 崩溃

//Logical Operators