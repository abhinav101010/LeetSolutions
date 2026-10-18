class Solution:
    def maximumProduct(self, nums, k):
        heapify(nums)
        for _ in range(k):
            heapreplace(nums, nums[0] + 1)
        mod = 10**9 + 7
        return reduce(lambda x, y: x * y % mod, nums)
