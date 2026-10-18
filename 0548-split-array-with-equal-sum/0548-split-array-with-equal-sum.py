from typing import List

class Solution:
    def splitArray(self, nums: List[int]) -> bool:
        n = len(nums)
        s = [0] * (n + 1)
        for i, num in enumerate(nums, 1):
            s[i] = s[i - 1] + num
        for j in range(3, n - 1):
            seen = set()
            for i in range(1, j - 1):
                if s[i] == s[j] - s[i + 1]:
                    seen.add(s[i])
            for k in range(j + 2, n):
                if s[n] - s[k + 1] == s[k] - s[j + 1] and (s[n] - s[k + 1]) in seen:
                    return True
        return False
