class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0, ans = 0;
        for (char ch : s) {
            if (ch == '1') ones++;
            else ans = min(ans+1, ones);
        }
        return ans;
    }
};
