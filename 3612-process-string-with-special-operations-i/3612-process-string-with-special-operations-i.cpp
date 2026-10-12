class Solution {
public:
    string processStr(string s) {
        string ans;
        for (char c : s) {
            if (c == '*') {
                if (!ans.empty()) ans.pop_back();
            } else if (c == '#') {
                int len = ans.size();
                for (int i = 0; i < len; i++) ans.push_back(ans[i]);
            } else if (c == '%') {
                reverse(ans.begin(), ans.end());
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};