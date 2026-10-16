class Solution:
    def isMajorityElement(self, nums, target):
        n = len(nums)
        # find first occurrence
        l, r = 0, n
        while l < r:
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m
        first = l
        if first >= n or nums[first] != target:
            return False
        # count occurrences
        cnt = 0
        i = first
        while i < n and nums[i] == target:
            cnt += 1
            i += 1
        return cnt > n // 2
