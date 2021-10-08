#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
bool array[10] = { 0 };
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return judge_rows(board) && judge_cols(board) && judge_palaces(board);
    }
    bool judge_rows(const vector<vector<char>>& board) {
        int size = board.size();
        for (int row = 0;row < size;row++) {
            const vector<char>&row_board = board[row];
            memset(array, 0, sizeof(array));
            for (auto &ch : row_board) {
                if ('.' == ch) {
                    continue;
                }
                int index = ch - '0';
                if (!array[index]) {
                    array[index] = true;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
    bool judge_cols(const vector<vector<char>>& board) {
        int size = board.size();
        for (int col = 0;col < size;col++) {
            memset(array, 0, sizeof(array));
            for (int i = 0;i < size;i++) {
                char ch = board[i][col];
                if ('.' == ch) {
                    continue;
                }
                int index = ch - '0';
                if (!array[index]) {
                    array[index] = true;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
    bool judge_palaces(const vector<vector<char>>& board) {
        int size = board.size();
        for (int row = 0;row < size;row +=3) {
            for (int col = 0;col < size;col +=3) {
                memset(array, 0, sizeof(array));
                for (int i = row;i < row + 3;i++) {
                    for (int j = col;j < col + 3;j++) {
                        char ch = board[i][j];
                        if ('.' == ch) {
                            continue;
                        }
                        int index = ch - '0';
                        if (!array[index]) {
                            array[index] = true;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
int main() {
 /*   vector<vector<char>>board = { {'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}
                                };*/
   vector<vector<char>>board = { {'8','3','.','.','7','.','.','.','.'},
                                 {'6','.','.','1','9','5','.','.','.'},
                                 {'.','9','8','.','.','.','.','6','.'},
                                 {'8','.','.','.','6','.','.','.','3'},
                                 {'4','.','.','8','.','3','.','.','1'},
                                 {'7','.','.','.','2','.','.','.','6'},
                                 {'.','6','.','.','.','.','2','8','.'},
                                 {'.','.','.','4','1','9','.','.','5'},
                                 {'.','.','.','.','8','.','.','7','9'}
                              };

    Solution ss;
    std::cout << ss.isValidSudoku(board) << std::endl;

    return 0;
}