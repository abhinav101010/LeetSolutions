class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        from collections import defaultdict
        count = defaultdict(int)
        count[0] = 1
        prefix = 0
        ans = 0
        for num in nums:
            prefix = (prefix + num) % k
            ans += count[prefix]
            count[prefix] += 1
        return ans
