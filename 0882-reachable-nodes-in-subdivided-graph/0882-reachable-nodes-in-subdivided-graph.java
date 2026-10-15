import java.util.*;
class Solution {
    public int reachableNodes(int[][] edges, int maxMoves, int n) {
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            int u = e[0], v = e[1], c = e[2];
            graph[u].add(new int[]{v, c + 1});
            graph[v].add(new int[]{u, c + 1});
        }
        // Dijkstra
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        pq.offer(new long[]{0, 0});
        while (!pq.isEmpty()) {
            long[] cur = pq.poll();
            long d = cur[0];
            int u = (int) cur[1];
            if (d > dist[u]) continue;
            for (int[] edge : graph[u]) {
                int v = edge[0];
                long w = edge[1];
                long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.offer(new long[]{nd, v});
                }
            }
        }
        // count original nodes reachable
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] <= maxMoves) ans++;
        }
        // count new nodes on edges
        for (int[] e : edges) {
            int u = e[0], v = e[1], cnt = e[2];
            long uReach = Math.max(0, maxMoves - dist[u]);
            long vReach = Math.max(0, maxMoves - dist[v]);
            ans += Math.min(cnt, uReach + vReach);
        }
        return ans;
    }
}
