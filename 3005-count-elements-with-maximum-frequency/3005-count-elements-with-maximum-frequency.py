class Solution:
    def maxFrequencyElements(self, nums):
        cnt = Counter(nums)
        mx = max(cnt.values())
        return sum(x for x in cnt.values() if x == mx)
