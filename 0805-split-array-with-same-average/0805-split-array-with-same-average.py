class Solution:
    def splitArraySameAverage(self, nums: list[int]) -> bool:
        n = len(nums)
        total = sum(nums)
        # DP: possible sums for each count
        # dp[k] = set of possible sums using k elements
        dp = [set() for _ in range(n//2 + 1)]
        dp[0].add(0)
        for num in nums:
            # iterate counts backwards
            for k in range(n//2, 0, -1):
                for prev in dp[k-1]:
                    dp[k].add(prev + num)
        for k in range(1, n//2 + 1):
            # check if total * k % n == 0
            if (total * k) % n == 0:
                target = (total * k) // n
                if target in dp[k]:
                    return True
        return False
