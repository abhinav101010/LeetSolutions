class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        reversedarr = sorted(nums)
        sortedArr = reversedarr[::-1]

        return nums == sortedArr or nums == reversedarr