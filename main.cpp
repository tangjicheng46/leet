#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
  std::vector<int> result;
  if (s.empty() || words.empty()) {
    return result;
  }
  size_t sLen = s.size();
  size_t wordCount = words.size();
  size_t wordLen = words[0].size();

  std::unordered_map<std::string, int> wordsMap;
  for (const std::string& iter : words) {
    if (wordsMap.find(iter) != wordsMap.end()) {
      wordsMap[iter] += 1;
    } else {
      wordsMap[iter] = 1;
    }
  }

  for (size_t i = 0; i < wordLen; i++) {
    int left = i;
    int right = i;
    std::unordered_map<std::string, int> currentWordsMap;
    while (right + wordLen <= sLen) {
      std::string word = s.substr(right, wordLen);
      right += wordLen;
      if (wordsMap.find(word) != wordsMap.end()) {
        if (currentWordsMap.find(word) != currentWordsMap.end()) {
          currentWordsMap[word] += 1;
        } else {
          currentWordsMap[word] = 1;
        }
        while (currentWordsMap[word] > wordsMap[word]) {
          std::string leftWord = s.substr(left, wordLen);
          left += wordLen;
          currentWordsMap[leftWord] -= 1;
        }
        if (right - left == wordLen * wordCount) {
          result.push_back(left);
        }
      } else {
        currentWordsMap.clear();
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
