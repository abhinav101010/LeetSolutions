#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        const int MAX = 1 << 16;
        vector<int> freq(MAX, 0);
        for (int x : A) {
            freq[x]++;
        }
        // SOS dp: dp[mask] = sum_{submask subset of mask} freq[submask]
        vector<int> dp = freq;
        for (int i = 0; i < 16; i++) {
            for (int mask = 0; mask < MAX; mask++) {
                if (mask & (1 << i)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        int allOnes = MAX - 1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int m = A[i] & A[j];
                int comp = allOnes ^ m;
                ans += dp[comp];
            }
        }
        return (int) ans;
    }
};
