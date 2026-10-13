class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        vector<char> mid;
        string chars;
        for (auto &p : count) {
            if (p.second % 2 == 1) mid.push_back(p.first);
            chars.append(p.second / 2, p.first);
        }
        if (mid.size() > 1) return {};
        vector<string> res;
        vector<bool> used(chars.size(), false);
        string path;
        path.resize(chars.size());
        sort(chars.begin(), chars.end());
        backtrack(chars, used, path, 0, mid, res);
        return res;
    }
    
    void backtrack(const string &chars, vector<bool> &used, string &path, int idx, const vector<char> &mid, vector<string> &res) {
        if (idx == chars.size()) {
            string half = path;
            string rev = half;
            reverse(rev.begin(), rev.end());
            string midStr = mid.empty() ? "" : string(1, mid[0]);
            res.push_back(half + midStr + rev);
            return;
        }
        for (int i = 0; i < chars.size(); i++) {
            if (used[i] || (i > 0 && chars[i] == chars[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            path[idx] = chars[i];
            backtrack(chars, used, path, idx + 1, mid, res);
            used[i] = false;
        }
    }
};