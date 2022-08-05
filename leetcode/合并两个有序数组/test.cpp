#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int>tmp;
        tmp.resize(m + n);
        int i = 0, j = 0;
        int k = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                tmp[k++] = nums1[i++];
            }
            else {
                tmp[k++] = nums2[j++];
            }
        }
        while (i < m) {
            tmp[k++] = nums1[i++];
        }
        while (j < n) {
            tmp[k++] = nums2[j++];
        }
        std::copy(begin(tmp), end(tmp), begin(nums1));
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i--];
            }
            else {
                nums1[k] = nums2[j--];
            }
            k--;
        }
    }
};
int main() {
    std::vector<int>nums1 = { 4, 0, 0, 0, 0, 0 };
    std::vector<int>nums2 = { 1, 2, 3, 4, 5 };
    int m = 1, n = 5;
    Solution ss;
    ss.merge1(nums1, m, nums2, n);
    for (auto &num : nums1) {
        std::cout << num << std::endl;
    }

    return 0;
}