#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left_val = matrix[0][0];
        int n = matrix.size();
        int right_val = matrix[n - 1][n - 1];
        int mid = 0;
        while (left_val < right_val) {
            mid = (left_val + right_val) >> 1;
            if (find_num(matrix, k, mid)) {
                right_val = mid;
            }
            else {
                left_val = mid + 1;
            }
        }
        return right_val;
    }
    bool find_num(const vector<vector<int>>& matrix, int k, int mid) {
        int n = matrix.size();
        int i = n - 1, j = 0;
        int cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                cnt += (i + 1);
                j++;
            }
            else {
                i--;
            }
        }
        return cnt >= k;
    }
};
int main() {
    vector<vector<int>>&matrix = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
    return 0;
}