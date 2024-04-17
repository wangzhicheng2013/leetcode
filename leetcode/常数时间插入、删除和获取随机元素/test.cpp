
#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;
class RandomizedSet {
private:
    std::unordered_map<int, int>val_index_;
    std::vector<int>vals_;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if (val_index_.find(val) != val_index_.end()) {
            return false;
        }
        val_index_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        auto it = val_index_.find(val);
        if (val_index_.end() == it) {
            return false;
        }
        int index = it->second;
        int last_index = vals_.size() - 1;
        int last_val = vals_[last_index];
        vals_[index] = last_val;
        vals_.pop_back();
        val_index_[last_val] = index; 
        val_index_.erase(val);
        return true;
    }
    
    int getRandom() {
        std::random_device rd;  
        std::mt19937 gen(rd());  
        std::uniform_int_distribution<> dis(0, vals_.size() - 1);  
        int index = dis(gen);
        return vals_[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
int main() {
    return 0;
}