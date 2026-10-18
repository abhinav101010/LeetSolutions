class Solution:
    def sumDivisibleByK(self, nums, k) :
        cnt = Counter(nums)
        return sum(x * v for x, v in cnt.items() if v % k == 0)
