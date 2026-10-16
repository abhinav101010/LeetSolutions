class Solution {
    public int minSwaps(int[] data) {
        int k = 0;
        for (int x : data) k += x;
        if (k <= 1) return 0;
        int zeros = 0;
        for (int i = 0; i < k; i++) if (data[i] == 0) zeros++;
        int ans = zeros;
        for (int i = k; i < data.length; i++) {
            if (data[i-k] == 0) zeros--;
            if (data[i] == 0) zeros++;
            ans = Math.min(ans, zeros);
        }
        return ans;
    }
}
