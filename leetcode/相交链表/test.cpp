#include <iostream>
#include <set>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = get_list_len(headA);
        int n = get_list_len(headB);
        int cnt = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        if (m > n) {
            cnt = m - n;
            for (int i = 0;(i < cnt) && p;i++) {
                p = p->next;
            }
        }
        else if (m < n) {
            cnt = n - m;
            for (int i = 0;(i < cnt) && q;i++) {
                q = q->next;
            }          
        }
        while (p && q) {
            if (p == q) {
                return p;
            }
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
    int get_list_len(ListNode *head) {
        int len = 0;
        ListNode* p = head;
        while (p) {
            ++len;
            p = p->next;
        }
        return len; 
    }
};
int main() {
    Solution ss;

    return 0;
}