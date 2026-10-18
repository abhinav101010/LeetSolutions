class Solution:
    def maximumScore(self, nums, s) -> int:
        ans = 0
        pq = []
        for x, c in zip(nums, s):
            heappush(pq, -x)
            if c == "1":
                ans -= heappop(pq)
        return ans
