#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <memory>
#include <sstream>
#include <iostream>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> words;
};

class Trie {
public:
    TrieNode* root;
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (auto &w : words) {
            insert(w);
        }
    }
    void insert(const string &word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->words.push_back(word);
        }
    }
    vector<string> startWith(const string &prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children.count(c)) return {};
            node = node->children[c];
        }
        return node->words;
    }
};

class Solution {
public:
    vector<vector<string>> res;
    int n;
    Trie* trie;
    void backtrack(vector<string> &path) {
        if (path.size() == n) {
            res.push_back(path);
            return;
        }
        int idx = path.size();
        string prefix;
        for (auto &p : path) {
            prefix += p[idx];
        }
        auto list = trie->startWith(prefix);
        for (auto &w : list) {
            path.push_back(w);
            backtrack(path);
            path.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty()) return res;
        n = words[0].size();
        trie = new Trie(words);
        vector<string> path;
        backtrack(path);
        return res;
    }
};