class Solution:
    def longestRepeatingSubstring(self, s):
        n = len(s)
        left, right = 1, n
        res = 0
        while left <= right:
            mid = (left + right) // 2
            if self.hasRepeating(s, mid):
                res = mid
                left = mid + 1
            else:
                right = mid - 1
        return res

    def hasRepeating(self, s, length):
        seen = set()
        for i in range(len(s) - length + 1):
            sub = s[i:i+length]
            if sub in seen: return True
            seen.add(sub)
        return False
