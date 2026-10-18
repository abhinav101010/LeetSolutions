class Solution:
    def getSneakyNumbers(self, nums):
        cnt = Counter(nums)
        return [x for x, v in cnt.items() if v == 2]
