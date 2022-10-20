#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    Solution(vector<int>& nums) {
        nums_ = nums;
        nums_original_ = nums;
    }
    
    vector<int> reset() {
        return nums_original_;
    }
    
    vector<int> shuffle() {
        random_shuffle(nums_.begin(), nums_.end());
        return nums_;
    }
private:
    vector<int>nums_;
    vector<int>nums_original_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main() {
    return 0;
}