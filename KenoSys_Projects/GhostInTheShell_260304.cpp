#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <cctype>
#include <vector>   //用于暂存句子中的单词数据
#include <unordered_set>    //存储功能词集合
#include "data/GhostCaller.h"

struct PhoneticData {
    int syllable_count;
    std::string last_phoneme;
    std::string stress_pattern;
};

class ByronMeterJudge {
private:
    std::unordered_map<std::string, PhoneticData> dict;
    std::unordered_map<std::string, PhoneticData> elision_dict; //省音词典

    //弱读功能词
    const std::unordered_set<std::string>weak_words = {
        "a", "an", "the", "for", "yet", "so", "at", "by", "from", "in", "into", "of", "on", "to", "with",
        "upon", "am", "is", "are", "was", "were", "be", "been", "being", "have", "has", "had", "do", "does",
        "did","shall", "will", "should", "would", "may", "might", "must", "can", "could", "i", "you", "he",
        "she", "it","we", "they", "me", "him", "her", "us", "them", "my", "your", "his", "its", "our",
        "their", "this","that", "these", "those", "than", "as"
    };

    const std::unordered_map<std::string, std::string> custom_stress = {
        //1.带次重音的副词/连词
        {"almost", "10"},{"always", "10"},{"also", "10"},{"therefore", "10"},{"wherefore", "10"},{"sometimes", "10"},{"somewhat", "10"},
        //2.高频复合词
        {"moonlight", "10"},{"midnight", "10"},{"sunshine", "10"},{"sunset", "10"},{"sunrise", "10"},{"heartbreak", "10"},{"earthquake", "10"},
        //3.多音节介词
        {"upon", "01"},{"without", "01"},{"within", "01"},{"before", "01"},{"behind", "01"},{"beyond", "01"},{"into", "10"},
        //4.叹词、古英语、宗教词汇
        {"alas", "01"},{"amen", "01"},{"farewell", "01"},{"myself", "01"},{"himself", "01"},{"herself", "01"}
    };

