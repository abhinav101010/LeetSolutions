class Solution {
    public int maxProduct(int[] nums) {
        int highest = nums[0];
        int least = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.length; i++) {
            int num = nums[i];
            if (num < 0) {
                int tmp = highest;
                highest = least;
                least = tmp;
            }
            highest = Math.max(num, highest * num);
            least = Math.min(num, least * num);
            ans = Math.max(ans, highest);
        }
        return ans;
    }
}