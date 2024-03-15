#include <stdio.h>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp_head = new ListNode;
        if (!tmp_head) {
            return nullptr;
        }
        ListNode* p = head;
        ListNode* q = nullptr;
        while (p) {
            q = p;
            p = p->next;
            q->next = tmp_head->next;
            tmp_head->next = q;
        }
        p = tmp_head->next;
        tmp_head->next = nullptr;
        delete tmp_head;
        tmp_head = nullptr;
        return p;
    }
};