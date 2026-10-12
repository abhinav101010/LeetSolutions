class Solution {
    public int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            int oneBits = Integer.bitCount(i);
            if (isPrime(oneBits)) ans++;
        }
        return ans;
    }

    private boolean isPrime(int n) {
        if (n < 2) return false;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) return false;
        }
        return true;
    }
}