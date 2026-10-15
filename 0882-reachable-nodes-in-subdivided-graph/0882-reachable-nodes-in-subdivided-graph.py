import heapq
from collections import defaultdict

class Solution:
    def reachableNodes(self, edges: list[list[int]], maxMoves: int, n: int) -> int:
        # build graph
        graph = defaultdict(list)
        for u, v, cnt in edges:
            graph[u].append((v, cnt + 1))
            graph[v].append((u, cnt + 1))
        # Dijkstra
        dist = [float('inf')] * n
        dist[0] = 0
        pq = [(0, 0)]  # (distance, node)
        while pq:
            d, node = heapq.heappop(pq)
            if d > dist[node]:
                continue
            for nei, w in graph[node]:
                nd = d + w
                if nd < dist[nei]:
                    dist[nei] = nd
                    heapq.heappush(pq, (nd, nei))
        # count reachable original nodes
        ans = sum(1 for d in dist if d <= maxMoves)
        # count reachable new nodes on each edge
        for u, v, cnt in edges:
            u_reach = max(0, maxMoves - dist[u])
            v_reach = max(0, maxMoves - dist[v])
            ans += min(cnt, u_reach + v_reach)
        return ans
