class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int lo = 1;
        int hi = 0;
        for (int p : piles) {
            if (p > hi) hi = p;
        }
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canEat(piles, h, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    private boolean canEat(int[] piles, int h, int speed) {
        long hours = 0;
        for (int p : piles) {
            hours += (p + speed - 1L) / speed;
            if (hours > h) return false;
        }
        return hours <= h;
    }
}
