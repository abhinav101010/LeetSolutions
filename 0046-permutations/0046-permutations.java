class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        backtrack(nums, used, cur, ans);
        return ans;
    }

    private void backtrack(int[] nums, boolean[] used, List<Integer> cur, List<List<Integer>> ans) {
        if (cur.size() == nums.length) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            cur.add(nums[i]);
            backtrack(nums, used, cur, ans);
            cur.remove(cur.size() - 1);
            used[i] = false;
        }
    }
}
