#include <stdio.h>
int main() {
    char c='k';
    int i=1, j=2, k=3;
    float x=3e+5, y=0.85;//300000
    int result_1 = 'a'+5<c, result_2 = x-5.25<=x+y;
    printf("%d, %d\n", result_1, -i-2*j>=k+1 );
    printf("%d, %d\n", 1<j<5, result_2 );//假如j是5，1<10和1<5都为真，会输出1,所以要写成(1<j)&&(j<5)
    printf("%d, %d\n", i+j+k==-2*j, k==j==i+5 );//先算k==j(3==2)假的，变成0,再算0==i+5(0==6)假的，还是0
    return 0;
}




//在if和while的判断里，只要不是0,全算作真
// Created by Madeleine on 2026/1/28.
//