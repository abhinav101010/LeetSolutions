#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        int n = strs.size();
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            string t = strs[i];
            string rev = string(t.rbegin(), t.rend());
            s[i] = t > rev ? t : rev;
        }
        string res = "";
        for (int i = 0; i < n; ++i) {
            string t = strs[i];
            string rev = string(t.rbegin(), t.rend());
            string parts[2] = {t, rev};
            for (int p = 0; p < 2; ++p) {
                string cur = parts[p];
                for (int j = 1; j < cur.size(); ++j) {
                    string prefix = cur.substr(j);
                    string suffix = cur.substr(0, j);
                    string candidate = prefix;
                    for (int k = 1; k < n; ++k) {
                        candidate += s[(i + k) % n];
                    }
                    candidate += suffix;
                    if (candidate > res) res = candidate;
                }
                if (n == 1) {
                    if (cur > res) res = cur;
                } else {
                    string candidate = cur;
                    for (int k = 1; k < n; ++k) {
                        candidate += s[(i + k) % n];
                    }
                    if (candidate > res) res = candidate;
                }
            }
        }
        return res;
    }
};
