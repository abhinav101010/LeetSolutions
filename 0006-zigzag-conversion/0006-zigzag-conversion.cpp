class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;

        string ans;
        int step = 2 * (numRows - 1);

        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < (int)s.size(); i += step) {
                ans.push_back(s[i]);

                if (r > 0 && r < numRows - 1 && i + step - 2 * r < (int)s.size()) {
                    ans.push_back(s[i + step - 2 * r]);
                }
            }
        }

        return ans;
    }
};
