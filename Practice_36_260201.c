#include <stdio.h>
int main() {
    struct {
        char *name;
        int num;
        int age;
        char group;
        float score;
    } stu1 = { "Tom", 12, 18, 'A', 136.5 },
*pstu = &stu1;

    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f!\n", (*pstu).name, (*pstu).num, (*pstu).age, (*pstu).group, (*pstu).score);
    printf("%s的学号是%d，年龄是%d，在%c组，今年的成绩是%.1f! \n", pstu->name, pstu->num, pstu->age, pstu->group, pstu->score);

    return 0;
}


//
// Created by Madeleine on 2026/2/1.
//

//结构体
//struct stu{
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//}stu1 = {"Tom", 12, 18, 'A', 136.5};
//结构体指针
//struct stu *pstu = &stu1;

//struct stu{
    //char *name;
    //int num;
    //int age;
    //char group;
    //float score;
//}stu1 = {"Tom", 12, 18, 'A', 136.5 }, *pstu = &stu1;

//struct stu*pstu = &stu1;

//struct stu*pstu = stu1;


//struct stu *pstu = &stu;
//struct stu *pstu = stu;

//(*pointer).memberName

//pointer->memberName







