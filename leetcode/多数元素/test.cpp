#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://leetcode.cn/leetbook/read/top-interview-questions/xm77tm/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums), end(nums));
        return nums[nums.size() / 2];
    }
    int majorityElement1(vector<int>& nums) {
        int count = 1;
        int major = nums[0];
        int size = nums.size();
        for (int i = 1;i < size;i++) {
            if (0 == count) {
                count++;
                major = nums[i];
            }
            else if (major == nums[i]) {
                count++;
            }
            else {
                --count;
            }
        }
        return major;
    }
};
int main() {
    vector<int>nums = { 3, 2, 3 };
    Solution ss;
    std::cout << ss.majorityElement1(nums) << std::endl;

    return 0;
}