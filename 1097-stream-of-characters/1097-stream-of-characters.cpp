#include <string>
#include <unordered_map>
#include <deque>
using namespace std;
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};
class StreamChecker {
    TrieNode* root;
    deque<char> stream;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto& w : words) {
            TrieNode* node = root;
            for (int i = w.size()-1; i >= 0; i--) {
                char c = w[i];
                if (!node->children.count(c)) node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->isEnd = true;
        }
    }
    bool query(char letter) {
        stream.push_front(letter);
        TrieNode* node = root;
        for (char c : stream) {
            if (!node->children.count(c)) return false;
            node = node->children[c];
            if (node->isEnd) return true;
        }
        return false;
    }
};
