#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;
struct Less {
    bool operator() (const std::pair<int, int>& e1, const std::pair<int, int>& e2) const {
        return e1.second < e2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        stat_map.clear();
        for (auto &num : nums) {
            auto it = stat_map.find(num);
            if (it == stat_map.end()) {
                stat_map.emplace(num, 1);
            }
            else {
                ++(it->second);
            }
        }
        vec.clear();
        for (const auto &m : stat_map) {
            vec.push_back(m);    
        }
        sort(vec.begin(), vec.end(), [] (const std::pair<int, int>& e1, const std::pair<int, int>& e2) { return e1.second > e2.second; } );
        std::vector<int>tmp;
        for (int i = 0;(i < k) && (i < vec.size());i++) {
            tmp.push_back(vec[i].first);
        }
        return tmp;
    }
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        stat_map.clear();
        for (auto &num : nums) {
            auto it = stat_map.find(num);
            if (it == stat_map.end()) {
                stat_map.emplace(num, 1);
            }
            else {
                ++(it->second);
            }
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Less>pq;
        for (const auto &m : stat_map) {
            pq.push(m);    
        }
        if (k > pq.size()) {
            k = pq.size();
        }
        std::vector<int>tmp;
        for (int i = 0;i < k;i++) {
            tmp.push_back(pq.top().first);
            pq.pop();
        }
        return tmp;
    }
private:
    std::unordered_map<int, int>stat_map;
    std::vector<std::pair<int, int> >vec;
};
int main() {
    std::vector<int>nums = { 1, 1, 1, 2, 2, 3 };
    int k = 2;
    auto vec = Solution().topKFrequent(nums, k);
    for (auto &e : vec) {
        std::cout << e << std::endl;
    }

    return 0;
}