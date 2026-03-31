#include <stdio.h>

int sum(int m, int n);

int main() {
    int begin = 10, end = 150;
    int result = sum(begin, end);
    printf("The sum from %d to %d is %d\n", begin, end, result);
    return 0;
}

int sum(int m, int n) {
    int i, sum=0;
    for (i=m; i<=n; i++) {
        sum+=i;
    }
    return sum;
}



//#include <stdio.h>

//int a = 10, b = 20, c;
//错误：不能出现加减乘除运算
//c = a + b;

//错误：不能出现对其他函数的调用
//printf("KenoSys.net");

//int main() {
    //return 0;
//}


//
// Created by Madeleine on 2026/1/30.
//