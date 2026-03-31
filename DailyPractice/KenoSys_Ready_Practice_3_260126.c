#include<stdio.h>
int main() {
    int is_lazy;

    do {
        printf("\n---------------------------------------------------------------\n");
        printf("Are you still thinking about KFC?(1 for Yes, 0 for NO/Work):");
        scanf("%d", &is_lazy);
        if(is_lazy != 0) {
            printf("Error: Gluttony detected! GO FUCKING BACK TO CODE, TRASH!\n");
        }
    }while (is_lazy != 0);
        printf("\nSystem Status: Normal. Welcome back, KenoSys.\n");

    //printf("Are you a lazy pig?(1 for Yes, 0 for No):");
    //scanf("%d", &is_lazy);

    //if (is_lazy==1) {
        //printf("GO FUCKING BACK TO CODE, TRASH!\n");
    //}else{
        //printf("Good KenoSys.\n");
    //}
    return 0;
}


//
// Created by Madeleine on 2026/1/26.
//