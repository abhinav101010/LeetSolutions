class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        
        if (s == goal) {
            vector<int> seen(26, 0);
            for (char c : s) {
                if (seen[c - 'a']++) return true;
            }
            return false;
        }
        
        int diff[2];
        int diffCount = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                if (diffCount == 2) return false;
                diff[diffCount++] = i;
            }
        }
        
        if (diffCount != 2) return false;
        
        return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
    }
};