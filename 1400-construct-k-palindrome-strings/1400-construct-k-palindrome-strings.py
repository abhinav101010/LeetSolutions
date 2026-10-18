class Solution:
    def canConstruct(self, s, k) :
        if len(s) < k:
            return False
        cnt = Counter(s)
        return sum(v & 1 for v in cnt.values()) <= k
