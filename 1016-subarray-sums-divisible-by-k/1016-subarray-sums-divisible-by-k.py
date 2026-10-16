class Solution:
    def subarraysDivByK(self, nums, k):
        count = {0: 1}
        prefix = 0
        ans = 0
        for n in nums:
            prefix = (prefix + n) % k
            ans += count.get(prefix, 0)
            count[prefix] = count.get(prefix, 0) + 1
        return ans
