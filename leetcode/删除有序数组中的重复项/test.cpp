#include <iostream>
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        int j = 0;
        int start = 0;
        int same_cnt = 0;
        while (i < size) {
            start = i;
            while ((i + 1 < size) && (nums[i] == nums[i + 1])) {
                ++same_cnt;
                ++i;
            }
            if (same_cnt > 0) {
                for(j = i + 1;j < size;j++) {
                    nums[j - same_cnt] = nums[j];
                }
                size -= same_cnt;
                same_cnt = 0;
            }
            i = start + 1;
        }
        return size;
    }
    int removeDuplicates1(std::vector<int>& nums) {
        int size = nums.size();
        int low = 0;
        int fast = 1;
        while (fast < size) {
            if (nums[low] == nums[fast]) {
                fast++;
                continue;
            }
            if (nums[++low] != nums[fast]) {
                nums[low] = nums[fast];
            }
            fast++;
        }
        return size ? (low + 1) : 0;
    }
};
int main() {
    //std::vector<int>nums = {1, 1, 1, 1};
    //std::vector<int>nums = {1, 1, 1, 1};
    //std::vector<int>nums = {1, 1, 1, 1, 2};
    //std::vector<int>nums = {1, 1, 1, 1, 2, 3, 4, 5, 7, 7, 7, 7, 9};
    std::vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    Solution ss;
    int size = ss.removeDuplicates(nums);
    for (int i = 0;i < size;i++) {
        std::cout << nums[i] << std::endl;
    }

    return 0;
}