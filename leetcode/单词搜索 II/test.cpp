#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
static const int TRIE_NODE_CAP = 26;
struct trie_node {
    struct trie_node *childs[TRIE_NODE_CAP] = { 0 };
    bool terminated = false;
    string key_word;
};

class Trie {
public:
    Trie() {
        if (!head_) {
            head_ = new trie_node;
        }
    }
    virtual ~Trie() { 
        if (head_) {
            delete head_;
            head_ = nullptr;
        }
    }
    void insert(string word) {
        int pos = 0;
        trie_node *node = head_;
        for (auto& ch : word) {
            pos = ch - 'a';
            if (nullptr == node->childs[pos]) {
                node->childs[pos] = new trie_node;
            }
            node = node->childs[pos];
        }
        if (node) {
            node->terminated = true;
            node->key_word = word;
        }
    }
public:
    trie_node *head_ = nullptr;
};
inline trie_node *find_letter_from_trie(char letter, trie_node *cur_node) {
    if (nullptr == cur_node) {
        return nullptr;
    }
    int pos = letter - 'a';
    return cur_node->childs[pos];
}
class Solution {
public:
    vector<string> findWords(vector<vector<char>>&board, vector<string>&words) {
        int m = board.size();
        int n = board[0].size();
        Trie trie_tree;
        for (auto &word : words) {
            trie_tree.insert(word);
        }
        vector<string>ret;
        char letter;
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                letter = board[i][j];
                board[i][j] = '*';
                back_tracking(ret, board, letter, trie_tree.head_, i, j, m, n);
                board[i][j] = letter;
            }
        }
        return ret;
    }
    void back_tracking(vector<string>&ret, vector<vector<char>>&board, char letter, trie_node *cur_node, int x_idx, int y_idx, int m, int n) {
        cur_node = find_letter_from_trie(letter, cur_node);
        if (nullptr == cur_node) {
            return;
        }
        if (cur_node->terminated) {
            ret.push_back(cur_node->key_word);
            cur_node->terminated = false;
        }
        if (x_idx > 0 && board[x_idx - 1][y_idx] != '*') {
            letter = board[x_idx - 1][y_idx];
            board[x_idx - 1][y_idx] = '*';
            back_tracking(ret, board, letter, cur_node, x_idx - 1, y_idx, m, n);
            board[x_idx - 1][y_idx] = letter;
        }
        if (y_idx > 0 && board[x_idx][y_idx - 1] != '*') {
            letter = board[x_idx][y_idx - 1];
            board[x_idx][y_idx - 1] = '*';
            back_tracking(ret, board, letter, cur_node, x_idx, y_idx - 1, m, n);
            board[x_idx][y_idx - 1] = letter;
        }
        if (x_idx < m - 1 && board[x_idx + 1][y_idx] != '*') {
            letter = board[x_idx + 1][y_idx];
            board[x_idx + 1][y_idx] = '*';
            back_tracking(ret, board, letter, cur_node, x_idx + 1, y_idx, m, n);
            board[x_idx + 1][y_idx] = letter;
        }
        if (y_idx < n - 1 && board[x_idx][y_idx + 1] != '*') {
            letter = board[x_idx][y_idx + 1];
            board[x_idx][y_idx + 1] = '*';
            back_tracking(ret, board, letter, cur_node, x_idx, y_idx + 1, m, n);
            board[x_idx][y_idx + 1] = letter;
        }
    }
};
int main() {
    Solution ss;
    vector<vector<char>>board = { { 'o', 'a', 'a', 'n' }, { 'e', 't', 'a', 'e' }, { 'i', 'h', 'k', 'r' }, { 'i', 'f', 'l', 'v'} };
    //vector<vector<char>>board = { { 'a', 'b' }, { 'c', 'd' } };
    vector<string>words = { "oath", "pea", "eat", "rain" };
    //vector<string>words = { "abcb" };
    auto ret = ss.findWords(board, words);
    for (auto &str : ret) {
        std::cout << str << std::endl;
    }

    return 0;
}