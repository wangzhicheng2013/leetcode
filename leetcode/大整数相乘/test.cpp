#include <string.h>
#include <ctype.h>
#include <iostream>
#include <string>
const int MAX_STR_LEN = 100;
bool str_is_digit(const char *str) {
    for (int i = 0;str[i];i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
inline int get_digit(char ch) {
    return ch - '0';
}
inline void disassemble(int num, int &a, int &b) {
    if (num <= 0 || num >= 100) {
        a = 0;
        b = 0;
        return;
    }
    a = num / 10;
    b = num % 10;
}

bool big_interger_multiply(const char *strA, const char *strB, std::string &res) {
    int sizeA = strlen(strA);
    int sizeB = strlen(strB);
    if (sizeA > MAX_STR_LEN || sizeB > MAX_STR_LEN) {
        std::cerr << "string len over:" << MAX_STR_LEN << std::endl;
        return false;
    }
    if (!str_is_digit(strA) || !str_is_digit(strB)) {
        std::cerr << "string contain non-digit!" << std::endl;
        return false;
    }
    int len = sizeA + sizeB;
    char *tmp_str = new char[len + 1];
    memset(tmp_str, 0, len + 1);
    if (!tmp_str) {
        return false;
    }
    int k = 0;
    for (int i = sizeA - 1;i >= 0;i--) {
        for (int j = sizeB - 1;j >= 0;j--) {
            k = i + j + 1;
            tmp_str[k] += get_digit(strA[i]) * get_digit(strB[j]);
            if (tmp_str[k] >= 10) {
                tmp_str[k - 1] = tmp_str[k] / 10;
                tmp_str[k] = tmp_str[k] % 10;
            }
        }
    }
    for (int i = 0;i < len;i++) {
        tmp_str[i] += '0';
    }
    if ('0' == tmp_str[0]) {
        res.assign(tmp_str + 1);
    }
    else {
        res = tmp_str;
    }
    delete []tmp_str;
    return true;
}
int main() {
    const char *strA = "10";
    const char *strB = "100";
    std::string res;
    if (big_interger_multiply(strA, strB, res)) {
        std::cout << res << std::endl;
    }
    
    return 0;
}