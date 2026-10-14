#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> mp;
        for (string& a : allowed) {
            string key = a.substr(0, 2);
            mp[key].insert(a[2]);
        }
        unordered_set<string> seen;
        function<bool(string)> dfs = [&](string row) -> bool {
            if (row.size() == 1) return true;
            if (seen.count(row)) return false;
            seen.insert(row);
            vector<vector<char>> options;
            for (int i = 0; i < (int)row.size()-1; i++) {
                string key = row.substr(i, 2);
                auto it = mp.find(key);
                if (it == mp.end()) return false;
                options.push_back(vector<char>(it->second.begin(), it->second.end()));
            }
            // backtrack
            return backtrack(options, 0, "", mp, seen, dfs);
        };
        return dfs(bottom);
    }
    
private:
    bool backtrack(vector<vector<char>>& options, int idx, string curr,
                   unordered_map<string, unordered_set<char>>& mp,
                   unordered_set<string>& seen,
                   function<bool(string)>& dfs) {
        if (idx == options.size()) {
            return dfs(curr);
        }
        for (char c : options[idx]) {
            if (backtrack(options, idx+1, curr + c, mp, seen, dfs)) {
                return true;
            }
        }
        return false;
    }
};
