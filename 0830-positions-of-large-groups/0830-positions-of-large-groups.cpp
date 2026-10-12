class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (i == s.size() || s[i] != s[i - 1]) {
                int end = i - 1;
                if (end - start + 1 >= 3) {
                    ans.push_back({start, end});
                }
                start = i;
            }
        }
        return ans;
    }
};