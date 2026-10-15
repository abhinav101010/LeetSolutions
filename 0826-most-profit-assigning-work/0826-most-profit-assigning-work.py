class Solution:
    def maxProfitAssignment(self, difficulty: list[int], profit: list[int], worker: list[int]) -> int:
        jobs = list(zip(difficulty, profit))
        jobs.sort()
        max_profit_up_to = []
        maxp = 0
        for d, p in jobs:
            maxp = max(maxp, p)
            max_profit_up_to.append(maxp)
        # extract difficulties for binary search
        diffs = [d for d, _ in jobs]
        import bisect
        ans = 0
        for w in worker:
            idx = bisect.bisect_right(diffs, w) - 1
            if idx >= 0:
                ans += max_profit_up_to[idx]
        return ans
