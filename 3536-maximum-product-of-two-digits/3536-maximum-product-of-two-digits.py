class Solution:
    def maxProduct(self, n: int) -> int:
        nums = [int(c) for c in str(n)]
        
        nums.sort()
        ans = max(nums[-1]*nums[-2], nums[0]*nums[1])
        return ans