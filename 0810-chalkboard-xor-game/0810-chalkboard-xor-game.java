class Solution {
    public boolean xorGame(int[] nums) {
        if (nums.length % 2 == 0) {
            return true;
        }
        int xr = 0;
        for (int v : nums) {
            xr ^= v;
        }
        return xr == 0;
    }
}
