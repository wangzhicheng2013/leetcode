#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return find_the_largest(nums, 0, nums.size() - 1, k);
    }
    int find_the_largest(vector<int>& nums, int start, int end, int k) {
        int pos = quick_partition(nums, start, end);
        int largest_index = end - pos + 1;
        if (k == largest_index) {
            return nums[pos];
        }
        else if (k < largest_index) {
            return find_the_largest(nums, pos + 1, end, k);
        }
        else {
            return find_the_largest(nums, start, pos - 1, k - (end - pos) - 1);
        }
    }
    int quick_partition(vector<int>& nums, int start, int end) {
        int i = start, j = end;
        int tmp = nums[i];
        while (i < j) {
            while (i < j && nums[j] > tmp) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] < tmp) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = tmp;
        return i;
    }
};
int main() {
    std::vector<int>v = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    //std::vector<int>v = { 2, 1 };
    int k = 4;
    Solution ss;
    std::cout << ss.findKthLargest(v, k) << std::endl;

    return 0;
}
