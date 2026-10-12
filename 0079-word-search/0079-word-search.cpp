class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, const string& word, int r, int c, int k) {
        if (k == word.size()) {
            return true;
        }
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[k]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = ' ';

        bool found = backtrack(board, word, r + 1, c, k + 1)
            || backtrack(board, word, r - 1, c, k + 1)
            || backtrack(board, word, r, c + 1, k + 1)
            || backtrack(board, word, r, c - 1, k + 1);

        board[r][c] = temp;
        return found;
    }
};
