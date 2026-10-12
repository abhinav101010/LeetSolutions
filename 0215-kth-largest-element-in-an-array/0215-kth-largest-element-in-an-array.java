class Solution {
    public int findKthLargest(int[] nums, int k) {
        return quickSelect(nums, 0, nums.length - 1, k);
    }

    private int quickSelect(int[] nums, int left, int right, int k) {
        int pivot = nums[right];
        int p = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot) {
                int tmp = nums[i];
                nums[i] = nums[p];
                nums[p] = tmp;
                ++p;
            }
        }
        int tmp = nums[p];
        nums[p] = nums[right];
        nums[right] = tmp;
        if (p == k - 1) return nums[p];
        if (p > k - 1) return quickSelect(nums, left, p - 1, k);
        return quickSelect(nums, p + 1, right, k);
    }
}