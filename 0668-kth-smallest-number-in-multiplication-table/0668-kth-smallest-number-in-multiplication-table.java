class Solution {
    private int count(int mid, int m, int n) {
        int total = 0;
        for (int i = 1; i <= m; i++) {
            total += Math.min(mid / i, n);
        }
        return total;
    }
    
    public int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (count(mid, m, n) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}