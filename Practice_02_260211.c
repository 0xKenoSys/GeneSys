#include <stdio.h>

int main() {
    int i =     10;

    while (i < 5) {
        printf("This will never be printed\n");
        i++;
    }
    printf("Loop finished. i = %d\n", i);   //printf后面一定要跟变量，否则会输出随机数据。要看warning，不能忽视

    return 0;
}
//另外，while 循环还有一个重要特点：如果循环条件一开始就不成立，那么循环体就一次也不执行。
//

//
//
//
//
// Created by 14423 on 2026/2/11.
//