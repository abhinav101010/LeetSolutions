from typing import List

class Solution:
    def largestUniqueNumber(self, nums: List[int]) -> int:
        cnt = {}
        for x in nums:
            cnt[x] = cnt.get(x, 0) + 1
        ans = -1
        for k, v in cnt.items():
            if v == 1 and k > ans:
                ans = k
        return ans