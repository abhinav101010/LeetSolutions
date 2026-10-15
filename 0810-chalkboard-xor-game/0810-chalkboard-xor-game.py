class Solution:
    def xorGame(self, nums: list[int]) -> bool:
        if len(nums) % 2 == 0:
            return True
        xr = 0
        for v in nums:
            xr ^= v
        return xr == 0
