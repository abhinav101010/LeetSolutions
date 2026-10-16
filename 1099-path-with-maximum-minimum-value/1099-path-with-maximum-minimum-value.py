import heapq
class Solution:
    def maximumMinimumPath(self, A):
        m, n = len(A), len(A[0])
        pq = [(-A[0][0], 0, 0)]
        seen = set()
        while pq:
            val, x, y = heapq.heappop(pq)
            score = -val
            if (x, y) == (m - 1, n - 1):
                return score
            if (x, y) in seen:
                continue
            seen.add((x, y))
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and (nx, ny) not in seen:
                    heapq.heappush(pq, (-min(score, A[nx][ny]), nx, ny))
        return -1
