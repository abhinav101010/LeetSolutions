class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] ans = new int[nums.length];
        int[] freq = new int[101];
        for (int num : nums) freq[num]++;
        int running = 0;
        int[] countLess = new int[101];
        for (int i = 0; i <= 100; i++) {
            countLess[i] = running;
            running += freq[i];
        }
        for (int i = 0; i < nums.length; i++) {
            ans[i] = countLess[nums[i]];
        }
        return ans;
    }
}