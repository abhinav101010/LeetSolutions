class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int,int)> dp = [&](int i, int j) -> int {
            if (i > j) return 0;
            if (memo[i][j] != -1) return memo[i][j];
            int res = dp(i, j - 1) + 1;
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    res = min(res, dp(i, k) + dp(k + 1, j - 1));
                }
            }
            memo[i][j] = res;
            return res;
        };
        return dp(0, n - 1);
    }
};