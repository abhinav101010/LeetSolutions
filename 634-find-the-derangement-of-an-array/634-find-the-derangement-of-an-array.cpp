class Solution {
public:
    int findDerangement(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;
        const int MOD = 1000000007;
        long a = 1, b = 0; // D(0), D(1)
        for (int i = 2; i <= n; i++) {
            long next = ((long)(i-1) * (a + b)) % MOD;
            a = b;
            b = next;
        }
        return (int) b;
    }
};
