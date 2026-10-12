class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        sub(0, nums, cur, ans);
        return ans;
    }

    private void sub(int i, int[] nums, List<Integer> cur, List<List<Integer>> ans) {
        if (i == nums.length) {
            ans.add(new ArrayList<>(cur));
            return;
        }

        sub(i + 1, nums, cur, ans);
        cur.add(nums[i]);
        sub(i + 1, nums, cur, ans);
        cur.remove(cur.size() - 1);
    }
}
