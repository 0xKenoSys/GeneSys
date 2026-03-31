#include <stdio.h>

void func2() {
    printf("KenoSys");
}

void func1() {
    printf("https://KenoSys.net/c/");
    func2();
}

int main() {
    func1();
    return 0;
}


//wrong version:
//#include <stdio.h>
//void func1(){
    //printf("http://c.biancheng.net");
    //void func2(){
        //printf("C语言小白变怪兽");
    //}
//}
//int main(){
    //func1();
    //return 0;
//}

// Created by Madeleine on 2026/1/30.
//