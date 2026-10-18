class Solution:
    def minRemoval(self, nums, k) -> int:
        nums.sort()
        cnt = 0
        for i, x in enumerate(nums):
            j = bisect_right(nums, k * x)
            cnt = max(cnt, j - i)
        return len(nums) - cnt
