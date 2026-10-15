class Solution {
    public int preimageSizeFZF(int K) {
        long lo = 0;
        long hi = 5L * K + 5; // safe upper bound
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            if (trailingZeros(mid) < K) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return trailingZeros(lo) == K ? 5 : 0;
    }
    private long trailingZeros(long x) {
        long count = 0;
        while (x > 0) {
            x /= 5;
            count += x;
        }
        return count;
    }
}
