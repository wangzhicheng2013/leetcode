#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = std::numeric_limits<int>::max();
        int mid = low;
        for (auto &num : nums) {
            if (num <= low) {
                low = num;
            }
            else if (num <= mid) {
                mid = num;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
int main() {
    vector<int>nums = { 1, 5, 0, 4, 1, 3 };
    std::cout << Solution().increasingTriplet(nums) << std::endl;

    return 0;
}