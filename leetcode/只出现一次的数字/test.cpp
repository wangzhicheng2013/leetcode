#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num;
        }
        return res;
    }
};
int main() {
    vector<int>nums = { 4, 1, 2, 1, 2};
    Solution ss;
    std::cout << ss.singleNumber(nums) << std::endl;

    return 0;
}