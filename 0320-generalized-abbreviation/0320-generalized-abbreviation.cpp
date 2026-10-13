class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string cur;
        function<void(int,int)> dfs = [&](int pos, int count) {
            if (pos == word.size()) {
                if (count) cur += to_string(count);
                res.push_back(cur);
                if (count) cur.resize(cur.size() - to_string(count).size());
                return;
            }
            if (count) {
                cur += to_string(count) + word[pos];
                dfs(pos + 1, 0);
                cur.pop_back();
                cur.resize(cur.size() - to_string(count).size());
            } else {
                cur.push_back(word[pos]);
                dfs(pos + 1, 0);
                cur.pop_back();
                dfs(pos + 1, 1);
            }
        };
        dfs(0, 0);
        return res;
    }
};