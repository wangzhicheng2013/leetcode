#include <string.h>
#include <iostream>
int detect_rumor(int expect, const char *truth) {
    char ch = 0;
    int index = 0;
    int count = 0;
    int len = strlen(truth);
    std::cin >> ch;
    while (ch != '#') {
        if (ch != truth[index]) {
            index = 0;
        }
        else {
            index++;
            if (index == len) {
                index = 0;
                ++count;
                std::cout << "find the truth:" << truth << " count:" << count << std::endl;                
            }
        }
        std::cin >> ch;
    }
    return count;
}
int main() {
    int expect = 0;
    std::cin >> expect;
    int count = detect_rumor(expect, "(zhangsheng)");
    std::cout << "real count:" << count << std::endl;
    if (expect <= count) {
        std::cout << "1 True" <<  std::endl;
    }
    else {
        std::cout << "0 False" <<  std::endl;
    }

    return 0;
}