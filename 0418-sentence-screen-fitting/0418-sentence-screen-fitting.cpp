class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for (auto &w : sentence) s += w + " ";
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                dp[i] = 1;
            } else if (i + cols >= n) {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + cols] + 1;
            }
        }
        int res = 0, pos = 0;
        for (int i = 0; i < rows; i++) {
            res += dp[pos];
            pos = (pos + cols) % n;
            while (pos < n && s[pos] == ' ') pos++;
            if (pos == n) pos = 0;
        }
        return res / sentence.size();
    }
};