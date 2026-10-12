class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<vector<int>>> memo;
    int m, n;
    
    int dp(int i, int j, int moves) {
        if (i < 0 || i >= m || j < 0 || j >= n) return 1;
        if (moves == 0) return 0;
        if (memo[i][j][moves] != -1) return memo[i][j][moves];
        
        long long total = dp(i+1, j, moves-1);
        total = (total + dp(i-1, j, moves-1)) % MOD;
        total = (total + dp(i, j+1, moves-1)) % MOD;
        total = (total + dp(i, j-1, moves-1)) % MOD;
        
        memo[i][j][moves] = total;
        return memo[i][j][moves];
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memo.assign(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return dp(startRow, startColumn, maxMove);
    }
};