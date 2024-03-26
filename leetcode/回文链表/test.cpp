#include <iostream>
#include <string>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *head;
void create_list(int n) {
    ListNode *tail = head;
    int e;
    for (int i = 0;i < n;i++) {
        std::cin >> e;
        ListNode *p = new ListNode(e);
        if (!head) {
            head = p;
        }
        else {
            tail->next = p;
        }
        tail = p;
    }
}
void show_list() {
    ListNode *p = head;
    for (;p;p = p->next) {
        std::cout << p->val << std::endl;
    }
}
class Solution {
private:
    ListNode* forward_ptr_ = nullptr;
public:
    bool isPalindrome(ListNode* head) {
        if (nullptr == head->next) {
            return true;
        }
        std::string str;
        ListNode* p = head;
        for (;p != nullptr;p = p->next) {
            str += std::to_string(p->val);
        }
        int size = str.size();
        for (int i = 0, j = size - 1;i < j;i++, j--) {
            if (str[i] != str[j]) {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome1(ListNode* head) {
        forward_ptr_ = head;
        return judge(head);
    }
    bool judge(ListNode* node) {
        if (node && forward_ptr_) {
            bool ret = judge(node->next) && (node->val == forward_ptr_->val);
            forward_ptr_ = forward_ptr_->next;
            return ret;
        }
        return true;
    }
};
int main() {
    create_list(6);
    show_list();
    Solution ss;
    std::cout << ss.isPalindrome1(head) << std::endl;
    
    return 0;
}