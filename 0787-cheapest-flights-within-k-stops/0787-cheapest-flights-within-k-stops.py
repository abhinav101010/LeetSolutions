class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, K: int) -> int:
        # Bellman-Ford: relax edges up to K+1 times (since K stops means K+1 edges)
        INF = float('inf')
        dist = [INF] * n
        dist[src] = 0
        for i in range(K + 1):
            # copy dist to avoid using updated values in same iteration
            tmp = dist.copy()
            for u, v, w in flights:
                if dist[u] == INF:
                    continue
                if dist[u] + w < tmp[v]:
                    tmp[v] = dist[u] + w
            dist = tmp
        return dist[dst] if dist[dst] != INF else -1
