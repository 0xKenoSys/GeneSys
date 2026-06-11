#include <stdio.h>
int main() {
    char choice;
    int money = 0, price = 0, change = 0;

    printf("[System] Welcome backe to the Black Market.\nMenu:\n A: 神经镇静剂($3)\n B:义体润滑油($5)\n C:赛博精神病解药($10)\n");
    printf("Please insert money: $");
    scanf("%d", &money);
    printf("Please select item(A/B/C): ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'A':
            price = 3;
            if (money >= price) {
                //判断大小之后再相减，否则会算出负数，出现无效计算
                //逻辑：前提是交易成功之后，再算账
                change =money - price;
                printf("[Success] Dispensing 神经镇静剂…\n");
                printf("Change returned: $%d\n", change);
            }else {
                printf("[Error] Insufficient funds.Returning $%d\n", money);
            }
            break;
        case 'B':
            price = 5;
            if (money >= price) {
                change =money - price;
                printf("[Success] Dispensing 义体润滑油…\n");
                printf("Change returned: $%d\n", change);
            }else {
                printf("[Error] Insufficient funds. Returning $%d\n", money);
            }
            break;
        case 'C':
            price = 10;
            if (money >= price) {
                change =money - price;
                printf("[Success] Dispensing 赛博精神病解药…\n");
                printf("Change returned: $%d\n", change);
            }else {
                printf("[Error] Insufficient funds. Returning $%d\n", money);
            }
            break;
        case 'D':
            price = 0;
            if (money > price) {
                printf("小调皮，做习题，习题难，今晚请你去裕昌吃火锅！");
            }else {
                printf("我有件你不知道的事要告诉你。\n什么事呢？\n我也不知道。");
            }
            break;
        default:
            printf("无效选择，吞币不退");
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/8.

//新的挑战：Project "Cyber Vending Machine"
//Switch Case 这一节你确实通关了“教学模式”。
//现在，我要给你一个**“实战模式”**的题目。
//这道题不仅考Switch，还考你的逻辑嵌套（Logic Nesting）。也就是说，在 case 里，还要再写 if。

//题目名称：黑市自动贩卖机
//场景描述：
//你走在这个赛博世界的贫民窟，路边有一台破旧的自动贩卖机。它只接受硬币，而且脾气不太好。
//商品列表：
 //* A: 神经镇静剂 (Cola) —— 售价 3 元
 //* B: 义体润滑油 (Coffee) —— 售价 5 元
 //* C: 赛博精神病解药 (Energy Drink) —— 售价 10 元
 //* D: 只有极客才知道的秘密 (Hidden Menu) —— 售价 0 元

//需求（Requirements）：
 //* 程序启动时，先打印菜单（显示商品代号和价格）。
 //* 第一步输入： 询问用户投入多少钱（整数 int money）。
 //* 第二步输入： 询问用户选择哪个商品（字符 char choice）。
 //* 逻辑处理（Core Logic）：
   //* 使用 switch (choice) 来判断用户选了 A, B, C 还是 D。
   //* 关键难点： 在每一个 case 内部，你必须检查钱够不够！
     //* 如果钱够（>= 价格）： 打印“购买成功”，并显示“找零：XX 元”。
     //* 如果钱不够： 打印“钱不够，穷鬼，把钱退你”，并显示退回的金额。
   //* 秘密菜单 D： 如果选 D，不需要钱，直接打印一句只有KenoSys能看懂的骚话（你自己定）。
   //* 无效输入： 如果选了 E、F 等不存在的选项，打印“无效选择，吞币不退”。
//代码提示：
 //* 你需要用到 switch 嵌套 if-else。
 //* 你需要处理 money - price 的数学运算。
 //* 输入字符前，最好用 getchar(); 吞掉输入金额后的那个回车，或者用我刚才教你的 scanf(" %c", ...)。



//Output Example（预期输出）：
//[System] Welcome to the Black Market.
//Menu:
//A: Cola ($3)
//B: Coffee ($5)
//C: Energy Drink ($10)

//Please insert money: 4
//Please select item (A/B/C): B

//[Error] Insufficient funds. Returning $4.

//或者：
//Please insert money: 20
//Please select item (A/B/C): C

//[Success] Dispensing Energy Drink...
//Change returned: $10.
