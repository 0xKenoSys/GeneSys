#include <stdio.h>

int main() {
    int i, j, total_energy;

    for (i = 1; i < 50; i++);
    {
        j = i;
            if (j % 3 == 0 && j % 5 == 0){
                goto end_loop;
            }
            printf("捕获的total_energy总和为：%d\n", total_energy);

    }

    end_loop:
  printf("[WARNING]系统过载！在 %d 处强制停机！\n", j);


    return 0;
}









//
// Created by Madeleine on 2026/2/4.
//