#include <iostream>
#include <cassert>
#include <vector>
#include <functional>
#include <algorithm>
enum HEAP_TYPE {
    BIG_HEAP,
    SMALL_HEAP,
};
template <typename T>
bool lesser(const T& a, const T& b) {
    return a < b;
}
template <typename T>
bool greater(const T& a, const T& b) {
    return a >= b;
}
template <typename DataType, HEAP_TYPE flag>
class heap {
public:
    const std::function<bool(const DataType&, const DataType&)>cmp_fun = (BIG_HEAP == flag) ? lesser<DataType> : greater<DataType>;
private:
    std::vector<DataType>vec_;
public:
    heap() {
        assert((BIG_HEAP == flag) || (SMALL_HEAP == flag));
    }
    void add(const DataType& e) {
        vec_.emplace_back(e);
        std::push_heap(vec_.begin(), vec_.end(), cmp_fun);
    }
    inline DataType peek() {
        assert(vec_.size() >= 1);
        return vec_[0];
    }
    DataType poll() {
        assert(vec_.size() >= 1);
        auto e = vec_[0];
        std::pop_heap(vec_.begin(), vec_.end(), cmp_fun);
        vec_.pop_back();
        return e;
    }
    inline size_t size() const {
        return vec_.size();
    }
};
class MedianFinder {
private:
    heap<int, BIG_HEAP>big_heap;
    heap<int, SMALL_HEAP>small_heap;
public:
    MedianFinder() {
    }
    void addNum(int num) {
        if (0 == ((big_heap.size() + small_heap.size()) & 1)) {
            if (big_heap.size() > 0 && big_heap.peek() > num) {
                small_heap.add(big_heap.poll());
                big_heap.add(num);
            }
            else {
                small_heap.add(num);
            }
        }
        else {
            if (small_heap.size() > 0 && small_heap.peek() < num) {
                big_heap.add(small_heap.poll());
                small_heap.add(num);
            }
            else {
                big_heap.add(num);
            }
        }
    }
    double findMedian() {
        if (big_heap.size() == small_heap.size()) {
            return (big_heap.peek() + small_heap.peek()) / 2.0;
        }
        return small_heap.peek();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 */
int main() {
    return 0;
}