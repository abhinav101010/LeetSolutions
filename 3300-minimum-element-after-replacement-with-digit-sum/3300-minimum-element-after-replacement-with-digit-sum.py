class Solution:
    def minElement(self, nums: List[int]) -> int:
        ans = []

        for i in range(len(nums)):
            digitSum = 0
            for c in str(nums[i]):
                digitSum+=int(c)
            ans.append(digitSum)
        return min(ans)