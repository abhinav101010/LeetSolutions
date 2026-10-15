import java.util.*;

class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n]; // 0 uncolored, 1 color A, -1 color B
        for (int start = 0; start < n; start++) {
            if (color[start] != 0) continue;
            // BFS
            Deque<Integer> queue = new ArrayDeque<>();
            queue.addLast(start);
            color[start] = 1;
            while (!queue.isEmpty()) {
                int node = queue.removeFirst();
                for (int nb : graph[node]) {
                    if (color[nb] == 0) {
                        color[nb] = -color[node];
                        queue.addLast(nb);
                    } else if (color[nb] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
