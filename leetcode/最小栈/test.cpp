#include <iostream>
#include <limits>
struct stack_node {
    stack_node(int e) : elem(e), next(nullptr) {
    }
    stack_node() {
        elem = 0;
        next = nullptr;
    }
    int elem;
    struct stack_node *next;
};
class MinStack {
public:
    MinStack() {
        top_ = new stack_node;
    }
    virtual ~MinStack() {
        stack_node *tmp = nullptr;
        for (stack_node *ptr = top_;ptr;ptr = ptr->next) {
            tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
    }
    void push(int val) {
        stack_node *p = new stack_node(val);
        if (!p) {
            return;
        }
        p->next = top_->next;
        top_->next = p;
        if (val < min_val_) {
            min_val_ = val;
        }
    }
    void pop() {
        if (nullptr == top_->next) {
            return;
        }
        auto ptr = top_->next;
        top_->next = ptr->next;
        int tmp = ptr->elem;
        delete ptr;
        if (tmp == min_val_) {
            min_val_ = std::numeric_limits<int>::max();
            for (ptr = top_->next;ptr;ptr = ptr->next) {
                if (ptr->elem < min_val_) {
                    min_val_ = ptr->elem;
                }
            }
        }

    }
    int top() {
        if (nullptr == top_->next) {
            return std::numeric_limits<int>::min();
        }
        return top_->next->elem;
    }   
    
    int getMin() {
        return min_val_;
    }
private:
    stack_node *top_ = nullptr;
    int min_val_ = std::numeric_limits<int>::max();
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->push(-1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    std::cout << param_4 << std::endl;
    
    return 0;
}