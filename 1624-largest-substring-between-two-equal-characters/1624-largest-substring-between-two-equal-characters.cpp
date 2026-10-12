class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int ans = -1;

        for (int i = 0; i < (int)s.size(); i++) {
            int idx = s[i] - 'a';

            if (first[idx] != -1) {
                ans = max(ans, i - first[idx] - 1);
            } else {
                first[idx] = i;
            }
        }

        return ans;
    }
};