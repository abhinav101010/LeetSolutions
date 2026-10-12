#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
    ~TrieNode() {
        for (auto &p : children) delete p.second;
    }
};

class MagicDictionary {
public:
    TrieNode* root = new TrieNode();
    MagicDictionary() {
        root = new TrieNode();
    }
    void buildDict(vector<string> dictionary) {
        for (const auto &word : dictionary) {
            TrieNode* node = root;
            for (char c : word) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isEnd = true;
        }
    }
    bool dfs(TrieNode* node, int idx, bool changed, const string &word) {
        if (idx == word.size()) return node->isEnd && changed;
        char c = word[idx];
        for (auto &p : node->children) {
            if (c == p.first) {
                if (dfs(p.second, idx + 1, changed, word)) return true;
            } else if (!changed) {
                if (dfs(p.second, idx + 1, true, word)) return true;
            }
        }
        return false;
    }
    bool search(string searchWord) {
        return dfs(root, 0, false, searchWord);
    }
};