class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0;
        int pi = 0;
        int star = -1;
        int mark = 0;

        while (si < (int)s.size()) {
            if (pi < (int)p.size() && (p[pi] == '?' || p[pi] == s[si])) {
                si++;
                pi++;
            } else if (pi < (int)p.size() && p[pi] == '*') {
                star = pi;
                mark = si;
                pi++;
            } else if (star != -1) {
                pi = star + 1;
                mark++;
                si = mark;
            } else {
                return false;
            }
        }

        while (pi < (int)p.size() && p[pi] == '*') {
            pi++;
        }
        return pi == (int)p.size();
    }
};
