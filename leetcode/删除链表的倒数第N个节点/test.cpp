#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {
    }
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        nodes_address_.clear();
        ListNode *p = head;
        for(;p;p = p->next) {
            nodes_address_.push_back(p);
        }
        int node_num = nodes_address_.size();
        int delete_node = node_num - n;         // start from 0
        if (delete_node < 0) {
            return head;
        }
        if (0 == delete_node) {
            p = head;
            head = head->next;
            p->next = nullptr;
            delete p;
            p = nullptr;
        }
        else {
            ListNode *pre = nodes_address_[delete_node - 1];
            p = pre->next;
            pre->next = p->next;
            p->next = nullptr;
            delete p;
            p = nullptr;
        }
        return head;   
    }
private:
    std::vector<ListNode *>nodes_address_;
};
int main() {
    return 0;
}