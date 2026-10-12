class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int r = 0, c = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    r = i; c = j;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] != '.') {
                if (board[i][c] == 'p') ans++;
                break;
            }
        }
        for (int i = r + 1; i < 8; i++) {
            if (board[i][c] != '.') {
                if (board[i][c] == 'p') ans++;
                break;
            }
        }
        for (int j = c - 1; j >= 0; j--) {
            if (board[r][j] != '.') {
                if (board[r][j] == 'p') ans++;
                break;
            }
        }
        for (int j = c + 1; j < 8; j++) {
            if (board[r][j] != '.') {
                if (board[r][j] == 'p') ans++;
                break;
            }
        }
        return ans;
    }
};
