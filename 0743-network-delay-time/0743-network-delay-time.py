from typing import List
import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # build adjacency list
        adj = [[] for _ in range(n+1)]
        for u, v, w in times:
            adj[u].append((v, w))
        # Dijkstra
        dist = [float('inf')] * (n+1)
        dist[k] = 0
        heap = [(0, k)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if dist[v] > dist[u] + w:
                    dist[v] = dist[u] + w
                    heapq.heappush(heap, (dist[v], v))
        max_dist = 0
        for i in range(1, n+1):
            if dist[i] == float('inf'):
                return -1
            if dist[i] > max_dist:
                max_dist = dist[i]
        return max_dist
