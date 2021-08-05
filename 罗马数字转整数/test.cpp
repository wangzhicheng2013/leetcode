#include <iostream>
#include <string>
#include <map>
typedef struct special_roman {
    const char *roman;
    int value;
} special_roman;
const int SPECIAL_ROMAN_LEN = 6;
special_roman romans[SPECIAL_ROMAN_LEN] = { {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900} };
std::map<char, int>common_roman = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

class Solution {
public:
    int romanToInt(std::string s) {
        int sum = 0;
        for (auto &r : romans) {
            auto pos = s.find(r.roman);
            if (pos != std::string::npos) {
                sum += r.value;
                s.erase(pos, 2);
            }
        }
        for (auto &ch : s) {
            sum += common_roman[ch];
        }
        return sum;
    }
};
int main() {
    Solution ss;
    std::string str("MCMXCIV");
    std::cout << ss.romanToInt(str) << std::endl;

    return 0;
}