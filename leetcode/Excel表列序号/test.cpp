#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
		int n = columnTitle.size();
		int sum = 0;
		int s = 1;
		
		for (int i = 0;i < n - 1;i++) {
			sum += s * 26;
			s*= 26;
		}
		s = 1;
		for (int i = n - 1;i >=0;i--) {
			sum = sum + (columnTitle[i] - 'A') * s;
			s *= 26;
		}
		return sum + 1;
    }
};
int main() {
	Solution ss;
	std::string str;
	std::cin >> str;
	std::cout << ss.titleToNumber(str) << std::endl;
	
	return 0;
}