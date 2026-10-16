class Solution:
    def missingElement(self, nums, k):
        n = len(nums)
        for i in range(1, n):
            if nums[i] - nums[i-1] > 1:
                diff = nums[i] - nums[i-1] - 1
                if k <= diff:
                    return nums[i-1] + k
                else:
                    k -= diff
        return nums[-1] + k
