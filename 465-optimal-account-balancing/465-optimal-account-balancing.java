import java.util.*;

class Solution {
    public int minTransfers(List<List<Integer>> transactions) {
        Map<Integer, Long> bal = new HashMap<>();
        for (List<Integer> t : transactions) {
            int x = t.get(0), y = t.get(1), z = t.get(2);
            bal.put(x, bal.getOrDefault(x, 0L) - z);
            bal.put(y, bal.getOrDefault(y, 0L) + z);
        }
        List<Long> debts = new ArrayList<>();
        for (long v : bal.values()) {
            if (v != 0) debts.add(v);
        }
        int n = debts.size();
        return dfs(debts, 0);
    }
    
    private int dfs(List<Long> debts, int start) {
        int n = debts.size();
        while (start < n && debts.get(start) == 0) {
            start++;
        }
        if (start == n) return 0;
        int res = Integer.MAX_VALUE;
        HashSet<Long> seen = new HashSet<>();
        for (int i = start + 1; i < n; i++) {
            long di = debts.get(i), ds = debts.get(start);
            if (di * ds < 0 && !seen.contains(di)) {
                seen.add(di);
                debts.set(i, di + ds);
                res = Math.min(res, 1 + dfs(debts, start + 1));
                debts.set(i, di);
            }
        }
        return res;
    }
}
