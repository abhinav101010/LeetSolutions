class Solution {
private:
    vector<int> bits;
    vector<vector<int>> memo;
    
    int dp(int i, int prev, bool tight) {
        if (i == (int)bits.size()) return 1;
        if (!tight && memo[i][prev] != -1) return memo[i][prev];
        
        int limit = tight ? bits[i] : 1;
        int total = 0;
        for (int d = 0; d <= limit; d++) {
            if (prev == 1 && d == 1) continue;
            total += dp(i + 1, d, tight && d == limit);
        }
        
        if (!tight) memo[i][prev] = total;
        return total;
    }

public:
    int findIntegers(int n) {
        while (n) {
            bits.push_back(n & 1);
            n >>= 1;
        }
        reverse(bits.begin(), bits.end());
        memo.assign(bits.size(), vector<int>(2, -1));
        return dp(0, 0, true);
    }
};