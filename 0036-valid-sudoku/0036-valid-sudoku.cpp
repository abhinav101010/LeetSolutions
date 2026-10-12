class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int d = c - '1';
                int b = (i / 3) * 3 + j / 3;
                if (rows[i][d] || cols[j][d] || boxes[b][d]) {
                    return false;
                }
                rows[i][d] = true;
                cols[j][d] = true;
                boxes[b][d] = true;
            }
        }
        return true;
    }
};
