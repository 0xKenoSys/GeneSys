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

public:
    void load_dict(const std::string&filepath) {
        std::ifstream file(filepath);
        std::string line;

        while (std::getline(file, line)) {
            if (line.empty() || line.substr(0, 3) == "; ; ;") continue;

            std::istringstream iss(line);
            std::string word;
            iss >> word;

            int syllables = 0;
            std::string stress = " ";
            std::string phoneme;
            std::string last_p = " ";

            while (iss >> phoneme) {
                if (isdigit(phoneme.back())) {
                    syllables++;
                    stress += phoneme.back();
                }
            }\
        dict[word] = {syllables, last_p, stress};
        }
        std::cout << "[SYSTEM] 词典加载完毕。共收录" << dict.size() << "个词汇。" << std::endl;
    }

    void judge_word(const std::string& word) {
        if (dict.find(word) != dict.end()) {
            PhoneticData data = dict[word];
            std::cout << "Word:" << word << " | 音节数：" << data.syllable_count << " ｜ 尾音：" << data.last_phoneme << " ｜ 节拍：" << data.stress_pattern << std::endl;
        }else {
            std::cout << "[WARNING]未知词汇：" << word << "。这不属于词汇库。" << std::endl;
        }
    }
};

int main() {
    ByronMeterJudge judge;
    judge.load_dict("cmudict.txt");
    judge.judge_word("HURRICANE");
    judge.judge_word("DESTRUCTION");
    return 0;

}
//
// Created by Madeleine on 2026/3/3.
//