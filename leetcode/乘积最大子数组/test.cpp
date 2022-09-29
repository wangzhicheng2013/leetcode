#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max_val = 1;
        int min_val = 1;
        int res = nums[0];
        for (int i = 0;i < size;i++) {
            if (nums[i] < 0) {
                swap(max_val, min_val);
            }
            max_val = max(max_val * nums[i], nums[i]);
            min_val = min(min_val * nums[i], nums[i]);
            res = max(res, max_val);
        }
        return res;
    }
};
int main() {
    vector<int> nums = { 2, 3, -2, 4 };
    Solution ss;
    cout << ss.maxProduct(nums) << endl;

    return 0;
}