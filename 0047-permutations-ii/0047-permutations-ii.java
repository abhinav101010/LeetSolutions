import java.util.*;

class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> ans = new HashSet<>();
        permute(nums, 0, ans);
        return new ArrayList<>(ans);
    }

    private void permute(int[] nums, int start, Set<List<Integer>> ans) {
        if (start == nums.length) {
            List<Integer> cur = new ArrayList<>();
            for (int x : nums) {
                cur.add(x);
            }
            ans.add(cur);
            return;
        }
        for (int i = start; i < nums.length; i++) {
            swap(nums, i, start);
            permute(nums, start + 1, ans);
            swap(nums, i, start);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
