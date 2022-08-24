#include <iostream>
#include <string>
using namespace std;
struct trie_node {
    struct trie_node *childs[26] = { 0 };
    bool terminated = false; 
};

class Trie {
public:
    Trie() {
        if (!head_) {
            head_ = new trie_node;
        }
    }
    virtual ~Trie() { 
        if (head_) {
            delete head_;
            head_ = nullptr;
        }
    }
    void insert(string word) {
        int pos = 0;
        trie_node *node = head_;
        for (auto& ch : word) {
            pos = ch - 'a';
            if (nullptr == node->childs[pos]) {
                node->childs[pos] = new trie_node;
            }
            node = node->childs[pos];
        }
        if (node) {
            node->terminated = true;
        }
    }
    
    bool search(string word) {
        int pos = 0;
        trie_node *node = head_;
        for (auto& ch : word) {
            pos = ch - 'a';
            if (nullptr == node->childs[pos]) {
                return false;
            }
            node = node->childs[pos];
        }
        return node && node->terminated;
    }
    
    bool startsWith(string prefix) {
        int pos = 0;
        trie_node *node = head_;
        for (auto& ch : prefix) {
            pos = ch - 'a';
            if (nullptr == node->childs[pos]) {
                return false;
            }
            node = node->childs[pos];
        }
        return node;
    }
private:
    trie_node *head_ = nullptr;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main() {
    Trie* obj = new Trie();
    obj->insert("insert");
    obj->insert("world");
    std::cout << obj->search("insert") << std::endl;
    std::cout << obj->search("world") << std::endl;
    std::cout << obj->search("worl") << std::endl;
    std::cout << obj->startsWith("inse") << std::endl;
    std::cout << obj->startsWith("nset") << std::endl;
    delete obj;

    return 0;
}