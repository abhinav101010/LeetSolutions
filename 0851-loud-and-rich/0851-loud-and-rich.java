import java.util.*;
class Solution {
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int n = quiet.length;
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] e : richer) {
            int u = e[0], v = e[1];
            adj[v].add(u); // u richer than v
        }
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        for (int i = 0; i < n; i++) {
            dfs(i, adj, quiet, ans);
        }
        return ans;
    }
    private int dfs(int v, List<Integer>[] adj, int[] quiet, int[] ans) {
        if (ans[v] != -1) {
            return ans[v];
        }
        int bestPerson = v;
        int bestQuiet = quiet[v];
        for (int u : adj[v]) {
            int cand = dfs(u, adj, quiet, ans);
            if (quiet[cand] < bestQuiet) {
                bestQuiet = quiet[cand];
                bestPerson = cand;
            }
        }
        ans[v] = bestPerson;
        return ans[v];
    }
}
