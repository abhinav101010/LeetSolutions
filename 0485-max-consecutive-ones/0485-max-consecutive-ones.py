class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        ans = 0
        length = 0
        for num in nums:
            if num == 1:
                length+=1
            else:
                ans = max(ans, length)
                length = 0
        return max(ans, length)