#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        int row = 0;
        bool switch_flag = true;
        int size = s.size();
        std::vector<std::vector<char> >z_array;
        z_array.resize(numRows);
        for (int k = 0;k < size;) {
            if (switch_flag && row < numRows - 1) {
                z_array[row++].emplace_back(s[k++]);
                continue;
            }
            if (numRows - 1 == row) {
                switch_flag = false;
            }
            if (!switch_flag && row > 0) {
                z_array[row--].emplace_back(s[k++]);
                continue;
            }
            if (0 == row) {
                switch_flag = true;
            }
        }
        std::string rs;
        for (int loop = 0;loop < numRows;++loop) {
            for (auto &ch : z_array[loop]) {
                rs += ch;
            }
        }
        return rs;
    }
};
int main() {
    Solution ss;
    std::cout << ss.convert("LEETCODEISHIRING", 3) << std::endl;

    return 0;
}
