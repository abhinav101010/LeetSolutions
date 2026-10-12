class Solution {
    public int[] sortArrayByParity(int[] nums) {
        int[] res = new int[nums.length];
        int idx = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                res[idx++] = num;
            }
        }
        for (int num : nums) {
            if (num % 2 == 1) {
                res[idx++] = num;
            }
        }
        return res;
    }
}