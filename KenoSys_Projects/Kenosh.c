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
            char *target_dir = args[1];
            //准备一个缓冲区，用来存放拼接后的完整路径
            char expanded_path[1024];

            //如果没有参数，或者参数是"~"，默认跳转到家目录
            if (target_dir == NULL || strcmp(target_dir, "~") == 0) {
                target_dir = getenv("HOME"); //获取系统的HOME环境变量
                if (target_dir == NULL) {
                    fprintf(stderr, "Kenosh: 无法获取 HOME 环境变量\n");
                    continue;
                }
            }

            //如果是以"~/"开头(比如"~/Desktop")
            else if (strncmp(target_dir, "~/", 2) == 0) {
                char *home = getenv("HOME");
                if (home == NULL) {
                    fprintf(stderr, "Kenosh: 无法获取 HOME 环境变量\n");
                    continue;
                }

                //核心操作：安全拼接字符串
                //target_dir + 1是精髓
                //如果target_dir是"~/Desktop", target_dir + 1 就变成了"/Desktop"
                //我们把 HOME 和"/Desktop"拼起来，塞进expanded_path
                snprintf(expanded_path, sizeof(expanded_path), "%s%s", home, target_dir + 1);

                //把要跳转的目标指向我们刚刚拼接好的新字符串
                target_dir = expanded_path;
            }


                //亲自下场，调用内核API改变当前进程的目录
                //printf("DEBUG: 实际交给 chdir 的路径是 -> [%s]\n", target_dir);

                if (chdir(target_dir) != 0){
                    perror("Kenosh: cd 失败");
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
            execvp(args[0], args);
            perror(args[0]);
            exit(127);
        }else if (pid > 0) {
            //父进程（Shell本体）：等待子进程结束
            wait(NULL);   //wait(NULL)就是waitpid(-1, NULL, 0)的简写。waitpid要读pid和进程表的退出状态然后内核删掉，否则已死但未销户就是僵尸进程
        }else {
            perror("fork失败");
        }
    }
    return 0;
}

//
// Created by Yingmei Zhang on 15/7/2026.
//
