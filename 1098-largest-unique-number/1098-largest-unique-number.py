from collections import Counter
class Solution:
    def largestUniqueNumber(self, A):
        c = Counter(A)
        ans = -1
        for k, v in c.items():
            if v == 1:
                ans = max(ans, k)
        return ans
