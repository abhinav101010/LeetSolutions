class Solution {
public:
    string getKey(const string &s) {
        string key;
        for (int i = 1; i < s.size(); i++) {
            int diff = (s[i] - s[i - 1] + 26) % 26;
            key += to_string(diff) + ',';
        }
        return key;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strings) {
            groups[getKey(s)].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &p : groups) {
            res.push_back(p.second);
        }
        return res;
    }
};