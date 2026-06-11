#include <stdio.h>
int main() {
    int nums[10] = {0, 1, 6, 10, 23, 34, 100, 177, 296, 999};
    int i, num, thisindex = -1;

    printf("Input an integer: ");
    scanf("%d", &num);
    for (i=0; i<10; i++) {
        if (nums[i] == num) {
            thisindex = i;
            break;
        }else if (nums[i] > num) {
            break;
        }
    }
    if (thisindex < 0) {
        printf("%d isn't in the array.\n", num);
    }else {
        printf("%d is in the array, its index is %d.\n", num, thisindex);
    }

    return 0;
}


//
// Created by Madeleine on 2026/1/29.
//