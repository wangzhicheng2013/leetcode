#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    virtual bool isInteger() const = 0;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    virtual int getInteger() const = 0;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    virtual const vector<NestedInteger> &getList() const = 0;
};
// 1
// [1,[2,3]]

class NestedIterator {
private:
    std::queue<int>q_;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        add_queue(nestedList);
    }
    
    int next() {
        int num = q_.front();
        q_.pop();
        return num;
    }
    
    bool hasNext() {
        return false == q_.empty();
    }
private:
    void add_queue(vector<NestedInteger> &nestedList) {
        for (auto &nestedInteger : nestedList) {
            if (nestedInteger.isInteger()) {
                q_.push(nestedInteger.getInteger());
            }
            else {
                add_queue(nestedInteger.getList());
            }
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */