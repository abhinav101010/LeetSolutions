class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int temp = k;
        for (int i = s.size() - 1; i >= 0; --i) {
            char c = s[i];
            if (c == '-') continue;
            if (temp == 0) {
                ans += '-';
                temp = k;
            }
            ans += c;
            --temp;
        }
        reverse(ans.begin(), ans.end());
        for (char &c : ans) c = toupper(c);
        return ans;
    }
};