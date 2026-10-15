#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        const int MOD = 1000000007;
        sort(A.begin(), A.end());
        int n = A.size();
        vector<long long> pow2(n, 0);
        pow2[0] = 1;
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = pow2[i];
            long long right = pow2[n-1-i];
            long long contrib = (left - right + MOD) % MOD;
            ans = (ans + contrib * A[i]) % MOD;
        }
        return (int) ans;
    }
};
