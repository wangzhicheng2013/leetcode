#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>>groups;
        if (strs.empty()) {
            return groups;
        }
        groups.emplace_back(std::vector<std::string>{ strs[0] });
        int size = strs.size();
        for (int i = 1;i < size;i++) {
            bool found = false;
            for (auto &vec : groups) {
                const std::string &first_str = vec[0];
                if (is_anagram(first_str, strs[i])) {
                    vec.emplace_back(strs[i]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                groups.emplace_back(std::vector<std::string>{ strs[i] });
            }
        }
        return groups;
    }
    bool is_anagram(const std::string &one, const std::string &other) {
        int size = one.size();
        if (other.size() != size) {
            return false;
        }
        int i = 0;
        memset(fingerprint_, 0, sizeof(fingerprint_));
        for (;i < size;i++) {
            ++fingerprint_[one[i] - 'a'];
        }
        for (i = 0;i < size;i++) {
            --fingerprint_[other[i] - 'a'];
        }
        for (i = 0;i < size;i++) {
            if (fingerprint_[one[i] - 'a']) {
                return false;
            }
        }
        return true;
    }
private:
    int fingerprint_[26];
};
int main() {
    std::vector<std::string>strs{ "eat", "tea", "tan", "ate", "nat", "bat" };
    Solution ss;
    auto groups = ss.groupAnagrams1(strs);
    for (auto &vec : groups) {
        int size = vec.size();
        for (int i = 0;i < size;i++) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}