#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *val = getenv("SHELL");
    //char *getenv(const char *name); 存在一个叫 getenv 的函数，收一个字符串，还一个字符串指针
    if (val != NULL)
        printf("SHELL = %s\n", val);
    else
        printf("SHELL is not set\n");
    exit(EXIT_SUCCESS);

}
//
// Created by Yingmei Zhang on 19/7/2026.
//
