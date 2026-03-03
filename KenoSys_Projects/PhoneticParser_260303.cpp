#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>

struct PhoneticData {
    int syllable_count;
    std::string last_phoneme;
    std::string stress_pattern;
};

class ByronMeterJudge {
private:
    std::unordered_map<std::string, PhoneticData> dict;

    std::string to_upper(const std::string& str) {
        std::string upper_str = str;
        for (char &c : upper_str) c = toupper(c);
        return upper_str;
    }

    std::string to_lower(const std::string& str) {
        std::string lower_str = str;
        for (char & c : lower_str) c = tolower(c);
        return lower_str;
    }

public:
    bool init_guillotine(const std::string& filepath) {
        std::ifstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "[FATAL] 初始化失败：找不到词典文件 " << filepath << "!\n";
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.empty() || line.substr(0, 3) == ";;;") continue;

            std::istringstream iss(line);
            std::string word;
            iss >> word;

            int syllables = 0;
            std::string stress = " ";
            std::string phoneme;
            std::string last_p = " ";

            while (iss >> phoneme) {
                last_p = phoneme;
                if (isdigit(phoneme.back())) {
                    syllables++;
                    stress += phoneme.back();
                }
            }
        dict[word] =  {syllables, last_p, stress};
        }
        file.close();
        std::cout << "[SYSTEM] 词典加载完毕。共收录" << dict.size() << "个词汇。" << std::endl;
        return true;
    }

    void judge_word(const std::string& word) {
        std::cout << "\n字典内部键值诊断：" << std::endl;
        for (const auto& pair : dict) {
            if (pair.first.find("HURRICANE")!=std::string::npos) {
                std::cout << "找到包含该词的Key:[" << pair.first << "[, Length: " << pair.first.length() << std::endl;
            }
        }
        std::cout << "---------------------------" << std::endl;
        std::string target = to_lower(word);
        auto it = dict.find(target);
        if (it != dict.end()) {
            const auto& data = it->second;
            std::cout << ">> 词汇：" << target << "\t| 音节数：" << data.syllable_count << "\t| 尾音：" << data.last_phoneme << "\t| 节拍：" << data.stress_pattern << "\n";
        }else {
            std::cout << "\n[WARNING]未知词汇：" << word << "。这不属于词汇库。打入虚无。" << std::endl;
        }
    }
};

int main() {
    std::cout << "==============================================================================\n";
    std::cout << "                   Byron Simulator - The Guillotine\n";
    std::cout << "==============================================================================\n\n";

    ByronMeterJudge judge;
    if (judge.init_guillotine("data/cmudict/cmudict.dict")) {
        std::cout << "\n测试词汇：";
        judge.judge_word("HURRICANE");
        judge.judge_word("DESTRUCTION");
    }

    return 0;

}
//
// Created by Madeleine on 2026/3/3.
//