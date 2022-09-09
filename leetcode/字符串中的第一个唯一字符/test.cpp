#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        for (int i = 0;i < size;i++) {
            if (s.find(s[i]) == s.rfind(s[i])) {
                return i;
            }
        }
        return -1;
    }
};
int main() {
    string s = "leetcode";
    Solution ss;
    std::cout << ss.firstUniqChar1(s) << std::endl;

    return 0;
}