#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    string minimizeResult(string expression) {
        size_t idx = expression.find('+');
        string l = expression.substr(0, idx);
        string r = expression.substr(idx + 1);
        int m = l.size(), n = r.size();
        ll mi = LLONG_MAX;
        string ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ll c = stoll(l.substr(i)) + stoll(r.substr(0, j + 1));
                ll a = i == 0 ? 1LL : stoll(l.substr(0, i));
                ll b = j == n - 1 ? 1LL : stoll(r.substr(j + 1));
                ll t = a * b * c;
                if (t < mi) {
                    mi = t;
                    ans = l.substr(0, i) + "(" + l.substr(i) + "+" + r.substr(0, j + 1) + ")" + r.substr(j + 1);
                }
            }
        }
        return ans;
    }
};
