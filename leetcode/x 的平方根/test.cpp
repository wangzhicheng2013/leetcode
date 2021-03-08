#include <cmath>
#include <iostream>
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        return int(sqrt(x));
    }
};
int main() {
    Solution ss;
    std::cout << ss.mySqrt(8) << std::endl; 
    std::cout << ss.mySqrt(4) << std::endl;
    return 0;
}