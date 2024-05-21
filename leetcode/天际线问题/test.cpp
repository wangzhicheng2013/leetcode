#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    using coordinate_height_type = std::pair<int, int>;
    static bool cmp(coordinate_height_type& coordinate_height_one, coordinate_height_type& coordinate_height_other) {
        int coordinate_one = coordinate_height_one.first;
        int height_one = coordinate_height_one.second;
        int coordinate_other = coordinate_height_other.first;
        int height_other = coordinate_height_other.second;
        return coordinate_one != coordinate_other ? 
                        (coordinate_one < coordinate_other) : (height_one < height_other); 
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        std::vector<coordinate_height_type>points;
        int x = 0, y = 0, height = 0;
        for (auto& e : buildings) {
            x = e[0];
            y = e[1];
            height = e[2];
            points.emplace_back(std::make_pair(x, -height));
            points.emplace_back(std::make_pair(y, height));
        }
        std::sort(points.begin(), points.end(), cmp);
        std::multiset<int, std::greater<int>>height_set;
        height_set.insert(0);
        int pre_max = 0;
        int max_val = 0;
        std::vector<vector<int>>sky_lines;
        for (auto& point : points) {
            x = point.first;
            height = point.second;
            if (height < 0) {
                height = -height;
                height_set.insert(height);
                max_val = *(height_set.begin());
                if (pre_max != max_val) {
                    pre_max = max_val;
                    sky_lines.emplace_back(std::vector<int>{x, height});
                }
            }
            else {
                height_set.erase(height_set.find(height));
                max_val = *(height_set.begin());
                if (pre_max != max_val) {
                    pre_max = max_val;
                    sky_lines.emplace_back(std::vector<int>{x, pre_max});
                }

            }
        }
        return sky_lines;
    }
};
int main() {
    std::vector<std::vector<int>>buildings = { { 0, 2, 3 }, { 2, 5, 3 } };
    Solution ss;
    auto sky_lines = ss.getSkyline(buildings);
    for (auto& v : sky_lines) {
        for (auto& e : v) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}