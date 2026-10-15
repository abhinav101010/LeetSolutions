class Solution:
    def numSubarraysWithSum(self, nums: list[int], goal: int) -> int:
        prefix = {0: 1}
        total = 0
        ans = 0
        for x in nums:
            total += x
            ans += prefix.get(total - goal, 0)
            prefix[total] = prefix.get(total, 0) + 1
        return ans
