#include<stdio.h>
int main() {
    char letter;
    int year;
    char url[30];
    float price;

    scanf("%c", &letter);
    scanf("%d",&year);
    scanf("%s",url);
    scanf("%f",&price);

    printf("The first letter of the word desk is %c.\n", letter);
    printf("Quoth the raven, my birth year is %d, and my personal website is %s. The price of my stud earring is %g￥.\n", year, url, price);

    return 0;
}


//
// Created by Madeleine on 2026/1/23.
//