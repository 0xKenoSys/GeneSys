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

        //一、读取输入
        if (!fgets(input, 1024, stdin)) break;
        input[strcspn(input, "\n")] = 0;    //去掉换行符

        //二、简易解析（按空格切分）
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        //三、执行(fork-exec-wait)
        if (args[0] == NULL) continue;  //如果只是敲了回车就跳过

        //四、内置命令强拦截
        //拦截exit
        if (strcmp(args[0], "exit") == 0) {
            printf("Kenosh: 已退出，再见！\n");
            break;
        }

        //拦截cd(Change Directory)
        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "Kenosh: 期望给 cd提供一个参数\n");
            }else {
                //亲自下场，调用内核API改变当前进程的目录
                if (chdir(args[1]) != 0) {
                    perror("Kenosh: cd 失败");
                }
            }
            continue;   //核心：拦截完毕，直接进入下一次循环，绝对不能fork
        }

        //拦截pwd(Print Working Directory)
        //严格来说pwd可以作为一个外部程序(/bin/pwd)执行
        //但把它做成内置命令能显著提升性能，避免fork开销
        if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            //获取当前工作目录
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            }else {
                perror("Kenosh: pwd 失败");
            }
            continue;   //同样，拦截完进入下一次循环
        }

        //内置命令强拦截结束，如果代码走到这，说明不是内置命令，fork后执行外部程序
        pid_t pid = fork(); //裂变

        if (pid == 0) {
            //子进程：执行命令
            if (execvp(args[0], args) == -1) {
                perror("命令执行失败");
            }
            exit(1);
        }else if (pid > 0) {
            //父进程（Shell本体）：等待子进程结束
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
