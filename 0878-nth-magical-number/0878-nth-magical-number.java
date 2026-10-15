class Solution {
    public int nthMagicalNumber(int n, int a, int b) {
        final int MOD = 1000000007;
        int g = gcd(a, b);
        long lcm = (long) a / g * b;
        long lo = Math.min(a, b);
        long hi = (long) n * Math.min(a, b);
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            long count = mid / a + mid / b - mid / lcm;
            if (count < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return (int) (lo % MOD);
    }
    private int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}
