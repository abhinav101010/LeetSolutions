class Solution {
private:
    unordered_map<string, bool> memo;
    
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) return false;
        
        memo.clear();
        return dfs(s1, 0, s2, 0, s1.size());
    }
    
private:
    bool dfs(const string& s1, int i1, const string& s2, int i2, int len) {
        string key = to_string(i1) + "," + to_string(i2) + "," + to_string(len);
        if (memo.count(key)) return memo[key];
        
        if (s1.substr(i1, len) == s2.substr(i2, len)) {
            return memo[key] = true;
        }
        
        string sub1 = s1.substr(i1, len);
        string sub2 = s2.substr(i2, len);
        sort(sub1.begin(), sub1.end());
        sort(sub2.begin(), sub2.end());
        if (sub1 != sub2) {
            return memo[key] = false;
        }
        
        for (int k = 1; k < len; k++) {
            // No swap
            if (dfs(s1, i1, s2, i2, k) && dfs(s1, i1 + k, s2, i2 + k, len - k)) {
                return memo[key] = true;
            }
            // Swap
            if (dfs(s1, i1, s2, i2 + len - k, k) && dfs(s1, i1 + k, s2, i2, len - k)) {
                return memo[key] = true;
            }
        }
        
        return memo[key] = false;
    }
};