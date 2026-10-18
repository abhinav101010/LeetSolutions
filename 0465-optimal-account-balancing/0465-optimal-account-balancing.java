import java.util.*;

public class Solution {
    private int dfs(int pos, int[] debt) {
        while (pos < debt.length && debt[pos] == 0) pos++;
        if (pos == debt.length) return 0;
        int res = Integer.MAX_VALUE;
        for (int i = pos + 1; i < debt.length; ++i) {
            if ((debt[i] > 0 && debt[pos] < 0) || (debt[i] < 0 && debt[pos] > 0)) {
                debt[i] += debt[pos];
                res = Math.min(res, 1 + dfs(pos + 1, debt));
                debt[i] -= debt[pos];
                if (debt[pos] + debt[i] == 0) break;
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
    
    public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> balance = new HashMap<>();
        for (int[] t : transactions) {
            balance.put(t[0], balance.getOrDefault(t[0], 0) - t[2]);
            balance.put(t[1], balance.getOrDefault(t[1], 0) + t[2]);
        }
        List<Integer> list = new ArrayList<>();
        for (int v : balance.values()) {
            if (v != 0) list.add(v);
        }
        int[] debt = new int[list.size()];
        for (int i = 0; i < list.size(); ++i) debt[i] = list.get(i);
        return dfs(0, debt);
    }
}
