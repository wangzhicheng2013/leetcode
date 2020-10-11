#include <stdio.h>
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
    bool isValidBST(TreeNode* root) {
        static int last_val;
        static bool last_val_empty = true;
        if (!root) {
            return true;
        }
        if (root->left) {
            isValidBST(root->left);
        }
        if (true == last_val_empty) {
            last_val_empty = false;
        }
        else {
            if (root->val <= last_val) {
                return false;
            }
        }
        last_val = root->val;
        if (root->right) {
            isValidBST(root->right);
        }
        return true;
    }
    void create_bt(TreeNode *&root) {
        int e;
        cin >> e;
        if (e != -1) {
            root = (TreeNode *)malloc(sizeof(TreeNode));
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
    bool isValidBST1(TreeNode* root) {
        if (!root) {
            return true;
        }
        if (!root->left && !root->right) {
            return true;
        }
        if (root->left && root->left->val >= root->val) {
            return false;
        }
        if (root->right && root->right->val <= root->val) {
            return false;
        }
    }
};
int main() {
    Solution s;
    s.create_bt(root);
    s.show_bt(root);
    
    return 0;
}