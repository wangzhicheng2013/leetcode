#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int start_pos = 0, end_pos = k;
        std::vector<int>max_values;
        int size = nums.size();
        while ((start_pos < end_pos) && (end_pos <= size)) {
            auto max_value = std::max_element(nums.begin() + start_pos, nums.begin() + end_pos);
            max_values.push_back(*max_value);
            start_pos++;
            end_pos++;
        }
        return max_values;
    }
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        std::vector<int>max_values;
        std::deque<int>desc_index_deque;
        int w = k - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (!desc_index_deque.empty() && desc_index_deque.front() + k == i) {
                desc_index_deque.pop_front();
            }
            while (!desc_index_deque.empty() && nums[desc_index_deque.back()] < nums[i]) {
                desc_index_deque.pop_back();
            }
            desc_index_deque.push_back(i);
            if (i < w) {
                continue;
            }
            max_values.push_back(nums[desc_index_deque.front()]);
        }
        return max_values;
    }
};
int main() {
    vector<int>nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    int k = 3;
    Solution ss;
    auto max_values = ss.maxSlidingWindow(nums, k);
    for (auto &v : max_values) {
        std::cout << v << std::endl;
    } 
    
    return 0;
}