#include <stdio.h>
int main() {
    int isVip = 0;
    float cost = 120.5;
    int hasCoupon = 1;

    if (isVip || (cost > 100 && hasCoupon)) {     //写成if (isVip || (cost > 100 && hasCoupon))即可，非0即真
        printf("打折");                           //不要写(isVip == 1 || (cost > 100 && hasCoupon == 1))
    }else {
        printf("NO no");
    }
    return 0;
}

//第七关：极客的优惠券 (Logic Priority) //为什么这个题要叫Logic Priority？没懂啊
//题目： 某商店的打折规则如下：
//* 只要你是 会员 (isVip)，就打折。
//* 或者，如果你的 消费金额 (cost) 超过 100 并且 有优惠券(hasCoupon)，也打折。
//<!— end list -->
//* 代码任务： 定义三个变量 int isVip = 0, float cost = 120.5, int hasCoupon = 1。写一个 if 语句，用最精简的逻辑表达式把上述规则写出来。
//
// Created by Madeleine on 2026/2/7.
//