#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 密码记录结构体
struct PasswordRecord {
    string platform;
    string username;
    string password;
};

class PasswordManager {
private:
    vector<PasswordRecord> records;
    string filename = "data.bin";
    char cryptoKey = 'X'; // 基础的异或密钥

    // 极简异或加密/解密逻辑（用于防止明文直接存储）
    string encryptDecrypt(const string& input) {
        string output = input;
        for (size_t i = 0; i < input.size(); i++) {
            output[i] = input[i] ^ cryptoKey;
        }
        return output;
    }

    // 将数据保存到本地文件
    void saveToFile() {
        ofstream file(filename, ios::trunc);
        if (!file.is_open()) {
            cout << "错误：无法保存文件。" << endl;
            return;
        }
        for (const auto& record : records) {
            file << encryptDecrypt(record.platform) << " "
                 << encryptDecrypt(record.username) << " "
                 << encryptDecrypt(record.password) << "\n";
        }
        file.close();
    }

    // 从本地文件加载数据
    void loadFromFile() {
        ifstream file(filename);
        if (!file.is_open()) return; // 文件不存在则跳过

        string p, u, pwd;
        while (file >> p >> u >> pwd) {
            records.push_back({
                encryptDecrypt(p),
                encryptDecrypt(u),
                encryptDecrypt(pwd)
            });
        }
        file.close();
    }

public:
    PasswordManager() {
        loadFromFile();
    }

    // 添加新密码
    void addRecord() {
        PasswordRecord newRecord;
        cout << "\n请输入平台名称 (如 GitHub): ";
        cin >> newRecord.platform;
        cout << "请输入用户名/邮箱: ";
        cin >> newRecord.username;
        cout << "请输入密码: ";
        cin >> newRecord.password;

        records.push_back(newRecord);
        saveToFile();
        cout << ">> 记录添加成功并已安全保存！\n";
    }

    // 显示所有密码
    void displayRecords() {
        if (records.empty()) {
            cout << "\n>> 当前密码本为空。\n";
            return;
        }

        cout << "\n================= 你的密码本 =================" << endl;
        for (size_t i = 0; i < records.size(); ++i) {
            cout << "[" << i + 1 << "] 平台: " << records[i].platform
                 << " | 账号: " << records[i].username
                 << " | 密码: " << records[i].password << endl;
        }
        cout << "==============================================" << endl;
    }
};

int main() {
    PasswordManager manager;
    int choice;

    cout << "欢迎使用个人密码本" << endl;

    while (true) {
        cout << "\n1. 添加新账号密码" << endl;
        cout << "2. 查看所有密码" << endl;
        cout << "3. 退出" << endl;
        cout << "请选择操作 (1-3): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << ">> 无效输入，请输入数字。\n";
            continue;
        }

        switch (choice) {
            case 1:
                manager.addRecord();
                break;
            case 2:
                manager.displayRecords();
                break;
            case 3:
                cout << ">> 已安全退出密码本。" << endl;
                return 0;
            default:
                cout << ">> 选择无效，请重试。" << endl;
        }
    }

    return 0;
}


//
// Created by Madeleine on 2026/3/1.
//