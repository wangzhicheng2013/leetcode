#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* bt_root = nullptr;
class Solution {
private:
    int count = 0;
    bool find = false;
    int val = -1;
public:
    int kthSmallest(int k) {
        return kthSmallest(bt_root, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        get_kth_smallest(root, k);
        return val;
    }
    void get_kth_smallest(TreeNode* root, int k) {
        if ((nullptr == root) || (true == find)) {
            return;
        }
        get_kth_smallest(root->left, k);
        if (++count == k) {
            val = root->val;
            find = true;
            return;
        }
        get_kth_smallest(root->right, k);
    }
    void create_btree() {
        int n = 10;
        int val = 0;
        srand(time(nullptr));
        for (int i = 0;i < n;i++) {
            val = rand() % n;
            create_btree(bt_root, val);
        }
    }
    void create_btree(TreeNode* &root, int val) {
        if (nullptr == root) {
            root = new TreeNode(val);
        }
        else if (root->val > val) {
            create_btree(root->left, val);
        }
        else {
            create_btree(root->right, val);
        }
    }
    void print_btree() {
        print_btree(bt_root);
    }
    void print_btree(TreeNode* root) {
        if (nullptr == root) {
            return;
        }
        print_btree(root->left);
        std::cout << root->val << " ";
        print_btree(root->right);
    }
};
int main() {
    Solution ss;
    ss.create_btree();
    ss.print_btree();
    std::cout << std::endl;
    int k;
    std::cin >> k;
    std::cout << "k = " << ss.kthSmallest(k) << std::endl;

    return 0;
}