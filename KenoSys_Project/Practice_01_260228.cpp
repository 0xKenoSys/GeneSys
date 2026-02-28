#include <iostream>
#include <string>

int main() {
    std:: string input; //不能少写一个冒号。在C++里，单个冒号是“标签”，搭配goto语句

    std::cout <<"欢迎使用命令行工具！"<< std::endl;
    std::cout <<"输入'help'查看帮助，输入'exit'退出程序。" << std::endl;

    //核心骨架：无限循环(RERL模式)
    while (true) {
        std::cout << "命令行工具 > ";  //1.打印提示符(Print)
                                    //2.读取用户输入的一整行(Read)
        std::getline(std::cin, input);
                                    //3.解析并执行逻辑(Eval)
        if (input == "exit" || input == "quit") {
            std :: cout << "正在退出命令行工具，再见！" << std::endl;
            break;  //遇到exit时，打破循环，程序结束
        }else if (input == "help"){
            std::cout << "当前支持的命令：help; exit" << std::endl;
        }else if (input.empty()) {
            continue;   //如果用户直接按了回车，什么都不做，直接开始下一轮循环
        }else {
            std::cout << "未知命令：" << input << "（待开发...）" << std::endl;
        }
    }
    return 0;
}


//
// Created by Madeleine on 2026/2/28.
