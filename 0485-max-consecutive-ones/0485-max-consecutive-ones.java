class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans = 0;
        int length = 0;
        for (int num : nums) {
            if (num == 1) {
                length++;
            } else {
                ans = Math.max(ans, length);
                length = 0;
            }
        }
        return Math.max(ans, length);
    }
}