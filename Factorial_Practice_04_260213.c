#include <stdio.h>
int main() {
    int n, i, factorial=1;  //一定要初始化

    printf("Enter a number:\n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)    //for循环不需要像if、while语句那样加花括号，也不用加分号
        factorial = n * i;

    printf("The factorial of the number is:\n%d", factorial);
    return 0;

}



//C语言求n的阶乘（n!）
//从键盘输入一个数，求出这个数的阶乘，即 n!。
//算法思想
//首先要清楚阶乘定义，所谓 n 的阶乘，就是从 1 开始乘以比前一个数大 1 的数，一直乘到 n，用公式表示就是：1×2×3×4×…×(n-2)×(n-1)×n=n!

//具体的操作:利用循环解决问题，设循环变量为 i，初值为 1，i 从 1 变化到 n；依次让 i 与 sum 相乘，并将乘积赋给 sum。
//① 定义变量 sum，并赋初值 1。
//② i 自增 1。
//③ 直到 i 超过 n。

// Created by Madeleine on 2026/2/13.
//