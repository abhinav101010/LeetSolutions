class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        final int INF = 1_000_000_000;
        int[] dist = new int[n];
        int[] tmp = new int[n];
        java.util.Arrays.fill(dist, INF);
        dist[src] = 0;
        for (int i = 0; i <= K; i++) {
            java.util.Arrays.fill(tmp, INF);
            for (int[] flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                if (dist[u] == INF) continue;
                if (dist[u] + w < tmp[v]) {
                    tmp[v] = dist[u] + w;
                }
            }
            // copy tmp to dist
            System.arraycopy(tmp, 0, dist, 0, n);
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
}
