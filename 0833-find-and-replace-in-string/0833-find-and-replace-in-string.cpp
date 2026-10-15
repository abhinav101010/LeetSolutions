#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int, pair<string,string>> matches;
        int m = indices.size();
        for (int i = 0; i < m; i++) {
            int idx = indices[i];
            string src = sources[i];
            string tgt = targets[i];
            if (s.substr(idx, src.size()) == src) {
                matches[idx] = {src, tgt};
            }
        }
        string res;
        int i = 0;
        int n = s.size();
        while (i < n) {
            if (matches.find(i) != matches.end()) {
                auto p = matches[i];
                res += p.second;
                i += p.first.size();
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
};
