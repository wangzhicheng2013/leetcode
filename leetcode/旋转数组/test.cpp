#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k %= size;
        reverse(nums, 0, size - k - 1);
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - 1);
    }
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
int main() {
    vector<int>nums = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;
    Solution ss;
    ss.rotate(nums, k);
    for (auto &num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}