#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string reverseWords(std::string s) {
    std::vector<std::string> vec;
    size_t i = 0, j = 0;
    while (i < s.size()) {
        if (s[i] != ' ') {
            j = i;
            while (j < s.size() && s[j] != ' ') {
                j += 1;
            }
            std::string temp(s.begin() + i, s.begin() + j);
            vec.push_back(temp);
            i = j;
        } else {
            i += 1;
        }
    }
    std::string result;
    for (size_t i = vec.size() - 1; i >= 1; i--) {
        result += vec[i];
        result += " ";
    }
    result += vec[0];
    return result;
}

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}