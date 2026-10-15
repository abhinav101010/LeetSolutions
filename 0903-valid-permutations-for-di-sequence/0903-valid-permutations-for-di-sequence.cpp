#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numPermsDISequence(string S) {
        const int MOD = 1000000007;
        int n = S.size();
        vector<long long> dp(1, 1);
        for (char ch : S) {
            vector<long long> ndp(dp.size() + 1, 0);
            if (ch == 'I') {
                long long acc = 0;
                for (int j = 0; j < dp.size(); j++) {
                    ndp[j+1] = acc;
                    acc = (acc + dp[j]) % MOD;
                }
            } else { // 'D'
                long long acc = 0;
                for (int j = dp.size() - 1; j >= 0; j--) {
                    acc = (acc + dp[j]) % MOD;
                    ndp[j] = acc;
                }
            }
            dp = ndp;
        }
        long long ans = 0;
        for (long long v : dp) {
            ans = (ans + v) % MOD;
        }
        return (int) ans;
    }
};
