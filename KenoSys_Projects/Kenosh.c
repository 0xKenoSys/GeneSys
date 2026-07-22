#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_ARGS 100
#define MAX_INPUT 1024

//辅助函数：负责清理动态分配的参数内存，防止内存泄露
void free_args(char **args) {
    for (int i = 0; args[i] != NULL; i++) {
        free(args[i]);
        args[i] = NULL;
    }
}

//核心函数：自定义的非破坏性词法分析器
 void parse_command(const char *input, char **args) {
    int argc = 0;
    const char *p = input;

    while (*p != '\0') {
        //1. 跳过所有前导空白字符
        while (*p == ' ' || *p == '\t' || *p == '\n') {
            p++;
        }
        if (*p == '\0') break;

        //2. 探查特殊控制符号（重定向、管道）
        if (*p == '>' || *p == '<' || *p == '|') {
            //前瞻逻辑（Lookahead）：判断是否是连续的 >>
            if (*p == '>' && *(p + 1) == '>') {
                args[argc] = malloc(3);
                strcpy(args[argc], ">>");
                p += 2;
            }else {
                args[argc] = malloc(2);
                args[argc][0] = *p;
                args[argc][1] = '\0';
                p++;    //指针步进一格
            }
            argc++;
            continue;
        }

        //3. 提取常规命令和参数
        const char *start = p;  //锚定当前单词的起始内存地址
        //持续向后推进，直到遇到空格、结束符或特殊符号
        while (*p != '\0' && *p != ' ' && *p != '\t' && *p != '\n' && *p != '>' && *p != '<' && *p != '|') {
            p++;
        }

        //利用指针算术计算出当前参数的具体长度
        int len = p -start;
        args[argc] = malloc(len + 1);
        strncpy(args[argc], start, len);
        args[argc][len] = '\0'; //必须手动封口
        argc++;

        //安全边界控制
        if (argc >= MAX_ARGS - 1) break;
    }

    //execvp要求参数数组必须以NULL结尾
    args[argc] = NULL;
}

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("Kenosh> ");

        //一、读取输入
        if (!fgets(input, MAX_INPUT, stdin)) break;
        input[strcspn(input, "\n")] = 0;    //去掉换行符

        //初始化args数组为NULL
        memset(args, 0, sizeof(args));

        //二、执行精密解析
        parse_command(input, args);

        //如果只是敲了回车或空格，就清理后跳过
        if (args[0] == NULL) {
            free_args(args);
            continue;  //
        }

        //三、内置命令强拦截
        //拦截exit
        if (strcmp(args[0], "exit") == 0) {
            printf("Kenosh: 已退出，再见！\n");
            break;
        }

        //拦截cd(Change Directory)
        if (strcmp(args[0], "cd") == 0) {
            char *target_dir = args[1];
            //准备一个缓冲区，用来存放拼接后的完整路径
            char expanded_path[MAX_INPUT];

            //如果没有参数，或者参数是"~"，默认跳转到家目录
            if (target_dir == NULL || strcmp(target_dir, "~") == 0) {
                target_dir = getenv("HOME"); //获取系统的HOME环境变量
                if (target_dir == NULL) {
                    fprintf(stderr, "Kenosh: 无法获取 HOME 环境变量\n");
                    continue;
                }
            } else if (strncmp(target_dir, "~/", 2) == 0) {
                char *home = getenv("HOME");
                if (home != NULL) {
                    snprintf(expanded_path, sizeof(expanded_path), "%s%s", home, target_dir +1);
                    target_dir = expanded_path;
                }else{
                    fprintf(stderr, "Kenosh: 无法获取 HOME 环境变量\n");
                    free_args(args);
                    continue;
                }
            }

                //亲自下场，调用内核API改变当前进程的目录
                //printf("DEBUG: 实际交给 chdir 的路径是 -> [%s]\n", target_dir);

            if (chdir(target_dir) != 0){
                    perror("Kenosh: cd 失败");
            }

                //核心修正：拦截完毕进入下一次循环前，必须释放堆区内存
            free_args(args);
            continue;   //核心：拦截完毕，直接进入下一次循环，绝对不能fork
        }

        //拦截pwd(Print Working Directory)
        //严格来说pwd可以作为一个外部程序(/bin/pwd)执行
        //但把它做成内置命令能显著提升性能，避免fork开销
        if (strcmp(args[0], "pwd") == 0) {
            char cwd[MAX_INPUT];
            //获取当前工作目录
            if (getcwd(cwd, sizeof(cwd)) != NULL) {
                printf("%s\n", cwd);
            }else {
                perror("Kenosh: pwd 失败");
            }
            free_args(args);
            continue;   //同样，拦截完进入下一次循环
        }

        //内置命令强拦截结束，如果代码走到这，说明不是内置命令，fork后执行外部程序
        pid_t pid = fork(); //裂变

        if (pid == 0) {
            //子进程，在execvp之前，必须先处理可能存在的I/O重定向
            int fd_out = -1;
            int i = 0;

            //遍历当前解析出来的参数数组，寻找重定向符号
            while (args[i] != NULL) {
                if (strcmp(args[i], ">") == 0) {
                    //防御性编程：确保'>'后面确实跟了文件名
                    if (args[i + 1] == NULL) {
                        fprintf(stderr, "Kenosh: 语法错误，缺少重定向目标文件\n");
                        exit(1);
                    }

                    //步骤一：打开（或创建）目标文件
                    //O_WRONLY: 只写模式
                    //O_CREAT: 如果文件不存在就创建它
                    //O_TRUNC: 如果文件已存在。清空它的内容（这就是'>'覆盖的语义）
                    //0644: 新文件的权限掩码，所有者读写，其他人只读
                    fd_out = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

                    if (fd_out < 0) {
                        perror("Kenosh: 无法打开重定向文件");
                        exit(1);
                    }

                    //步骤二：核心欺骗操作(dup2)
                    //dup2(oldfd, newfd)会把newfd关闭，并让newfd指向oldfd所指向的文件
                    //这里我们把STDOUT_FILEND（也就是1）指向刚刚打开的文件fd_out
                    if (dup2(fd_out, STDOUT_FILENO) < 0) {
                        perror("Kenosh: 重定向输出失败");
                        exit(1);
                    }

                    //复制完成后，原来的fd_out编号就不需要了，及时关闭以节约资源
                    close(fd_out);

                    //步骤三：截断参数数组
                    //ls只需要["ls", NULL]
                    //我们把'>'所在的位置强行改为NULL，这样execvp就看不到后面的重定向信息了
                    args[i] = NULL;

                    //找到一个'>'并处理完即可跳出循环
                    break;
                }
                i++;
            }

            //处理完所有重定向后，再执行外部程序
            //此时，子进程的标准输出已经被绑定到文件上，execvp替换进程映像后，这个文件描述符的映射依然保留
            execvp(args[0], args);
            perror(args[0]);
            exit(127);
        }else if (pid > 0) {
            //父进程（Shell本体）：等待子进程结束
            wait(NULL);   //wait(NULL)就是waitpid(-1, NULL, 0)的简写。waitpid要读pid和进程表的退出状态然后内核删掉，否则已死但未销户就是僵尸进程
        }else {
            perror("fork失败");
        }

            //五、清理本次循环产生的动态Token
        free_args(args);
    }
    return 0;
}


// Created by Yingmei Zhang on 15/7/2026.
