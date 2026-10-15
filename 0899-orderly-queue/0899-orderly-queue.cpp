#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        if (K == 1) {
            string s2 = S + S;
            int n = S.size();
            string best = s2.substr(0, n);
            for (int i = 1; i < n; i++) {
                string cand = s2.substr(i, n);
                if (cand < best) {
                    best = cand;
                }
            }
            return best;
        } else {
            sort(S.begin(), S.end());
            return S;
        }
    }
};
