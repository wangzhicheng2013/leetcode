#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        len = s.size();
        find_palindrome(s, 0);
        return ret_;
    }
    void find_palindrome(const std::string &s, int start) {
        if (start >= len) {
            ret_.push_back(tmp_);
            return;
        }
        for (int i = start;i < len;i++) {
            if (is_palindrome(s, start, i)) {
                if (0 == start) {
                    tmp_.clear();
                }
                tmp_.push_back(s.substr(start, i - start + 1));
                find_palindrome(s, i + 1);
                tmp_.pop_back();
            }
        }
    }
    bool is_palindrome(const std::string &str, int start, int end) {
        int i = start;
        int j = end;
        while (i < j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
private:
    int len = 0;
    std::vector<std::string>tmp_;
    std::vector<std::vector<std::string>>ret_;
};
int main() {
    Solution ss;
    std::string s = "aab";
    auto vec = ss.partition(s);
    for (auto &v : vec) {
        for (auto &v1 : v) {
            std::cout << v1 << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}