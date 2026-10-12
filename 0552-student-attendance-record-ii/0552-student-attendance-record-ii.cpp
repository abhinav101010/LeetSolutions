class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<vector<int>>> memo;
    int n;
    
    int dp(int i, int a, int l) {
        if (i == n) return 1;
        if (memo[i][a][l] != -1) return memo[i][a][l];
        
        long long total = dp(i + 1, a, 0); // P
        if (a == 0) total = (total + dp(i + 1, 1, 0)) % MOD; // A
        if (l < 2) total = (total + dp(i + 1, a, l + 1)) % MOD; // L
        
        memo[i][a][l] = total;
        return memo[i][a][l];
    }

public:
    int checkRecord(int n) {
        this->n = n;
        memo.assign(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return dp(0, 0, 0);
    }
};