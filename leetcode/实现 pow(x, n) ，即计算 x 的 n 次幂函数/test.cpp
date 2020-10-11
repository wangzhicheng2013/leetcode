#include <iostream>
class Solution {
public:
    double myPow(double x, int n) {
        if (fabs(x - 1.0) < 0.00000001) {
            return 1;
        }
        if (fabs(x + 1.0) < 0.00000001) {
            return n % 2 ? -1 : 1;
        }
        if (fabs(x - 0) < 0.00000001) {
            return 0;
        }
        if (0 == n) {
            return 1;
        }
        if (n > 0) {
            return positive_pow(x, n);
        }
        return negative_pow(x, n);
    }
    double positive_pow(double x, int n) {
        double value = 1;
        while (n > 0) {
            if (n % 2) {
                value *= x;
            }
            if (fabs(value - 0) < 0.00000001) {
                return 0;
            }
            x *= x;
            n = (n >> 1);
        }
        return value;
    }
    double negative_pow(double x, int n) {
        double value = 1;
        for (int i = n;i < 0;i++) {
            value *= (1 / x);
            if (fabs(value - 0) < 0.00000001) {
                return 0;
            }
        }
        return value;
    }
};
int main() {
    return 0;
}