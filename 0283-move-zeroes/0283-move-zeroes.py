class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ans = []
        for n in nums:
            if n != 0: ans.append(n)
        nums[:] = ans + [0] * (len(nums) - len(ans))