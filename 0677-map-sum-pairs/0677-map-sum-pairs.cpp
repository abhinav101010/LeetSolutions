#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int val = 0;
    ~TrieNode() {
        for (auto &p : children) delete p.second;
    }
};

class MapSum {
public:
    TrieNode* root;
    MapSum() {
        root = new TrieNode();
    }
    void insert(string key, int val) {
        TrieNode* node = root;
        for (char c : key) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->val = val;
    }
    int dfs(TrieNode* node) {
        int s = node->val;
        for (auto &p : node->children) {
            s += dfs(p.second);
        }
        return s;
    }
    int sum(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) return 0;
            node = node->children[c];
        }
        return dfs(node);
    }
};