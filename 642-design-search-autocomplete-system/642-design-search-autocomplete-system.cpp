#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int hot = 0; // negative for sorting ascending
    bool isEnd = false;
    TrieNode() {}
};

class AutocompleteSystem {
private:
    TrieNode* root;
    TrieNode* node;
    string prefix;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        node = root;
        prefix = "";
        for (int i = 0; i < sentences.size(); i++) {
            add(sentences[i], times[i]);
        }
    }
    
    void add(string sentence, int times) {
        TrieNode* cur = root;
        for (char ch : sentence) {
            if (cur->children.find(ch) == cur->children.end()) {
                cur->children[ch] = new TrieNode();
            }
            cur = cur->children[ch];
        }
        cur->isEnd = true;
        cur->hot -= times;
    }
    
    void dfs(TrieNode* node, string path, vector<pair<int, string>>& res) {
        if (node->isEnd) {
            res.push_back({node->hot, path});
        }
        for (auto& p : node->children) {
            dfs(p.second, path + p.first, res);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            add(prefix, 1);
            node = root;
            prefix.clear();
            return {};
        }
        prefix += c;
        if (node == nullptr) {
            return {};
        }
        if (node->children.find(c) == node->children.end()) {
            node = nullptr;
            return {};
        }
        node = node->children[c];
        vector<pair<int, string>> list;
        dfs(node, prefix, list);
        sort(list.begin(), list.end());
        vector<string> ans;
        for (int i = 0; i < min(3, (int)list.size()); i++) {
            ans.push_back(list[i].second);
        }
        return ans;
    }
};
