class Solution {
private:
    bool isSubsequence(const string& s, const string& t) {
        if (s.size() > t.size()) return false;
        int i = 0;
        for (char c : t) {
            if (i < (int)s.size() && s[i] == c) i++;
        }
        return i == (int)s.size();
    }

public:
    int findLUSlength(vector<string>& strs) {
        unordered_map<string, int> count;
        for (const string& s : strs) count[s]++;
        
        vector<string> unique;
        for (auto& [s, c] : count) unique.push_back(s);
        sort(unique.begin(), unique.end(), [](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        for (const string& s : unique) {
            if (count[s] == 1) {
                bool isSubseq = false;
                for (const string& t : unique) {
                    if (t != s && isSubsequence(s, t)) {
                        isSubseq = true;
                        break;
                    }
                }
                if (!isSubseq) return s.size();
            }
        }
        return -1;
    }
};