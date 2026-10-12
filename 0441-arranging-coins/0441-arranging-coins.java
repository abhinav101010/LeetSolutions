class Solution {
    public int arrangeCoins(int n) {
        long nLong = (long) n;
        long ans = 0;
        while (nLong >= ans + 1) {
            ans++;
            nLong -= ans;
        }
        return (int) ans;
    }
}