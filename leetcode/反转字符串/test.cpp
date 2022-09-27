#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0, j = size - 1;i < j;i++, j--) {
            swap(s[i], s[j]);
        }
    }
};
int main() {
    vector<char>s = { 'H', 'a', 'n', 'n', 'a', 'h' };
    Solution ss;
    ss.reverseString(s);
    for (auto ch : s) {
        cout << ch;
    }
    cout << endl;

    return 0;
}