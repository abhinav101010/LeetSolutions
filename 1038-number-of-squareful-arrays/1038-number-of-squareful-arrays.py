class Solution:
    def numSquarefulPerms(self, nums):
        n = len(nums)
        nums.sort()
        used = [False] * n
        ans = 0

        def backtrack(path):
            nonlocal ans
            if len(path) == n:
                ans += 1
                return
            for i in range(n):
                if used[i]: continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]: continue
                if path and not (int((path[-1] + nums[i]) ** 0.5) ** 2 == path[-1] + nums[i]): continue
                used[i] = True
                backtrack(path + [nums[i]])
                used[i] = False

        backtrack([])
        return ans
