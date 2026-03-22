#include <iostream> //这两行是预处理指令。iostream包含了输入输出流的功能（用来cin和cout）;
#include <string>   //string包含了C++标准字符串类的功能（用来使用std::string）

int main() {    //int main()：程序的入口点，程序从这里开始执行
    std:: string input; //声明一个名为input的字符串变量，用来存放用户敲进去的字
    //不能少写一个冒号。在C++里，单个冒号是“标签”，搭配goto语句
    //那么在c++语法里::是什么意思？::叫做“作用域解析运算符Scope Resolution Operator”，可以理解为“属于”的意思
    //C++标准库里的所有东西都被装在一个叫std(standard)的大箱子（命名空间）里，防止和别人写的同名代码起冲突。std::string的意思就是：我要用std这个箱子里的string类型

    std::cout <<"欢迎使用命令行工具！"<< std::endl;   //cout和<<又是什么？endl又是什么？
    std::cout <<"输入'help'查看帮助，输入'exit'退出程序。" << std::endl;
                                                  //cout: stands for "Character OUTput"，代表标准输出流，通常就是屏幕/终端。
                                                  //<<：“流插入运算符”，把右边的数据推向左边的屏幕（cout）里展示出来
                                                  //std::endl(END Line)：它的作用有两个：一是换行（相当于敲了次回车），二是刷新输出缓冲区（强制把暂存的数据立刻显示到屏幕上）
                                                  //提问：冲刷缓冲区，比如呢？有啥情况要冲刷啊？冲刷哪里、什么时候积累的数据啊？

    //核心骨架：无限循环(RERL模式)
    while (true) {  //创建无限循环，只要不遇到break就一直运行
        std::cout << "命令行工具 > ";  //1.打印提示符(Print)
                                     //2.读取用户输入的一整行(Read)
        std::getline(std::cin, input);  //[&]又是什么东西？是编辑器提供的内联提示Inlay Hints。
                                              //在C++底层，getline函数需要直接修改input变量的内容，所以它接收的是变量的引用(Reference，符号为&)，而不是变量的拷贝。编辑器很贴心地用[&]标记出来，告诉你：“注意哦，这里传入的cin和input在函数内部是会被直接操作/修改的。”
                                     //3.解析并执行逻辑(Eval)   //Eval又是什么？ //REPL: Read, Eval(uate), Print, Loop。判断输入的是什么命令，并决定执行什么代码
        if (input == "exit" || input == "quit") {
            std :: cout << "正在退出命令行工具，再见！" << std::endl;
            break;  //遇到exit时，打破循环，程序结束
        }else if (input == "help"){ //提问：前文有了break，后文的else就失效了，这种情况不冗余吗？ //为了可读性。传达逻辑“这些条件是互斥的，只会选择一个分支走”
            std::cout << "当前支持的命令：help; exit" << std::endl;
        }else if (input.empty()) {  //input.empty()又是什么语法？怎么和自然语言这么接近？ //面向对象（OOP）语法。针对input这个对象，去问它是不是空的。.empty()是属于这个对象的一个动作（成员函数/方法）
            continue;   //如果用户直接按了回车，什么都不做，直接开始下一轮循环
            //可是这个continue;看起来好像不起作用，是冗余的。的确冗余。不过我猜测还是为了可读性吧。
        }else {
            std::cout << "未知命令：" << input << "（待开发...）" << std::endl;   //什么叫命令行？Command Line Interface 基于文本的交互界面
        }
    }
    return 0;
}


//
// Created by Madeleine on 2026/2/28.
