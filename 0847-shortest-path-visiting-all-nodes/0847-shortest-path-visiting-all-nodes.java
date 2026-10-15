import java.util.*;

class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if (n == 1) return 0;
        Queue<int[]> queue = new LinkedList<>(); // [node, mask, dist]
        Set<String> visited = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            queue.add(new int[]{i, mask, 0});
            visited.add(i + "," + mask);
        }
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int node = cur[0];
            int mask = cur[1];
            int dist = cur[2];
            if (mask == (1 << n) - 1) {
                return dist;
            }
            for (int nei : graph[node]) {
                int nmask = mask | (1 << nei);
                String key = nei + "," + nmask;
                if (!visited.contains(key)) {
                    visited.add(key);
                    queue.add(new int[]{nei, nmask, dist + 1});
                }
            }
        }
        return -1;
    }
}
