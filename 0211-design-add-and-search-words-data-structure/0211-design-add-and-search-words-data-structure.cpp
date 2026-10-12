class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isEnd = false;
        }
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
private:
    bool dfs(TrieNode* node, const string& word, int i) {
        if (i == (int)word.size()) return node->isEnd;
        
        char c = word[i];
        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && dfs(node->children[j], word, i + 1)) {
                    return true;
                }
            }
            return false;
        }
        
        int idx = c - 'a';
        if (!node->children[idx]) return false;
        return dfs(node->children[idx], word, i + 1);
    }
};