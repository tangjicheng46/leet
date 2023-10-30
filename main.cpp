#include <iostream>
#include <stack>

int longestValidParentheses(std::string s) {
    std::stack<int> st;
    int maxLength = 0;
    int start = -1; // 记录当前有效括号子串的起始位置

    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            if (st.empty()) {
                start = i; // 更新起始位置
            } else {
                st.pop();
                if (st.empty()) {
                    maxLength = std::max(maxLength, i - start);
                } else {
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }
    }

    return maxLength;
}

int main() {
    std::string s = "(()))())(";
    int result = longestValidParentheses(s);
    std::cout << "Length of longest valid parentheses substring: " << result << std::endl;

    return 0;
}
