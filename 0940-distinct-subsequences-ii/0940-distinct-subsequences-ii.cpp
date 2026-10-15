#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;
        long dp = 1; // empty
        vector<int> last(26, 0);
        for (char ch : s) {
            int idx = ch - 'a';
            long prev = dp;
            dp = (dp * 2) % MOD;
            dp = (dp - last[idx] + MOD) % MOD;
            last[idx] = (int) prev;
        }
        return (int) ((dp - 1 + MOD) % MOD);
    }
};
