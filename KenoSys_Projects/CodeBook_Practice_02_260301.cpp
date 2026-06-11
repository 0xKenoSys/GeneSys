#include <codecvt>      //为什么codecvt没有用上？
#include <iostream>     //用于控制台的输入输出：cin,cout
#include <fstream>      //用于文件读写操作：保存和读取密码文件
#include <vector>       //引入向量容器，用于存储可变数量的密码记录
#include <string>       //提供字符串处理功能

using namespace std;    //使用标准命名空间，这样在代码中就不需要每次都写std::cout或std::string

//密码记录结构体
struct PasswordRecord { //用来把一条密码记录的三个要素打包在一起
    string platform;
    string username;
    string password;

};

class PasswordManager { //声明密码管理器的主体类
private:                //定义类的私有属性，只能在类内部访问：
    vector<PasswordRecord> records;     //records：一个vector容器，在内存中存放所有的PasswordRecord
    string filename = "data.bin";       //filename：设定存储数据的文件名为"data.bin"
    char cryptoKey = 'X'; //基础的异或密钥//设定一个简单的字符'X'作为加密/解密密钥

    //极简异或（XOR）加密/解密逻辑（用于防止明文直接存储）//由于XOR运算的数学特性，同一个函数既可以用来加密，也可以用来解密
    string encryptDecrypt(const string&input) const {   //const是什么东西？
        string output = input;      //这个赋值的意义在哪里 //size_t是什么？input.size()是什么？咋这么接近自然语言？
        for (size_t i=0; i<input.size();i++) {    //通过一个for循环，将输入额度字符串中的每一个字符都与cryptoKey(即'X')进行异或运算，从而将明文变乱码，或者将乱码还原为明文（这一步是不是可以单步运算，或者如何看见内存的变化？以及，c++和c语言在内存这一块的区别是什么）
            output[i]=input[i]^cryptoKey;         //^是什么意思
        }
        return output;                  //return output;是在干嘛？
    }

    //将数据保存到本地文件
    void saveToFile() {     //定义了一个名为saveToFile的私有方法，负责把内存里(records列表)的最新密码数据写入到本地硬盘的文件中
        ofstream file(filename, ios::trunc);    //ofstream：代表“输出文件流”(Output File Stream)，专门用于向文件写入数据。filename:之前定义的data.bin。ios::trunc:这是一个非常重要的文件打开模式(Truncate)，它的作用是：如果data.bin已经存在，打开它时会清空里面原有的所有内容，这样可以保证每次保存时，写入的都是当前列表里最新、最完整的数据，而不是和旧数据混杂在一起
        if (!file.is_open()) {  //安全防错机制。尝试打开文件后，检查是否成功打开（比如可能因为权限不足导致打开失败）。如果失败，在屏幕上打印错误提示，并直接return结束这个保存动作。
            cout<<"错误：无法保存文件。"<<endl; //!file.is_open()这个语法好接近自然语言？
            return;
        }
        for (const auto& record:records) {  //这是一个现代C++的“范围for循环”。它会依次遍历records列表里的每一个密码记录（record）。使用const auto&是为了提高性能，直接引用原数据而不做多余的拷贝//求细说、别的实践？
            file << encryptDecrypt(record.platform) << "\n" //循环体内部，依次处理当前记录的platform、username和password
            << encryptDecrypt(record.username) << "\n"      //在写入文件file<<之前，分别将这三个字段放进了encryptDecrypt(...)函数中进行处理。也就是说，保存到本地文件里的不是明文，而是经过异或加密的乱码
            << encryptDecrypt(record.password) << "\n";     //每一个字段后面都紧跟了一个<<"\n"*（换行符），这与后面的loadFromFile函数遥相呼应————存的时候每个字段占一行。读的时候用getline每次刚好读一行
        }
        file.close();   //所有的记录都循环写入完毕后，关闭文件。这是一个好习惯，可以确保数据从内存缓冲区真正写入硬盘，并释放操作系统资源
    }

