class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        combine(1, n, k, cur, ans);
        return ans;
    }

    private void combine(int start, int n, int k, List<Integer> cur, List<List<Integer>> ans) {
        if (cur.size() == k) {
            ans.add(new ArrayList<>(cur));
            return;
        }

        for (int i = start; i <= n; i++) {
            cur.add(i);
            combine(i + 1, n, k, cur, ans);
            cur.remove(cur.size() - 1);
        }
    }
}
