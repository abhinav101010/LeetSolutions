class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        backtrack(candidates, 0, target, cur, ans);
        return ans;
    }

    private void backtrack(int[] candidates, int start, int target, List<Integer> cur, List<List<Integer>> ans) {
        if (target == 0) {
            ans.add(new ArrayList<>(cur));
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (candidates[i] > target) {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.add(candidates[i]);
            backtrack(candidates, i + 1, target - candidates[i], cur, ans);
            cur.remove(cur.size() - 1);
        }
    }
}
