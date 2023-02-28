#include <iostream>
#include <cmath>

int main() {
    int a, b;
    std::cin >> a >> b;
    int max_val = 0;
    for (int m = a;m <= b;m++) {
        for (int n = a;n <= b;n++) {
            int t = n * n - m * n - m * m;
            if (t * t != 1) {
                continue;
            }
            t = m * m + n * n;
            if (t > max_val) {
                max_val = t;
            }
        }
    }
    std::cout << "max val:" << max_val << std::endl;

    return 0;
}