#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        int index = 0;
        int size = digits.size();
        std::string str;
        if (0 == size) {
            return std::vector<std::string>();
        }
        if (1 == size) {
            index = digits[0] - '0';
            str = digit_array[index];
            std::vector<std::string>vec;
            for (auto &ch : str) {
                vec.emplace_back(std::string("") + ch);
            }
            return vec;
        }
        std::string digits_size_1(digits, 0, size - 1);
        auto vec = letterCombinations(digits_size_1);
        std::vector<std::string>new_vec;
        index = digits[size - 1] - '0';
        str = digit_array[index];
        for (auto &word : vec) {
            for (auto &ch : str) {
                new_vec.emplace_back(word + ch);
            }
        }
        return new_vec;
    }
private:
    const std::string digit_array[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
};
int main() {
    std::string digits = "234";
    Solution ss;
    auto vec = ss.letterCombinations(digits);
    for (auto &str : vec) {
        std::cout << str << std::endl;
    }

    return 0;
}