class Solution {
    public int[] singleNumber(int[] nums) {
        int bitwise = 0;
        for (int num : nums) {
            bitwise ^= num;
        }

        int diff = bitwise & (-bitwise);
        int[] ans = new int[2];
        for (int num : nums) {
            if ((num & diff) == 0) {
                ans[0] ^= num;
            } else {
                ans[1] ^= num;
            }
        }
        return ans;
    }
}
