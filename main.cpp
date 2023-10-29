#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> result;
    if (s.empty() || words.empty()) {
        return result;
    }

    int wordLen = words[0].size(); // 单个单词的长度
    int totalLen = wordLen * words.size(); // 所有单词总长度
    int sLen = s.size();

    // 创建一个哈希表，用于记录words中每个单词的出现次数
    std::unordered_map<std::string, int> wordCount;
    for (const std::string& word : words) {
        wordCount[word]++;
    }

    for (int i = 0; i < wordLen; i++) {
        int left = i; // 滑动窗口的左边界
        int right = i; // 滑动窗口的右边界
        std::unordered_map<std::string, int> window; // 滑动窗口内的单词出现次数

        while (right + wordLen <= sLen) {
            std::string word = s.substr(right, wordLen);
            right += wordLen;

            // 如果word是words中的一个单词，将其加入窗口中
            if (wordCount.find(word) != wordCount.end()) {
                window[word]++;
                // 如果窗口中某个单词的出现次数超过了在words中的出现次数，移动左边界
                while (window[word] > wordCount[word]) {
                    std::string leftWord = s.substr(left, wordLen);
                    left += wordLen;
                    window[leftWord]--;
                }

                // 如果窗口中所有单词的出现次数和总长度一致，说明找到了一个合法的子串
                if (right - left == totalLen) {
                    result.push_back(left);
                }
            }
            // 如果word不在words中，重置窗口
            else {
                window.clear();
                left = right;
            }
        }
    }

    return result;
}

int main() {
    std::string s = "barfoothefoobarman";
    std::vector<std::string> words = {"foo", "bar"};
    std::vector<int> result = findSubstring(s, words);
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    return 0;
}
