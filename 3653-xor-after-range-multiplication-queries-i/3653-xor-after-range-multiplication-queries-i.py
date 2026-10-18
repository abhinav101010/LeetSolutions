class Solution:
    def xorAfterQueries(self, nums, queries) :
        mod = 10**9 + 7
        for l, r, k, v in queries:
            for idx in range(l, r + 1, k):
                nums[idx] = nums[idx] * v % mod
        return reduce(xor, nums)
