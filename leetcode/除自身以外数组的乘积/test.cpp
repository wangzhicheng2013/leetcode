#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>res(size, 0);
        int i = 0;
        res[0] = 1;
        int left = 1;
        for (i = 1;i < size;i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (i = size - 1;i >= 1;i--) {
            res[i] = res[i] * right;
            right = nums[i] * right;
        }
        res[0] = right;

        return res;
    }
};
int main() {
    std::vector<int>nums = { 1, 2, 3, 4 };
    auto res = Solution().productExceptSelf(nums);
    for (auto &num : res) {
        std::cout << num << std::endl;
    }

    return 0;
}