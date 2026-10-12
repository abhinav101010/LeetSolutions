class Solution {
    public boolean isTrionic(int[] nums) {
        int n = nums.length;
        int i = 1;
        boolean start = false;
        while (i < n && nums[i] > nums[i - 1]) {
            i++;
            start = true;
            if (i == n) return false;
        }
        boolean mid = false;
        while (i < n && nums[i] < nums[i - 1] && start) {
            i++;
            mid = true;
            if (i == n) return false;
        }
        boolean end = false;
        while (i < n && nums[i] > nums[i - 1] && mid) {
            i++;
            end = true;
        }
        return start && mid && end && i == n;
    }
}