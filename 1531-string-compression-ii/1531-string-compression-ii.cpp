#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[110][110];
    static const int K_MAX = 101;
    
    int getLength(int maxFreq) {
        if (maxFreq == 1) return 1;
        if (maxFreq < 10) return 2;
        if (maxFreq < 100) return 3;
        return 4;
    }
    
    int compression(string& s, int i, int k) {
        if (k < 0) return K_MAX;
        if (i == s.length() || (int)s.length() - i <= k) return 0;
        if (dp[i][k] != K_MAX) return dp[i][k];
        int maxFreq = 0;
        array<int, 128> count{}; 
        for (int j = i; j < (int)s.length(); ++j) {
            maxFreq = max(maxFreq, ++count[s[j]]);
            dp[i][k] = min(dp[i][k], getLength(maxFreq) + compression(s, j + 1, k - (j - i + 1 - maxFreq)));
        }
        return dp[i][k];
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        for (int i = 0; i < 110; ++i) {
            for (int j = 0; j < 110; ++j) {
                dp[i][j] = K_MAX;
            }
        }
        return compression(s, 0, k);
    }
};
