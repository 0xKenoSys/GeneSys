#include <stdio.h>

int main() {
    int i;
    int total_energy = 0;   //声明一个变量时，要初始化，否则它的值是随机的内存垃圾

    for (i = 1; i <= 50; i++)   //这里不能有分号，分号代表语句结束
    {
        if (i % 3 == 0 && i % 5 ==0) {
            printf("[WARNING]系统过载！在 %d 处强制停机！\n", i);
            goto end_loop;
        }

        else if (i % 3 == 0){
            printf("[Noise]丢弃：%d\n", i);
        }
        else if (i % 5 == 0){
            printf("[Signal]捕获：%d\n", i);
            total_energy += i;
        }
    }
    end_loop:
    printf("捕获的total_energy总和为：%d\n", total_energy);

    return 0;
}

//
// Created by Madeleine on 2026/2/4.
//

//1. 建立循环： 遍历从 1 到 50 的所有整数。
//2. 识别噪音（Noise）： 如果这个数字 只能被 3 整除（例如 3, 6, 9...），打印 "[Noise] 丢弃: %d\n"。
//3. 捕获信号（Signal）： 如果这个数字 只能被 5 整除（例如 5, 10, 20...），打印 "[Signal] 捕获: %d\n"，并且把这个数字加到一个叫 total_energy 的变量里。
//4. 系统崩溃（Critical）： 如果这个数字 既能被 3 整除，又能被 5 整除（比如 15），这代表系统过载！
//• 打印 "[WARNING] 系统过载！在 %d 处强制停机！\n"。
//• 立刻使用 goto 语句跳出整个循环，直接跳转到结尾。
//5. 汇报： 在程序的最后（循环之外，标签之后），打印出停机前捕获的 total_energy 总和。
//• 它考察了你的 % (取模) 运算逻辑（这是极客的直觉）。
//• 它考察了 if - else if 的优先级陷阱（先判断同时被3和5整除，还是先判断其他的？）。
//• 它给了你刚学的 goto 一个真正的用武之地（模拟系统崩溃退出）。


