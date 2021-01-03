#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *p = head;
        ListNode *next_p = nullptr;
        ListNode *pre_p = nullptr;
        while (p && p->next) {
            next_p = p->next;
            if (p == head) {
                head = next_p;
            }
            if (pre_p) {
                pre_p->next = next_p;
            }
            p->next = next_p->next;
            next_p->next = p;
            p = next_p->next->next;
            pre_p = next_p->next;
        }
        return head;
    }
    ListNode *create_list(int n) {
        if (n <= 0) {
            return nullptr;
        }
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        for (int i = 1;i <= n;i++) {
            ListNode *p = new ListNode(i);
            if (!p) {
                return nullptr;
            }
            if (!head) {
                head = p;
            }
            else {
                tail->next = p;
            }
            tail = p;
        }
        return head;
    }
    void show_list(ListNode *head) {
        ListNode *p = head;
        while (p) {
            std::cout << p->val << std::endl;
            p = p->next;
        }
    }
};
int main() {
    Solution ss;
    ListNode *head = ss.create_list(3);
    head = ss.swapPairs(head);
    ss.show_list(head);

    return 0;
}