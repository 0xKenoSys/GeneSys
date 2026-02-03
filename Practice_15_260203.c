#include <stdio.h>
#include <stdlib.h>

#define N 3;

struct stu {
    char name[10];
    int num;
    int age;
    float score;
}boys[N], boy, *pboys;

int main() {
    FILE *fp;
    int i;
    pboys = boys;
    if ( (fp=fopen("/Users/madelin/Desktop/Limbo/Inbox/demo.txt", "wb+")) == NULL ) {
        printf("Cannot open file. Press any key to exit.\n");
 6        exit(1);
    }

    printf("Input data:\n");
    for (i=0; i<N; i++,pboys++) {

        scanf("%s %d %d %f\n", pboys->name, &pboys->num, &pboys->age, &pboys->score);
    }
    fwrite(boys, sizeof(struct stu), N, fp);//写入三条学生信息
    fseek(fp, sizeof(struct stu), SEEK_SET); //移动指针位置
    fread(&boy, sizeof(struct stu), 1, fp ); //读取一条学生信息
    printf("%s %d %d %f\n", boy.name, boy.num, boy.age, boy.score);

    fclose(fp);
    return 0;
}

//
// Created by Madeleine on 2026/2/3.
//

//void rewind ( FILE *fp );

//int fseek ( FILE *fp, long offset, int origin );
