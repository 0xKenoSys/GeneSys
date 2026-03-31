#include <stdio.h>//这么屌，第一次遇到第一行不是int main() {的代码

void success() {
    puts("Succeed!");
}

void fail() {
    puts("Failed!");
}

int main() {
    int isOK = 1; // 1表示真，0表示假
    isOK ? success() : fail();
    return 0;
}
//其实没搞懂这个代码在干嘛。怎么莫名其妙就输出了一个Succeed!


//
// Created by Madeleine on 2026/1/29.
//