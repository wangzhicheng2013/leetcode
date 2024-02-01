#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow_p = head;
        ListNode *fast_p = head;
        while (slow_p) {
            slow_p = slow_p->next;
            if (!slow_p) {
                return false;
            }
            for (int i = 0;i < 2;i++) {
                fast_p = fast_p->next;
                if (!fast_p) {
                    return false;
                }
            }
            if (slow_p == fast_p) {     // ring
                return true;
            }
        }
        return false;
    }
};
int main() {
    return 0;
}