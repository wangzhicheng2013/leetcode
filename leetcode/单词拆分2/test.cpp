#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        std::vector<bool>dp(size + 1, false);
        dp[0] = true;
        for (int i = 1;i <= size;i++) {
            for (const auto& word : wordDict) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word && dp[i - len]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};
int main() {
    std::vector<std::string>wordDict = { "car", "ca", "rs" };
    std::string s = "cars";
    Solution ss;
    std::cout << ss.wordBreak(s, wordDict) << std::endl;
    
    return 0;
}