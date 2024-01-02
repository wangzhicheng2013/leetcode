#include <iostream>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* global_head = nullptr;
void create_list() {
    int n = 4;
    Node* p = nullptr;
    Node* tail = nullptr;
    for (int i = 0;i < n;i++) {
        p = new Node(i);
        if (global_head) {
            tail->next = p;
        }
        else {
            global_head = p;
        }
        tail = p;
        p = p->next;
    }
    p = global_head;
    for (int i = 0;i < 3;i++) {
        p = p->next;
    }
    global_head->random = p;
}
void show_list(Node *node) {
    Node* p = node;
    while (p) {
        std::cout << p->val << std::endl;
        if (p->random) {
            std::cout << p->random->val << std::endl;
        }
        std::cout << "-------------------" << std::endl;
        p = p->next;
    }
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        Node* new_head = nullptr;
        Node* tail = nullptr;
        Node* new_p = nullptr;
        // construct a new link list
        while (p) {
            new_p = new Node(p->val);
            if (new_head) {
                tail->next = new_p;
            }
            else {
                new_head = new_p;
            }
            tail = new_p;
            p = p->next;
        }
        p = head;
        new_p = new_head;
        Node* p_random = nullptr;
        Node* new_p_random = nullptr;
        while (p) {
            if (p->random) {
                p_random = head;
                new_p_random = new_head;
                while (p_random != p->random) {
                    p_random = p_random->next;
                    new_p_random = new_p_random->next;
                }
                new_p->random = new_p_random;
            }
            else {
                new_p->random = nullptr;
            }
            p = p->next;
            new_p = new_p->next;
        }
        return new_head;
    }
};
int main() {
    create_list();
    Solution ss;
    Node* p = ss.copyRandomList(global_head);
    show_list(p);
    
    return 0;
}