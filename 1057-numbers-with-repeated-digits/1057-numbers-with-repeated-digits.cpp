#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;
class Solution {
    int perm(int n, int k) {
        if (k > n || k < 0) return 0;
        int res = 1;
        for (int i = 0; i < k; i++) res *= (n-i);
        return res;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string s = to_string(n);
        int length = s.size();
        int ans = 0;
        for (int i = 1; i < length; i++) {
            ans += 9 * perm(9, i-1);
        }
        unordered_set<int> used;
        for (int i = 0; i < length; i++) {
            int c = s[i] - '0';
            for (int d = 0; d < c; d++) {
                if (d == 0 && i == 0) continue;
                if (used.count(d)) continue;
                ans += perm(9 - i, length - 1 - i);
            }
            if (used.count(c)) break;
            used.insert(c);
        }
        if (used.size() == length) ans++;
        return n - ans;
    }
};
