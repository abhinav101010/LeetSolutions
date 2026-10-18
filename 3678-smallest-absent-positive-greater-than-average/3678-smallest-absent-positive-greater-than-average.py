class Solution:
    def smallestAbsent(self, nums) :
        s = set(nums)
        ans = max(1, sum(nums) // len(nums) + 1)
        while ans in s:
            ans += 1
        return ans
