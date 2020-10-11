#include <iostream>
#include <set>
struct ListNode {
    int val;
    bool visited = false;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow_p = head;
        ListNode *fast_p = head;
        bool is_ring = false;
        while (slow_p) {
            slow_p = slow_p->next;
            if (!slow_p) {
                return nullptr;
            }
            for (int i = 0;i < 2;i++) {
                fast_p = fast_p->next;
                if (!fast_p) {
                    return nullptr;
                }
            }
            if (slow_p == fast_p) {     // ring
                is_ring = true;
                break;
            }
        }
        if (!is_ring) {
            return nullptr;
        }
        slow_p = head;
        while (slow_p != fast_p) {
            slow_p = slow_p->next;
            fast_p = fast_p->next;
        }
        return slow_p;
    }
};
int main() {
    return 0;
}