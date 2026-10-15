import java.util.*;
class Solution {
    public boolean possibleBipartition(int n, int[][] dislikes) {
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();
        for (int[] e : dislikes) {
            int u = e[0], v = e[1];
            graph[u].add(v);
            graph[v].add(u);
        }
        int[] color = new int[n + 1]; // 0 uncolored, 1 and -1
        for (int start = 1; start <= n; start++) {
            if (color[start] != 0) continue;
            Deque<Integer> q = new ArrayDeque<>();
            q.addLast(start);
            color[start] = 1;
            while (!q.isEmpty()) {
                int u = q.pollFirst();
                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.addLast(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
