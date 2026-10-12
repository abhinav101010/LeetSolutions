class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ans = [0]
        for num in nums:
            ans.append(ans[-1]+num)
        ans.pop(0)
        return ans