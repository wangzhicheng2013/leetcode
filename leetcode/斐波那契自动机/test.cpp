#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
/*
3
5 2 1
01
1
10 1 1
0
0
5 1 1
1
1
*/
static const int CAPACITY = 998244353;
static const std::string PATTERN = "11";
struct fibonacci_elem {
    int n;
    int str_first_len;
    int str_second_len;
    std::string str_first;
    std::string str_second;
    int sub11_str_num;
};
struct fibonacci_automaton {
    void init() {
        std::cin >> num;
        for (int i = 0;i < num;i++) {
            fibonacci_elem elem;
            std::cin >> elem.n >> elem.str_first_len >> elem.str_second_len;
            std::cin >> elem.str_first;
            std::cin >> elem.str_second;
            elems.push_back(elem);
        }
    }
    void show() {
        for (int i = 0;i < elems.size();i++) {
            const fibonacci_elem &elem = elems[i];
            /*std::cout << "n = " << elem.n << std::endl;
            std::cout << "elem.str_first_len = " << elem.str_first_len << std::endl;
            std::cout << "elem.str_second_len = " << elem.str_second_len << std::endl;

            std::cout << "elem.str_first = " << elem.str_first << std::endl;
            std::cout << "elem.str_second = " << elem.str_second << std::endl;
            std::cout << "elem.sub11_str_num = " << elem.sub11_str_num << std::endl;*/
            std::cout << elem.sub11_str_num << std::endl;
        }
    }
    void automaton() {
        for (int i = 0;i < elems.size();i++) {
            fibonacci_elem &elem = elems[i];
            std::string third_str;
            fibonacci(elem.n - 2, elem.str_first, elem.str_second, third_str);
            elem.sub11_str_num =  pattern_matching(third_str, PATTERN) % CAPACITY;
        }
    }
    void load_bitset(const std::string &str, std::bitset)
    void fibonacci(int iterations, const std::string &first, const std::string &second, std::string &third_str) {
        std::string first_str = first;
        std::string second_str = second;
        long first_val = 0, second_val = 0, third_val = 0;
        int loop = 0;
        for (int i = 1;i <= iterations;i++) {
            first_val = atol(first_str.c_str());
            second_val = atol(second_str.c_str());
            loop = second_str.size();
            for (int j = 0;j < loop;j++) {
                first_val *= 10;
            }
            third_val = first_val + second_val;
            first_str = second_str;
            second_str = std::to_string(third_val);
        }
        third_str = std::to_string(third_val);
        std::cout << "third str = " << third_str << std::endl;
    }
    int pattern_matching(const std::string &m_str, const std::string &p_str) {
        int count = 0;
        int pos = 0;
        while (true) {
            pos = m_str.find(p_str, pos);
            if (pos != std::string::npos) {
                ++count;
                pos++;
            }
            else {
                break;
            }
        }
        return count;
    }
    std::vector<fibonacci_elem>elems;
    int num;
};
int main() {
    fibonacci_automaton fa;
    fa.init();
    fa.automaton();
    fa.show();

    return 0;
}