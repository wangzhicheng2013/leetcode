#include <iostream>
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
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || (nullptr == head->next)) {
            return head;
        }
        ListNode* odd_head = nullptr, *odd_tail = nullptr;
        ListNode* even_head = nullptr, *even_tail = nullptr;
        int index = 1;
        ListNode* p = head;
        ListNode* q = nullptr;
        while (p) {
            q = p;
            p = p->next;
            q->next = nullptr;
            if (index & 0x01) {
                if (nullptr == odd_head) {
                    odd_head = q;
                }
                else {
                    odd_tail->next = q;
                }
                odd_tail = q;
            }
            else {
                 if (nullptr == even_head) {
                    even_head = q;
                }
                else {
                    even_tail->next = q;
                }
                even_tail = q;            
            }
            ++index;
        }
        odd_tail->next = even_head;
        return odd_head;
    }
};
int main() {
    create_list(6);
    show_list();
    Solution ss;
    head = ss.oddEvenList(head);
    show_list();
    
    return 0;
}