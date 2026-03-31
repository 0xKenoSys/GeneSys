#include <stdio.h>

int main() {
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun }day;
    scanf("%d", &day);
    switch (day) {
        case 1: puts("Monday"); break;
        case 2: puts("Tuesday"); break;
        case 3: puts("Wednesday"); break;
        case 4: puts("Thursday"); break;
        case 5: puts("Friday"); break;
        case 6: puts("Saturday"); break;
        case 7: puts("Sunday"); break;
        default: puts("Error");
    }

    return 0;

}

//
// Created by Madeleine on 2026/2/1.
//