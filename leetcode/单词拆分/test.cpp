#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
class Solution {
public:
    std::vector<std::string>wordBreak(const std::string &s, const std::vector<std::string>&wordDict) {
        std::unordered_map<std::string, std::vector<std::string>>mp;
        return word_break(s, wordDict, mp);
    }
    std::vector<std::string>word_break(const std::string &s, 
                                       const std::vector<std::string>&wordDict, 
                                       std::unordered_map<std::string, std::vector<std::string>>&mp) {
        auto it = mp.find(s);
        if (it != end(mp)) {
            return it->second;
        }
        if (s.empty()) {
            return { "" };
        }
        std::vector<std::string>res;
        for (auto &word : wordDict) {
            if (s.substr(0, word.size()) != word) {
                continue;
            }
            std::vector<std::string>tmp = word_break(s.substr(word.size()), wordDict, mp);
            for (auto &str : tmp) {
                res.emplace_back(word + (str.empty() ? "" : " " + str));
            }
        }
        mp[s] = res;
        return res;
    }
};
int main() {
    std::vector<std::string>wordDict = { "apple", "pen", "applepen", "pine", "pineapple" };
    std::string s = "pineapplepenapple";
    Solution ss;
    auto vec = ss.wordBreak(s, wordDict);
    for (auto &str : vec) {
        std::cout << str << std::endl;
    }

    return 0;
}