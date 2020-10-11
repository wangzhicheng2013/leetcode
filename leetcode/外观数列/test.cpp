#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
class Solution {
public:
    std::string countAndSay(int n) {
        int digitals_size = n;
        char buf[16] = "";
        std::string new_str("1");
        std::string last_str;
        for (int i = 1;i < digitals_size;i++) {
            last_str = new_str;
            new_str.clear();
            int size = last_str.size();
            int j = 0;
            int repeated = 1;
            while (j < size) {
                if (last_str[j] == last_str[j + 1]) {
                    ++repeated;
                }
                else {
                    snprintf(buf, sizeof(buf), "%d%c", repeated, last_str[j]);
                    new_str += buf;
                    repeated = 1;
                }
                j++;
            }
        }
        return new_str;
    }
};
int main() {
    Solution ss;

    return 0;
}