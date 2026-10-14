#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        int n = S.size();
        vector<bool> mark(n, false);
        for (string& w : words) {
            int len = w.size();
            size_t pos = S.find(w);
            while (pos != string::npos) {
                for (int i = 0; i < len; i++) {
                    mark[pos + i] = true;
                }
                pos = S.find(w, pos + 1);
            }
        }
        string res;
        int i = 0;
        while (i < n) {
            if (mark[i]) {
                res += "<b>";
                while (i < n && mark[i]) {
                    res += S[i];
                    i++;
                }
                res += "</b>";
            } else {
                res += S[i];
                i++;
            }
        }
        return res;
    }
};
