class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int wordId = -1;
    vector<int> palindromeSuffixes;
    
    ~TrieNode() {
        for (auto& [_, child] : children) delete child;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        for (int i = 0; i < (int)words.size(); i++) {
            TrieNode* node = root;
            const string& word = words[i];
            for (int j = word.size() - 1; j >= 0; j--) {
                char c = word[j];
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                string prefix = word.substr(0, j + 1);
                if (isPalindrome(prefix)) {
                    node->palindromeSuffixes.push_back(i);
                }
                node = node->children[c];
            }
            node->wordId = i;
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < (int)words.size(); i++) {
            TrieNode* node = root;
            const string& word = words[i];
            for (int j = 0; j < (int)word.size(); j++) {
                if (node->wordId != -1 && node->wordId != i) {
                    string suffix = word.substr(j);
                    if (isPalindrome(suffix)) {
                        result.push_back({i, node->wordId});
                    }
                }
                char c = word[j];
                if (!node->children.count(c)) break;
                node = node->children[c];
            }
            if (node->wordId != -1 && node->wordId != i) {
                result.push_back({i, node->wordId});
            }
            for (int pid : node->palindromeSuffixes) {
                if (pid != i) result.push_back({i, pid});
            }
        }
        
        // Cleanup
        delete root;
        return result;
    }
    
private:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};