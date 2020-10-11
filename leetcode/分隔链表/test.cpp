
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
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
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *low_head = new ListNode(0);
        if (!low_head) {
            return nullptr;
        }
        ListNode *low_tail = low_head;
        ListNode *p = head;
        ListNode *pre = nullptr;
        ListNode *q = nullptr;
        while (p) {
            if (p->val < x) {
                q = p->next;
                if (!pre) {
                    head = q;
                }
                else {
                    pre->next = p->next;
                }
                p->next = nullptr;
                low_tail->next = p;
                low_tail = p;
                p = q;
            }
            else {
                pre = p;
                p = p->next;
            }
        }
        if (low_head != low_tail) {
            low_tail->next = head;
            head = low_head->next;
        }
        low_head->next = nullptr;
        delete low_head;
        return head;
    }
};
int main() {
    create_list(6);
    show_list();

    return 0;
}