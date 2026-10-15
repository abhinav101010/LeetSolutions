import java.util.*;
class Solution {
    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }
        int[] count = new int[n];
        int[] ans = new int[n];
        Arrays.fill(count, 1);
        // first dfs
        dfs(0, -1, graph, count, ans);
        // second dfs
        dfs2(0, -1, graph, count, ans, n);
        return ans;
    }
    private void dfs(int u, int parent, List<Integer>[] graph, int[] count, int[] ans) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            dfs(v, u, graph, count, ans);
            count[u] += count[v];
            ans[u] += ans[v] + count[v];
        }
    }
    private void dfs2(int u, int parent, List<Integer>[] graph, int[] count, int[] ans, int n) {
        for (int v : graph[u]) {
            if (v == parent) continue;
            ans[v] = ans[u] - count[v] + (n - count[v]);
            dfs2(v, u, graph, count, ans, n);
        }
    }
}
