#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int n = matrix.size();
        int start_i = 0, start_j = 0;
        int next_i = 0, next_j = 0;
        int val = 0, next_val = 0;
        int cnt = 0;
        int size = n * n;
        for (i = 0;i < n;i++) {
            for (j = i;j < n - i - 1;j++) {
                start_i = i;
                start_j = j;
                val = matrix[i][j];
                while (true) {
                    next_i = j;
                    next_j = n - i - 1;
                    if (next_i < 0 || next_j < 0) {
                        break;
                    }
                    next_val = matrix[next_i][next_j];
                    matrix[next_i][next_j] = val;
                    i = next_i;
                    j = next_j;
                    val = next_val;
                    cnt++;
                    if ((i == start_i) && (j == start_j)) {
                        break;
                    }
                }
                if (cnt >= size) {
                    return;
                }
            }
        }
    }
};
int main() {
    Solution ss;
    //vector<vector<int>>matrix {{1}};
    //vector<vector<int>>matrix { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9} };
    vector<vector<int>>matrix { { 5, 1, 9, 11 }, { 2, 4, 8, 10 }, { 13, 3, 6, 7}, { 15, 14, 12, 16 } };
    ss.rotate(matrix);
    int size = matrix.size();
    for (int i = 0;i < size;i++) {
        for (int j = 0;j < size;j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}