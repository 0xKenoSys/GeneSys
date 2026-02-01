#include <stdio.h>

int max(int *intArr, int len) {
    int i, maxValue = intArr[0];
    for (i=1; i<len; i++) {
        if (maxValue < intArr[i]) {
            maxValue = intArr[i];
        }
    }

    return maxValue;
}

int main() {
    int nums[6], i;
    int len = sizeof(nums)/sizeof(int);
    for (i=0; i<len; i++) {
        scanf("%d", nums+i);
    }
    printf("Max value is %d!\n", max(nums, len));

    return 0;

}
//
// Created by Madeleine on 2026/2/1.
//

//int max(int intArr[6], int len) {
    //int i, maxValue = intArr[0];
    //for (i=1; i<len; i++) {
        //if (maxValue < intArr[i]) {
            //maxValue = intArr[i];
        //}
    //}
    //return maxValue;
//}

//int max(int intArr[], int len) {
    //int i, maxValue = intArr[0];
    //for (i=1; i<len; i++) {
        //if (maxValue < intArr[i]) {
            //maxValue = intArr[i];
        //}
    //}
    //return maxValue;
//}






















