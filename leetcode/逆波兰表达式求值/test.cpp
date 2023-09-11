#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
private:
    bool is_digit(const std::string& token) {
        return (token != "+") && (token != "-") && (token != "*") && (token != "/"); 
    }
    int compute(int left_operand, int right_operand, const std::string& op) {
        if (0 == op.compare("+")) {
            return left_operand + right_operand;
        }
        else if (0 == op.compare("-")) {
            return left_operand - right_operand;
        }
        else if (0 == op.compare("*")) {
            return left_operand * right_operand;
        }
        return left_operand / right_operand;
    }
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int>num_stack;
        int left_operand = 0, right_operand = 0, res = 0;
        for (auto& token : tokens) {
            if (is_digit(token)) {
                num_stack.push(atoi(token.c_str()));
                continue;
            }
            if (num_stack.size() < 2) {
                break;
            }
            right_operand = num_stack.top();
            num_stack.pop();
            left_operand = num_stack.top();
            num_stack.pop();
            num_stack.push(compute(left_operand, right_operand, token));
        }
        return num_stack.top();
    }
};
int main() {
    std::vector<string>tokens = { "2", "1", "+", "3", "*" };
    Solution ss;
    std::cout << ss.evalRPN(tokens) << std::endl;

    return 0;
}