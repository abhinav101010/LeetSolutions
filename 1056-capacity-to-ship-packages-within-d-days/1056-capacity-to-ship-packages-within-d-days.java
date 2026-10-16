class Solution {
    public int shipWithinDays(int[] weights, int D) {
        int left = 0, right = 0;
        for (int w : weights) {
            if (w > left) left = w;
            right += w;
        }
        while (left < right) {
            int mid = (left + right) / 2;
            int days = 1;
            int cur = 0;
            for (int w : weights) {
                if (cur + w > mid) {
                    days++;
                    cur = 0;
                }
                cur += w;
            }
            if (days <= D) right = mid;
            else left = mid + 1;
        }
        return left;
    }
}
