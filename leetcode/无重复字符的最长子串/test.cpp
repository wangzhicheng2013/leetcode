#include <iostream>
#include <bitset>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int forward_pos = 0;
        int i = 0;
        int sub_str_len = 0;
        int max_sub_str_len = 0;
        while (forward_pos < size) {
            i = forward_pos;
            while (i < size) {
                auto &ch = s[i];
                if (!hash_char[ch]) {
                    hash_char[ch] = 1;
                    ++sub_str_len;
                    ++i;
                }
                else {
                    if (sub_str_len > max_sub_str_len) {
                        max_sub_str_len = sub_str_len;
                    }
                    forward_pos++;
                    sub_str_len = 0;
                    hash_char.reset();
                    break;
                }
            }
            if (i >= size) {
                if (sub_str_len > max_sub_str_len) {
                    max_sub_str_len = sub_str_len;
                }
                break;
            }
        }
        return max_sub_str_len;
    }
private:
    bitset<128>hash_char;
};
int main() {
    Solution ss;
    std::cout << ss.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << ss.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << ss.lengthOfLongestSubstring("pwwkew") << std::endl;
    std::cout << ss.lengthOfLongestSubstring("") << std::endl;
    std::cout << ss.lengthOfLongestSubstring("dvdf") << std::endl;

    return 0;
}