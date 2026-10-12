#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
    ~TrieNode() {
        for (auto &p : children) delete p.second;
    }
};

class Trie {
public:
    TrieNode* root = new TrieNode();
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    string findRoot(const string &word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!node->children.count(c)) return word;
            node = node->children[c];
            if (node->isEnd) return word.substr(0, i+1);
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const string &w : dictionary) trie.insert(w);
        stringstream ss(sentence);
        string token, result;
        while (ss >> token) {
            if (!result.empty()) result += " ";
            result += trie.findRoot(token);
        }
        return result;
    }
};