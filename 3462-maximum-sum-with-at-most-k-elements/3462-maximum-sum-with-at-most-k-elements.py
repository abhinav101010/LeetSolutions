class Solution:
    def maxSum(self, grid, limits, k) :
        pq = []
        for nums, limit in zip(grid, limits):
            nums.sort()
            for _ in range(limit):
                heappush(pq, nums.pop())
                if len(pq) > k:
                    heappop(pq)
        return sum(pq)
