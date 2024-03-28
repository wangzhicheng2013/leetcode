#include <iostream>
struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* tmp = node->next;
        node->next = node->next->next;
        delete tmp;
        tmp = nullptr;
    }
};
int main() {
    return 0;
}