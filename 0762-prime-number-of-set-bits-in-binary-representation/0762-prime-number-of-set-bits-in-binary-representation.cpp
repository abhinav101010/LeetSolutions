class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int oneBits = __builtin_popcount(i);
            if (isPrime(oneBits)) ans++;
        }
        return ans;
    }

private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) return false;
        }
        return true;
    }
};