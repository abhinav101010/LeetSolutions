import heapq

class Solution:
    def mincostToHireWorkers(self, quality: list[int], wage: list[int], k: int) -> float:
        workers = sorted(((w / q, q, w) for q, w in zip(quality, wage)))
        # heap of negative quality (max-heap via min-heap of negative)
        max_heap = []
        sumq = 0
        ans = float('inf')
        for ratio, q, w in workers:
            heapq.heappush(max_heap, -q)
            sumq += q
            if len(max_heap) > k:
                sumq += heapq.heappop(max_heap)  # pop negative, so sumq += negative = sumq - largest quality
            if len(max_heap) == k:
                ans = min(ans, ratio * sumq)
        return ans
