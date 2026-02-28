#include <stdio.h>
int main() {
    int nums[10] = {1, 10, 6, 296, 177, 23, 0, 100, 34, 99 };
    int i, num, thisindex = -1;

    printf("Input an integer: ");
    scanf("%d", &num);
    for (i=0; i<10; i++) {
        if (nums[i] == num) {
            thisindex = i;
            break;
        }
    }
    if (thisindex < 0) {
        printf("%d isn't in the arrey.\n", num);
    }else {
        printf("%d is in the array, it's index is %d.\n", num, thisindex);
    }

    return 0;
}


// Created by Madeleine on 2026/1/29.
//