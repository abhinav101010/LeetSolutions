class Solution:
    def divideArray(self, nums):
        cnt = Counter(nums)
        return all(v % 2 == 0 for v in cnt.values())