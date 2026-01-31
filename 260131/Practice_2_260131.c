#include <stdio.h>

int n = 10;

void func1() {
    int n = 20;
    printf("func1 n: %d\n", n);
}

void func2(int n) {
    printf("func2 n: %d\n", n);
}

void func3() {
    printf("func3 n: %d\n", n);
}

int main() {
    int n = 30;
    func1();
    func2(n);
    func3();

    {
        int n = 40;
        printf("block n: %d\n", n);
    }
    printf("main n: %d\n", n);

    return  0;

}
//int f1(int a){
    //int b,c;
    //return a+b+c;
//}
//int main(){
    //int m,n;
    //return 0;
//}
// Created by Madeleine on 2026/1/31.
//int a, b;
//void func1(){
    //T0D0:
//}

//float x, y;
//int func2()[
    //T0D0:
//}

//int main(){
    //T0D0:
    //return 0;
//}