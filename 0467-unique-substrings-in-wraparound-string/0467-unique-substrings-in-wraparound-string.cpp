class Solution {
public:
    int findSubstringInWraproundString(string s) {
        vector<int> dp(26, 0);
        int maxLen = 0;
        
        for (int i = 0; i < (int)s.size(); i++) {
            char ch = s[i];
            if (i > 0 && (ch - s[i-1] == 1 || (s[i-1] == 'z' && ch == 'a'))) {
                maxLen++;
            } else {
                maxLen = 1;
            }
            int idx = ch - 'a';
            dp[idx] = max(dp[idx], maxLen);
        }
        
        int result = 0;
        for (int v : dp) result += v;
        return result;
    }
};