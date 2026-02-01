#include <stdio.h>

int main() {
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } day;
    scanf("%d", &day);
    switch (day) {
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Friday"); break;
        case Fri: puts("Saturday"); break;
        case Sat: puts("Sunday"); break;
        default: puts("Error");
    }
    return 0;
}

//
// Created by Madeleine on 2026/2/1.
//