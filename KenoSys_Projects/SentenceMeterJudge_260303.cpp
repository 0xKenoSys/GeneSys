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
            std::string stress = "";
            std::string phoneme;
            std::string last_p = "";

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

    bool judge_sentence_meter(const std::string& sentence, int expected_syllables) {
        std::istringstream iss(sentence);
        std::string raw_word;

        int total_syllables = 0;
        std::string total_stress_pattern = "";
        while (iss >> raw_word) {
            std::string clean_word = "";
            for (char c : raw_word) {
                if (std::isalpha(c) || c == '\'') {
                    clean_word += tolower(c);
                }
            }
            if (clean_word.empty())continue;
            auto it = dict.find(clean_word);
            if (it != dict.end()) {
                total_syllables += it->second.syllable_count;
                total_stress_pattern += it->second.stress_pattern;
            }else {
                std::cout << "[REJECT]句子含有糟糕词汇：" << clean_word << "。打入虚空。" << "\n";
                return false;
            }
        }

        if (total_syllables != expected_syllables) {
            std::cout << "[REJECT]音节断裂。打入虚空。期望 " << expected_syllables << " 音节，实际 " << total_syllables << " 音节。\n";
            return false;
        }

        int iambic_score = 0;
        for (size_t i = 1; i < total_stress_pattern.length(); i += 2) {
            if (total_stress_pattern[i] == '1' || total_stress_pattern[i] == '2') {
                iambic_score ++;
            }
        }
      if (iambic_score < expected_syllables / 2 - 1) {
            std::cout << "[REJECT]节拍混乱。打入虚空。检测到非抑扬格模式：" << total_stress_pattern << "\n";
            return false;
        }
        std::cout << "[ACCEPT]合格的格律。虚空狂喜。\n";
        return true;
    }   void judge_word(const std::string& word) {
        std::string target = to_lower(word);
        auto it = dict.find(target);
        if (it != dict.end()) {
            const auto& data = it->second;
            std::cout << "\n>> 词汇：" << target << "\t| 音节数：" << data.syllable_count << "\t| 尾音：" << data.last_phoneme << "\t| 节拍：" << data.stress_pattern << "\n";
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

    std::cout << "\n测试句子：\n";
        std::string test_sentence1 = "With pleasure drugged, he almost longed for woe,\n";
        int expected_syllables1 = 10;
        judge.judge_sentence_meter(test_sentence1, expected_syllables1);
        std::string test_sentence2 = "And even for change of scene would seek the shades below.\n"; //这句话有13个音节，那么以后要考虑音节放宽。比如/n/音是否可以宽限，尤其是诗歌里常见的可缩写的词
        int expected_syllables2 = 12;
        judge.judge_sentence_meter(test_sentence2, expected_syllables2);
    }

    return 0;
}
//
// Created by Madeleine on 2026/3/3.
//
////
// Created by Madeleine on 2026/3/3.
//