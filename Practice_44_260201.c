#include <stdio.h>
#include <stdlib.h>

#define TOTAL 4

struct {
    char name[20];
    int num;
    char sex;
    char profession;
    union{
        float score;
        char course[20];
    } sc;
} bodys[TOTAL];

int main() {
    int i;
    for (i=0; i<TOTAL; i++) {
        printf("Input info: ");
        scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));
        if (bodys[i].profession == 's') {
            scanf("%f", &bodys[i].sc.score);
        }else {
            scanf("%s", bodys[i].sc.course);
        }
        fflush(stdin);
    }

    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    for(i=0; i<TOTAL; i++) {
        if(bodys[i].profession == 's') {
            printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course); //把最后一个%f改成%s就正常了
        }else {
            printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course);
        }
    }
    return 0;
}


//
// Created by Madeleine on 2026/2/1.
//