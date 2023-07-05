#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        if (false == check(s)) {
            return atoi(s.c_str());
        }
        std::stack<int>num_stack;
        std::stack<char>operator_stack;
        std::string str;
        for (auto &ch : s) {
            if (32 == ch) {
                continue;
            }
            if (isdigit(ch)) {
                str += ch;
                continue;
            }
            num_stack.push(atoi(str.c_str()));
            str.clear();
            if (operator_stack.empty() || is_greator(ch, operator_stack.top())) {
                operator_stack.push(ch);
                continue;
            }
            while (false == operator_stack.empty()) {
                do_compute(num_stack, operator_stack);
                if (operator_stack.empty() || is_greator(ch, operator_stack.top())) {
                    break;
                }
            }
            operator_stack.push(ch);
        }
        if (false == str.empty()) {
            num_stack.push(atoi(str.c_str()));
        }
        while (false == operator_stack.empty()) {
            do_compute(num_stack, operator_stack);
        }
        return num_stack.top();
    }
    bool check(const std::string& s) {
        for (auto& ch : s) {
            if (('+' == ch) || ('-' == ch) || ('*' == ch) || ('/' == ch)) {
                return true;
            }
        }
        return false;
    }
    void do_compute(std::stack<int>&num_stack, std::stack<char>&operator_stack) {
        assert(num_stack.size() >= 2);
        int left = 0, right = 0, result = 0;
        char op = 0; 
        right = num_stack.top();
        num_stack.pop();
        left = num_stack.top();
        num_stack.pop();
        op = operator_stack.top();
        operator_stack.pop();
        result = compute(left, right, op);
        num_stack.push(result);       
    }
    inline bool is_greator(char ch1, char ch2) {
        return operator_level(ch1) > operator_level(ch2);
    }
    inline int operator_level(char ch) {
        switch (ch)
        {
        case '+':
        case '-':
            return 0;
            break;
        case '*':
        case '/':
            return 1;
            break;
        default:
            break;
        }
        assert(0);
        return -1;
    }
    inline int compute(int left, int right, char op) {
        switch (op)
        {
        case '+':
            return left + right;
            break;
        case '-':
            return left - right;
            break;
        case '*':
            return left * right;
            break;
        case '/':
            assert(right);
            return left / right;
            break;
        default:
            break;
        }
        assert(0);
        return 0;
    }
    int calculate1(string s) {
        std::vector<int>vec;
        int n = s.size();
        int num = 0;
        char pre_sign = '+';
        for(int i = 0;i < n;i++) {
            if (isdigit(s[i])) {
                num = 10 * num + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || (n - 1 == i)) {
                switch (pre_sign)
                {
                case '+':
                    vec.push_back(num);
                    break;
                case '-':
                    vec.push_back(-num);
                    break;
                case '*':
                    vec.back() *= num;
                    break;
                case '/':
                    vec.back() /= num;
                    break;
                default:
                    assert(0);
                    break;
                }
                num = 0;
                if (!isdigit(s[i])) {
                    pre_sign = s[i];
                }
            }
        }
        int res = 0;
        for(auto &val : vec){
            res += val;
        }
        return res;
    }
};
int main() {
    Solution ss;
    std::cout << ss.calculate1("3+2*2") << std::endl;

    return 0;
}