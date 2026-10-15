#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        string cur;
        dfs(0, cur, s, res);
        return res;
    }
    void dfs(int idx, string& cur, const string& s, vector<string>& res) {
        if (idx == s.size()) {
            res.push_back(cur);
            return;
        }
        char c = s[idx];
        if (isalpha(c)) {
            cur.push_back(tolower(c));
            dfs(idx+1, cur, s, res);
            cur.pop_back();
            cur.push_back(toupper(c));
            dfs(idx+1, cur, s, res);
            cur.pop_back();
        } else {
            cur.push_back(c);
            dfs(idx+1, cur, s, res);
            cur.pop_back();
        }
    }
};
