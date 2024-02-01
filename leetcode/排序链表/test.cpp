#include <time.h>
#include <iostream>
#include <list>
#include <cassert>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* head = nullptr;
void create_list(int n) {
    srand(time(nullptr));
    ListNode* p = nullptr;
    for (int i = 0;i < n;i++) {
        p = new ListNode(rand() % n);
        assert(p);
        if (nullptr == head) {
            head = p;
        }
        else {
            p->next = head->next;
            head->next = p;
        }
    }
}
void show_list() {
    for (ListNode* p = head;p != nullptr;p = p->next) {
        std::cout << p->val << std::endl;
    }
}
void delete_list() {
    ListNode* p = head;
    ListNode* tmp = nullptr;
    while (p != nullptr) {
        tmp = p;
        p = p->next;
        delete tmp;
    }   
}
class Solution {
private:
    ListNode* get_mid_node(ListNode* head) {
        ListNode* fast_node = head;
        ListNode* slow_node = head;
        while (fast_node && fast_node->next) {
            fast_node = fast_node->next->next;
            slow_node = slow_node->next;
        }
        return slow_node;
    }
    ListNode* merge_list(ListNode* head1, ListNode* head2) {
        ListNode* tmp_head = new ListNode;
        if (nullptr == tmp_head) {
            return nullptr;
        }
        ListNode* tail = tmp_head;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;  
            }
            tail = tail->next;
        }
        if (head1) {
            tail->next = head1;
        }
        else if (head2) {
            tail->next = head2;
        }
        ListNode* new_head = tmp_head->next;
        delete tmp_head;
        return new_head;
    }
    ListNode* do_sortList(ListNode* head) {
        if ((nullptr == head) || (nullptr == head->next)) {
            return head;
        }
        ListNode* mid = get_mid_node(head);
        ListNode* pre = head;
        while (pre->next != mid) {
            pre = pre->next;
        }
        pre->next = nullptr;
        ListNode* left = do_sortList(head);
        ListNode* right = do_sortList(mid);
        return merge_list(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        ListNode* tmp_head = new ListNode;
        if (nullptr == tmp_head) {
            return nullptr;
        }
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        ListNode* pre = nullptr;
        while (p) {
            q = p;
            p = p->next;
            q->next = nullptr;
            if (nullptr == tmp_head->next) {
                tmp_head->next = q;
                continue;
            }
            r = tmp_head->next;
            pre = tmp_head;
            while ((r != nullptr) && (r->val <= q->val)) {
                pre = r;
                r = r->next;
            }
            if (nullptr == r) {
                pre->next = q;
            }
            else {
                q->next = r;
                pre->next = q;
            }
        }
        head = tmp_head->next;
        delete tmp_head;
        return head;
    }
    ListNode* sortListMerge(ListNode* head) {
        return do_sortList(head);
    }

};
int main() {
    int n = 10;
    create_list(n);
    std::cout << "sorted before-----------------" << std::endl;
    show_list();
    Solution ss;
    head = ss.sortList(head);
    //head = ss.sortListMerge(head);
    std::cout << "sorted after-----------------" << std::endl;
    show_list();
    delete_list();
    std::list<int>ll;
    for (int i = 0;i < n;i++) {
        ll.push_back(rand() % n);
    }
    ll.sort();  
    for (const auto& elem : ll) {
        std::cout << elem << std::endl;
    }
     
    return 0;
}