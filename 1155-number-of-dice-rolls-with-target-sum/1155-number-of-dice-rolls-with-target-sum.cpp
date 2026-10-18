#include <vector>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;
        vector<int> f(target + 1, 0);
        f[0] = 1;
        for (int i = 0; i < n; i++) {
            vector<int> g(target + 1, 0);
            for (int j = 1; j <= target; j++) {
                for (int h = 1; h <= k; h++) {
                    if (j - h >= 0) {
                        g[j] = (g[j] + f[j - h]) % MOD;
                    }
                }
            }
            f = g;
        }
        return f[target];
    }
};
