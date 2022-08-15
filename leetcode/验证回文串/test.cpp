#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int start_pos = 0;
        int end_pos = size - 1;
        char left = 0;
        char right = 0;
        while (start_pos < end_pos) {
            if (!isdigit(s[start_pos]) && !isalpha(s[start_pos]))  {
                start_pos++;
                continue;
            }
            if (!isdigit(s[end_pos]) && !isalpha(s[end_pos]))  {
                end_pos--;
                continue;
            }
            left = s[start_pos];
            right = s[end_pos];
            if (isupper(left)) {
                left = tolower(left);
            }
            if (isupper(right)) {
                right = tolower(right);
            }
            if (left != right) {
                return false;
            }
            start_pos++;
            --end_pos;
        }
        return true;
    }
};
int main() {
    string s = "A man, a plan, a canal: Panama";
    Solution ss;
    std::cout << ss.isPalindrome(s) << std::endl;

    return 0;
}