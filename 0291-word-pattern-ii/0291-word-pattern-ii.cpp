class Solution {
public:
    unordered_map<char, string> map;
    unordered_set<string> used;
    bool res = false;
    
    bool wordPatternMatch(string pattern, string s) {
        backtrack(0, 0, pattern, s);
        return res;
    }
    
    void backtrack(int i, int j, string &pattern, string &s) {
        if (res) return;
        if (i == pattern.size() && j == s.size()) {
            res = true;
            return;
        }
        if (i == pattern.size() || j == s.size()) return;
        char p = pattern[i];
        for (int k = j; k < s.size(); k++) {
            string sub = s.substr(j, k - j + 1);
            if (map.count(p) && map[p] == sub) {
                backtrack(i + 1, k + 1, pattern, s);
            } else if (!map.count(p) && !used.count(sub)) {
                map[p] = sub;
                used.insert(sub);
                backtrack(i + 1, k + 1, pattern, s);
                used.erase(sub);
                map.erase(p);
            }
        }
    }
};