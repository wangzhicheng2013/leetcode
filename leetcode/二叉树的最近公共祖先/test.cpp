#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* bt_root = nullptr;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*>ancestors_p, ancestors_q;
        bool find = false;
        save_ancestors(root, p, ancestors_p, find);
        find = false;
        save_ancestors(root, q, ancestors_q, find);
        int size_p = ancestors_p.size();
        int size_q = ancestors_q.size();
        int i = 0, j = 0;
        while ((i < size_p) && (j < size_q)) {
            if (ancestors_p[i] == ancestors_q[j]) {
                i++;
                j++;
            }
            else {
                break;
            }
        }
        if (i < size_p) {
            return ancestors_p[i - 1];
        }
        else if (j < size_q) {
            return ancestors_q[j - 1];
        }
        return root;    
    }
    void save_ancestors(TreeNode* root,
                        TreeNode* p,
                        std::vector<TreeNode*>& ancestors,
                        bool& find) {
        if ((nullptr == root) || (true == find)) {
            return;
        }
        ancestors.push_back(root);
        if (root == p) {
            find = true;
            return;
        }
        else {
            save_ancestors(root->left, p, ancestors, find);
            save_ancestors(root->right, p, ancestors, find);
            if (!find) {
                ancestors.pop_back();
            }
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
bool get_node(TreeNode* root, int val, TreeNode** node) {
    if (root && (val == root->val)) {
        *node = root;
        return true;
    }
    else if (root) {
        if (false == get_node(root->left, val, node)) {
            return get_node(root->right, val, node);
        }
    }
    else {
        return false;
    }
}
int main() {
    create_btree(bt_root);
    print_btree(bt_root);
    std::cout << "\n=====================\n";
    int val;
    std::cin >> val;
    TreeNode* p = nullptr;
    get_node(bt_root, val, &p);
    std::cin >> val;
    TreeNode* q = nullptr;
    get_node(bt_root, val, &q);
    if (p) {
        std::cout << "get:" << p->val << std::endl;
    }
    if (q) {
        std::cout << "get:" << q->val << std::endl;
    }
    Solution ss;
    TreeNode* r = ss.lowestCommonAncestor(bt_root, p, q);
    std::cout << r->val << std::endl;

    return 0;
}