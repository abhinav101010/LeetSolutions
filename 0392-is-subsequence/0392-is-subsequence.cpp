class Solution {
public:
    bool isSubsequence(string s, string t) {
        int prev = -1;
        for (int i = 0; i < s.size(); i++) {
            int curr = t.find(s[i], prev + 1);
            if (curr == string::npos) {
                return false;
            }
            prev = curr;
        }
        return true;
    }
};