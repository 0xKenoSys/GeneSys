#ifndef CPPPROJECTS_GHOSTCALLER_H
#define CPPPROJECTS_GHOSTCALLER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <curl/curl.h>

class GhostCaller {
private:
    std::string api_key;
    //使用目前响应最快的flash模型，适合打回重写
    std::string api_url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=";

    //cURL的回调函数，用于接收API吐回来的数据
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
        userp->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    //粗暴但有效的JSON提取（提取"text":"..."中的内容）
    std::string extract_text_from_json(const std::string& json_response) {
        std::string target = "\"text\": \"";
        size_t start_pos = json_response.find(target);
        if (start_pos == std::string::npos)return "[API ERROR]没有找到文本。";

        start_pos += target.length();
        size_t end_pos = json_response.find("\"", start_pos);

        std::string result = json_response.substr(start_pos, end_pos - start_pos);
        //清理换行符
        result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());
        return result;
    }

public:
    GhostCaller(const std::string& key) : api_key(key){}

    std::string generate_line(const std::string& prompt) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;

        curl = curl_easy_init();
        if (curl) {
            std::string full_url = api_url + api_key;
            curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());

            //构造请求头
            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            //构造极简的JSON Payload
            std::string json_payload = R"({"contents":[{"parts":[{"text": ")" + prompt + R"("}]}]})";
            curl_easy_setopt(curl,CURLOPT_POSTFIELDS, json_payload.c_str());

            //设置接收回调
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            //为了速度，关掉SSL证书校验
            //curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

            //强制libcurl走代理（Astrill默认的本地代理端口通常是3278或3279）
            //保险起见，指定一个常见的本地代理
            //改细节
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            //curl_easy_setopt(curl, CURLOPT_PROXY, "http://127.0.0.1:3278");

            //执行请求
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                std::cerr << "cURL请求失败：" << curl_easy_strerror(res) << std::endl;
            }

            //清理
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }

        //把API的回音打印出来，看看报什么错
        std::cout << "\n[DEBUG]深渊的回音：" << readBuffer << "\n";

        return extract_text_from_json(readBuffer);
    }
};

#endif //CPPPROJECTS_GHOSTCALLER_H
//
// Created by Madeleine on 2026/3/4.
//
