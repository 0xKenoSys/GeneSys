#include <stdio.h>
int main() {
    struct {
        char *name;
        int num;
        int age;
        char group;
        float money;
    } stu1;

    stu1.name ="Tom";
    stu1.num = 12;
    stu1.age = 18;
    stu1.group = 'A';
    stu1.money = 1000000.0;

    printf("%s的学号是%d，年龄是%d，在%c组，今年的零花钱是%.1f！\n", stu1.name, stu1.num, stu1.age, stu1.group, stu1.money);

    return 0;
}


//struct stu {
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//};

//struct stu {
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//} stu1, stu2;

//struct {
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//}stu1, stu2;

//struct {
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//} stu1, stu2 = {"Tom", 12, 18, 'A', 100000.0} ;


//
// Created by Madeleine on 2026/2/1.
//