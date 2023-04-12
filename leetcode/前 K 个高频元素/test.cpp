#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
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
        for (auto m : stat_map) {
            vec.push_back(m);    
        }
        sort(vec.begin(), vec.end(), [] (const std::pair<int, int>& e1, const std::pair<int, int>& e2) { return e1.second > e2.second; } );
        std::vector<int>tmp;
        for (int i = 0;(i < k) && (i < vec.size());i++) {
            tmp.push_back(vec[i].first);
        }
        return tmp;
    }
private:
    std::map<int, int>stat_map;
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