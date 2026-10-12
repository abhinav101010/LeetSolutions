class Solution {
    public int subsetXORSum(int[] nums) {
        return backtrack(nums, 0, 0);
    }
    
    private int backtrack(int[] nums, int i, int currentXor) {
        if (i == nums.length) {
            return currentXor;
        }
        int include = backtrack(nums, i + 1, currentXor ^ nums[i]);
        int exclude = backtrack(nums, i + 1, currentXor);
        return include + exclude;
    }
}