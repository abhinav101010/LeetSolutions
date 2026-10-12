class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;
        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            word = "";
        }
    };
    
    TrieNode* root;
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicates
        }
        
        board[i][j] = '#';
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto& dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < (int)board.size() && nj >= 0 && nj < (int)board[0].size() && board[ni][nj] != '#') {
                dfs(board, ni, nj, node, result);
            }
        }
        board[i][j] = c;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for (const string& word : words) {
            insert(word);
        }
        
        vector<string> result;
        for (int i = 0; i < (int)board.size(); i++) {
            for (int j = 0; j < (int)board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        
        return result;
    }
};