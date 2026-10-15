import java.util.*;
class Solution {
    public int[] beautifulArray(int N) {
        Map<Integer, List<Integer>> memo = new HashMap<>();
        memo.put(1, Arrays.asList(1));
        return solve(N, memo).stream().mapToInt(Integer::intValue).toArray();
    }
    private List<Integer> solve(int n, Map<Integer, List<Integer>> memo) {
        if (memo.containsKey(n)) {
            return memo.get(n);
        }
        List<Integer> odds = solve((n + 1) / 2, memo);
        List<Integer> evens = solve(n / 2, memo);
        List<Integer> res = new ArrayList<>();
        for (int x : odds) res.add(2 * x - 1);
        for (int x : evens) res.add(2 * x);
        memo.put(n, res);
        return res;
    }
}
