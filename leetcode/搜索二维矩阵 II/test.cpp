#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        int rows = matrix.size();
        while (row < rows && col >= 0) {
            if (target == matrix[row][col]) {
                return true;
            }
            else if (target < matrix[row][col]) {
                col--;
            }
            else {
                row++;
            }
        }
        return false;
    }
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        for (auto &array : matrix) {
            if ((*begin(array) <= target) && (*(end(array) - 1)>= target)) {
                if (find(array, target)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool find(const std::vector<int>&array, int target) {
        int low = 0;
        int high = array.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (array[mid] == target) {
                return true;
            }
            else if (array[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};
int main() {
    std::vector<vector<int>> matrix = { {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19 }, { 3, 6, 9, 16, 22 }, { 10, 13, 14, 17, 24 }, { 18, 21, 23, 26, 30 } };
    Solution ss;
    std::cout << ss.searchMatrix(matrix, 20) << std::endl;

    return 0;
}