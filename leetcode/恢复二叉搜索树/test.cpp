#include <stdio.h>
#include <iostream>
#include <algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};
TreeNode *root;
class Solution {
public:
    void create_bt(TreeNode *&root) {
        int e;
        std::cin >> e;
        if (e != -1) {
            root = (TreeNode *)malloc(sizeof(TreeNode));
            root->val = e;
            root->left = nullptr;
            root->right = nullptr;
            create_bt(root->left);
            create_bt(root->right);
        }
    }
    void show_bt(TreeNode *root) {
        if (!root) {
            return;
        }
        std::cout << root->val << std::endl;
        show_bt(root->left);
        show_bt(root->right);
    }
    void transform_tree(TreeNode *root) {
        if (!root) {
            return;
        }
        transform_tree(root->left);
        if (pre_node && pre_node->val > root->val) {
            std::swap(pre_node->val, root->val);
            change = true;
            return;

        }
        pre_node = root;
        transform_tree(root->right);
    }
    void recoverTree(TreeNode *root) {
        do {
            pre_node = nullptr;
            change = false;
            transform_tree(root);
        } while (change);
    }
private:
    TreeNode *pre_node;
    bool change;
};
int main() {
    Solution s;
    s.create_bt(root);
    s.show_bt(root);
    s.recoverTree(root);
    s.show_bt(root);
    
    return 0;
}