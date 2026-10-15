class Solution:
    def numSubarrayBoundedMax(self, nums: list[int], left: int, right: int) -> int:
        def count(bound):
            res = 0
            cur = 0
            for v in nums:
                if v <= bound:
                    cur += 1
                else:
                    cur = 0
                res += cur
            return res
        return count(right) - count(left - 1)
