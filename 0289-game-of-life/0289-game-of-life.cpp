class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        
        int m = board.size(), n = board[0].size();
        int dirs[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] & 1)) {
                        live++;
                    }
                }
                
                if (board[i][j] == 1) {
                    if (live == 2 || live == 3) board[i][j] = 3; // 11: stays alive
                    else board[i][j] = 1; // 01: dies
                } else {
                    if (live == 3) board[i][j] = 2; // 10: becomes alive
                    else board[i][j] = 0; // 00: stays dead
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};