#include <iostream>
#include <stack>

int longestValidParentheses(std::string s) {
    size_t maxLength = 0;
    std::stack<int> st;
    int start = -1;
    for (size_t i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (st.empty()) {
          start = i;
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
