#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        if (!size1 && !size2) {
            return 0;
        }
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total_left_count = (size1 + size2 + 1) / 2;
        int start = 0;
        int end = size1;
        while (start < end) {
            int left_count = start + (end - start + 1) / 2; 
            if (nums1[left_count - 1] > nums2[total_left_count - left_count]) {
                end = left_count - 1;
            }
            else {
                start = left_count;
            }
        }
        
        int i = start;
        int j = total_left_count - i;
        double left1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == size1) ? INT_MAX : nums1[i];
        int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == size2) ? INT_MAX : nums2[j];
        if ((size1 + size2) % 2) {
            return left1 > left2 ? left1 : left2;
        }
        else {
            double max_left = left1 > left2 ? left1 : left2;
            double min_right = right1 < right2 ? right1: right2;
            return (max_left + min_right) / 2.0;
        }
    }
};
int main() {
    int size1 = 100;
    int size2 = 101;
    vector<int>nums1;
    vector<int>nums2;
    for (int i = 0;i < size1;i++) {
        nums1.push_back(2 * i + 1);
        nums2.push_back(2 * i + i - 2);
    }
    Solution ss;
    std::cout << ss.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
