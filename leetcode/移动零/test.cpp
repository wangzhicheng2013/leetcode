#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 输入: nums = [0,1,0,3,12] => 1 
    // 输出: [1,3,12,0,0]
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        int j = 0;
        while (j < size) {
            if (0 == nums[j]) {
                j++;
                continue;
            }
            nums[i++] = nums[j++];
        }
        for (int k = i;k < j;k++) {
            nums[k] = 0;
        }
    }
};
int main() {
    //vector<int>nums = { 1, 0, 1 };
    vector<int>nums = { 0, 1, 0, 3, 12 };
    Solution ss;
    ss.moveZeroes(nums);
    for (auto &num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}