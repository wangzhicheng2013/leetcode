#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* bt_root = nullptr;
class Solution {
private:
    const int NULL_VAL = -1001;
    const char SEP_CHAR = ';';
    const char NULL_CHAR = '#';
    int cur_pos = -1;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string data;
        if (root) {
            serialize_bt(root, data);
        }
        return data;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        if (data.empty()) {
            return nullptr;
        }
        std::vector<int>vals;
        fetch_vals(data, vals);
        deserialize_bt(root, vals);
        return root;
    }
    void serialize_bt(TreeNode* root, std::string& data) {
        if (root) {
            data += std::to_string(root->val);
        }
        else {
            data += NULL_CHAR;
        }
        data += SEP_CHAR;
        if (root) {
            serialize_bt(root->left, data);
            serialize_bt(root->right, data);
        }
    }
    // 1;2;#;#;3;#;#; => 12NULL_VALNULL_VAL3NULL_VALNULL_VAL
    void fetch_vals(const std::string& data, std::vector<int>&vals) {
        int start = 0, end = 0;
        char buf[8] = { 0 };
        int len = 0;
        while (start < data.size()) {
            while ((end < data.size()) && data[end] != SEP_CHAR) {
                ++end;
            }
            len = end - start;
            if (len > 0) {
                memset(buf, 0, sizeof(buf));
                memcpy(buf, &(data[start]), len);
                if ('#' == buf[0]) {
                    vals.push_back(NULL_VAL);
                }
                else {
                    vals.push_back(atoi(buf));
                }
            }
            start = end + 1;
            end = start;
        }
    }
    void deserialize_bt(TreeNode*& root, const std::vector<int>&vals) {
        ++cur_pos;
        if (vals[cur_pos] != NULL_VAL) {
            root = new TreeNode(vals[cur_pos]);
            deserialize_bt(root->left, vals);
            deserialize_bt(root->right, vals);
        }
    }
};
void create_btree(TreeNode* &root) {
    int val = 0;
    std::cin >> val;
    if (-1 == val) {
        return;
    }
    if (nullptr == root) {
        root = new TreeNode(val);
        create_btree(root->left);
        create_btree(root->right);
    }
}
void print_btree(TreeNode* root) {
    if (nullptr == root) {
        return;
    }
    std::cout << root->val << " ";
    print_btree(root->left);
    print_btree(root->right);
}
void delete_tree(TreeNode* &root) {
    if (root) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
        root = nullptr;
    }
}
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main() {
    create_btree(bt_root);
    print_btree(bt_root);
    std::cout << std::endl;
    Solution ss;
    std::string str = ss.serialize(bt_root);
    std::cout << str << std::endl;
    TreeNode* new_root = ss.deserialize(ss.serialize(bt_root));
    print_btree(new_root);
    std::cout << std::endl;
    delete_tree(bt_root);
    delete_tree(new_root);

    return 0;
}
