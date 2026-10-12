class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if (memo[i][j]) return memo[i][j];
            
            int maxLen = 1;
            for (auto& d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                    maxLen = max(maxLen, 1 + dfs(ni, nj));
                }
            }
            
            memo[i][j] = maxLen;
            return maxLen;
        };
        
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, dfs(i, j));
            }
        }
        return result;
    }
};