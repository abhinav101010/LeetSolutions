#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxA(int n) {
        if (n <= 6) return n;
        vector<int> dp(n+1);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        for (int i = 7; i <= n; i++) {
            for (int j = i - 3; j >= 1; j--) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[n];
    }
};
