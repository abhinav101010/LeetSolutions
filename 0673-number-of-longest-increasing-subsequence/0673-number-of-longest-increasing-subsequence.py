from typing import List
from collections import Counter

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp_len = [1] * n
        dp_cnt = [1] * n
        max_len = 1
        for i in range(n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp_len[j] + 1 > dp_len[i]:
                        dp_len[i] = dp_len[j] + 1
                        dp_cnt[i] = dp_cnt[j]
                    elif dp_len[j] + 1 == dp_len[i]:
                        dp_cnt[i] += dp_cnt[j]
            max_len = max(max_len, dp_len[i])
        res = 0
        for i in range(n):
            if dp_len[i] == max_len:
                res += dp_cnt[i]
        return res