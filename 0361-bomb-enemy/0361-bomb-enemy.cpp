class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        vector<int> colHits(n, 0);
        for (int i = 0; i < m; i++) {
            int rowHits = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W') {
                    rowHits = 0;
                    colHits[j] = 0;
                } else if (grid[i][j] == 'E') {
                    rowHits++;
                    colHits[j]++;
                } else {
                    if (i == 0 || grid[i - 1][j] == 'W') {
                        colHits[j] = 0;
                        for (int k = i; k < m; k++) {
                            if (grid[k][j] == 'W') break;
                            if (grid[k][j] == 'E') colHits[j]++;
                        }
                    }
                    if (j == 0 || grid[i][j - 1] == 'W') {
                        rowHits = 0;
                        for (int k = j; k < n; k++) {
                            if (grid[i][k] == 'W') break;
                            if (grid[i][k] == 'E') rowHits++;
                        }
                    }
                    res = max(res, rowHits + colHits[j]);
                }
            }
        }
        return res;
    }
};