    //从本地文件加载数据
    void loadFromFile() {       //负责在程序启动时从data.bin读取数据
        ifstream file(filename);
        if (!file.is_open())return;//文件不存在则跳过

        string p,u,pwd;
        while (getline(file, p) && getline(file, u) && getline(file, pwd)) {    //这是一个巧妙的读取循环。它使用getline每次尝试从文件读取三行（分别存入临时变量p,u,pwd代表平台、账号、密码）。只要能成功读取三行，循环就继续。
            records.push_back(PasswordRecord{   //将读取到的数据存入records列表中 //存入时调用了encryptDecrypt函数将文件中加密存放的内容还原成了明文   //为什么要这么做？是输出要用吗？
                encryptDecrypt(p),
                encryptDecrypt(u),
                encryptDecrypt(pwd)
            });
        }
        file.close();   //读取完毕后关闭文件
    }

public: //公共方法与用户交互
    PasswordManager() { //PasswordManager()构造函数。在main函数中创建PasswordManager对象时，它会自动调用loadFromFile()，把之前保存的密码加载到内存里
        loadFromFile();
    }
    //添加新密码
    void addRecord() {  //添加新密码的功能  //通过cout和cin提示并获取用户输入的平台、用户名和密码，存入一个新的newRecord结构体中
        PasswordRecord newRecord;
        cout << "\n请输入平台名称：";
        cin >> newRecord.platform;
        cout << "请输入用户名/邮箱：";
        cin >> newRecord.username;
        cout << "请输入密码：";
        cin >> newRecord.password;

        records.push_back(newRecord);   //将新记录追加到内存列表中。 //什么是内存列表，是records列表吗？
        saveToFile();   //调用保存函数，将更新后的列表加密并写入本地文件
        cout <<">>记录添加成功并已安全保存！\n";
    }

    //显示所有密码
    void displayRecords() { //查看所有密码的功能
        if (records.empty()) {  //首先检查records是否为空，如归为空则提示并直接返回（return）
            cout << "\n>>当前密码本为空。\n";
            return;
        }

        cout << "\n你的密码本" << endl;
        for (size_t i=0; i < records.size(); ++i) { //如果不为空，则通过for循环遍历records列表，将每一个平台、账号、密码格式化后打印在屏幕上
            cout << "[" << i+1 <<"]平台：" << records[i].platform << "｜账号：" << records[i].username << "｜密码：" << records[i].password << endl;
        }
        cout << "\n" << endl;
    }
};

int main() {    //主程序逻辑。main函数入口，实例化了PasswordManager为manager，并打印欢迎语
    PasswordManager manager;
    int choice;

    cout << "欢迎使用个人密码本" << endl;

    while (true) {  //开启一个无限循环，构建了程序的主菜单，并等待用户输入操作数字
        cout << "\n1.添加新账号密码" << endl;
        cout << "2.查看所有密码" << endl;
        cout << "3.退出" << endl;
        cout << "请选择操作（1-3）：";

        if (!(cin >> choice)) { //输入防错校验：这是一个非常规范的防崩溃设计。如果用户输入的不是数字，cin >> choice会失败
            cin.clear();        //会清除输入流的错误状态
            cin.ignore(10000,'\n'); //会把刚才输入的错误字符清空，防止程序陷入死循环
            cout << ">>无效输入，请输入数字。\n";  //然后通过continue直接跳回菜单开头让用户重新输入
            continue;
        }

        switch (choice) {   //根据用户输入的数字执行相应操作
            case 1:
                manager.addRecord();    //添加记录
                break;
            case 2:
                manager.displayRecords();   //显示记录
                break;
            case 3:
                cout << ">>已安全退出密码本。" << endl;  //打印退出提示，并通过return 0;彻底结束主程序
                return 0;
            default:
                cout << ">>选择无效，请重试。" << endl;  //如果用户输入了4、5等无关数字，提示“选择无效”
        }
    }

    return 0;
}
// Created by Madeleine on 2026/3/1.
//