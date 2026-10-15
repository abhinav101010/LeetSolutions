import java.util.*;
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<Integer>[] rgraph = new ArrayList[n];
        int[] outdegree = new int[n];
        for (int i = 0; i < n; i++) {
            rgraph[i] = new ArrayList<>();
        }
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].length;
            for (int v : graph[u]) {
                rgraph[v].add(u);
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        boolean[] safe = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0) {
                q.addLast(i);
            }
        }
        while (!q.isEmpty()) {
            int u = q.removeFirst();
            safe[u] = true;
            for (int v : rgraph[u]) {
                outdegree[v]--;
                if (outdegree[v] == 0) {
                    q.addLast(v);
                }
            }
        }
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (safe[i]) {
                result.add(i);
            }
        }
        return result;
    }
}