    std::string to_lower(const std::string& str) {
        std::string lower_str = str;
        for (char & c : lower_str) c = tolower(c);
        return lower_str;
    }

public:
    //构造函数：省音规则
    ByronMeterJudge() {
        elision_dict["even"] = {1, "n", "1"};;
        elision_dict["over"] = {1,"r", "1"};
        elision_dict["never"] = {1,"r", "1"};
        elision_dict["heaven"] = {1,"r","1"};
    }
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
        dict[to_lower(word)] =  {syllables, last_p, stress};
        }
        file.close();
        std::cout << "[SYSTEM] 词典加载完毕。共收录" << dict.size() << "个词汇。" << std::endl;
        return true;
    }

    bool judge_sentence_meter(const std::string& sentence, int expected_syllables) {
        std::istringstream iss(sentence);
        std::string raw_word;

        std::vector<std::string>word_buffer;
        std::vector<PhoneticData>phonetic_buffer;

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
                PhoneticData current_data = it->second;
                if (weak_words.find(clean_word) != weak_words.end()) {
                    current_data.stress_pattern = std::string(current_data.syllable_count, '0');
                }else if (custom_stress.find(clean_word)!=custom_stress.end()) {
                    current_data.stress_pattern = custom_stress.at(clean_word);
                }

                total_syllables += current_data.syllable_count;
                total_stress_pattern += current_data.stress_pattern;

                word_buffer.push_back(clean_word);

                phonetic_buffer.push_back(current_data);
            }else {
                std::cout << "[REJECT]句子含有糟糕词汇：" << clean_word << "。打入虚空。" << "\n";
                return false;
            }
        }

        if (total_syllables > expected_syllables) {
            std::cout << "[WARNING]音步溢出（当前 " << total_syllables << " 音节 > 期望 " << expected_syllables << " 音节）。启动省音补丁...\n";

            for (size_t i = 0; i < word_buffer.size(); ++i) {
                if (total_syllables == expected_syllables)break;

                auto elision_it = elision_dict.find(word_buffer[i]);
                if (elision_it != elision_dict.end()) {
                    int diff = phonetic_buffer[i].syllable_count - elision_it -> second.syllable_count;
                    if (diff > 0) {
                        std::cout << "->触发省音：将 '" << word_buffer[i] << "' 压缩为 " << elision_it -> second.syllable_count << " 音节。\n";

                        total_syllables -= diff;

                        phonetic_buffer[i] = elision_it->second;
                    }
                }
            }
        }

        if (total_syllables != expected_syllables) {
            std::cout << "[REJECT]音节断裂。打入虚空。期望 " << expected_syllables << " 音节，实际 " << total_syllables << " 音节。\n";
            return false;
        }

        std::string final_stress_pattern = "";
        for (const auto& data : phonetic_buffer) {
            final_stress_pattern += data.stress_pattern;
        }

        int iambic_score = 0;
        for (size_t i = 1; i < total_stress_pattern.length(); i += 2) {
            if (final_stress_pattern[i] == '1' || final_stress_pattern[i] == '2') {
                iambic_score ++;
            }
        }

        int perfect_feet = 0;
        int total_feet = expected_syllables / 2;

        for (size_t i = 0; i < final_stress_pattern.length() - 1; i += 2) {
            char weak_beat = final_stress_pattern[i];
            char strong_beat = final_stress_pattern[i+1];

            if (weak_beat == '0' && strong_beat == '1') {
                perfect_feet++;
            }
        }

        int required_feet = total_feet -1;
        if (perfect_feet < required_feet){
        std::cout << "[REJECT]节拍混乱。打入虚空。抑扬格音步数量不足（" << perfect_feet << "/" << total_feet << "）。\n";
        std::cout << ">> 看看尸体：" << final_stress_pattern << "\n";
        return false;
        }


      if (iambic_score < expected_syllables / 2 - 1) {
            std::cout << "[REJECT]节拍混乱。打入虚空。检测到非抑扬格模式：" << final_stress_pattern << "\n";
            return false;
        }
        std::cout << "[ACCEPT]合格的格律。最终重音流：" << final_stress_pattern << "\n";
        return true;
    }

    void judge_word(const std::string& word) {
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
    judge.init_guillotine("data/cmudict/cmudict.dict");

    std::string my_api_key = "AIzaSyDF5Pga3y8ULL11Ridi-WhDEmDqO9xpYwU";
    GhostCaller gemini(my_api_key);

    std::cout << "\n[SYSTEM]接入Unity中枢。开始吟诵...\n";
    std::string tyrant_prompt = "你现在是Lord Byron，写一行英文诗，五步抑扬格，10个音节，轻重交替。不要使用任何Markdown格式，不要星号、连字符等。题材为塔罗牌里的任何一张，但不要出现这张牌的具体名称。";
    int max_retries = 5;
    bool success = false;

    for (int i = 1; i <= max_retries; ++i) {
        std::cout << "\n>>> 正在进行第 " << i << " 次吟诵..." << std::endl;

        std::string ai_sentence = gemini.generate_line(tyrant_prompt);
        std::cout << "Unity原始输出：" << ai_sentence << "\n";

        std::cout << "开启格律判案" << std::endl;
        if (judge.judge_sentence_meter(ai_sentence, 10)) {
            std::cout << "\n==============================================================================\n";
            std::cout << "[吟诵完毕]从虚空存活的句子：\n";
            std::cout << " " <<ai_sentence << "\n";
                success = true;
            break;
        }else {
            std::cout << ">>审判未通过。深渊吃得很饱。\n"; //这里可以进阶：把报错信息加入prompt让ai改正
        }
    }
    if (!success) {
        std::cout << "\n[SYSTEM]连续 " << max_retries << " 次吟诵失败，鬼魂已被断头台斩碎。\n";
    }


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

//
// Created by Madeleine on 2026/3/4.
//