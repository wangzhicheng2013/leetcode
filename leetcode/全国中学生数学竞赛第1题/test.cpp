#include <iostream>
#include <vector>
#include <cmath>
int solution(int k) {
    int sum = 0;
    int n = 1;
    while (true) {
        if (pow(3, n) <= 2022) {
            n++;
        }
        else if (pow(n, 3) < k)  {
            std::cout << "n = " << n << std::endl;
            sum += n++;
        }
        else {
            break;
        }
    }
    return sum;
}
int main() {
    std::cout << solution(2022) << std::endl;

    return 0;
}

