#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        std::vector<int>tmp;
        int i = 0, j = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();
        while (i < size1 && j < size2) {
            if (nums1[i] < nums2[j]) {
                i++;
            }
            else if (nums1[i] == nums2[j]) {
                tmp.push_back(nums1[i]);
                i++;
                j++;
            }
            else {
                j++;
            }
        }
        return tmp;
    }
};
int main() {
    vector<int>nums1 = { 1, 2, 2, 1 }, nums2 = { 2 };
    Solution ss;
    auto tmp = ss.intersect(nums1, nums2);
    for (auto &num : tmp) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}