#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        int size = s.size();
        char ch;
        char left_bracket;
        std::stack<char>left_bracket_stack;
        for(;i < size;i++) {
            ch = s[i];
            if (is_left_bracket(ch)) {
                left_bracket_stack.push(ch);
            }
            else {
                if (!get_left_bracket(ch, left_bracket)) {
                    return false;
                }
                if (left_bracket_stack.empty() || (left_bracket_stack.top() != left_bracket)) {
                    return false;
                }
                left_bracket_stack.pop();
            }
        }
        return left_bracket_stack.empty();
    }
    bool is_left_bracket(char ch) {
        switch (ch)
        {
        case '(':
            return true;
            break;
         case '[':
            return true;
            break;
        case '{':
            return true;
            break;
        default:
            return false;
        }
    }
    bool get_left_bracket(const char right_bracket, char &left_bracket) {
        switch (right_bracket)
        {
        case ')':
            left_bracket = '(';
            return true;
            break;
         case ']':
            left_bracket = '[';
            return true;
            break;
        case '}':
            left_bracket = '{';
            return true;
            break;
        default:
            return false;
        }
    }
};
int main() {
    return 0;
} 