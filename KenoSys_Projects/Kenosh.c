#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    char input[1024];
    char *args[100];

    while (1) {
        printf("Kenosh> ");

        if (!fgets(input, 1024, stdin)) break;
        input[strcspn(input, "\n")] = 0;    //去掉换行符

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        if (args[0] == NULL) continue;

        pid_t pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("命令执行失败");
            }
            exit(1);
        }else if (pid > 0) {
            wait(NULL);
        }else {
            perror("fork失败");
        }
    }
    return 0;
}

//
// Created by Yingmei Zhang on 15/7/2026.
//
